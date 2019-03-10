#ifndef EDITPRESSUREPROFILE_H
#define EDITPRESSUREPROFILE_H

#include <QWidget>

namespace Ui {
class EditPressureProfile;
}

class EditPressureProfile : public QWidget
{
    Q_OBJECT

public:
    explicit EditPressureProfile(QWidget *parent = nullptr);
    ~EditPressureProfile();

private:
    Ui::EditPressureProfile *ui;
};

#endif // EDITPRESSUREPROFILE_H
