#include <Arduino.h>
#include "Drivers/Motor.h"
#include "PinDefinitions.h"

Motor rightMotor(RIGHT_FORWARDS_PIN, RIGHT_BACKWARDS_PIN, RIGHT_SPEED_PIN);
Motor leftMotor(LEFT_FORWARDS_PIN, LEFT_BACKWARDS_PIN, LEFT_SPEED_PIN);

void setup() {
    rightMotor.init();
    leftMotor.init();
    Serial.begin(115200);

}

void loop() {
// write your code here

}

