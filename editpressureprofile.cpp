#include "editpressureprofile.h"
#include "ui_editpressureprofile.h"

EditPressureProfile::EditPressureProfile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditPressureProfile)
{
    ui->setupUi(this);
}

EditPressureProfile::~EditPressureProfile()
{
    delete ui;
}
