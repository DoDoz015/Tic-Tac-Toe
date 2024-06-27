#include "replaygamewindow.h"
#include "ui_replaygamewindow.h"
#include "mainwindow.h"
#include "gamehistory.h"

ReplayGameWindow::ReplayGameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReplayGameWindow),
    currentStepIndex(-1)
{

    ui->setupUi(this);

    connect(ui->NextStep, &QPushButton::clicked, this, &ReplayGameWindow::on_NextStep_Clicked);
    connect(ui->PreviousStep, &QPushButton::clicked, this, &ReplayGameWindow::on_PreviousStep_Clicked);

    loadGameDetails();
    loadGameSteps();
    displayCurrentStep();
}

ReplayGameWindow::~ReplayGameWindow()
{
    delete ui;
}

void ReplayGameWindow::loadGameDetails()
{
    QSqlQuery query;
    query.prepare("SELECT Player1_ID, Player2_ID, Winner_ID FROM Game WHERE Game_ID = :Game_ID");
    query.bindValue(":Game_ID", gameId);

    if (!query.exec()) {
        qDebug() << "Failed to load game details:" << query.lastError();
        return;
    }

    if (query.next()) {
        player1Id = query.value(0).toInt();
        player2Id = query.value(1).toInt();
        winnerId = query.value(2).toInt();
        qDebug() << "Player 1 ID:" << player1Id;
        qDebug() << "Player 2 ID:" << player2Id;
        qDebug() << "Winner ID:" << winnerId;

        if (winnerId == player1Id) {
            ui->labelWinner->setText("Winner: Player 1 (X)");
        } else if (winnerId == player2Id) {
            ui->labelWinner->setText("Winner: Player 2 (O)");
        } else {
            ui->labelWinner->setText("Draw");
     }
   }
}

void ReplayGameWindow::loadGameSteps()
{
    QSqlQuery query;
    query.prepare("SELECT Step_Number, Row, Col, Player_ID FROM GameSteps WHERE Game_ID = :Game_ID ORDER BY Step_Number ASC");
    query.bindValue(":Game_ID", gameId);

    if (!query.exec()) {
        qDebug() << "Failed to load game steps:" << query.lastError();
        return;
    }

    while (query.next()) {
        GameStep step;
        step.stepNumber = query.value(0).toInt();
        step.row = query.value(1).toInt();
        step.col = query.value(2).toInt();
        step.playerId = query.value(3).toInt();
        gameSteps.append(step);
    }
}

void ReplayGameWindow::displayCurrentStep()
{

    if (currentStepIndex >= 0 && currentStepIndex < gameSteps.size()) {
        const GameStep &step = gameSteps[currentStepIndex];
        QString playerSymbol = (step.playerId == player1Id) ? "X" : "O";// here is the bug chat
        ui->gridLayout->itemAtPosition(step.row, step.col)->widget()->setProperty("text", playerSymbol);
    }
}
void ReplayGameWindow::removePrevStep()
{

    if (currentStepIndex >= 0 && currentStepIndex < gameSteps.size()) {
        const GameStep &step = gameSteps[currentStepIndex];

        ui->gridLayout->itemAtPosition(step.row, step.col)->widget()->setProperty("text", "");
    }
}



void ReplayGameWindow::on_NextStep_Clicked()
{
    if (currentStepIndex < gameSteps.size() - 1) {
        ++currentStepIndex;
        displayCurrentStep();
    }
}

void ReplayGameWindow::on_PreviousStep_Clicked()
{
    if (currentStepIndex >= 0) {
        removePrevStep();
        --currentStepIndex;
    }
}

void ReplayGameWindow::on_Home_clicked()
{
    hide();
    MainWindow * mainwindow = new MainWindow(this);
    mainwindow->show();
}


void ReplayGameWindow::on_Back_clicked()
{
    hide();
    GameHistory * gamehistory = new GameHistory(this);
    gamehistory->show();
}


