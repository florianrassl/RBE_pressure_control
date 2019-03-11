#include "editprofile.h"
#include "ui_editprofile.h"

EditProfile::EditProfile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditProfile)
{
    ui->setupUi(this);
}

EditProfile::~EditProfile()
{
    delete ui;
}

void EditProfile::on_buttonExit_clicked()
{
    this->hide();
}