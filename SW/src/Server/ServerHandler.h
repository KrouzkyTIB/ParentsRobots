//
// Created by jiri on 10.9.22.
//

#ifndef SW_COMMUNICATION_HANDLER_H
#define SW_COMMUNICATION_HANDLER_H
#define NUMBER_OF_SSIDS 8

#include "Arduino.h"
#include <WiFi.h>
#include "ESPAsyncWebServer.h"

class ServerHandler {
private:
    std::string ssid;
    static const std::string ssidNames[NUMBER_OF_SSIDS];
    uint8_t channel;
    static const IPAddress localIp;
    static const IPAddress gateway;
    static const IPAddress subnet;
    AsyncWebServer* server;

private:
    static void handleDataRequest(AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total);


public:
    void init(uint8_t ssidIndex);
    void addCallHandler(const char * path, WebRequestMethodComposite method, void (*callback) (AsyncWebServerRequest *request));
};

#endif //SW_COMMUNICATION_HANDLER_H
