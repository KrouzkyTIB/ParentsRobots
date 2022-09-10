//
// Created by jiri on 10.9.22.
//

#ifndef SW_COMMUNICATION_HANDLER_H
#define SW_COMMUNICATION_HANDLER_H
#define NUMBER_OF_SSIDS 8

#include "Arduino.h"
#include <WiFi.h>
#include <HTTPSServer.hpp>
#include <HTTPRequest.hpp>
#include <HTTPResponse.hpp>
#include "SSLCert.hpp"

using namespace httpsserver;

class ServerHandler {
private:
    std::string ssid;
    static const std::string ssidNames[NUMBER_OF_SSIDS];
    uint8_t channel;
    static const IPAddress localIp;
    static const IPAddress gateway;
    static const IPAddress subnet;
    HTTPServer *server;


public:
    void init(uint8_t ssidIndex);
    void addCallHandler(ResourceNode * nodeRoot);
    bool isServerRunning();
    void handleClients();
};

#endif //SW_COMMUNICATION_HANDLER_H
