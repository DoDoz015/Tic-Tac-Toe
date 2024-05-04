#include "thegame.h"
#include "ui_thegame.h"
#include <QMessageBox>
#include <QDebug>
using namespace std;



TheGame::TheGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TheGame),
 currentPlayer("X")
{
    ui->setupUi(this);


    // Connect the clicked signal of all buttons to the same slot
    connect(ui->pushButton,   &QPushButton::clicked, this,   &TheGame::on_pushButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &TheGame::on_pushButton_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &TheGame::on_pushButton_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &TheGame::on_pushButton_clicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &TheGame::on_pushButton_clicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &TheGame::on_pushButton_clicked);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &TheGame::on_pushButton_clicked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &TheGame::on_pushButton_clicked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &TheGame::on_pushButton_clicked);

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

TheGame::~TheGame()
{
    delete ui;
}


void TheGame::on_pushButton_clicked()
{
    // Get the sender button
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    if (button->text().isEmpty()) {
        button->setText(currentPlayer);
         switchPlayer();
    }
    checkForWin();




}
void TheGame::checkForWin()
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
        QMessageBox::information(this, "Winner!", winner + " wins!");
    }

}

void TheGame::switchPlayer()
{
    currentPlayer = (currentPlayer == "X") ? "O" : "X";
}

// function to return the user wants X or O
