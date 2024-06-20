#pragma once
#ifndef GAMEAI_H
#define GAMEAI_H

#include <QWidget>
#include <QPushButton>
#include <QDialog>
#include <QGuiApplication>
#include <QScreen>

#include <QStack>

// Struct to represent a move
struct MoveAI {
    int row;
    int col;
    QString player;  // 'X' or 'O'
};

extern QStack<MoveAI> moveStackAI;



namespace Ui {
class GameAi;
}

class GameAi : public QDialog
{
    Q_OBJECT

public:
    explicit GameAi(QWidget *parent = nullptr);
    ~GameAi();

    private slots:

    void on_pushButton_clicked();

    void on_Reset_clicked();

    void on_New_Game_clicked();

    void on_Undo_clicked();

private:

    Ui::GameAi *ui;

    QPushButton *grid[3][3];

    bool End_Game_AI;

    QString HumanPlayer;

    QString AIPlayer;

    void checkForWin();

    void AIMove();

    int minimax(bool isMaximizing, int alpha, int beta);

    QString checkWinner();

};

#endif // GAMEAI_H
