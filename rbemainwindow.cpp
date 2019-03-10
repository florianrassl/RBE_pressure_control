#include "rbemainwindow.h"
#include "ui_rbemainwindow.h"

rbeMainWindow::rbeMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rbeMainWindow)
{
    ui->setupUi(this);
    viewSensors = new ViewSensors();
}

rbeMainWindow::~rbeMainWindow()
{
    delete ui;
}

void rbeMainWindow::on_buttonViewSensor_clicked()
{
    viewSensors->show();
}

void rbeMainWindow::on_buttonExit_clicked()
{
    QApplication::quit();
}
