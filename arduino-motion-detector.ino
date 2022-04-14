// PINs in use
#define TRIG_PIN 11       
#define ECHO_PIN 10      
#define BUZZER_PIN 12

// Distance to trigger alarm
#define MIN_DISTANCE 20

long distance;
bool found = false;

void setup() {
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  detectMotion();
  delay(1000);
}

void detectMotion() {
  long duration, distance;

  // Ultrasonic magic with pins
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration / 2) / 29.1;

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
