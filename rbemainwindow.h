#ifndef RBEMAINWINDOW_H
#define RBEMAINWINDOW_H

#include <QMainWindow>
#include "viewsensors.h"

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

private:
    Ui::rbeMainWindow *ui;
    ViewSensors*viewSensors;
};

#endif // RBEMAINWINDOW_H
