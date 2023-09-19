// Defining the informations to connect with Blynk 

#define BLYNK_TEMPLATE_ID "TMPL2oHzvEd9B"
#define BLYNK_TEMPLATE_NAME "test"
#define BLYNK_AUTH_TOKEN "zBqDQbUYlgFXXa9DtLmDJu3zxGvJ4q88"

// Import all the labraries
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Auhtentification informations with Blynk

char auth[] = "zBqDQbUYlgFXXa9DtLmDJu3zxGvJ4q88";
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

// The state of the LED 
int state = 0;
// The pin number of the LED 
#define pinLed 4
// Create an object of type BlynkerTimer
BlynkTimer timer;

// Predifined function to read instructions from Blynk 
BLYNK_WRITE(V4)
{
  state = param.asInt();
  if(state == 1)
  {
    digitalWrite(pinLed, HIGH);
    Serial.write("LED Stopped...");
    Blynk.virtualWrite(V4,HIGH);
  }else{
    digitalWrite(pinLed, LOW);
    Serial.write("LED Started...");
    Blynk.virtualWrite(V4,LOW);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(pinLed, OUTPUT);
  Blynk.begin(auth,ssid,pass);
}

void loop() {

  Blynk.run();
  timer.run();
}
