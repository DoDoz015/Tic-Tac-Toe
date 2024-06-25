#ifndef GAMEHISTORYLOGIN_H
#define GAMEHISTORYLOGIN_H
#include"gamehistory.h"
#include <QDialog>
#include <QWidget>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>



namespace Ui {
class GameHistoryLogin;
}

class GameHistoryLogin : public QDialog
{
    Q_OBJECT

public:
    explicit GameHistoryLogin(QWidget *parent = nullptr);
    ~GameHistoryLogin();

private slots:
    void on_Verify_clicked();

private:
    Ui::GameHistoryLogin *ui;
    GameHistory * gamehistory;
    QString hashPassword(const QString &password) ;
    bool checkPassword(const QString &inputPassword, const QString &hashedPassword) ;



};

#endif // GAMEHISTORYLOGIN_H
