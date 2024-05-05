#ifndef STARTGAME_H
#define STARTGAME_H
#include "thegame.h"
#include <QDialog>



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


private:
    Ui::StartGame *ui;
    TheGame * theGame;





};


#endif // STARTGAME_H
