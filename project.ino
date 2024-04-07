#include <Blynk.h>

#include <ESP8266WiFi.h>

#define BLYNK_PRINT Serial    
#include <BlynkSimpleEsp8266.h>
char auth[] = "a0tl9-wUE068NVfHzdk4ntna2m2EjTUq";

/* WiFi credentials */
char ssid[] = "....";
char pass[] = "gamegame123";

/* HC-SR501 Motion Detector */
#define ledPin D1 
#define pirPin D2
int pirValue; 
int motionDetected = 0;

void setup()
{
  Serial.begin(115200);
  
  Blynk.begin(auth, ssid, pass);
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  digitalWrite(ledPin, LOW);
}

void loop()
{
  getPirValue();
  Blynk.run();
}


void getPirValue(void)
{
  pirValue = digitalRead(pirPin);
  if (pirValue) .
  { Blynk.email("archit.601@gnail.com", "ESP8266 Alert", "Motion Detected");
    Serial.println("==> Motion detected");
    Blynk.notify(" Motion detected");  
  }
  
  digitalWrite(ledPin, pirValue);
}
