#include "gamehistory.h"
#include "ui_gamehistory.h"
#include "mainwindow.h"
#include <QLabel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


GameHistory::GameHistory(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GameHistory)
{
    ui->setupUi(this);
    layout = new QVBoxLayout(this);
    fetchAndDisplayGameHistory(userId);
}

GameHistory::~GameHistory()
{
    delete ui;
}

void GameHistory::fetchAndDisplayGameHistory(int userId)
{
    qDebug() << "Fetching game history for user ID:" << userId;

    // Prepare the SQL query
    QSqlQuery query;
    query.prepare("SELECT Game_ID, Player1_ID, Player2_ID, Winner_ID FROM Game WHERE Player1_ID = :userId OR Player2_ID = :userId");
    query.bindValue(":userId", userId);

    // Execute the query and check for errors
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError();
        return;
    }

    int gameCount = 0;
    while (query.next()) {
        gameId = query.value(0).toInt();
        int player1Id = query.value(1).toInt();
        int player2Id = query.value(2).toInt();
        int winnerId = query.value(3).toInt();

        qDebug() << "Game ID:" << gameId << ", Player 1 ID:" << player1Id << ", Player 2 ID:" << player2Id << ", Winner ID:" << winnerId;

        // Create a new button for each game
        QPushButton *gameButton = new QPushButton(QString("Game %1").arg(++gameCount));
        layout->addWidget(gameButton);
        buttonToGameIdMap[gameButton] = gameId;

        // Connect the button to open the ReplayGameWindow
        connect(gameButton, &QPushButton::clicked, this, &GameHistory::onGameButtonClicked);
    }

    // If no games found, display a message
    if (gameCount == 0) {
        QLabel *noGamesLabel = new QLabel("No games found.");
        layout->addWidget(noGamesLabel);
    }
}

void GameHistory::onGameButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button && buttonToGameIdMap.contains(button)) {
        gameId = buttonToGameIdMap[button];
        hide();
        replaygamewindow = new ReplayGameWindow(this);
        replaygamewindow->show();
    }
}
