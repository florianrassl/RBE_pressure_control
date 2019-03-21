#ifndef VIEWSENSORS_H
#define VIEWSENSORS_H

#include <QWidget>
#include <vector>
#include <QLabel>
#include <QProgressBar>
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
    void initUI(std::vector<Sensor>);//TODO
    void updateUI(std::vector<Sensor>);

private slots:
    void on_buttonExit_pressed();

private:
    Ui::ViewSensors *ui;

    //TODO
    struct UISensor{
        UISensor(QString name, ViewSensors *p){
            //init ui elements
            sName = new QLabel(name);
            sBar = new QLabel("xxx");
            sProgressBar = new QProgressBar();
            //TODO set probs
            //p->ui-> TODO
        }
        QLabel *sName;
        QLabel *sBar;
        QProgressBar *sProgressBar;
    };
    std::vector<UISensor*> uiVector;
};

#endif // VIEWSENSORS_H
