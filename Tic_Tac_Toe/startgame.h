#pragma once
#ifndef STARTGAME_H
#define STARTGAME_H
#include "thegame.h"
#include <QDialog>
#include "gameai.h"
extern bool manage;




namespace Ui {
class StartGame;
}

class StartGame : public QDialog
{
    Q_OBJECT

public:
    explicit StartGame(QWidget *parent = nullptr);
    ~StartGame();



private slots:
    void on_oneVSone_clicked();


    void on_oneVSai_clicked();

private:
    Ui::StartGame *ui;
    TheGame * theGame;
    GameAi * Gameai;




};


#endif // STARTGAME_H
