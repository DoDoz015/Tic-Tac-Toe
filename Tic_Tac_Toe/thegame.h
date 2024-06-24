#pragma once
#ifndef THEGAME_H
#define THEGAME_H
#include <QWidget>
#include <QPushButton>
#include <QDialog>
#include <QGuiApplication>
#include <QScreen>

#include <QStack>

// Struct to represent a move
struct Move {
    int row;
    int col;
    QString player;  // 'X' or 'O'
};

extern QStack<Move> moveStack;



namespace Ui {
class TheGame;
}

class TheGame : public QDialog
{
    Q_OBJECT

public:
    explicit TheGame(QWidget *parent = nullptr);
    ~TheGame();



private slots:
    //void handleCellClicked();

    void on_pushButton_clicked();
    void checkForWin();

    void on_Reset_clicked();

    void on_New_Game_clicked();






    void on_Undo_clicked();

private:
    QPushButton *grid[3][3];
    Ui::TheGame *ui;
    QString currentPlayer;
    bool End_Game;
    int stepNumber;  // Add this line to track the step number
    void startNewGame() ;


    void switchPlayer();
    int lastInsertedGameID;


};

#endif // THEGAME_H

