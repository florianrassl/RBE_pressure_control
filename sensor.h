#ifndef SENSOR_H
#define SENSOR_H

#include <QString>
#include <sstream>

struct Sensor{
    Sensor(int sMax) : sMax(sMax){
        sName = "Sensor" + QString::number(sCount++);
    }
    Sensor(int sMax, QString sName) : sMax(sMax), sName(sName){

    }
    const float sMax;
    float sValue = 0;
    QString sName;
    int getSPercent(){
        return static_cast<int>(sValue / sMax * 100.f);
    }
    QString getSText(){
        std::ostringstream buff;
        buff << sValue << " Bar";
        return QString::fromStdString(buff.str());
    }

private:
    static int sCount;
};

int Sensor::sCount = 0;

#endif // SENSOR_H
