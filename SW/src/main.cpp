#include <Arduino.h>
#include <soc/rtc_cntl_reg.h>
#include "Drivers/Motor.h"
#include "PinDefinitions.h"
#include "Server/ServerHandler.h"
#include "Data/FrontEndData.h"

#define READY_BLINKING 5
Motor rightMotor(RIGHT_FORWARDS_PIN, RIGHT_BACKWARDS_PIN, RIGHT_SPEED_PIN);
Motor leftMotor(LEFT_FORWARDS_PIN, LEFT_BACKWARDS_PIN, LEFT_SPEED_PIN);
ServerHandler serverHandler;

uint8_t readWifiChannelSettings();

void setup() {

}

void loop() {
// write your code here

}


uint8_t readWifiChannelSettings() {
    pinMode(WIFI_CHANNEL_SELECTOR1, INPUT_PULLUP);
    pinMode(WIFI_CHANNEL_SELECTOR2, INPUT_PULLUP);
    pinMode(WIFI_CHANNEL_SELECTOR3, INPUT_PULLUP);
    return digitalRead(WIFI_CHANNEL_SELECTOR3) * 4 +
           digitalRead(WIFI_CHANNEL_SELECTOR2) * 2 +
           digitalRead(WIFI_CHANNEL_SELECTOR1);
}






