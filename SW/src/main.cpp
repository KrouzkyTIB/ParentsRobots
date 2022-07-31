#include <Arduino.h>
#include "Drivers/Motor.h"
#include "PinDefinitions.h"

Motor rightMotor(RIGHT_FORWARDS_PIN, RIGHT_BACKWARDS_PIN, RIGHT_SPEED_PIN);
Motor leftMotor(LEFT_FORWARDS_PIN, LEFT_BACKWARDS_PIN, LEFT_SPEED_PIN);

void setup() {
// write your initialization code here
    rightMotor.init();
    leftMotor.init();
    Serial.begin(115200);
//    pinMode(32, OUTPUT);
//    digitalWrite(32, HIGH);
//    delay(1000);
//    digitalWrite(32, LOW);
}

void loop() {
// write your code here
    Serial.println("Hello world");
    rightMotor.setSpeed(100);
    leftMotor.setSpeed(100);
    delay(2000);
    rightMotor.setSpeed(50);
    leftMotor.setSpeed(50);
    delay(2000);
}

