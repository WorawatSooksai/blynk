#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6fSvQ8J3G"
#define BLYNK_TEMPLATE_NAME "lab5"
#define BLYNK_AUTH_TOKEN "zoIKkIqskCam_UnJl-GHPbNUm_i4a_uO"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Bonezegei_DHT11.h>
Bonezegei_DHT11 dht(D5);
BlynkTimer timer;

char ssid[] = "BuaBiw";
char pass[] = "11111111";
BLYNK_WRITE(V0){
  int pinValue = param.asInt();
  if(pinValue == 1 ){
    digitalWrite(D6,HIGH);
  }else{
    digitalWrite(D6,LOW);
  }
}
void myhumandtemp(){

  if (dht.getData()) {                         // get All data from DHT11
    float tempDeg = dht.getTemperature();
    int hum = dht.getHumidity();
    Blynk.virtualWrite(V1,hum);
    Blynk.virtualWrite(V2,tempDeg);

    }

  
   
}
void setup()
{ 
  pinMode(D6,OUTPUT); 
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  dht.begin();
  timer.setInterval(1000, myhumandtemp);  
}

void loop()
{
  Blynk.run();
  timer.run();
}

