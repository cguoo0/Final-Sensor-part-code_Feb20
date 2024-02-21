#include <Arduino.h>

// Define pins for HC-SR04
const int trigPin = 0;
const int echoPin = 1;

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Define sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Clear the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin HIGH for 10 microseconds to send the pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin and calculate the duration in microseconds
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  // Speed of sound = 34300 cm/s at sea level
  // The time returned is the time it takes to go to the object and back, so we divide by 2
  // 34300 cm/s divided by 2 (back and forth) = 17150 cm/s
  float distance = duration * 0.0343 / 2;

  // Print the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  // Delay 1 second before the next measurement
  delay(1000);
}
