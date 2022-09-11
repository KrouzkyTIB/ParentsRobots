//
// Created by jiri on 11.9.22.
//

#include "FrontEndData.h"

FrontEndData *FrontEndData::instance = nullptr;

FrontEndData *FrontEndData::getInstance() {
    if (FrontEndData::instance == nullptr) {
        FrontEndData::instance = new FrontEndData();
    }
    return FrontEndData::instance;
}

FrontEndData::FrontEndData() {
    this->rightMotorPower = 0;
    this->leftMotorPower = 0;
    this->lightsOn = false;
}

int8_t FrontEndData::getRightMotorPower() const {
    return rightMotorPower;
}

void FrontEndData::setRightMotorPower(int8_t rightMotorPower) {
    this->rightMotorPower = rightMotorPower;
}

int8_t FrontEndData::getLeftMotorPower() const {
    return leftMotorPower;
}

void FrontEndData::setLeftMotorPower(int8_t leftMotorPower) {
    this->leftMotorPower = leftMotorPower;
}

bool FrontEndData::isLightsOn() const {
    return lightsOn;
}

void FrontEndData::setLightsOn(bool lightsOn) {
    this->lightsOn = lightsOn;
}
