#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QCryptographicHash>

using namespace std;
bool firsttimeai = true;
bool firsttime = true;
int loggedInUser1ID = 0;
int loggedInUser2ID = 0;
QString loggedInUser1 ;
QString loggedInUser2 ;
QString loggedInUser;  // Username of the logged-in user
int userId;
int gameId;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyDB = QSqlDatabase::addDatabase("QSQLITE");
    // replace with database path from your PC
    MyDB.setDatabaseName("A:/Project NAASR/DoDz/tic-tac-toe/Tic_Tac_Toe/tictactoe.db");
    MyDB.open();

}


MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::hashPassword(const QString &password) {
    QByteArray passwordData = password.toUtf8();
    QByteArray hashed = QCryptographicHash::hash(passwordData, QCryptographicHash::Sha256).toHex();
    return QString(hashed);
}

bool MainWindow::checkPassword(const QString &inputPassword, const QString &hashedPassword) {
    QString inputHashed = hashPassword(inputPassword);
    return inputHashed == hashedPassword;
}



void MainWindow::on_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login Error", "Please enter both username and password.");
        return;
    }

    // Check if a user is already logged in
    if(manage){
    if (username==loggedInUser) {
        QMessageBox::warning(this, "Login Error", "This user is already logged in");
        return;
    }}


    QSqlQuery query;
    query.prepare("SELECT * FROM Player WHERE username = :username");
    query.bindValue(":username", username);


    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    if (query.next()) {
        QString storedPasswordHash = query.value("password").toString();
        if (checkPassword(password, storedPasswordHash)){
            if (firsttime){

            loggedInUser1ID = query.value(0).toInt();
                loggedInUser1 = username;

            } else{

                loggedInUser2ID = query.value(0).toInt();
                loggedInUser2 = username;

            }


        qDebug() << "Login successful!";
        QMessageBox::information(this, "Login Success", "Logged in successfully.");

        // Set the username of the logged-in user
        loggedInUser = username;

        // Check if a user is already logged in
        if(!loggedInUser.isEmpty()){
            if (manage) {
                if (firsttime) {
                    hide();
                    startGame = new StartGame(this);
                    startGame->show();
                    firsttime = false;
                } else {
                    hide();
                    theGame = new TheGame(this);
                    theGame->show();
                    firsttime = true;
                }
            } else {
                if (firsttimeai) {
                    hide();
                    gameai = new GameAi(this);
                    gameai->show();
                } else {
                    hide();
                    startGame = new StartGame(this);
                    startGame->show();
                }
            }
        }
    } else {
            qDebug() << "Login failed. Invalid password.";
            QMessageBox::warning(this, "Login Error", "Invalid password.");
        }

 }
    // Your existing code to show the appropriate game window based on conditions
    else {
        qDebug() << "Login failed. User not found.";
        QMessageBox::warning(this, "Login Error", "User not found.");
    }


    }



void MainWindow::on_Save_clicked()
{
    QString username = ui->lineEdit_username_2->text();
    QString password = ui->lineEdit_password_2->text();
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Sign Up Error", "Please enter both username and password.");
         return;
    }

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM Player WHERE username = :username");
    checkQuery.bindValue(":username", username);

    if (!checkQuery.exec()) {
        qDebug() << "Error checking username existence:" << checkQuery.lastError().text();
        ui->lineEdit_username_2->clear();
        ui->lineEdit_password_2->clear();
        return;
    }

    if (checkQuery.next()) {
        qDebug() << "Username already exists.";
        QMessageBox::warning(this, "Sign Up Error", "Username already exists.");
        ui->lineEdit_username_2->clear();
        ui->lineEdit_password_2->clear();
        return;
    }
    QString hashedPassword = hashPassword(password);

    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO Player (username, password, created_at) VALUES (:username, :password, :created_at)");
    insertQuery.bindValue(":username", username);
    insertQuery.bindValue(":password", hashedPassword);
    insertQuery.bindValue(":created_at", currentTime);


    if (!insertQuery.exec()) {
        qDebug() << "Error inserting data into database:" << insertQuery.lastError().text();
        return;
    }

    qDebug() << "Sign up successful!";
    QMessageBox::information(this, "Sign Up Success", "Account created successfully.");
    ui->lineEdit_username_2->clear();
    ui->lineEdit_password_2->clear();


}


void MainWindow::on_Game_History_clicked()
{
    // create class urgamedetails
    // it will be in every class and contains login
    // it shows all the games and if any game pressed show details
    //search with chat what to use instead of push buttons do the above one
    hide();
    gamehistorylogin = new GameHistoryLogin(this);
    gamehistorylogin->show();
}

