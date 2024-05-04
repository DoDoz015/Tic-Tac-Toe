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

private:
    QPushButton *grid[3][3];
    Ui::TheGame *ui;
    QString currentPlayer;

    void switchPlayer();



};

#endif // THEGAME_H
