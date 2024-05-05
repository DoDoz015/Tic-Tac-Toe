/********************************************************************************
** Form generated from reading UI file 'startgame.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTGAME_H
#define UI_STARTGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartGame
{
public:
    QPushButton *pushButton_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *oneVSone;
    QPushButton *pushButton_2;

    void setupUi(QDialog *StartGame)
    {
        if (StartGame->objectName().isEmpty())
            StartGame->setObjectName("StartGame");
        StartGame->resize(896, 441);
        pushButton_3 = new QPushButton(StartGame);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(400, 330, 93, 29));
        layoutWidget = new QWidget(StartGame);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(340, 150, 221, 81));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        oneVSone = new QPushButton(layoutWidget);
        oneVSone->setObjectName("oneVSone");

        horizontalLayout->addWidget(oneVSone);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        retranslateUi(StartGame);
        QObject::connect(pushButton_3, &QPushButton::clicked, StartGame, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(StartGame);
    } // setupUi

    void retranslateUi(QDialog *StartGame)
    {
        StartGame->setWindowTitle(QCoreApplication::translate("StartGame", "Dialog", nullptr));
        pushButton_3->setText(QCoreApplication::translate("StartGame", "Exit", nullptr));
        oneVSone->setText(QCoreApplication::translate("StartGame", "1vs1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("StartGame", "1vsAI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartGame: public Ui_StartGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTGAME_H
