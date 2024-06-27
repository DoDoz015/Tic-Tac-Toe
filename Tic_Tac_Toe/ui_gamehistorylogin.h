/********************************************************************************
** Form generated from reading UI file 'gamehistorylogin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEHISTORYLOGIN_H
#define UI_GAMEHISTORYLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameHistoryLogin
{
public:
    QPushButton *Verify;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_Username;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_Password;

    void setupUi(QDialog *GameHistoryLogin)
    {
        if (GameHistoryLogin->objectName().isEmpty())
            GameHistoryLogin->setObjectName("GameHistoryLogin");
        GameHistoryLogin->resize(1019, 495);
        Verify = new QPushButton(GameHistoryLogin);
        Verify->setObjectName("Verify");
        Verify->setGeometry(QRect(380, 270, 93, 29));
        layoutWidget = new QWidget(GameHistoryLogin);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(330, 190, 229, 69));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        lineEdit_Username = new QLineEdit(layoutWidget);
        lineEdit_Username->setObjectName("lineEdit_Username");

        horizontalLayout->addWidget(lineEdit_Username);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        lineEdit_Password = new QLineEdit(layoutWidget);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEdit_Password);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(GameHistoryLogin);

        QMetaObject::connectSlotsByName(GameHistoryLogin);
    } // setupUi

    void retranslateUi(QDialog *GameHistoryLogin)
    {
        GameHistoryLogin->setWindowTitle(QCoreApplication::translate("GameHistoryLogin", "Dialog", nullptr));
        Verify->setText(QCoreApplication::translate("GameHistoryLogin", "Verify", nullptr));
        label_2->setText(QCoreApplication::translate("GameHistoryLogin", "username", nullptr));
        lineEdit_Username->setPlaceholderText(QString());
        label_3->setText(QCoreApplication::translate("GameHistoryLogin", "password", nullptr));
        lineEdit_Password->setPlaceholderText(QString());
    } // retranslateUi

};

namespace Ui {
    class GameHistoryLogin: public Ui_GameHistoryLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEHISTORYLOGIN_H
