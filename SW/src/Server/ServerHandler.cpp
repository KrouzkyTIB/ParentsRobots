//
// Created by jiri on 10.9.22.
//

#include "ServerHandler.h"

#define MAX_CONNECTED_DEVICES 1
#define SHOW_SSID 0
#define HTTP_PORT 80
#define USER_PATH "/"
#define DATA_PATH "/command"
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
    this->server = new AsyncWebServer(HTTP_PORT);
    Serial.println(WiFi.softAPIP());
    this->server->begin();
    this->server->onRequestBody(handleDataRequest);

}

void ServerHandler::addCallHandler(const char *path,
                                   WebRequestMethodComposite method,
                                   void (*callback)(AsyncWebServerRequest *request)) {
    server->on(path, method, callback);
}

void ServerHandler::handleDataRequest(AsyncWebServerRequest *request,
                                      uint8_t *data,
                                      size_t len,
                                      size_t index,
                                      size_t total) {
    if (request->method() == HTTP_POST && request->url() == DATA_PATH) {
        Serial.println((char *) data);
    }


}







