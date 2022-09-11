//
// Created by jiri on 11.9.22.
//

#ifndef SW_FRONTENDDATA_H
#define SW_FRONTENDDATA_H

#include <Arduino.h>

class FrontEndData {
private:
    int8_t rightMotorPower;
    int8_t leftMotorPower;
    bool lightsOn;

    FrontEndData();

    static FrontEndData *instance;
public:
    FrontEndData(FrontEndData const &) = delete;

    void operator=(FrontEndData const &) = delete;

    static FrontEndData *getInstance();

    int8_t getRightMotorPower() const;

    void setRightMotorPower(int8_t rightMotorPower);

    int8_t getLeftMotorPower() const;

    void setLeftMotorPower(int8_t leftMotorPower);

    bool isLightsOn() const;

    void setLightsOn(bool lightsOn);


};


#endif //SW_FRONTENDDATA_H
