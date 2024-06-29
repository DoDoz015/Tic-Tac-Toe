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
         player1Id = query.value(1).toInt();
         player2Id = query.value(2).toInt();
        int winnerId = query.value(3).toInt();

        QString player1Username = getUsernameById(player1Id);
        QString player2Username = getUsernameById(player2Id);
        QString winnerUsername = getUsernameById(winnerId);

        qDebug() << "Game ID:" << gameId << ", Player 1 Username:" << player1Username << ", Player 2 Username:" << player2Username << ", Winner Username:" << winnerUsername;

        QString gameGrid = getGameGridById(gameId);

        // Create a new button for each game
        QPushButton *gameButton = new QPushButton(QString("Game %1: %2 vs %3, Winner: %4\n%5")
                                                      .arg(++gameCount)
                                                      .arg(player1Username)
                                                      .arg(player2Username)
                                                      .arg(winnerUsername)
                                                      .arg(gameGrid));
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

QString GameHistory::getUsernameById(int Player_ID)
{
    QSqlQuery query;
    query.prepare("SELECT username FROM Player WHERE Player_ID = :Player_ID");
    query.bindValue(":Player_ID", Player_ID);

    if (!query.exec()) {
        qDebug() << "Error fetching username for user ID:" << Player_ID << " Error: " << query.lastError();
        return "Unknown";
    }

    if (query.next()) {
        return query.value(0).toString();
    }

    return "Draw";
}

QString GameHistory::getGameGridById(int gameId)
{
    QString grid[3][3] = {{"", "", ""}, {"", "", ""}, {"", "", ""}};

    QSqlQuery query;
    query.prepare("SELECT Row, Col, Player_ID FROM GameSteps WHERE Game_ID = :gameId ORDER BY Step_Number ASC");
    query.bindValue(":gameId", gameId);

    if (!query.exec()) {
        qDebug() << "Error fetching game steps for game ID:" << gameId << " Error: " << query.lastError();
        return "Error fetching game steps";
    }

    while (query.next()) {
        int row = query.value(0).toInt();
        int col = query.value(1).toInt();
        int playerId = query.value(2).toInt();

        QString playerSymbol = (playerId == player1Id) ? "X" : "O";  // Adjust according to your logic
        grid[row][col] = playerSymbol;
    }

    QString gameGrid;
    for (int i = 0; i < 3; ++i) {
        gameGrid += QString("%1 | %2 | %3\n")
                        .arg(grid[i][0].isEmpty() ? "  " : grid[i][0])
                        .arg(grid[i][1].isEmpty() ? "  " : grid[i][1])
                        .arg(grid[i][2].isEmpty() ? "  " : grid[i][2]);
    }

    return gameGrid;
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
