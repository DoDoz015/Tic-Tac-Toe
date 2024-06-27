/********************************************************************************
** Form generated from reading UI file 'gamehistory.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEHISTORY_H
#define UI_GAMEHISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameHistory
{
public:
    QWidget *gameHistoryLayout;

    void setupUi(QDialog *GameHistory)
    {
        if (GameHistory->objectName().isEmpty())
            GameHistory->setObjectName("GameHistory");
        GameHistory->resize(830, 584);
        gameHistoryLayout = new QWidget(GameHistory);
        gameHistoryLayout->setObjectName("gameHistoryLayout");
        gameHistoryLayout->setGeometry(QRect(150, 60, 541, 391));

        retranslateUi(GameHistory);

        QMetaObject::connectSlotsByName(GameHistory);
    } // setupUi

    void retranslateUi(QDialog *GameHistory)
    {
        GameHistory->setWindowTitle(QCoreApplication::translate("GameHistory", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameHistory: public Ui_GameHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEHISTORY_H
