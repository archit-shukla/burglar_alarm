#include <Blynk.h>

/**************************************************************
 * IoT Motion Detector with Blynk
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 * 
 * Developed by Marcelo Rovai - 30 November 2016
 **************************************************************/
#include <ESP8266WiFi.h>

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <BlynkSimpleEsp8266.h>
char auth[] = "a0tl9-wUE068NVfHzdk4ntna2m2EjTUq";

/* WiFi credentials */
char ssid[] = "vivo 1851";
char pass[] = "12345677";

/* HC-SR501 Motion Detector */
#define ledPin D1 
#define pirPin D2 // Input for HC-S501
int pirValue; // Place to store read PIR Value
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

  Blynk.run();
  getPirValue(); 
}

/***************************************************
 * Get PIR data
 **************************************************/
void getPirValue(void)
{
  pirValue = digitalRead(pirPin);
  if (pirValue) 
  { Blynk.email("archit.601@gnail.com", "ESP8266 Alert", "Motion Detected");
    Serial.println("==> Motion detected");
    Blynk.notify("T==> Motion detected");
    
  }
  digitalWrite(ledPin, pirValue);  
  
}
