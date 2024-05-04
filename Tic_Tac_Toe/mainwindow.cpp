#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     MyDB = QSqlDatabase::addDatabase("QSQLITE");
    MyDB.setDatabaseName("A:/Project NAASR/sqlite/tictactoe.db");
    if(!MyDB.open()){
        ui->label->setText("failed db");
    }
    else  {
        ui->label->setText("connected db");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login Error", "Please enter both username and password.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM User WHERE username = :username AND password_hash = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    if (query.next()) {
        qDebug() << "Login successful!";
        QMessageBox::information(this, "Login Success", "Logged in successfully.");
        hide();
        startGame = new StartGame(this);
        startGame -> show();


        // Perform actions after successful login, such as opening a new window or updating UI
    } else {
        qDebug() << "Login failed. Invalid username or password.";
        QMessageBox::warning(this, "Login Error", "Invalid username or password.");
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
    checkQuery.prepare("SELECT * FROM User WHERE username = :username");
    checkQuery.bindValue(":username", username);

    if (!checkQuery.exec()) {
        qDebug() << "Error checking username existence:" << checkQuery.lastError().text();
        return;
    }

    if (checkQuery.next()) {
        qDebug() << "Username already exists.";
        QMessageBox::warning(this, "Sign Up Error", "Username already exists.");
        return;
    }

    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO User (username, password_hash, created_at) VALUES (:username, :password_hash, :created_at)");
    insertQuery.bindValue(":username", username);
    insertQuery.bindValue(":password_hash", password);
    insertQuery.bindValue(":created_at", currentTime);

    if (!insertQuery.exec()) {
        qDebug() << "Error inserting data into database:" << insertQuery.lastError().text();
        return;
    }

    qDebug() << "Sign up successful!";
    QMessageBox::information(this, "Sign Up Success", "Account created successfully.");

}

