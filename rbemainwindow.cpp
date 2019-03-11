#include <vector>

#include "sensor.h"
#include "rbemainwindow.h"
#include "ui_rbemainwindow.h"

rbeMainWindow::rbeMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rbeMainWindow)
{
    ui->setupUi(this);

    editProfile = new EditProfile();
    viewSensors = new ViewSensors();
    c = new Controller();

    qRegisterMetaType<std::vector<Sensor>>("std::vector<Sensor>");
    QObject::connect(c, &Controller::newDataAvailable,
                     viewSensors, &ViewSensors::updateUI, Qt::QueuedConnection);
}

rbeMainWindow::~rbeMainWindow()
{
    delete ui;
}

void rbeMainWindow::on_buttonViewSensor_clicked()
{
    viewSensors->show();
}

void rbeMainWindow::on_buttonEdit_clicked()
{
    editProfile->show();
}

void rbeMainWindow::on_buttonExit_clicked()
{
    QApplication::quit();
}
