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

void ViewSensors::updateUI(std::vector<Sensor> sVector){
    //s0
    ui->progressBarSystem->setValue(sVector[0].getSPercent());
    ui->systemPressure->setText(sVector[0].getSText());
    if(sVector[0].getSPercent() >= 100){
        ui->systemPressure->setStyleSheet("color: red;");
    }
    else{
         ui->systemPressure->setStyleSheet("color: white;");
    }

    //s1
    ui->progressBarS1->setValue(sVector[1].getSPercent());
    ui->sensor1->setText(sVector[1].getSText());
    if(sVector[1].getSPercent() >= 100){
        ui->sensor1->setStyleSheet("color: red;");
    }
    else{
         ui->sensor1->setStyleSheet("color: white;");
    }

    //s2
    ui->progressBarS2->setValue(sVector[2].getSPercent());
    ui->sensor2->setText(sVector[2].getSText());
    if(sVector[2].getSPercent() >= 100){
        ui->sensor2->setStyleSheet("color: red;");
    }
    else{
         ui->sensor2->setStyleSheet("color: white;");
    }

    //s3
    ui->progressBarS3->setValue(sVector[3].getSPercent());
    ui->sensor3->setText(sVector[3].getSText());
    if(sVector[3].getSPercent() >= 100){
        ui->sensor3->setStyleSheet("color: red;");
    }
    else{
         ui->sensor3->setStyleSheet("color: white;");
    }

    //s4
    ui->progressBarS4->setValue(sVector[4].getSPercent());
    ui->sensor4->setText(sVector[4].getSText());
    if(sVector[4].getSPercent() >= 100){
        ui->sensor4->setStyleSheet("color: red;");
    }
    else{
         ui->sensor4->setStyleSheet("color: white;");
    }

    //s5
    ui->progressBarS5->setValue(sVector[5].getSPercent());
    ui->sensor5->setText(sVector[5].getSText());
    if(sVector[5].getSPercent() >= 100){
        ui->sensor5->setStyleSheet("color: red;");
    }
    else{
         ui->sensor5->setStyleSheet("color: white;");
    }

    //s6
    ui->progressBarS6->setValue(sVector[6].getSPercent());
    ui->sensor6->setText(sVector[6].getSText());
    if(sVector[6].getSPercent() >= 100){
        ui->sensor6->setStyleSheet("color: red;");
    }
    else{
         ui->sensor6->setStyleSheet("color: white;");
    }
}

void ViewSensors::on_buttonExit_pressed()
{
   this->hide();
}
