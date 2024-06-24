#include "gamehistorylogin.h"
#include "ui_gamehistorylogin.h"
#include "mainwindow.h"


GameHistoryLogin::GameHistoryLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GameHistoryLogin)
{
    ui->setupUi(this);
}

GameHistoryLogin::~GameHistoryLogin()
{
    delete ui;
}

QString GameHistoryLogin::hashPassword(const QString &password) {
    QByteArray passwordData = password.toUtf8();
    QByteArray hashed = QCryptographicHash::hash(passwordData, QCryptographicHash::Sha256).toHex();
    return QString(hashed);

}

bool GameHistoryLogin::checkPassword(const QString &inputPassword, const QString &hashedPassword) {
    QString inputHashed = hashPassword(inputPassword);
    return inputHashed == hashedPassword;
}



void GameHistoryLogin::on_Verify_clicked()

{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login Error", "Please enter both username and password.");
        return;
    }

    // Authenticate user
    QSqlQuery query;
    query.prepare("SELECT Player_ID, password FROM Player WHERE Username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next()) {
        QString storedPasswordHash = query.value("password").toString();
        if (checkPassword(password, storedPasswordHash)) {
            userId = query.value(0).toInt();
            this->accept();

            // Open game history window
            hide();
            gamehistory = new GameHistory(this);
            gamehistory->show();
        } else {
            QMessageBox::warning(this, "Authentication Failed", "Invalid username or password.");
        }
    } else {
        QMessageBox::warning(this, "Authentication Failed", "User not found.");
    }


}

