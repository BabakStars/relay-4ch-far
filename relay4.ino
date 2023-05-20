#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "BABAK";
const char* pass = "1374138319952004bb";
String payload;

bool ch1=false; bool ch2=false; bool ch3=false; bool ch4=false;
ESP8266WebServer server(80);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(ssid,pass);
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  
  digitalWrite(D0,1); 
  digitalWrite(D1,1);
  digitalWrite(D2,1);
  digitalWrite(D3,1);
  
 while(WiFi.status() != WL_CONNECTED)
 {
  delay(250); 
 }
}

void loop() {
  // put your main code here, to run repeatedly:
  //server.handleClient();
  delay(100);
  if(WiFi.status() == WL_CONNECTED)
      {
        HTTPClient http;

            http.begin("http://nbaelectronic.ir/pardis/rr.php");
            http.addHeader("Content-Type","application/x-www-form-urlencoded");
            String ss2 = "pass=pasis12712345678";
            int httpCode = http.POST(ss2);
            if(httpCode > 0)
            {
              payload = http.getString();
              Serial.print("Status: ");
              Serial.println(payload);
              if(payload == "0")
              {
                digitalWrite(D0,1);
                digitalWrite(D1,1);
                digitalWrite(D2,1);
                digitalWrite(D3,1);
              }
              //*********************CH1************
              if(payload == "1")
              {
                digitalWrite(D0,0);
              }
              if(payload == "11")
              {
                digitalWrite(D0,1);
              }
              //*********************CH1************
              //*********************CH2************
              if(payload == "10")
              {
                digitalWrite(D1,0);
              }
              if(payload == "101")
              {
                digitalWrite(D1,1);
              }
              //*********************CH2************
              //*********************CH3************
               if(payload == "100")
              {
                digitalWrite(D2,0);
              }
               if(payload == "110")
              {
                digitalWrite(D2,1);
              }
              //*********************CH3************
              //*********************CH4************              
              if(payload == "1000")
              {
                digitalWrite(D3,0);
              }
              if(payload == "1001")
              {
                digitalWrite(D3,1);
              }
           http.end(); 
      }
}
}
