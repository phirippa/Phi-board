#include <ESP8266WiFi.h>
#include <PubSubClient.h>
const char* ssid = "Ria2G";         // 접속 가능한 WiFi 공유기 이름으로 수정
const char* password = "12345679";  // 해당 공유기의 패스워드로 수정

const char* userId = "mqtt_ship";   // Broker에 접속 가능한 ID
const char* userPw = "1234";        // 해당 ID에 대한 패스워드
const char* clientId = userId;
char* server = "192.168.0.18";      // Broker's IP address

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

void loop() {}
