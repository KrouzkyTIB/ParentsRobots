#include <Arduino.h>
#include <soc/rtc_cntl_reg.h>
#include "Drivers/Motor.h"
#include "PinDefinitions.h"
#include "Server/ServerHandler.h"
#include "Data/FrontEndData.h"

Motor rightMotor(RIGHT_FORWARDS_PIN, RIGHT_BACKWARDS_PIN, RIGHT_SPEED_PIN);
Motor leftMotor(LEFT_FORWARDS_PIN, LEFT_BACKWARDS_PIN, LEFT_SPEED_PIN);
ServerHandler serverHandler;

uint8_t readWifiChannelSettings();

void setup() {
    WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);
    rightMotor.init();
    leftMotor.init();
    Serial.begin(115200);
    serverHandler.init(readWifiChannelSettings());
    pinMode(READY_LED, OUTPUT);
    digitalWrite(READY_LED, HIGH);
}

void loop() {
// write your code here
    serverHandler.handleClient();
    FrontEndData *data = FrontEndData::getInstance();
    rightMotor.setSpeed(data->getRightMotorPower());
    leftMotor.setSpeed(data->getLeftMotorPower());
}


uint8_t readWifiChannelSettings() {
    pinMode(WIFI_CHANNEL_SELECTOR1, INPUT_PULLUP);
    pinMode(WIFI_CHANNEL_SELECTOR2, INPUT_PULLUP);
    pinMode(WIFI_CHANNEL_SELECTOR3, INPUT_PULLUP);
    return digitalRead(WIFI_CHANNEL_SELECTOR3) * 4 +
           digitalRead(WIFI_CHANNEL_SELECTOR2) * 2 +
           digitalRead(WIFI_CHANNEL_SELECTOR1);
}






