#include "ESP8266WiFi.h"

void setup() {
  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Setup done");

}

void loop() {
  Serial.println("scan start");

  // Print WiFi MAC address:
  printMacAddress();
 
  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0)
    Serial.println("no networks found");
  else
  {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i)
    {
      // Print SSID and RSSI for each network found
              
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(" dBm)");

      if(WiFi.RSSI(i) >= -55)
      {
        Serial.print("  meter");
      }else if(WiFi.RSSI(i) < -55 && WiFi.RSSI(i) >= -65)
      {
        Serial.print(" 4 meter");
      }else if(WiFi.RSSI(i) < -65 && WiFi.RSSI(i) >= -75)
      {
        Serial.print(" 6 meter");
      }else if(WiFi.RSSI(i) < -75 && WiFi.RSSI(i) >= -85)
      {
        Serial.print(" 8 meter");
      }else
      {
        Serial.print(" 12 meter");
      }
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*"); 
      delay(10);
    }
    Serial.println("=========================");
  }
  Serial.println("");

  // Wait a bit before scanning again
  delay(10000);
}

void printMacAddress() {
  // the MAC address of your Wifi shield
  byte mac[6];

  // print your MAC address:
  WiFi.macAddress(mac);
  Serial.print("MAC: ");
  Serial.print(mac[5], HEX);
  Serial.print(":");
  Serial.print(mac[4], HEX);
  Serial.print(":");
  Serial.print(mac[3], HEX);
  Serial.print(":");
  Serial.print(mac[2], HEX);
  Serial.print(":");
  Serial.print(mac[1], HEX);
  Serial.print(":");
  Serial.println(mac[0], HEX);
}
