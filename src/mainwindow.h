#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv/cxcore.h>
#include <QTimer>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_template_buttom_clicked();
    void on_tabWidget_currentChanged(int index);
    void stopped_timer();

private:
    float matchTwoShapes(IplImage* image1, IplImage* image2);
    void capture();
    void drawBox(IplImage* img, CvRect box);

    Ui::MainWindow *m_ui;
    CvCapture* m_capWebcam;
    IplImage* m_imgOriginal;
    IplImage* m_imgProcessed;
    IplImage *m_gray;
    CvScalar m_color;
    CvMemStorage* m_strStorage;
    QStringList m_alphabetTable;
    QTimer *m_timer;

    char m_charCheckForEscKey;
    bool m_showGray;
    bool m_startmatching;
    bool m_stopCapture;
};

#endif // MAINWINDOW_H
