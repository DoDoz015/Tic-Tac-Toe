/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QPushButton *Login;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_username_2;
    QLineEdit *lineEdit_password_2;
    QPushButton *Save;
    QPushButton *pushButton;
    QPushButton *Game_History;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(480, 150, 251, 181));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 60, 63, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 90, 63, 20));
        lineEdit_username = new QLineEdit(groupBox);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setGeometry(QRect(100, 60, 113, 26));
        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(100, 90, 113, 26));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        Login = new QPushButton(groupBox);
        Login->setObjectName("Login");
        Login->setGeometry(QRect(100, 140, 93, 29));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(120, 160, 211, 171));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 50, 63, 20));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 90, 63, 20));
        lineEdit_username_2 = new QLineEdit(groupBox_2);
        lineEdit_username_2->setObjectName("lineEdit_username_2");
        lineEdit_username_2->setGeometry(QRect(80, 50, 113, 26));
        lineEdit_password_2 = new QLineEdit(groupBox_2);
        lineEdit_password_2->setObjectName("lineEdit_password_2");
        lineEdit_password_2->setGeometry(QRect(80, 90, 113, 26));
        lineEdit_password_2->setEchoMode(QLineEdit::Password);
        Save = new QPushButton(groupBox_2);
        Save->setObjectName("Save");
        Save->setGeometry(QRect(60, 130, 93, 29));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(350, 480, 93, 29));
        Game_History = new QPushButton(centralwidget);
        Game_History->setObjectName("Game_History");
        Game_History->setGeometry(QRect(620, 10, 121, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Sign in", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "username", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "password", nullptr));
        Login->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Sign up", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "username", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "password", nullptr));
        Save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        Game_History->setText(QCoreApplication::translate("MainWindow", "Game History", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
