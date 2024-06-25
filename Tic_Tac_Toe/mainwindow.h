#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define AI_id 123456

#include "gamehistory.h"
#include "gamehistorylogin.h"
#include "startgame.h"
#include "thegame.h"
#include "gameai.h"
#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QDialog>
#include <QFileInfo>
extern QString loggedInUser ;
extern int gameId;
extern int loggedInUser1ID ;
extern  int loggedInUser2ID ;
extern QString loggedInUser1 ;
extern QString loggedInUser2 ;
extern int userId;

extern bool firsttimeai;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

   // void on_pushButton_clicked();

    void on_Login_clicked();

    void on_Save_clicked();


    void on_Game_History_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase MyDB;
    StartGame * startGame;
    TheGame * theGame;
    GameAi * gameai;
    GameHistoryLogin * gamehistorylogin;

    QString hashPassword(const QString &password);
    bool checkPassword(const QString &inputPassword, const QString &hashedPassword);



};
#endif // MAINWINDOW_H
