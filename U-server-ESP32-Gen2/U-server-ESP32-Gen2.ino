#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>
#include <WebSerial.h>
#include <ESPmDNS.h>

#include "page1.h"
#include "page2.h"
#include "page3.h"
#include "page4.h"
#include "page404.h"
#include "pageFaviconJS.h"

const char* ssid = "wrtManMini";
const char* password = "1231231232023";
const char* host = "my-esp32";

int count = 0;

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }

  if(!MDNS.begin(host)) {
    return;
  }

  AsyncElegantOTA.begin(&server, "username", "password");    // Start ElegantOTA
  AsyncElegantOTA.setID("myCAM-2023");
  WebSerial.begin(&server);                                  // Start WebSerial
  server.begin();

  server.onNotFound([](AsyncWebServerRequest *request){
    AsyncWebServerResponse* response = request->beginResponse(404, "text/html", FPSTR(page404content));
    request->send(response);
  });

  server.on("/favicon.js", HTTP_GET, [](AsyncWebServerRequest *request){
  AsyncWebServerResponse* response = request->beginResponse(200, "text/html", FPSTR(pageFaviconJS));
  request->send(response);
  });

  server.on(page1link, HTTP_GET, [](AsyncWebServerRequest *request) {
    AsyncWebServerResponse *response = request->beginResponse(200, "text/html", FPSTR(page1content));
    response->addHeader("Cache-Control", "no-cache");
    response->addHeader("Refresh", "5");
    request->send(response);
  });

  server.on(page2link, HTTP_GET, [](AsyncWebServerRequest *request) {
    AsyncWebServerResponse *response = request->beginResponse(200, "text/html", FPSTR(page2content));
    response->addHeader("Cache-Control", "no-cache");
    response->addHeader("Refresh", "5");
    request->send(response);
  });

  server.on(page3link, HTTP_GET, [](AsyncWebServerRequest *request) {
    AsyncWebServerResponse *response = request->beginResponse(200, "text/html", FPSTR(page3content));
    response->addHeader("Cache-Control", "no-cache");
    response->addHeader("Refresh", "5");
    request->send(response);
  });

  server.on(page4link, HTTP_GET, [](AsyncWebServerRequest *request) {
    AsyncWebServerResponse *response = request->beginResponse(200, "text/html", FPSTR(page4content));
    response->addHeader("Cache-Control", "no-cache");
    response->addHeader("Refresh", "5");
    request->send(response);
  });

}

void loop(void) {
  count++;
  WebSerial.println("Hello, word! It ESP32-CAM!");
  WebSerial.println(count);
  Serial.println(WiFi.localIP());
  delay(10000);
}
