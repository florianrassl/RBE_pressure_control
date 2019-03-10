#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>

class Controller
{
public:
    Controller();

private:
    void controllerLoop();
    void parsData();
    void saveData();
    void updateUI();
    std::string serialPort;
};

#endif // CONTROLLER_H
