#include "thegame.h"
#include "ui_thegame.h"
#include <QMessageBox>
#include <QDebug>
#include "mainwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMetaType>

QStack<Move> moveStack;

TheGame::TheGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TheGame),
    currentPlayer("X"),
    stepNumber(0)  // Initialize step number
{
    ui->setupUi(this);
    End_Game = true;
    startNewGame();

    // Connect the clicked signal of all buttons to the same slot
    connect(ui->pushButton_1, &QPushButton::clicked, this, &TheGame::on_pushButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &TheGame::on_pushButton_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &TheGame::on_pushButton_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &TheGame::on_pushButton_clicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &TheGame::on_pushButton_clicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &TheGame::on_pushButton_clicked);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &TheGame::on_pushButton_clicked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &TheGame::on_pushButton_clicked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &TheGame::on_pushButton_clicked);
    //connect(ui->Reset, &QPushButton::clicked, this, &TheGame::on_Reset_clicked);
    //connect(ui->Undo, &QPushButton::clicked, this, &TheGame::on_Undo_clicked);
    //connect(ui->New_Game, &QPushButton::clicked, this, &TheGame::on_New_Game_clicked);

    grid[0][0] = ui->pushButton_1;
    grid[0][1] = ui->pushButton_2;
    grid[0][2] = ui->pushButton_3;
    grid[1][0] = ui->pushButton_4;
    grid[1][1] = ui->pushButton_5;
    grid[1][2] = ui->pushButton_6;
    grid[2][0] = ui->pushButton_7;
    grid[2][1] = ui->pushButton_8;
    grid[2][2] = ui->pushButton_9;
}

TheGame::~TheGame() {
    delete ui;
}

void TheGame::startNewGame() {
    // Insert a new game entry with Player1_ID and Player2_ID
    QSqlQuery query;
    query.prepare("INSERT INTO Game (Player1_ID, Player2_ID, Winner_ID) VALUES (:Player1_ID, :Player2_ID, :Winner_ID)");
    query.bindValue(":Player1_ID", loggedInUser1ID);
    query.bindValue(":Player2_ID", loggedInUser2ID);
    query.bindValue(":Winner_ID", QVariant(QMetaType(QMetaType::Int)));  // Placeholder for Winner_ID

    if (!query.exec()) {
        qDebug() << "Failed to insert new game:" << query.lastError();
    } else {
        lastInsertedGameID = query.lastInsertId().toInt();  // Save the last inserted game ID
        qDebug() << "Started new game with Game_ID:" << lastInsertedGameID;
    }
}

void TheGame::on_pushButton_clicked() {
    if (End_Game) {
        QPushButton *button = qobject_cast<QPushButton*>(sender());

        if (button->text().isEmpty()) {
            button->setText(currentPlayer);

            // Determine the row and column of the move
            int row = -1, col = -1;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (grid[i][j] == button) {
                        row = i;
                        col = j;
                        break;
                    }
                }
                if (row != -1) break;
            }

            if (row != -1 && col != -1) {
                // Push the move into the stack
                Move move;
                move.row = row;
                move.col = col;
                move.player = currentPlayer;
                moveStack.push(move);

                // Insert the move into the GameSteps table
                QSqlQuery query;
                query.prepare("INSERT INTO GameSteps (Game_ID, Step_Number, Row, Col, Player_ID) VALUES (:Game_ID, :Step_Number, :Row, :Col, :Player_ID)");
                query.bindValue(":Game_ID", lastInsertedGameID);
                query.bindValue(":Step_Number", ++stepNumber);  // Increment and bind step number
                query.bindValue(":Row", row);
                query.bindValue(":Col", col);
                query.bindValue(":Player_ID", (currentPlayer == "X") ? loggedInUser1ID : loggedInUser2ID);

                if (!query.exec()) {
                    qDebug() << "Failed to insert game step:" << query.lastError();
                } else {
                    qDebug() << "Inserted game step with Step_Number:" << stepNumber;
                }
            }

            switchPlayer();
            checkForWin();
        }
    }
}

