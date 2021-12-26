#include "SR04.h"

// PINs in use
#define TRIG_PIN 11       
#define ECHO_PIN 10      
#define BUZZER_PIN 12

// Distance to trigger alarm
#define MIN_DISTANCE 20

long distance;
bool found = false;

// Ultrasonic vars
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);

void setup() {
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  detectMotion();
  delay(1000);
}

void detectMotion() {
  distance = sr04.Distance();
  if (distance < MIN_DISTANCE) {
    found = true;
    Serial.print("Motion detected! Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    startAlarm();
  } else if (found) {
    found = false;
    Serial.println("No motion");
  }
}

void startAlarm() {
  tone(BUZZER_PIN, 1000, 500);
  delay(1);
}
