#include <ESP8266WiFi.h>
#include <PubSubClient.h>
const char* ssid = "Ria2G";
const char* password = "12345679";
const char* clientId = "mqtt_ship";
const char* userPw = "1234";
const char* userId = clientId;
char *topic = "MyOffice/Indoor/#";
char* server = "192.168.0.18"; //MQTT broker IP address
char messageBuf[100];

void callback(char* topic, byte* payload, unsigned int length) { 
  Serial.println("Message arrived!\nTtopic: " + String(topic));
  Serial.println("Length: "+ String(length, DEC));
  
  strncpy(messageBuf, (char*)payload, length);
  messageBuf[length] = '\0';
  Serial.println("Payload: "+ String(messageBuf) + "\n\n");
}

WiFiClient wifiClient; 
PubSubClient client(server, 1883, callback, wifiClient);
void setup() {
  Serial.begin(9600);
  Serial.print("\nConnecting to "); Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("."); delay(500);
  }
  Serial.println("\nWiFi Connected");

  while ( !client.connect(clientId, userId, userPw) ){ 
    Serial.print("*"); delay(1000);
  }
  Serial.println("\nConnected to broker");
  Serial.println(String("Subscribing! topic = ") + topic);
  client.subscribe(topic);
}

void loop() {
  client.loop();
}