void TheGame::checkForWin() {
    QString winner;
    int winnerID = 0;
    QString winnerUser;

    // Check rows
    for (int row = 0; row < 3; ++row) {
        if (!grid[row][0]->text().isEmpty() &&
            grid[row][0]->text() == grid[row][1]->text() &&
            grid[row][1]->text() == grid[row][2]->text()) {
            winner = grid[row][0]->text();
            break;
        }
    }

    // Check columns
    for (int col = 0; col < 3; ++col) {
        if (!grid[0][col]->text().isEmpty() &&
            grid[0][col]->text() == grid[1][col]->text() &&
            grid[1][col]->text() == grid[2][col]->text()) {
            winner = grid[0][col]->text();
            break;
        }
    }

    // Check diagonals
    if (!grid[0][0]->text().isEmpty() &&
        grid[0][0]->text() == grid[1][1]->text() &&
        grid[1][1]->text() == grid[2][2]->text()) {
        winner = grid[0][0]->text();
    } else if (!grid[0][2]->text().isEmpty() &&
               grid[0][2]->text() == grid[1][1]->text() &&
               grid[1][1]->text() == grid[2][0]->text()) {
        winner = grid[0][2]->text();
    }

    // If a winner is found, display a message
    if (!winner.isEmpty()) {
        End_Game = false;
        winnerUser = (winner == "X") ? loggedInUser1 : loggedInUser2;
        QMessageBox::information(this, "Winner!", winnerUser + " wins!");
        winnerID = (winner == "X") ? loggedInUser1ID : loggedInUser2ID;

        // Update the Winner_ID in the Game table
        QSqlQuery query;
        query.prepare("UPDATE Game SET Winner_ID = :Winner_ID WHERE Game_ID = :Game_ID");
        query.bindValue(":Winner_ID", winnerID);
        query.bindValue(":Game_ID", lastInsertedGameID);
        if (!query.exec()) {
            qDebug() << "Failed to update game result:" << query.lastError();
        } else {
            qDebug() << "Updated game result with Winner_ID:" << winnerID;
        }
    }
    // Check for draw
    else {
        bool isFull = true;

        // Check if any button in the grid is empty
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                QPushButton *button = grid[row][col];
                if (button->text().isEmpty()) {
                    isFull = false;
                    break;  // No need to continue checking if one button is empty
                }
            }
            if (!isFull) {
                break;  // No need to continue checking if one button is empty
            }
        }

        // Show message if the board is full (draw)
        if (isFull) {
            End_Game = false;
            QMessageBox::information(this, "Game Over", "It's a draw!");
            // You can perform any additional actions here, such as resetting the board or ending the game
            winnerID = 0;

            // Update the Winner_ID in the Game table to indicate a draw
            QSqlQuery query;
            query.prepare("UPDATE Game SET Winner_ID = :Winner_ID WHERE Game_ID = :Game_ID");
            query.bindValue(":Winner_ID", winnerID);
            query.bindValue(":Game_ID", lastInsertedGameID);
            if (!query.exec()) {
                qDebug() << "Failed to update game result:" << query.lastError();
            } else {
                qDebug() << "Updated game result to indicate draw with Game_ID:" << lastInsertedGameID;
            }
        }
    }
}

void TheGame::switchPlayer() {
    currentPlayer = (currentPlayer == "X") ? "O" : "X";
}

void TheGame::on_Reset_clicked() {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            grid[row][col]->setText("");
        }
    }
    if (!End_Game)
    {
        startNewGame();
    }
    else
    {
        QSqlQuery query;
        query.prepare("DELETE FROM GameSteps WHERE Game_ID = :Game_ID");
        query.bindValue(":Game_ID", lastInsertedGameID);

        if (!query.exec()) {
            qDebug() << "Failed to delete game steps:" << query.lastError();
        } else {
            qDebug() << "Deleted game steps for Game_ID:" << lastInsertedGameID;
        }
    }
    currentPlayer = "X";
    End_Game = true;
    stepNumber = 0;  // Reset step number
}

void TheGame::on_New_Game_clicked() {
    loggedInUser = NULL;
    if(End_Game){
    QSqlQuery query;
    query.prepare("DELETE FROM GameSteps WHERE Game_ID = :Game_ID");
    query.bindValue(":Game_ID", lastInsertedGameID);

    if (!query.exec()) {
        qDebug() << "Failed to delete game steps:" << query.lastError();
    } else {
        qDebug() << "Deleted game steps for Game_ID:" << lastInsertedGameID;
    }
    QSqlQuery queryGame;
    queryGame.prepare("DELETE FROM Game WHERE Game_ID = :Game_ID");
    queryGame.bindValue(":Game_ID", lastInsertedGameID);

    if (!queryGame.exec()) {
        qDebug() << "Failed to delete game record:" << queryGame.lastError();
    } else {
        qDebug() << "Deleted game record for Game_ID:" << lastInsertedGameID;
    }
    }
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

void TheGame::on_Undo_clicked() {
    if (moveStack.isEmpty()) {
        QMessageBox::information(this, "Undo", "No moves to undo!");
        return;
    }

    // Pop the last move
    Move lastMove = moveStack.pop();

    // Update the game board
    grid[lastMove.row][lastMove.col]->setText("");

    // Switch back to the player who made the undone move
    switchPlayer();

    // If the game was previously ended, allow it to continue
    if (!End_Game) {
        End_Game = true;
    }

    // Debug statement to check lastInsertedGameID
    qDebug() << "Attempting to delete game step with Game_ID:" << lastInsertedGameID << " and Step_Number:" << stepNumber;

    // Delete the last inserted game step from the database
    QSqlQuery query;
    query.prepare("DELETE FROM GameSteps WHERE Game_ID = :Game_ID AND Step_Number = :Step_Number");
    query.bindValue(":Game_ID", lastInsertedGameID);
    query.bindValue(":Step_Number", stepNumber--);  // Decrement step number after binding

    if (!query.exec()) {
        qDebug() << "Failed to delete game step:" << query.lastError();
    } else {
        qDebug() << "Successfully deleted game step with Step_Number:" << stepNumber + 1;
    }
}
