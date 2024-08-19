#include <dht11.h>
#define DHT11PIN 4 

dht11 DHT11;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT); 
  pinMode(7,OUTPUT); 
  pinMode(A1,INPUT);
  //pinMode(11,INPUT);

}

void loop() {
  int moistRead;
  int moist;
  int dry;

  int chk = DHT11.read(DHT11PIN);

  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Temperature  (C): ");
  Serial.println((float)DHT11.temperature, 2);
  
  moistRead= analogRead(A1);

  dry = 450;
  moist = 400;
  
  if(moistRead<moist){
    Serial.println("WET");
    digitalWrite(13,LOW);
    digitalWrite(7,LOW);
  }
  else{
    digitalWrite(7,HIGH);
    digitalWrite(13,HIGH);
    Serial.println("DRY");
  }
  Serial.println(moistRead);
  delay(1000);
}
