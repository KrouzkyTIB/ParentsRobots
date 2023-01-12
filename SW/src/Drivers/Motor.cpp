//
// Created by jiri on 30.7.22.
//

#include "Motor.h"
#include "Arduino.h"
#define PWM_FREQUENCY 5000
#define PWM_RESOLUTION 10
#define MAX_SPEED 100
#define MAX_PWM 1024
#define MIN_SPEED 0

uint8_t Motor::channelCounter = 8;
Motor::Motor(const uint8_t forwardsPin,
             const uint8_t backwardsPin,
             const uint8_t speedPin) :
        forwardsPin(forwardsPin),
        backwardsPin(backwardsPin),
        speedPin(speedPin),
        pwmChannel(Motor::channelCounter--) {
    speed = 0;
}

void Motor::init() const {
    pinMode(forwardsPin, OUTPUT);
    pinMode(backwardsPin, OUTPUT);
    digitalWrite(forwardsPin, LOW);
    digitalWrite(backwardsPin, LOW);
    ledcSetup(pwmChannel, PWM_FREQUENCY, PWM_RESOLUTION);
    ledcAttachPin(speedPin, pwmChannel);
    ledcWrite(pwmChannel, 0);
}

void Motor::setSpeed(int8_t newSpeed) {
    if (abs(newSpeed) > MAX_SPEED) {
        return;
    }
    this->speed = newSpeed;
    if (speed == 0) {
        digitalWrite(forwardsPin, LOW);
        digitalWrite(backwardsPin, LOW);
    } else if (speed > 0) {
        digitalWrite(forwardsPin, HIGH);
        digitalWrite(backwardsPin, LOW);
    } else {
        digitalWrite(forwardsPin, LOW);
        digitalWrite(backwardsPin, HIGH);
    }
    uint32_t newPwmValue = map(abs(speed), MIN_SPEED, MAX_SPEED, 0, MAX_PWM);
    ledcWrite(pwmChannel, newPwmValue);
}

int8_t Motor::getSpeed() {
    return this->speed;
}
