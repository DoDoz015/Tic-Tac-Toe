#ifndef THEGAME_H
#define THEGAME_H
#include <QWidget>
#include <QPushButton>
#include <QDialog>
#include <QGuiApplication>
#include <QScreen>

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




 private:
    QPushButton *grid[3][3];
    Ui::TheGame *ui;
    QString currentPlayer;
    bool End_Game;

    void switchPlayer();



};

#endif // THEGAME_H
