#include "startgame.h"
#include "ui_startgame.h"
#include "mainwindow.h"

StartGame::StartGame(QWidget *parent) : QDialog(parent), ui(new Ui::StartGame)
{
    ui->setupUi(this);
}

StartGame::~StartGame()
{
    delete ui;
}

void StartGame::on_oneVSone_clicked()
{
    // Start a new one-on-one game
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}
