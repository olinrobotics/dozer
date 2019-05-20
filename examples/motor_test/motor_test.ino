#include "Arduino.h"
#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Create new motor shield object
Adafruit_MotorShield motorShield = Adafruit_MotorShield();

// Create new pointers to motorshield motor objects
Adafruit_DCMotor *motor1 = motorShield.getMotor(1);
Adafruit_DCMotor *motor2 = motorShield.getMotor(2);
Adafruit_DCMotor *motor3 = motorShield.getMotor(3);

void setup() {
  // Runs once on startup or reset

  Serial.begin(9600);  // Open serial communication
  motorShield.begin(); // Initialize motor shield

  stopMotors(); // Ensure motors are not moving
  runTest(true);
}

void loop() {
  // Runs as long as robot is running
  // Currently catches in while true loop, so that test only runs once
  while(1);
}

void runTest(bool debug) {
  // Tests motors 1 - 3
  // If debug is true, serial prints

  if(debug) Serial.println("Testing Motor 1: ");
  testMotor(motor1, debug);
  if(debug) Serial.println("Testing Motor 2: ");
  testMotor(motor2, debug);
  if(debug) Serial.println("Testing Motor 3: ");
  testMotor(motor3, debug);

  stopMotors();
}

void testMotor(Adafruit_DCMotor* motor, bool debug) {
  // Sweeps motor through forward and backward full speed range
  // If debug is true, serial prints states

  uint8_t i;

  // Sweep forward speeds
  motor->run(FORWARD);
  if(debug) Serial.println("Test: forward acceleration");
  for (i=0; i<255; i++) {
    motor->setSpeed(i);
    delay(10);
  }

  if(debug) Serial.println("Test: forward decceleration");
  for (i=255; i>0; i--) {
    motor->setSpeed(i);
    delay(10);
  }

  // Sweep backward speeds
  motor->run(BACKWARD);
  if(debug) Serial.println("Test: backward acceleration");
  for (i=0; i<255; i++) {
    motor->setSpeed(i);
    delay(10);
  }
  if(debug) Serial.println("Test: backward decceleration");
  for (i=255; i>0; i--) {
    motor->setSpeed(i);
    delay(10);
  }

  // Stop motor
  motor->run(RELEASE);

}

void stopMotors() {
  // Sets all motor speeds to 0
  motor1->setSpeed(0);
  motor2->setSpeed(0);
  motor3->setSpeed(0);
}
