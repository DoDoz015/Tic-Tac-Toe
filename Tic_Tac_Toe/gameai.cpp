#include "gameai.h"
#include "ui_gameai.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMetaType>
#include <limits>

bool onetime = true;
QStack<MoveAI> moveStackAI;

GameAi::GameAi(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::GameAi),
    HumanPlayer("X"),
    AIPlayer("O"),
    stepNumber(0)
{
       // Initialize step number
    ui->setupUi(this);
    End_Game_AI = true;
    startNewGame();

    // Connect the clicked signal of all buttons to the same slot
    connect(ui->pushButton_1, &QPushButton::clicked, this, &GameAi::on_pushButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &GameAi::on_pushButton_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &GameAi::on_pushButton_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &GameAi::on_pushButton_clicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &GameAi::on_pushButton_clicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &GameAi::on_pushButton_clicked);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &GameAi::on_pushButton_clicked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &GameAi::on_pushButton_clicked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &GameAi::on_pushButton_clicked);
    // connect(ui->Reset, &QPushButton::clicked, this, &GameAi::on_Reset_clicked);
    // connect(ui->Undo, &QPushButton::clicked, this, &GameAi::on_Undo_clicked);

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

GameAi::~GameAi()
{
    delete ui;
}

void GameAi::startNewGame() {
    // Insert a new game entry with Player1_ID and Player2_ID
    QSqlQuery query;
    query.prepare("INSERT INTO Game (Player1_ID, Player2_ID, Winner_ID) VALUES (:Player1_ID, :Player2_ID, :Winner_ID)");
    query.bindValue(":Player1_ID", loggedInUser1ID);
    query.bindValue(":Player2_ID", AI_id);
    query.bindValue(":Winner_ID", QVariant(QMetaType(QMetaType::Int)));  // Placeholder for Winner_ID

    if (!query.exec()) {
        qDebug() << "Failed to insert new game:" << query.lastError();
    } else {
        lastInsertedGameID = query.lastInsertId().toInt();  // Save the last inserted game ID
        qDebug() << "Started new game with Game_ID:" << lastInsertedGameID;
    }
}

void GameAi::on_pushButton_clicked() {
    if (End_Game_AI) {
        QPushButton *button = qobject_cast<QPushButton*>(sender());

        if (button->text().isEmpty()) {
            button->setText(HumanPlayer);

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
                MoveAI move;
                move.row = row;
                move.col = col;
                move.player = HumanPlayer;
                moveStackAI.push(move);

                // Insert the move into the GameSteps table
                QSqlQuery query;
                query.prepare("INSERT INTO GameSteps (Game_ID, Step_Number, Row, Col, Player_ID) VALUES (:Game_ID, :Step_Number, :Row, :Col, :Player_ID)");
                query.bindValue(":Game_ID", lastInsertedGameID);
                query.bindValue(":Step_Number", ++stepNumber);  // Increment and bind step number
                query.bindValue(":Row", row);
                query.bindValue(":Col", col);
                query.bindValue(":Player_ID", loggedInUser1ID);

                if (!query.exec()) {
                    qDebug() << "Failed to insert game step:" << query.lastError();
                } else {
                    qDebug() << "Inserted game step with Step_Number:" << stepNumber;
                }
            }

            checkForWin();
            if (End_Game_AI) {
                AIMove();
                checkForWin();
            }
        }
    }
}

