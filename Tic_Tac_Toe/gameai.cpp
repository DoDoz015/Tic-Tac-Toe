#include "gameai.h"
#include "ui_gameai.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QDebug>
bool onetime = true;
GameAi::GameAi(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GameAi),
    HumanPlayer("X"),
    AIPlayer("O")
{
    ui->setupUi(this);
    End_Game_AI = true;
    // Connect the clicked signal of all buttons to the same slot
    connect(ui->pushButton,   &QPushButton::clicked, this,   &GameAi::on_pushButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &GameAi::on_pushButton_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &GameAi::on_pushButton_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &GameAi::on_pushButton_clicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &GameAi::on_pushButton_clicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &GameAi::on_pushButton_clicked);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &GameAi::on_pushButton_clicked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &GameAi::on_pushButton_clicked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &GameAi::on_pushButton_clicked);
    connect(ui->Reset, &QPushButton::clicked, this, &GameAi::on_Reset_clicked);

    grid[0][0] = ui->pushButton;
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

void GameAi::on_pushButton_clicked()
{

    if (End_Game_AI) {
        QPushButton *button = qobject_cast<QPushButton*>(sender());

        if (button->text().isEmpty()) {
            button->setText(HumanPlayer);
            checkForWin();
            if (End_Game_AI) {
                AIMove();
                checkForWin();
            }
        }
    }
}
void GameAi::AIMove()
{
    int bestScore = std::numeric_limits<int>::min();
    int bestRow = -1;
    int bestCol = -1;

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (grid[row][col]->text().isEmpty()) {
                grid[row][col]->setText("O");
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
        grid[bestRow][bestCol]->setText("O");
    }
}



int GameAi::minimax(bool isMaximizing, int alpha, int beta)
{
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
            if (!isFull) {
                break;
            }
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
                    if (beta <= alpha) {
                        break;
                    }
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
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return bestScore;
    }
}




void GameAi::checkForWin()
{
    QString winner;

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
        End_Game_AI = false;
        QMessageBox::information(this, "Winner!", winner + " wins!");
    }
    // Check For Draaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaw!
    else{
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
        if(onetime){
            if (isFull) { onetime = false;
            QMessageBox::information(this, "Draw", "It's a draw! The game is over.");

            // You can perform any additional actions here, such as resetting the board or ending the game
            }


        }

    }

}

QString GameAi::checkWinner()
{
    // Check rows
    for (int row = 0; row < 3; ++row) {
        if (!grid[row][0]->text().isEmpty() &&
            grid[row][0]->text() == grid[row][1]->text() &&
            grid[row][1]->text() == grid[row][2]->text()) {
            return grid[row][0]->text();
        }
    }

    // Check columns
    for (int col = 0; col < 3; ++col) {
        if (!grid[0][col]->text().isEmpty() &&
            grid[0][col]->text() == grid[1][col]->text() &&
            grid[1][col]->text() == grid[2][col]->text()) {
            return grid[0][col]->text();
        }
    }

    // Check diagonals
    if (!grid[0][0]->text().isEmpty() &&
        grid[0][0]->text() == grid[1][1]->text() &&
        grid[1][1]->text() == grid[2][2]->text()) {
        return grid[0][0]->text();
    }
    if (!grid[0][2]->text().isEmpty() &&
        grid[0][2]->text() == grid[1][1]->text() &&
        grid[1][1]->text() == grid[2][0]->text()) {
        return grid[0][2]->text();
    }

    return "";
}


void GameAi::on_Reset_clicked()
{
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            grid[row][col]->setText("");
        }

    }

    End_Game_AI = true;
      onetime = true;

}


void GameAi::on_New_Game_clicked()
{
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow -> show();
      onetime = true;
    End_Game_AI = true;
}

