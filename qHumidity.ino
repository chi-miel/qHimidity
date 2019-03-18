
// Example testing sketch for various DHT humidity/temperature sensors

// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"
#include <Adafruit_Sensor.h>
#include <rgb_lcd.h>

rgb_lcd ecran;

boolean alert = false;
float thresholdH = 40.00;
float thresholdT = 50.00;

int light = 100;

int sensorPin = 7;
int sensorValue;
int lastState = 0;
int currentState = 0;

#define DHTPIN 4     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11 Humidity Captor

// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println(F("DHTxx test!"));

  dht.begin();

  ecran.begin(16,2);

  pinMode(sensorPin, OUTPUT);
  digitalWrite(sensorPin, HIGH);
  
}

void loop() {
  // Wait a few seconds between measurements.
  delay(1000);
  ecran.clear();

  //Light captor value
  int valeur = analogRead(A3);

  // security
  sensorValue = digitalRead(sensorPin);
  currentState = sensorValue;
  if(currentState != lastState) {
    ecran.print("Box's Moving!!");
    delay(5000);
  }
  
  //debug
  //Serial.println(sensorValue);
  lastState = sensorValue;
  
  while (valeur > light) {
    ecran.clear();
    ecran.print("Box open !!!!");
    valeur = analogRead(A3);
    delay(1000);
  }

  // Reading temperature or humidity takes about 250 milliseconds!
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Check sensor value

  if (h > thresholdH) {
    ecran.setCursor(0,0);
    ecran.print("Alert H :");
    ecran.print(h);
    alert=true;
    //send mail alert 
  }

  if (t > thresholdT) {
    ecran.setCursor(0,1);
    ecran.print("Alert T :");
    ecran.print(t);
    ecran.print(" C");
    alert=true;
    //send mail alert
  }

  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(hic);
  Serial.print(F("°C "));

  if (alert==false) {
    ecran.clear();
    ecran.setCursor(0,0);
    ecran.print(F("H:"));
    ecran.print(h);
    ecran.print("%");
    ecran.print(F("T:"));
    ecran.print(t);
    ecran.print("C");
    ecran.setCursor(0,1);
    ecran.print("Lum:");
    ecran.print(valeur);
  }

  
}
