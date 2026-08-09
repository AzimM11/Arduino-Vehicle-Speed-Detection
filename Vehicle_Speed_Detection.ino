#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD: I2C address 0x27, 16 columns, 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin connections
const int IR_SENSOR_1 = 2;
const int IR_SENSOR_2 = 3;
const int BUZZER = 11;

// Actual distance between the two IR sensors
const float SENSOR_DISTANCE = 0.20;  // 20 cm = 0.20 m

// Overspeed limit
const float SPEED_LIMIT = 50.0;      // km/h

unsigned long timer1 = 0;
unsigned long timer2 = 0;

bool sensor1Detected = false;
bool sensor2Detected = false;

float speedKmph = 0.0;

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  pinMode(IR_SENSOR_1, INPUT);
  pinMode(IR_SENSOR_2, INPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(BUZZER, LOW);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WELCOME TO");

  lcd.setCursor(0, 1);
  lcd.print("AZIM PROJECT");

  delay(2000);
  lcd.clear();
}

void loop() {

  // Sensor 1 detects the vehicle
  if (digitalRead(IR_SENSOR_1) == LOW && !sensor1Detected) {
    timer1 = millis();
    sensor1Detected = true;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Vehicle Detected");
    lcd.setCursor(0, 1);
    lcd.print("Measuring...");
  }

  // Sensor 2 detects the vehicle
  if (digitalRead(IR_SENSOR_2) == LOW &&
      sensor1Detected && !sensor2Detected) {

    timer2 = millis();
    sensor2Detected = true;

    // Calculate time in seconds
    float timeSeconds = (timer2 - timer1) / 1000.0;

    // Calculate speed in m/s
    float speedMs = SENSOR_DISTANCE / timeSeconds;

    // Convert m/s to km/h
    speedKmph = speedMs * 3.6;

    // Display speed
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Speed: ");
    lcd.print(speedKmph, 1);
    lcd.print(" Km/H");

    lcd.setCursor(0, 1);

    // Overspeed detection
    if (speedKmph > SPEED_LIMIT) {
      lcd.print("OVER SPEEDING");
      digitalWrite(BUZZER, HIGH);
      Serial.println("OVER SPEEDING!");
    }
    else {
      lcd.print("NORMAL SPEED");
      digitalWrite(BUZZER, LOW);
      Serial.println("Normal Speed");
    }

    Serial.print("Speed: ");
    Serial.print(speedKmph, 2);
    Serial.println(" km/h");

    delay(3000);

    digitalWrite(BUZZER, LOW);

    // Reset for next vehicle
    sensor1Detected = false;
    sensor2Detected = false;
    speedKmph = 0.0;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No Car Detected");
  }

  // Waiting for a vehicle
  if (!sensor1Detected && !sensor2Detected) {
    lcd.setCursor(0, 0);
    lcd.print("Vehicle Speed");
    lcd.setCursor(0, 1);
    lcd.print("Waiting...     ");
  }

  delay(50);
}
