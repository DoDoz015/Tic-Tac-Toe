#include "replaygamewindow.h"
#include "ui_replaygamewindow.h"

ReplayGameWindow::ReplayGameWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ReplayGameWindow)
{
    ui->setupUi(this);
}

ReplayGameWindow::~ReplayGameWindow()
{
    delete ui;
}
