#include "rbemainwindow.h"
#include "ui_rbemainwindow.h"
#include "viewsensors.h"

rbeMainWindow::rbeMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rbeMainWindow)
{
    ui->setupUi(this);
}

rbeMainWindow::~rbeMainWindow()
{
    delete ui;
}

void rbeMainWindow::on_buttonViewSensor_clicked()
{
    ViewSensors*viewSensors = new ViewSensors();
    viewSensors->show();
}

void rbeMainWindow::on_buttonExit_clicked()
{
    QApplication::quit();
}
