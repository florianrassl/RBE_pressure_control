#include "controller.h"

Controller::Controller()
{
    sVector.push_back(Sensor(250.f));
    sVector.push_back(Sensor(250.f));
    sVector.push_back(Sensor(250.f));
    sVector.push_back(Sensor(250.f));
    sVector.push_back(Sensor(250.f));
    sVector.push_back(Sensor(250.f));
    sVector.push_back(Sensor(250.f));

    tCon = new std::thread(&Controller::controllerLoop, this);
}

Controller::~Controller(){
    //TODO exit  thread properly
}

void Controller::parsData(){
    //TODO TEST CODE
    for(Sensor &s : sVector){
        s.sValue +=1;
            if(s.sValue > 270)
                s.sValue = 0;
        }
}

void Controller::sendData(){
    //TODO
}

void Controller::saveData(){
    //TODO save
}

int Controller::controllerLoop(){
    while(true){
        //TODO SET INTERVALL AND FUCK
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        sendData();
        parsData();
        saveData();
        newDataAvailable(sVector);
    }
   // return 0;
}
