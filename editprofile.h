#ifndef EDITPROFILE_H
#define EDITPROFILE_H

#include <QWidget>
#include <list>
#include "profileentry.h"

namespace Ui {
class EditProfile;
}

class EditProfile : public QWidget
{
    Q_OBJECT

public:
    explicit EditProfile(QWidget *parent = nullptr);
    ~EditProfile();

private slots:
    void on_buttonExit_clicked();
    void on_buttonAdd_clicked();
    void on_buttonDelete_clicked();
    void on_buttonClear_clicked();
    void on_buttonLoad_clicked();
    void on_buttonSave_clicked();
    void on_tableEdit_cellChanged(int row, int column);

private:
    Ui::EditProfile *ui;
    std::list<ProfileEntry> pList;
    void fillTable();
    void addTableRow(ProfileEntry);
    void addTableRow(ProfileEntry, int);
    void loadProfile(std::string);
};

#endif // EDITPROFILE_H
