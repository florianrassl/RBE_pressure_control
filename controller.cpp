#include "controller.h"

Controller::Controller()
{
    sVector.push_back(Sensor(100.f));
    sVector.push_back(Sensor(100.f));
    sVector.push_back(Sensor(100.f));
    sVector.push_back(Sensor(100.f));
    sVector.push_back(Sensor(100.f));
    sVector.push_back(Sensor(100.f));
    sVector.push_back(Sensor(100.f));

    tCon = new std::thread(&Controller::controllerLoop, this);
}

Controller::~Controller(){

}
//TODO exut threat properly

void Controller::parsData(){
    //TODO TEST CODE
    for(Sensor &s : sVector){
        s.sValue +=1;
            if(s.sValue > 110)
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
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        sendData();
        parsData();
        saveData();
        newDataAvailable(sVector);
    }
   // return 0;
}
