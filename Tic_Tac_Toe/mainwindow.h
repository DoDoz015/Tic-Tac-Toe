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
<<<<<<< HEAD
    void on_pushButton_clicked();
=======
    void on_Login_clicked();

    void on_Save_clicked();
>>>>>>> c6671ae2d93e8535cd7fa95ce1696fe8c5e6b038

private:
    Ui::MainWindow *ui;
    QSqlDatabase MyDB;
    StartGame * startGame;

};
#endif // MAINWINDOW_H
