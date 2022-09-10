#include <Arduino.h>
#include "Drivers/Motor.h"
#include "PinDefinitions.h"
#include "Server/ServerHandler.h"

#define USER_PATH "/"
#define DATA_PATH "/command"

void handleDataPacket(httpsserver::HTTPRequest *request, httpsserver::HTTPResponse *response);

Motor rightMotor(RIGHT_FORWARDS_PIN, RIGHT_BACKWARDS_PIN, RIGHT_SPEED_PIN);
Motor leftMotor(LEFT_FORWARDS_PIN, LEFT_BACKWARDS_PIN, LEFT_SPEED_PIN);
ServerHandler server;

void setup() {
    rightMotor.init();
    leftMotor.init();
    Serial.begin(115200);
    server.init(1);
    server.addCallHandler(new ResourceNode(
            DATA_PATH,
            "POST",
            handleDataPacket
    ));
}

void loop() {
// write your code here
    server.handleClients();
//    Serial.println("running");
}

void handleDataPacket(httpsserver::HTTPRequest *request, httpsserver::HTTPResponse *response) {
    size_t length = request->getContentLength();
    char payload[length];
    memset(payload, 0, length);
    request->readChars(payload, length);
    Serial.println(payload);
    response->setStatusCode(200);
    response->setHeader("Content-Type", "application/json");
    response->setStatusText("OK");
    response->println("OK");
    response->finalize();
    response->flush();
}


