#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set up SQLite database
    MyDB = QSqlDatabase::addDatabase("QSQLITE");
    MyDB.setDatabaseName("C:/mokhtar/github/tic-tac-toe/tictactoe.db");
    if(!MyDB.open()){
        ui->label->setText("failed db");
    } else {
        ui->label->setText("connected db");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Login_clicked()
{
    static bool firstTime = true;
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    // Check if username or password is empty
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login Error", "Please enter both username and password.");
        return;
    }

    // Prepare and execute SQL query to check login credentials
    QSqlQuery query;
    query.prepare("SELECT * FROM Player WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    // If login is successful, open the game window
    if (query.next()) {
        qDebug() << "Login successful!";
        QMessageBox::information(this, "Login Success", "Logged in successfully.");

        if (firstTime){
            hide();
            startGame = new StartGame(this);
            startGame->show();
            firstTime = false;
        } else {
            hide();
            theGame = new TheGame(this);
            theGame->show();
            firstTime = true;
        }

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

    // Check if username or password is empty
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Sign Up Error", "Please enter both username and password.");
        return;
    }

    // Check if username already exists
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM Player WHERE username = :username");
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

    // Insert new user into database
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO Player (username, password, created_at) VALUES (:username, :password, :created_at)");
    insertQuery.bindValue(":username", username);
    insertQuery.bindValue(":password", password);
    insertQuery.bindValue(":created_at", currentTime);

    if (!insertQuery.exec()) {
        qDebug() << "Error inserting data into database:" << insertQuery.lastError().text();
        return;
    }

    qDebug() << "Sign up successful!";
    QMessageBox::information(this, "Sign Up Success", "Account created successfully.");
}
