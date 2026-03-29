#include <Arduino.h>

#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif

#include <Firebase_ESP_Client.h>
#include "addons/RTDBHelper.h"

/* WiFi Credentials */
#define WIFI_SSID "wifi"      //  WiFi name
#define WIFI_PASSWORD "pass"  //  WiFi password

/* Firebase Credentials */
#define API_KEY "AlzaSyCxMzC0w3HNuLl5On4fXDFE9eFGlmh3pnw"
#define DATABASE_URL "https://gas-leakage-detection-c3b6e-default-rtdb.asia-southeast1.firebasedatabase.app"

/* Firebase Objects */
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

/* Pin Definitions */
int buzzer = D2;
int sensorPin = A0;
int greenLED = D3;
int blueLED = D1;

/* Threshold */
int sensorThreshold = 250;

void setup() {
  Serial.begin(115200);

  pinMode(buzzer, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(sensorPin, INPUT);

  digitalWrite(greenLED, HIGH);
  digitalWrite(blueLED, LOW);

  /* WiFi Connection */
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }

  Serial.println();
  Serial.print("Connected. IP Address: ");
  Serial.println(WiFi.localIP());

  /* Firebase Setup */
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  Serial.println("Connected to Firebase");
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.print("Gas Sensor Value: ");
  Serial.println(sensorValue);

  if (sensorValue > sensorThreshold) {
    Serial.println("⚠ Gas Detected!");

    digitalWrite(blueLED, HIGH);
    digitalWrite(greenLED, LOW);
    tone(buzzer, 1500);

    Firebase.RTDB.setString(&fbdo, "GLDAS/Status", "Gas Detected");
    Firebase.RTDB.setInt(&fbdo, "GLDAS/SensorValue", sensorValue);
  } 
  else {
    Serial.println("Normal");

    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, LOW);
    noTone(buzzer);

    Firebase.RTDB.setString(&fbdo, "GLDAS/Status", "Normal");
    Firebase.RTDB.setInt(&fbdo, "GLDAS/SensorValue", sensorValue);
  }

  delay(1000);
}
