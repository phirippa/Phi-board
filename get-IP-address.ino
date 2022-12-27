#include <ESP8266WiFi.h>

// AP_NAME : 접속 가능한 WiFi 공유기 이름으로 변경
const char* ssid = "AP_NAME";
// PASSWORD : 해당 공유기에 접속하기 위한 패스워트로 변경
const char* password = "PASSWORD";

void setup() {
  Serial.begin(9600);
 
  Serial.print("\nConnecting to ");
  Serial.println(ssid);

  // 해당 공유기에 접속 시도
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nWiFi Connected");
  
  // Phi 보드가 공유기로부터 할당 받은 "(사설)IP 주소" 출력
  Serial.print("Local IP address : ");
  Serial.println( WiFi.localIP() );
}

void loop() {
}
