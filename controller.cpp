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
    //TODO sim code
}

void Controller::sendData(){

}

void Controller::saveData(){
    //TODO save
}

void Controller::updateUI(){

}

int Controller::controllerLoop(){
    while(true){
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        for(Sensor &s : sVector){
            s.sValue +=1;
            if(s.sValue > 110)
                s.sValue = 0;
        }
        //viewSensors->updateView(sVector);
        newDataAvailable(sVector);
    }
   // return 0;
}
