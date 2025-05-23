#include <M5Atom.h>
#include <WiFi.h>
#include <Arduino.h>

CRGB dispColor(uint8_t r, uint8_t g, uint8_t b) {
  return (CRGB)((r << 16) | (g << 8) | b);
}

const char *ssid = "TP-Link_B308";
const char *password = "29640393";

void setup() {
  M5.begin(true, false, true);
  delay(50);
  M5.dis.drawpix(0, dispColor(255, 0, 255));
  delay(50);

  Serial.begin(115200);
  Serial.print("Starting WiFi connection to ");

  WiFi.begin(ssid, password);
  Serial.print(ssid);

  Serial.print("...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  M5.update();

  if (WiFi.status() != WL_CONNECTED){
    M5.dis.drawpix(0, dispColor(255, 0, 255));
    Serial.println("WiFi not connected");
  }else{
    M5.dis.drawpix(0, dispColor(0, 255, 0));
    Serial.println("WiFi connected");
  }

  delay(1000);
}