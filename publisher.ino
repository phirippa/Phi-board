#include <ESP8266WiFi.h>
#include <PubSubClient.h>
const char* ssid = "Ria2G";
const char* password = "12345679";
const char* userId = "mqtt_ship";
const char* userPw = "1234";
const char* clientId = userId;
char* topic = "MyOffice/Indoor/Temp";
char* server = "192.168.0.18"; //MQTT broker IP address

WiFiClient wifiClient; 
PubSubClient client(server, 1883, wifiClient);

void setup() {
  Serial.begin(9600);
 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nWiFi Connected");
  Serial.print("Local IP address(board's IP address) : ");
  Serial.println( WiFi.localIP() );

  Serial.println("Connecting to broker");
  while ( !client.connect(clientId, userId, userPw) ){ 
    Serial.print("*");
    delay(1000);
  }
  Serial.println("Connected to broker!!");
}

void loop() {
  client.publish(topic, "27.32");
  Serial.println(String(topic) + " : 27.32");
  delay(2000);
}
