#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <vector>
#include <thread>
#include <QObject>
#include "sensor.h"

class Controller : public QObject
{
    Q_OBJECT

public:
    Controller();
    ~Controller();

public: signals:
    void newDataAvailable(std::vector<Sensor>);

private:
    int controllerLoop();
    void parsData();
    void sendData();
    void saveData();
    std::string serialPort;
    std::vector<Sensor> sVector;
    std::thread *tCon;
};

#endif // CONTROLLER_H
