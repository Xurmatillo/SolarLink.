#include <ESP8266WiFi.h>

const char* ssid = "YourWiFiSSID"; // Your WiFi SSID
const char* password = "YourWiFiPassword"; // Your WiFi password

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  WiFi.disconnect();
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAP("ESP8266 Repeater", "password");
  WiFi.begin(ssid, password);

  Serial.println("WiFi Repeater is ready");
}

void loop() {
  delay(5000);
  Serial.println("WiFi Repeater is active");
}
