//
// Created by jiri on 30.7.22.
//

#ifndef SW_MOTOR_H
#define SW_MOTOR_H

#include <Arduino.h>

class Motor {
private:
    const uint8_t forwardsPin;
    const uint8_t backwardsPin;
    const uint8_t speedPin;
    const uint8_t pwmChannel;
    int8_t speed;
    static uint8_t channelCounter;

public:
    Motor(uint8_t forwardsPin, uint8_t backwardsPin, uint8_t speedPin);
    void setSpeed(int8_t newSpeed);
    int8_t getSpeed();
    Motor() = delete;
    void init() const;
};


#endif //SW_MOTOR_H
