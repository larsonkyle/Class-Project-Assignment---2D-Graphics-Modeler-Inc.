/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *headwidget;
    QLabel *label;
    QGroupBox *loginBox;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *username;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLineEdit *password;
    QPushButton *Loginbutton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/loginWindow.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("#centralWidget{\n"
"\n"
"border-image: url(:/images/background.jpg);\n"
"\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("#centralwidget{\n"
"\n"
"border-image: url(:/images/background.jpg)\n"
"\n"
"}\n"
""));
        headwidget = new QWidget(centralwidget);
        headwidget->setObjectName(QString::fromUtf8("headwidget"));
        headwidget->setGeometry(QRect(330, 30, 141, 121));
        headwidget->setStyleSheet(QString::fromUtf8("#headwidget{\n"
"\n"
"border-image:url(:/images/loginIcon.png);\n"
"\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 160, 221, 71));
        loginBox = new QGroupBox(centralwidget);
        loginBox->setObjectName(QString::fromUtf8("loginBox"));
        loginBox->setGeometry(QRect(280, 230, 281, 231));
        loginBox->setStyleSheet(QString::fromUtf8("#loginBox{\n"
"\n"
"background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(170, 255, 127, 255), stop:1 rgba(0, 170, 255, 255));\n"
"border-radius: 8px;\n"
"\n"
"\n"
"font: 700 14pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(loginBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(loginBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        username = new QLineEdit(loginBox);
        username->setObjectName(QString::fromUtf8("username"));
        username->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));

        verticalLayout->addWidget(username);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(loginBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        password = new QLineEdit(loginBox);
        password->setObjectName(QString::fromUtf8("password"));
        password->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));

        verticalLayout_2->addWidget(password);


        verticalLayout_3->addLayout(verticalLayout_2);

        Loginbutton = new QPushButton(loginBox);
        Loginbutton->setObjectName(QString::fromUtf8("Loginbutton"));
        Loginbutton->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 127);\n"
"font: 700 14pt \"Segoe UI\";"));

        verticalLayout_3->addWidget(Loginbutton);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", " Login System", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:700; color:#000000;\">2D Painter Login</span></p></body></html>", nullptr));
        loginBox->setTitle(QCoreApplication::translate("MainWindow", "Please Login", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p/><p><span style=\" font-size:14pt; color:#000000;\">Username</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; color:#000000;\">Password</span></p></body></html>", nullptr));
        Loginbutton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
