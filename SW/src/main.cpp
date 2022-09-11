#include <Arduino.h>
#include <rtc_wdt.h>
#include "Drivers/Motor.h"
#include "PinDefinitions.h"
#include "Server/ServerHandler.h"


void handleDataPacket(AsyncWebServerRequest *request);

Motor rightMotor(RIGHT_FORWARDS_PIN, RIGHT_BACKWARDS_PIN, RIGHT_SPEED_PIN);
Motor leftMotor(LEFT_FORWARDS_PIN, LEFT_BACKWARDS_PIN, LEFT_SPEED_PIN);
ServerHandler serverHandler;

void setup() {
    rightMotor.init();
    leftMotor.init();
    Serial.begin(115200);
    serverHandler.init(1);
}

void loop() {
// write your code here
//    Serial.println("running");
//    rtc_wdt_feed();
    serverHandler.handleClient();
}




