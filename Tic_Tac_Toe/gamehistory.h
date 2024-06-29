#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H
#include "replaygamewindow.h"

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QVBoxLayout>
#include <QMap>
#include <QPushButton>
namespace Ui {
class GameHistory;
}

class GameHistory : public QDialog
{
    Q_OBJECT

public:
    explicit GameHistory(QWidget *parent = nullptr);
    ~GameHistory();

private:
    Ui::GameHistory *ui;
    QVBoxLayout *layout;
    QMap<QPushButton*, int> buttonToGameIdMap; // Map to store buttons and their game IDs
    void fetchAndDisplayGameHistory(int userId);
    ReplayGameWindow * replaygamewindow;
    QString getUsernameById(int userId);
    QString getGameGridById(int gameId);
    int player2Id;
    int player1Id;




private slots:
    void onGameButtonClicked();
};

#endif // GAMEHISTORY_H
