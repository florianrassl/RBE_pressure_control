#include "viewsensors.h"
#include "ui_viewsensors.h"

ViewSensors::ViewSensors(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewSensors)
{
    ui->setupUi(this);
}

ViewSensors::~ViewSensors()
{
    delete ui;
}
