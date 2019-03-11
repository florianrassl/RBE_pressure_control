#include "editprofile.h"
#include "ui_editprofile.h"
#include <QFileDialog>
#include <fstream>

EditProfile::EditProfile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditProfile)
{
    ui->setupUi(this);

   // ui->tableEdit->setColumnWidth(1, 300);
    QHeaderView *verticalHeader = ui->tableEdit->verticalHeader();
    verticalHeader->setSectionResizeMode(QHeaderView::Fixed);
    verticalHeader->setDefaultSectionSize(24);

    loadProfile("./default.csv");
    if(!pList.empty())
        fillTable();
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
    pList.push_back(ProfileEntry(0, 0));
    addTableRow(pList.back());
}

void EditProfile::on_buttonDelete_clicked()
{
    int first, last;
    auto selected = ui->tableEdit->selectedItems();
    if(selected.size() == 0) return;
    first = selected.first()->row();
    last = selected.last()->row();

    auto iterF = pList.begin();
    auto iterL = pList.begin();
    for(; first; first--)
        iterF++;
    for(; last; last--)
        iterL++;
    pList.erase(iterF, ++iterL);

    while(ui->tableEdit->rowCount() != 0)
        ui->tableEdit->removeRow(0);
    fillTable();
}

void EditProfile::on_buttonClear_clicked()
{
    while(ui->tableEdit->rowCount() != 0)
        ui->tableEdit->removeRow(0);
    pList.clear();
}

#include <iostream>
void EditProfile::on_buttonLoad_clicked()
{
    QString fileName = QFileDialog::
            getOpenFileName(this, tr("open file"), "./",
            tr("CSV file (*.csv)"));
    if(fileName.size() <= 5) return;
    pList.clear();
    loadProfile(fileName.toStdString());
    fillTable();
}

void EditProfile::loadProfile(std::string path){
    size_t sT, sP;
    std::string line, sTime, sPressure;
    int iT, iP;
    std::ifstream fileLoad(path);
    if(fileLoad.is_open()){
        while(std::getline(fileLoad, line)){
            sT = line.find_first_of(',');
            sTime = line.substr(0, sT);
            sP = line.find_last_of(',');
            sPressure = line.substr(sT+1, sP-sT-1);
            iT = std::stoi(sTime);
            iP = std::stoi(sPressure);
            pList.push_back(ProfileEntry(iT, iP));
        }
    }
    fileLoad.close();
}

void EditProfile::on_buttonSave_clicked()
{
    QString fileName = QFileDialog::
            getSaveFileName(this,
            tr("open file"), "./", tr("CSV file (*.csv)"));
    if(fileName.size() <=5 ) return;

    std::ofstream fileSave;
    fileSave.open(fileName.toStdString());
    for(auto const &i : pList){
        fileSave << i.time << "," << i.pressure << "," << std::endl;
    }
    fileSave.close();
}

void EditProfile::on_tableEdit_cellChanged(int row, int column)
{
    bool ok;
    auto item = ui->tableEdit->item(row, column);
    QString value = item->text();
    int intValue =value.toInt(&ok);
    if(!ok){
        item->setTextColor(Qt::red);
        return;
    }
    item->setTextColor(Qt::black);
    auto iter = pList.begin();
    for(; row; row--)
        iter++;
    if(column==0)
        (*iter).time = intValue;
    else
        (*iter).pressure = intValue;
}

void EditProfile::fillTable(){
    while(ui->tableEdit->rowCount() != 0)
        ui->tableEdit->removeRow(0);
    for(ProfileEntry const &pe : pList){
        addTableRow(pe);
    }
}

void EditProfile::addTableRow(ProfileEntry p){
    ui->tableEdit->insertRow(ui->tableEdit->rowCount());
    ui->tableEdit->setItem(ui->tableEdit->rowCount()-1, 0,
                           new QTableWidgetItem(QString::number(p.time)));
    ui->tableEdit->setItem(ui->tableEdit->rowCount()-1, 1,
                           new QTableWidgetItem(QString::number(p.pressure)));
}