void GameAi::AIMove() {
    int bestScore = std::numeric_limits<int>::min();
    int bestRow = -1;
    int bestCol = -1;

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (grid[row][col]->text().isEmpty()) {
                grid[row][col]->setText(AIPlayer);
                int score = minimax(false, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
                grid[row][col]->setText("");
                if (score > bestScore) {
                    bestScore = score;
                    bestRow = row;
                    bestCol = col;
                }
            }
        }
    }

    if (bestRow != -1 && bestCol != -1) {
        grid[bestRow][bestCol]->setText(AIPlayer);

        // Push the AI move into the stack
        MoveAI move;
        move.row = bestRow;
        move.col = bestCol;
        move.player = AIPlayer;
        moveStackAI.push(move);

        // Insert the AI move into the GameSteps table
        QSqlQuery query;
        query.prepare("INSERT INTO GameSteps (Game_ID, Step_Number, Row, Col, Player_ID) VALUES (:Game_ID, :Step_Number, :Row, :Col, :Player_ID)");
        query.bindValue(":Game_ID", lastInsertedGameID);
        query.bindValue(":Step_Number", ++stepNumber);  // Increment and bind step number
        query.bindValue(":Row", bestRow);
        query.bindValue(":Col", bestCol);
        query.bindValue(":Player_ID", AI_id);

        if (!query.exec()) {
            qDebug() << "Failed to insert game step:" << query.lastError();
        } else {
            qDebug() << "Inserted game step with Step_Number:" << stepNumber;
        }
    }
}

int GameAi::minimax(bool isMaximizing, int alpha, int beta) {
    QString winner = checkWinner();

    if (winner == AIPlayer) {
        return 1;
    } else if (winner == HumanPlayer) {
        return -1;
    } else {
        bool isFull = true;
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (grid[row][col]->text().isEmpty()) {
                    isFull = false;
                    break;
                }
            }
            if (!isFull) break;
        }
        if (isFull) {
            return 0;
        }
    }

    if (isMaximizing) {
        int bestScore = std::numeric_limits<int>::min();
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (grid[row][col]->text().isEmpty()) {
                    grid[row][col]->setText(AIPlayer);
                    int score = minimax(false, alpha, beta);
                    grid[row][col]->setText("");
                    bestScore = std::max(score, bestScore);
                    alpha = std::max(alpha, score);
                    if (beta <= alpha) break;
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = std::numeric_limits<int>::max();
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (grid[row][col]->text().isEmpty()) {
                    grid[row][col]->setText(HumanPlayer);
                    int score = minimax(true, alpha, beta);
                    grid[row][col]->setText("");
                    bestScore = std::min(score, bestScore);
                    beta = std::min(beta, score);
                    if (beta <= alpha) break;
                }
            }
        }
        return bestScore;
    }
}

void GameAi::checkForWin() {
    QString winner = checkWinner();
    if (!winner.isEmpty()) {
        End_Game_AI = false;
        QMessageBox::information(this, "Game Over", winner + " wins!");

        // Update the Winner_ID in the Game table
        QSqlQuery query;
        query.prepare("UPDATE Game SET Winner_ID = :Winner_ID WHERE Game_ID = :Game_ID");
        query.bindValue(":Winner_ID", winner == HumanPlayer ? loggedInUser1ID : AI_id);
        query.bindValue(":Game_ID", lastInsertedGameID);

        if (!query.exec()) {
            qDebug() << "Failed to update winner:" << query.lastError();
        } else {
            qDebug() << "Updated winner for Game_ID:" << lastInsertedGameID;
        }
    } else {
        bool isFull = true;
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (grid[row][col]->text().isEmpty()) {
                    isFull = false;
                    break;
                }
            }
            if (!isFull) break;
        }
        if (isFull) {
            End_Game_AI = false;
            QMessageBox::information(this, "Game Over", "It's a draw!");


            // Update the Winner_ID to indicate a tie (null value)
            QSqlQuery query;
            query.prepare("UPDATE Game SET Winner_ID = NULL WHERE Game_ID = :Game_ID");
            query.bindValue(":Game_ID", lastInsertedGameID);

            if (!query.exec()) {
                qDebug() << "Failed to update game result for draw:" << query.lastError();
            } else {
                qDebug() << "Updated game result for draw for Game_ID:" << lastInsertedGameID;
            }
        }
    }
}

