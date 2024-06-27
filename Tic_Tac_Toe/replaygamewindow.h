#ifndef REPLAYGAMEWINDOW_H
#define REPLAYGAMEWINDOW_H

#include <QDialog>
#include <QVector>
#include <QPushButton>
#include <QLabel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
//#include "mainwindow.h"


namespace Ui {
class ReplayGameWindow;
}

struct GameStep {
    int stepNumber;
    int row;
    int col;
    int playerId;
};

class ReplayGameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ReplayGameWindow(QWidget *parent = nullptr);
    ~ReplayGameWindow();

private slots:
    void on_NextStep_Clicked();
    void on_PreviousStep_Clicked();

    void on_Home_clicked();

    void on_Back_clicked();

private:
    void loadGameDetails();
    void loadGameSteps();
    void displayCurrentStep();
    void removePrevStep();

    Ui::ReplayGameWindow *ui;
    QVector<GameStep> gameSteps;
    int player1Id;
    int currentStepIndex;
    int winnerId;
    int player2Id;

};

#endif // REPLAYGAMEWINDOW_H
