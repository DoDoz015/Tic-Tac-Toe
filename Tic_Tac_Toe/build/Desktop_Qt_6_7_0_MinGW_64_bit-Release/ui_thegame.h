/********************************************************************************
** Form generated from reading UI file 'thegame.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEGAME_H
#define UI_THEGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TheGame
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_1;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QPushButton *pushButton_9;
    QPushButton *pushButton_7;
    QPushButton *Reset;
    QPushButton *New_Game;
    QPushButton *Undo;
    QPushButton *pushButton_10;

    void setupUi(QDialog *TheGame)
    {
        if (TheGame->objectName().isEmpty())
            TheGame->setObjectName("TheGame");
        TheGame->resize(1256, 695);
        layoutWidget = new QWidget(TheGame);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(440, 140, 316, 316));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_1 = new QPushButton(layoutWidget);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setMinimumSize(QSize(100, 100));
        QFont font;
        font.setPointSize(36);
        font.setBold(true);
        pushButton_1->setFont(font);

        gridLayout->addWidget(pushButton_1, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(100, 100));
        pushButton_3->setFont(font);

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setMinimumSize(QSize(100, 100));
        pushButton_5->setFont(font);

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(100, 100));
        pushButton_2->setFont(font);

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(100, 100));
        pushButton_4->setFont(font);

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setMinimumSize(QSize(100, 100));
        pushButton_8->setFont(font);

        gridLayout->addWidget(pushButton_8, 2, 1, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setMinimumSize(QSize(100, 100));
        pushButton_6->setFont(font);

        gridLayout->addWidget(pushButton_6, 1, 2, 1, 1);

        pushButton_9 = new QPushButton(layoutWidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setEnabled(true);
        pushButton_9->setMinimumSize(QSize(100, 100));
        pushButton_9->setFont(font);

        gridLayout->addWidget(pushButton_9, 2, 2, 1, 1);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setMinimumSize(QSize(100, 100));
        pushButton_7->setFont(font);

        gridLayout->addWidget(pushButton_7, 2, 0, 1, 1);

        Reset = new QPushButton(TheGame);
        Reset->setObjectName("Reset");
        Reset->setGeometry(QRect(550, 520, 93, 29));
        New_Game = new QPushButton(TheGame);
        New_Game->setObjectName("New_Game");
        New_Game->setGeometry(QRect(400, 520, 93, 29));
        Undo = new QPushButton(TheGame);
        Undo->setObjectName("Undo");
        Undo->setGeometry(QRect(700, 520, 93, 29));
        pushButton_10 = new QPushButton(TheGame);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(540, 610, 91, 61));

        retranslateUi(TheGame);
        QObject::connect(pushButton_10, &QPushButton::clicked, TheGame, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(TheGame);
    } // setupUi

    void retranslateUi(QDialog *TheGame)
    {
        TheGame->setWindowTitle(QCoreApplication::translate("TheGame", "Dialog", nullptr));
        pushButton_1->setText(QString());
        pushButton_3->setText(QString());
        pushButton_5->setText(QString());
        pushButton_2->setText(QString());
        pushButton_4->setText(QString());
        pushButton_8->setText(QString());
        pushButton_6->setText(QString());
        pushButton_9->setText(QString());
        pushButton_7->setText(QString());
        Reset->setText(QCoreApplication::translate("TheGame", "Reset", nullptr));
        New_Game->setText(QCoreApplication::translate("TheGame", "New Game", nullptr));
        Undo->setText(QCoreApplication::translate("TheGame", "Undo", nullptr));
        pushButton_10->setText(QCoreApplication::translate("TheGame", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TheGame: public Ui_TheGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEGAME_H