QString GameAi::checkWinner() {
    QString winner;

    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (grid[i][0]->text() == grid[i][1]->text() && grid[i][1]->text() == grid[i][2]->text() && !grid[i][0]->text().isEmpty()) {
            winner = grid[i][0]->text();
            break;
        }
        if (grid[0][i]->text() == grid[1][i]->text() && grid[1][i]->text() == grid[2][i]->text() && !grid[0][i]->text().isEmpty()) {
            winner = grid[0][i]->text();
            break;
        }
    }

    // Check diagonals
    if (grid[0][0]->text() == grid[1][1]->text() && grid[1][1]->text() == grid[2][2]->text() && !grid[0][0]->text().isEmpty()) {
        winner = grid[0][0]->text();
    }
    if (grid[0][2]->text() == grid[1][1]->text() && grid[1][1]->text() == grid[2][0]->text() && !grid[0][2]->text().isEmpty()) {
        winner = grid[0][2]->text();
    }

    return winner;
}


void GameAi::on_Reset_clicked()
{
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            grid[row][col]->setText("");
        }

    }
    onetime = true;
    End_Game_AI = true;
    moveStackAI.clear();


}


void GameAi::on_New_Game_clicked()
{
    loggedInUser = NULL;
    firsttimeai = false;
    End_Game_AI = true;
    moveStackAI.clear();
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow -> show();

}


void GameAi::on_Undo_clicked() {


    // Check if all grids are full
    bool allFull = true;
    // Check if all grids are empty
    bool allEmpty = true;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (grid[row][col]->text().isEmpty()) {
                allFull = false;
            }
            if (!grid[row][col]->text().isEmpty()) {
                allEmpty = false;
            }
        }
    }

    if (!allEmpty) {
        if (!moveStackAI.isEmpty()) {
            if (allFull) {
                // Pop and undo the last AI move
                if (!moveStackAI.isEmpty()) {
                    MoveAI lastMove = moveStackAI.pop();
                    grid[lastMove.row][lastMove.col]->setText("");
                    deleteMoveFromDatabase();

                    if (!End_Game_AI) {
                        // Debug statement to check lastInsertedGameID
                        qDebug() << "Attempting to delete game record with Game_ID:" << lastInsertedGameID;

                        // Delete the last inserted game record from the database
                        QSqlQuery query;
                        query.prepare("DELETE FROM Game WHERE Game_ID = :Game_ID");
                        query.bindValue(":Game_ID", lastInsertedGameID);

                        if (!query.exec()) {
                            qDebug() << "Failed to delete game record:" << query.lastError();
                        } else {
                            qDebug() << "Successfully deleted game record with Game_ID:" << lastInsertedGameID;
                            lastInsertedGameID = -1;  // Reset the last inserted game ID
                        }
                    }
                }
            } else {
                // Pop and undo the last two moves (AI and Human)
                if (!moveStackAI.isEmpty()) {
                    MoveAI lastMove = moveStackAI.pop();
                    grid[lastMove.row][lastMove.col]->setText("");
                    deleteMoveFromDatabase();

                    if (!moveStackAI.isEmpty()) {
                        lastMove = moveStackAI.pop();
                        grid[lastMove.row][lastMove.col]->setText("");
                        deleteMoveFromDatabase();
                    }
                }
            }
        }
    } else {
        QMessageBox::information(this, "Undo", "No moves to undo!");
        return;
    }

    if (End_Game_AI == false) {
        End_Game_AI = true;
        if (onetime == false) {
            onetime = true;
            if (allEmpty) {
                QMessageBox::information(this, "Undo", "No moves to undo!");
                return;
            }
        }
    }
}
void GameAi::deleteMoveFromDatabase() {
    // Delete the move from the GameSteps table
    QSqlQuery query;
    query.prepare("DELETE FROM GameSteps WHERE Game_ID = :Game_ID AND Step_Number = :Step_Number");
    query.bindValue(":Game_ID", lastInsertedGameID);
    query.bindValue(":Step_Number",stepNumber);
    (stepNumber)--;    // Decrement and bind step number

    if (!query.exec()) {
        qDebug() << "Failed to delete game step:" << query.lastError();
    } else {
        qDebug() << "Deleted game step with Step_Number:" << stepNumber + 1;
    }
}
