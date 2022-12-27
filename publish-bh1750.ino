#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include <Wire.h>
#include <BH1750.h>
BH1750 lightMeter;

const char* ssid = "Ria2G";
const char* password = "12345679";

const char* userId = "mqtt_ship";
const char* userPw = "1234";
const char* clientId = userId;

char *topic = "MyOffice/Indoor/Lux";
char* server = "192.168.0.18"; 
WiFiClient wifiClient; 
PubSubClient client(server, 1883, wifiClient);

void setup() {
  Serial.begin(9600);
  Serial.print("\nConnecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nWiFi Connected");

  Serial.println("Connecting to broker");
  while ( !client.connect(clientId, userId, userPw) ){ 
    Serial.print("*");
    delay(1000);
  }
  Serial.println("\nConnected to broker!!");
  Wire.begin();
  lightMeter.begin();
}

void loop() {
  char buf[20];
  float lux = lightMeter.readLightLevel();
  String strLuxValue = String( lux );
  strLuxValue.toCharArray(buf, strLuxValue.length() );

  client.publish(topic, buf);
  Serial.print(lux); Serial.print('\t'); Serial.println(buf);
  delay(2000);
}

