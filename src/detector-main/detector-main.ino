#include <LiquidCrystal.h>


LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Ultrasonic sensor
const int trigPin = 5;
const int echoPin = 6;

void setup() {
  lcd.begin(16, 2);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.print("Distance:");
}

void loop() {;
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo, with a timeout
  long duration = pulseIn(echoPin, HIGH, 30000);

  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);

  if (duration == 0) {
    lcd.print("Out of range");
  } 
  else {
    // Convert time to centimeters
    float distance = duration * 0.0343 / 2;

    // Reject impossible readings
    if (distance < 2 || distance > 400) {
      lcd.print("Out of range");
    } 
    else {
      lcd.print(distance);
      lcd.print(" cm");
    }
  }

  delay(200);
}