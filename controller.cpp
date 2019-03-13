#include "controller.h"

Controller::Controller()
{
    //TODO load sensor data from file;
    for(int i = 0; i < 7; i++){
        sVector.push_back(Sensor(250.f));
    }

    tCon = new std::thread(&Controller::controllerLoop, this);
}

Controller::~Controller(){
    //TODO exit  thread properly
}

void Controller::parsData(){
    //TODO TEST CODE
    //TODO SET INTERVALL AND FUCK
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    for(Sensor &s : sVector){
        s.sValue +=1;
            if(s.sValue > 270)
                s.sValue = 0;
        }
}

void Controller::sendData() const{
    //TODO
}

void Controller::saveData() const{
    //TODO save
}

int Controller::controllerLoop(){
    while(true){
        sendData();
        parsData();
        saveData();
        newDataAvailable(sVector);
    }
   // return 0;
}
