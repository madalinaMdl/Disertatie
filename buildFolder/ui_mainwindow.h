/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *exit;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QLabel *nombrecont;
    QLabel *label_2;
    QLabel *matchresultlabel;
    QLabel *label_3;
    QLabel *signname;
    QLabel *label_12;
    QSpinBox *tolerance_lvl;
    QPushButton *pushButton_3;
    QSpinBox *Delais;
    QWidget *tab_3;
    QWidget *tab_4;
    QPushButton *pushButton_2;
    QLineEdit *imageboxname;
    QLabel *label_4;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *template_buttom;
    QMenuBar *menuBar;
    QMenu *menuIceman;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(574, 453);
        exit = new QAction(MainWindow);
        exit->setObjectName(QStringLiteral("exit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(10, 70, 561, 341));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        nombrecont = new QLabel(tab_2);
        nombrecont->setObjectName(QStringLiteral("nombrecont"));
        nombrecont->setGeometry(QRect(240, 110, 66, 17));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 90, 51, 17));
        matchresultlabel = new QLabel(tab_2);
        matchresultlabel->setObjectName(QStringLiteral("matchresultlabel"));
        matchresultlabel->setGeometry(QRect(120, 90, 66, 17));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 170, 91, 17));
        signname = new QLabel(tab_2);
        signname->setObjectName(QStringLiteral("signname"));
        signname->setGeometry(QRect(120, 140, 101, 61));
        QFont font;
        font.setPointSize(24);
        font.setItalic(true);
        signname->setFont(font);
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 260, 111, 17));
        tolerance_lvl = new QSpinBox(tab_2);
        tolerance_lvl->setObjectName(QStringLiteral("tolerance_lvl"));
        tolerance_lvl->setGeometry(QRect(130, 250, 60, 27));
        tolerance_lvl->setValue(9);
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(324, 240, 71, 23));
        Delais = new QSpinBox(tab_2);
        Delais->setObjectName(QStringLiteral("Delais"));
        Delais->setGeometry(QRect(170, 40, 121, 29));
        Delais->setMaximum(10000);
        Delais->setValue(40);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        pushButton_2 = new QPushButton(tab_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(false);
        pushButton_2->setGeometry(QRect(230, 180, 91, 31));
        imageboxname = new QLineEdit(tab_4);
        imageboxname->setObjectName(QStringLiteral("imageboxname"));
        imageboxname->setEnabled(false);
        imageboxname->setGeometry(QRect(180, 90, 211, 31));
        label_4 = new QLabel(tab_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(130, 50, 311, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setWordWrap(true);
        tabWidget->addTab(tab_4, QString());
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 10, 241, 51));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 20, 91, 31));
        template_buttom = new QPushButton(centralWidget);
        template_buttom->setObjectName(QStringLiteral("template_buttom"));
        template_buttom->setEnabled(false);
        template_buttom->setGeometry(QRect(430, 20, 101, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 574, 21));
        menuIceman = new QMenu(menuBar);
        menuIceman->setObjectName(QStringLiteral("menuIceman"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuIceman->menuAction());
        menuIceman->addAction(exit);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        exit->setText(QApplication::translate("MainWindow", "Exit", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "American Sign Language", 0));
        nombrecont->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Precision", 0));
        matchresultlabel->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p>La lettre est :</p></body></html>", 0));
        signname->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "Tolerance LVL:", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "ok", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "British Sign Language", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Expressions", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "OK", 0));
        label_4->setText(QApplication::translate("MainWindow", "Enter the name of the new image", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Add new data", 0));
        label->setText(QApplication::translate("MainWindow", "Sign Language", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Start Webcam", 0));
        template_buttom->setText(QApplication::translate("MainWindow", "View Hand", 0));
        menuIceman->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
