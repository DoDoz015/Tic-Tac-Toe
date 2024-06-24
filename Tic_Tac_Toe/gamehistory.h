#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QVBoxLayout>
#include "replaygamewindow.h"



namespace Ui {
class GameHistory;
}

class GameHistory : public QDialog
{
    Q_OBJECT

public:
    explicit GameHistory(QWidget *parent = nullptr );
    ~GameHistory();

private slots:
    void onGameButtonClicked();

private:
    void fetchAndDisplayGameHistory(int userId);
    Ui::GameHistory *ui;
    QVBoxLayout *layout;
    QVector<int> gameIds; // Store game IDs to know which game to replay
    ReplayGameWindow * replaygamewindow;



};

#endif // GAMEHISTORY_H
