#ifndef REPLAYGAMEWINDOW_H
#define REPLAYGAMEWINDOW_H

#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class ReplayGameWindow;
}

class ReplayGameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ReplayGameWindow(QWidget *parent = nullptr);
    ~ReplayGameWindow();

private:
    Ui::ReplayGameWindow *ui;
};

#endif // REPLAYGAMEWINDOW_H
