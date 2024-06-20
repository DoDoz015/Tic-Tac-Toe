/********************************************************************************
** Form generated from reading UI file 'gameai.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEAI_H
#define UI_GAMEAI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameAi
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QPushButton *pushButton_9;
    QPushButton *pushButton_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_12;
    QPushButton *Reset;
    QPushButton *New_Game;
    QPushButton *pushButton_10;

    void setupUi(QDialog *GameAi)
    {
        if (GameAi->objectName().isEmpty())
            GameAi->setObjectName("GameAi");
        GameAi->resize(1342, 783);
        layoutWidget = new QWidget(GameAi);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(460, 110, 316, 316));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(100, 100));
        QFont font;
        font.setPointSize(36);
        font.setBold(true);
        pushButton->setFont(font);

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

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

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(100, 100));
        pushButton_2->setFont(font);

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_12 = new QPushButton(GameAi);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(720, 490, 93, 29));
        Reset = new QPushButton(GameAi);
        Reset->setObjectName("Reset");
        Reset->setGeometry(QRect(570, 490, 93, 29));
        New_Game = new QPushButton(GameAi);
        New_Game->setObjectName("New_Game");
        New_Game->setGeometry(QRect(420, 490, 93, 29));
        pushButton_10 = new QPushButton(GameAi);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(560, 580, 91, 61));

        retranslateUi(GameAi);
        QObject::connect(pushButton_10, &QPushButton::clicked, GameAi, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(GameAi);
    } // setupUi

    void retranslateUi(QDialog *GameAi)
    {
        GameAi->setWindowTitle(QCoreApplication::translate("GameAi", "Dialog", nullptr));
        pushButton->setText(QString());
        pushButton_3->setText(QString());
        pushButton_5->setText(QString());
        pushButton_4->setText(QString());
        pushButton_8->setText(QString());
        pushButton_6->setText(QString());
        pushButton_9->setText(QString());
        pushButton_7->setText(QString());
        pushButton_2->setText(QString());
        pushButton_12->setText(QCoreApplication::translate("GameAi", "Undo", nullptr));
        Reset->setText(QCoreApplication::translate("GameAi", "Reset", nullptr));
        New_Game->setText(QCoreApplication::translate("GameAi", "New Game", nullptr));
        pushButton_10->setText(QCoreApplication::translate("GameAi", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameAi: public Ui_GameAi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEAI_H
