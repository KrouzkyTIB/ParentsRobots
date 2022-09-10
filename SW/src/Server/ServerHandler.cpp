//
// Created by jiri on 10.9.22.
//

#include "ServerHandler.h"
#include <HTTPSServer.hpp>

#define MAX_CONNECTED_DEVICES 1
#define SHOW_SSID 0
#define HTTP_PORT 80
using namespace std::placeholders;


const IPAddress ServerHandler::localIp(10, 0, 0, 10);
const IPAddress ServerHandler::gateway(192, 168, 1, 1);
const IPAddress ServerHandler::subnet(255, 255, 255, 0);

const std::string ServerHandler::ssidNames[NUMBER_OF_SSIDS] = {"Car0",
                                                               "Car1",
                                                               "Car2",
                                                               "Car3",
                                                               "Car4",
                                                               "Car5",
                                                               "Car6",
                                                               "Car7"};


void ServerHandler::init(uint8_t ssidIndex) {
    if (ssidIndex >= NUMBER_OF_SSIDS) {
        throw std::range_error("Index out of bound exception");
    }
    this->ssid = ssidNames[ssidIndex];
    this->channel = ssidIndex;
    WiFi.softAP(this->ssid.c_str(), nullptr, channel, SHOW_SSID, MAX_CONNECTED_DEVICES);
    WiFi.softAPConfig(localIp, gateway, subnet);
    this->server = new httpsserver::HTTPServer(HTTP_PORT, MAX_CONNECTED_DEVICES, 0);
    this->server->start();
    Serial.println(WiFi.softAPIP());
}



void ServerHandler::addCallHandler(ResourceNode *nodeRoot) {
    this->server->registerNode(nodeRoot);
}

bool ServerHandler::isServerRunning() {
    return this->server->isRunning();
}

void ServerHandler::handleClients() {
    this->server->loop();
}






