#include "editprofile.h"
#include "ui_editprofile.h"

EditProfile::EditProfile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditProfile)
{
    ui->setupUi(this);

   // ui->tableEdit->setColumnWidth(1, 300);
}

EditProfile::~EditProfile()
{
    delete ui;
}

void EditProfile::on_buttonExit_clicked()
{
    this->hide();
}

void EditProfile::on_buttonAdd_clicked()
{

    /*
    int t, p;
    bool ok;
    t = static_cast<int>(ui->editTime->text().toUInt(&ok));
    if(!ok) return;
    p = static_cast<int>(ui->editPressure->text().toUInt(&ok));
    if(!ok) return;
    */
    pList.push_back(ProfileEntry(0, 0));
    addTableRow(pList.back());
}

void EditProfile::fillTable(){

}

void EditProfile::addTableRow(ProfileEntry p){
    ui->tableEdit->insertRow(ui->tableEdit->rowCount());
    ui->tableEdit->setItem(ui->tableEdit->rowCount()-1, 0,
                           new QTableWidgetItem(QString::number(p.time)));
    ui->tableEdit->setItem(ui->tableEdit->rowCount()-1, 1,
                           new QTableWidgetItem(QString::number(p.pressure)));
}
