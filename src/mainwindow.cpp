#include "mainwindow.h"
#include "qdebug.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow)
    , m_stopCapture(true)
    , m_showGray(false)
    , m_startmatching(false)

{
    m_alphabetTable << "A.jpg" << "B.jpg" << "C.jpg" << "D.jpg" << "E.jpg" << "F.jpg";
    m_color = cvScalar(0x00,0x00,0xff);
    m_timer = new QTimer(this);
    //connect(m_timer, SIGNAL(timeout()),this,SLOT(stopped_timer()));
    connect(m_timer, &QTimer::timeout, this, &MainWindow::stopped_timer);
    m_ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    cvDestroyAllWindows();
    delete m_ui;
}

void MainWindow::on_pushButton_clicked()
{
    m_stopCapture = !m_stopCapture;
    m_ui->pushButton_2->setEnabled(!m_stopCapture);
    m_ui->imageboxname->setEnabled(!m_stopCapture);
    m_ui->template_buttom->setEnabled(!m_stopCapture);

    if (m_stopCapture)
    {
        m_ui->pushButton->setText(QString("Start Capture"));
    }
    else
    {
        m_ui->pushButton->setText(QString("Stop Capture"));
        MainWindow::capture();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    const QString imageName = m_ui->imageboxname->text() + ".jpg";
    cvSaveImage(imageName.toStdString().c_str(), m_gray);
    m_ui->imageboxname->setText("");
}

void MainWindow::on_pushButton_3_clicked()
{
    m_startmatching = true;
}

void MainWindow::on_template_buttom_clicked()
{
    m_showGray = true;
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    qDebug() << "tab  nr: " << index;
}

void MainWindow::stopped_timer()
{
    m_ui->signname->setText("");
}


float MainWindow::matchTwoShapes(IplImage* image1, IplImage* image2)
{
    double matchresult = 100;
    double mincontour = 200;  // taille mimale du contour qu il faut le detecter
    int CVCONTOUR_APPROX_LEVEL;
    IplImage* img1_edge = cvCreateImage(cvGetSize(image1), 8, 1);
    IplImage* img2_edge = cvCreateImage(cvGetSize(image2), 8, 1);

    cvThreshold(image1, img1_edge, 128, 255, CV_THRESH_BINARY);
    cvThreshold(image2, img2_edge, 128, 255, CV_THRESH_BINARY);
    CvMemStorage* storage = cvCreateMemStorage();
    CvMemStorage* storage2 = cvCreateMemStorage();
    CvSeq* premier_contour_img1 = NULL;
    CvSeq* premier_contour_img2 = NULL;
    CvSeq* newseq = NULL;
    CvSeq* newseq2 = NULL;

    //first Border extraction
    cvFindContours(img1_edge, storage, &premier_contour_img1, sizeof(CvContour), CV_RETR_LIST);
    //second border extraction
    cvFindContours(img2_edge, storage2, &premier_contour_img2, sizeof(CvContour), CV_RETR_LIST);

    CVCONTOUR_APPROX_LEVEL = m_ui->tolerance_lvl->value();
    //extract aprox polu
    for (CvSeq* c = premier_contour_img1; c != NULL; c = c->h_next)
    {
        if (cvContourPerimeter(c) > mincontour)
        {
            newseq = cvApproxPoly(c, sizeof(CvContour), storage, CV_POLY_APPROX_DP, CVCONTOUR_APPROX_LEVEL, 0); //pprox
        }
    }

    for(CvSeq* c = premier_contour_img2; c != NULL; c = c->h_next)
    {
        if (cvContourPerimeter(c) > mincontour)
        {
            newseq2 = cvApproxPoly(c, sizeof(CvContour), storage2, CV_POLY_APPROX_DP, CVCONTOUR_APPROX_LEVEL, 0); //pprox
        }
    }

    //match the two contours
    if(newseq && newseq2)
    {
        matchresult = cvMatchShapes(newseq2, newseq, 1, 0.0); // inainte era cvMatchContours
    }

    cvReleaseImage(&img1_edge);
    cvReleaseImage(&img2_edge);
    cvReleaseMemStorage(&storage);
    cvReleaseMemStorage(&storage2);

    return matchresult;
}

void MainWindow::capture()
{
    float matchresult = 1;
    m_capWebcam = cvCaptureFromCAM(0);
    cvNamedWindow("Original", CV_WINDOW_AUTOSIZE);

    IplImage* tableauxImage[6];
    for (int i = 0; i < 6; i++)
    {
        QString b = QString("C:/Users/Madalina/Downloads/SignsLanguageRecognition-master/build-untitled-Desktop_Qt_5_7_0_MSVC2015_64bit-Release/release/%1").arg(m_alphabetTable.at(i));
        tableauxImage[i]= new IplImage(cv::imread(b.toStdString(), CV_LOAD_IMAGE_GRAYSCALE));
    }

    while (1)
    {
        m_imgOriginal = cvQueryFrame(m_capWebcam);
        m_gray= cvCreateImage(cvGetSize(m_imgOriginal), 8, 1);
        cvFlip(m_imgOriginal, m_imgOriginal, 1);
        cvCvtColor(m_imgOriginal, m_gray, CV_BGR2GRAY);
        cvSetImageROI(m_gray, cvRect(100,100,200,200));
        cvThreshold(m_gray, m_gray, 100, 255, CV_THRESH_BINARY_INV);
        MainWindow::drawBox(m_imgOriginal, cvRect(100,100,200,200));

        // when show Roi Button is clicked
        if (m_showGray)
        {
            cvNamedWindow("template gray", CV_WINDOW_AUTOSIZE);
            cvShowImage("template gray", m_gray);
        }

        cvShowImage("Original", m_imgOriginal);
        for( int i = 0; i < 6; i++)
        {
            if (m_startmatching)
            {
                matchresult = MainWindow::matchTwoShapes(tableauxImage[i], m_gray);
            }

            if (matchresult < 0.1)
            {
                m_ui->signname->setText(QString((m_alphabetTable.at(i))[0])); //good match
                m_timer->start(1000);
            }
            else
            {
                m_color = matchresult < 0.25 ? cvScalar(0x00,0xff,0x00) : cvScalar(0x00,0x00,0xff);
            }

            m_ui->matchresultlabel->setText(QString::number(matchresult));
        }

        m_charCheckForEscKey = cvWaitKey(m_ui->Delais->value());// delay (in ms), and get key press, if any
        if((m_charCheckForEscKey == 27) || (m_stopCapture))
            break;
    }

    for (int i = 0; i < 6; i++)
    {
        cvReleaseImage(&tableauxImage[i]);
    }

    cvReleaseCapture(&m_capWebcam);
    cvDestroyAllWindows();
}

void MainWindow::drawBox(IplImage* img, CvRect box)
{
    cvRectangle(img, cvPoint(box.x, box.y), cvPoint(box.x + box.width, box.y + box.height), m_color);
}
