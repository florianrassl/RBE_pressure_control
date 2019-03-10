#ifndef VIEWSENSORS_H
#define VIEWSENSORS_H

#include <QWidget>
#include <vector>
#include "sensor.h"

namespace Ui {
class ViewSensors;
}

class ViewSensors : public QWidget
{
    Q_OBJECT

public:
    explicit ViewSensors(QWidget *parent = nullptr);
    ~ViewSensors();

public slots:
    void updateUI(std::vector<Sensor>);

private slots:
    void on_buttonExit_pressed();

private:
    Ui::ViewSensors *ui;
};

#endif // VIEWSENSORS_H
