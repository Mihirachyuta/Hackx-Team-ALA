#include "FirebaseESP8266.h"  // Install Firebase ESP8266 library
#include <ESP8266WiFi.h>
//#include <DHT.h>    // Install DHT11 Library and Adafruit Unified Sensor Library
int a[2][2]={{1,2},{3,4}};

#define FIREBASE_HOST "local-iterator-273207-default-rtdb.firebaseio.com" //Without http:// or https:// schemes
#define FIREBASE_AUTH "XOPZJCNGbkojHryHRQwMms6FLafwd54q1KHLNBsM"
#define WIFI_SSID "Venu"
#define WIFI_PASSWORD "9849641927"


int led = 5;     // Connect LED to D5



//Define FirebaseESP8266 data object
FirebaseData firebaseData;
FirebaseData ledData;

FirebaseJson json1;



const int s1=13;
const int s0=12;
String s[4]={"00","01","10","11"}; 
int pins[4]={A0,A1,A2,A3};
int connectedPins[10][4]; 
int a=A1;
int Vin=5;
int Vout=3;
int R2;
int R1=5;
void setup() {
  // put your setup code here, to run once:
pinMode(s1,OUTPUT);
pinMode(s0,OUTPUT);

Serial.begin(115200);

  pinMode(led,OUTPUT);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

void loop() {
  int m=0;
  for(int i=0;i<4;i++){
    selectMux(s[i]);
    for(int j=0;j<4;j++){
      if(j>i){
        int a=analogRead(pins[j]);
        if(a>1){
          connectedPins[m][0]=i;
          connectedPins[m][1]=j;
          m++;
        }
      }
  }
 }
  for(int i=0; i<m;i++){
    int j=connectedPins[i][0];
    int k=connectedPins[i][1];
    int a=analogRead(pins[j]);
    int b=analogRead(pins[j]);
    float r=Vin*(a-b)/(1024-a);
    float current=(a-b)/r;
    connectedPins[i][2]=findComponent(r);
  } 
  Firebase.setJson(firebaseData,"/FirebaseIOT/Data", a);
}

int findComponent(float r){
  if(r<=3.1 && r>=2.9){
    return 1;
  }
  else if(r<=4.1 && r>=3.9){
    return 2;
  }
  else if(r<=5.1 && r>=4.9){
    return 3;
  }else{
    return 0;
    }
  
 }


void setMux(int i,int j){
  digitalWrite(s1,i);
  digitalWrite(s0,j);
}

void selectMux(String s){
  if(s=='00'){
    setMux(0,0);
  }
  if(s=='01'){
    setMux(0,1);
  }
  if(s=='10'){
    setMux(1,0);
  }
  if(s=='11'){
    setMux(1,1);
  }
}

  
