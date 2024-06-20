#include "startgame.h"
#include "ui_startgame.h"
#include "mainwindow.h"
bool manage = true;

StartGame::StartGame(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StartGame)
{

    ui->setupUi(this);
}

StartGame::~StartGame()
{
    delete ui;
}

void StartGame::on_oneVSone_clicked()
{
     manage=true;
        hide();
        MainWindow *mainWindow = new MainWindow();
        mainWindow -> show();

}


void StartGame::on_oneVSai_clicked()
{
    manage=false;
    hide();
    Gameai = new GameAi(this);
    Gameai -> show();

}

