#ifndef RBEMAINWINDOW_H
#define RBEMAINWINDOW_H

#include <QMainWindow>
#include "viewsensors.h"
#include "controller.h"
#include "editprofile.h"

namespace Ui {
class rbeMainWindow;
}

class rbeMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit rbeMainWindow(QWidget *parent = nullptr);
    ~rbeMainWindow();

private slots:
    void on_buttonViewSensor_clicked();
    void on_buttonExit_clicked();

    void on_buttonEdit_clicked();

private:
    Ui::rbeMainWindow *ui;
    EditProfile *editProfile;
    ViewSensors *viewSensors;
    Controller *c;
};

#endif // RBEMAINWINDOW_H
