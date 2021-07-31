#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;

const char* ssid = "Venu"; //Your Network SSID
const char* password = "9849641927"; //Your Network Password
WiFiClient client;
unsigned long myChannelNumber = 944934 ; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "BD49CBANH6WVM6IL"; //Your Write API Key

void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200);
 delay(10);
 WiFi.begin(ssid, password);
 ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
  int frequency_decoded,voltage_decoded;
  int frequency = analogRead(A0);
  frequency_decoded=frequency*200/1024;
  ThingSpeak.writeField(myChannelNumber,1,frequency_decoded, myWriteAPIKey);
  Serial.print("frequency channel");
  delay(100);
  int voltage = analogRead(A0);
  voltage_decoded=voltage*12/1024;
  ThingSpeak.writeField(myChannelNumber,2,voltage_decoded, myWriteAPIKey);
  Serial.print("voltage channel");
  delay(100);
  //Update in ThingSpeak
}
