//
// Created by jiri on 10.9.22.
//

#include "ServerHandler.h"
#include "SPIFFS.h"

#define MAX_CONNECTED_DEVICES 1
#define SHOW_SSID 0
#define HTTP_PORT 80
#define USER_PATH "/"
#define BUNDLE_JS_PATH "/bundle.js"
#define DATA_PATH "/command"
using namespace std::placeholders;

const IPAddress ServerHandler::localIp(10, 0, 0, 10);
const IPAddress ServerHandler::gateway(192, 168, 1, 1);
const IPAddress ServerHandler::subnet(255, 255, 255, 0);
String ServerHandler::bundleJs = "";
String ServerHandler::indexHtml = "";
WebServer ServerHandler::server(HTTP_PORT);

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
    if (!SPIFFS.begin()) {
        throw std::runtime_error("SPIFFS is not running!");
    }
    readString("/index.html", &ServerHandler::indexHtml);
    readString("/bundle.js.gz", &ServerHandler::bundleJs);
    this->ssid = ssidNames[ssidIndex];
    this->channel = ssidIndex;
    WiFi.softAP(this->ssid.c_str(), nullptr, channel, SHOW_SSID, MAX_CONNECTED_DEVICES);
    WiFi.softAPConfig(localIp, gateway, subnet);
    Serial.println(WiFi.softAPIP());
    server.on(USER_PATH, ServerHandler::handleIndexHTMLServe);
    server.on(BUNDLE_JS_PATH, ServerHandler::handleBundleJsServe);
    server.on(DATA_PATH, ServerHandler::handleData);
    server.begin();
}

void ServerHandler::handleIndexHTMLServe() {
    server.send(200, "text/html", ServerHandler::indexHtml);
}

void ServerHandler::handleBundleJsServe() {
    server.sendHeader("Content-Encoding", "gzip");
    server.send(200, "text/javascript", ServerHandler::bundleJs);
}

void ServerHandler::handleClient() {
    server.handleClient();
}

void ServerHandler::readString(const String filename, String *buffer) {
    File f = SPIFFS.open(filename);
    while (f.peek() != EOF) {
        buffer->concat((char) f.read());
    }
    f.close();
}

void ServerHandler::handleData() {
    for (int i = 0; i < server.args(); i++){
        Serial.print(server.argName(i));
        Serial.print(" : ");
        Serial.println(server.arg(i));
    }

    server.send(200, "text/plain", "OK");
}










