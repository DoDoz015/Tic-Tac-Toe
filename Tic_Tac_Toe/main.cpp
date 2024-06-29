#include "mainwindow.h"
// #include "thegame.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    // TheGame game;
    // game.testCheckForWin();
    return a.exec();
}
