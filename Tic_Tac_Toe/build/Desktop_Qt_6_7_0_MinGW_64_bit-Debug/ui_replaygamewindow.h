/********************************************************************************
** Form generated from reading UI file 'replaygamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLAYGAMEWINDOW_H
#define UI_REPLAYGAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReplayGameWindow
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_1;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QPushButton *pushButton_9;
    QPushButton *pushButton_7;
    QPushButton *pushButton_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *PreviousStep;
    QPushButton *NextStep;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *Back;
    QPushButton *Home;

    void setupUi(QDialog *ReplayGameWindow)
    {
        if (ReplayGameWindow->objectName().isEmpty())
            ReplayGameWindow->setObjectName("ReplayGameWindow");
        ReplayGameWindow->resize(984, 531);
        layoutWidget = new QWidget(ReplayGameWindow);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(300, 50, 316, 316));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_1 = new QPushButton(layoutWidget);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setEnabled(false);
        pushButton_1->setMinimumSize(QSize(100, 100));
        QFont font;
        font.setPointSize(36);
        font.setBold(true);
        pushButton_1->setFont(font);
        pushButton_1->setAutoDefault(false);

        gridLayout->addWidget(pushButton_1, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setEnabled(false);
        pushButton_3->setMinimumSize(QSize(100, 100));
        pushButton_3->setFont(font);
        pushButton_3->setAutoDefault(false);

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setEnabled(false);
        pushButton_5->setMinimumSize(QSize(100, 100));
        pushButton_5->setFont(font);
        pushButton_5->setAutoDefault(false);

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setEnabled(false);
        pushButton_4->setMinimumSize(QSize(100, 100));
        pushButton_4->setFont(font);
        pushButton_4->setAutoDefault(false);

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setEnabled(false);
        pushButton_8->setMinimumSize(QSize(100, 100));
        pushButton_8->setFont(font);
        pushButton_8->setAutoDefault(false);

        gridLayout->addWidget(pushButton_8, 2, 1, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setEnabled(false);
        pushButton_6->setMinimumSize(QSize(100, 100));
        pushButton_6->setFont(font);
        pushButton_6->setAutoDefault(false);

        gridLayout->addWidget(pushButton_6, 1, 2, 1, 1);

        pushButton_9 = new QPushButton(layoutWidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setEnabled(false);
        pushButton_9->setMinimumSize(QSize(100, 100));
        pushButton_9->setFont(font);
        pushButton_9->setAutoDefault(false);

        gridLayout->addWidget(pushButton_9, 2, 2, 1, 1);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setEnabled(false);
        pushButton_7->setMinimumSize(QSize(100, 100));
        pushButton_7->setFont(font);
        pushButton_7->setAutoDefault(false);

        gridLayout->addWidget(pushButton_7, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setEnabled(false);
        pushButton_2->setMinimumSize(QSize(100, 100));
        pushButton_2->setFont(font);
        pushButton_2->setAutoDefault(false);

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        layoutWidget1 = new QWidget(ReplayGameWindow);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(340, 370, 235, 111));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        PreviousStep = new QPushButton(layoutWidget1);
        PreviousStep->setObjectName("PreviousStep");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/back_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        PreviousStep->setIcon(icon);
        PreviousStep->setIconSize(QSize(100, 50));
        PreviousStep->setFlat(true);

        horizontalLayout->addWidget(PreviousStep);

        NextStep = new QPushButton(layoutWidget1);
        NextStep->setObjectName("NextStep");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/images/next_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        NextStep->setIcon(icon1);
        NextStep->setIconSize(QSize(100, 50));
        NextStep->setFlat(true);

        horizontalLayout->addWidget(NextStep);

        widget = new QWidget(ReplayGameWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 416, 101, 81));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Back = new QPushButton(widget);
        Back->setObjectName("Back");

        verticalLayout->addWidget(Back);

        Home = new QPushButton(widget);
        Home->setObjectName("Home");

        verticalLayout->addWidget(Home);


        retranslateUi(ReplayGameWindow);

        NextStep->setDefault(false);


        QMetaObject::connectSlotsByName(ReplayGameWindow);
    } // setupUi

    void retranslateUi(QDialog *ReplayGameWindow)
    {
        ReplayGameWindow->setWindowTitle(QCoreApplication::translate("ReplayGameWindow", "Dialog", nullptr));
        pushButton_1->setText(QString());
        pushButton_3->setText(QString());
        pushButton_5->setText(QString());
        pushButton_4->setText(QString());
        pushButton_8->setText(QString());
        pushButton_6->setText(QString());
        pushButton_9->setText(QString());
        pushButton_7->setText(QString());
        pushButton_2->setText(QString());
        PreviousStep->setText(QString());
        NextStep->setText(QString());
        Back->setText(QCoreApplication::translate("ReplayGameWindow", "Back", nullptr));
        Home->setText(QCoreApplication::translate("ReplayGameWindow", "Home", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReplayGameWindow: public Ui_ReplayGameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLAYGAMEWINDOW_H
