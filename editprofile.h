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

private:
    Ui::EditProfile *ui;
    std::list<ProfileEntry> pList;
    void fillTable();
    void addTableRow(ProfileEntry);
};

#endif // EDITPROFILE_H
