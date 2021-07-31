#include "FirebaseESP8266.h"  // Install Firebase ESP8266 library
#include <ESP8266WiFi.h>


#define FIREBASE_HOST "local-iterator-273207-default-rtdb.firebaseio.com" //Without http:// or https:// schemes
#define FIREBASE_AUTH "XOPZJCNGbkojHryHRQwMms6FLafwd54q1KHLNBsM"
#define WIFI_SSID "Venu"
#define WIFI_PASSWORD "9849641927"

//Define FirebaseESP8266 data object
FirebaseData firebaseData;
FirebaseData ledData;

FirebaseJson json1;

void setup() {
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);

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

void loop() 
{ String data=Firebase.getString(firebaseData,"/FirebaseIOT/Data")
  int X[4][3];
  int Y[4][3];
  int Z[4][4];
  int row,i,a,b,m,n,p,q,c;
  for(row=0;row<10;row++)
  {
    a =2,b=3,c=2;
    switch(c)
    {case 1 : p=0,q=1;
     case 2 : p=1,q=0;
     case 3 : p=1,q=1;
    }
    m=a-1;
    n=(a-1)+(b-a-1);
    for(i=m;i<=n;i++)
      {if(i==m)
        {X [row][i] = p;}
       else
       {X [row] [i] = 1;
      }
    for(i=m;i<=n;i++)
      {if(i==m)
        {Y [row][i] = q;}
       else
       {Y [row] [i] = 1;
      }

    Z[row][m] =1;
    Z[row][n] =1;
  } 
  for(int j=0;j<3;j++)
  { 
  digitalWrite(A0,X[0][j]);
  digitalWrite(A1,Y[0][j]);
  digitalWrite(A2,X[1][j]);
  digitalWrite(A3,Y[1][j]);
  digitalWrite(A4,X[2][j]);
  digitalWrite(A5,Y[2][j]);
  digitalWrite(A6,X[3][j]);
  digitalWrite(A7,Y[4][j]);
  delay(1000);
  }}}
}
