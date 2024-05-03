#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "startgame.h"

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

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
    void on_Login_clicked();

    void on_Save_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase MyDB;
    StartGame * startGame;

};
#endif // MAINWINDOW_H