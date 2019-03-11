#ifndef SENSOR_H
#define SENSOR_H

#include <QString>
#include <sstream>

struct Sensor{
    Sensor(int sMax) : sMax(sMax){
    }
    const float sMax;
    float sValue = 0;
    int getSPercent(){
        return static_cast<int>(sValue / sMax * 100.f);
    }
    QString getSText(){
        std::ostringstream buff;
        buff << sValue << " Bar";
        return QString::fromStdString(buff.str());
    }
};

#endif // SENSOR_H
