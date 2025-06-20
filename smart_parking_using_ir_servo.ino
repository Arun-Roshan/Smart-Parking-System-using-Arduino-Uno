#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1  
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pin definitions
const int irSensorPin = 2;
const int redLedPin = 3;
const int greenLedPin = 4;
const int servoPin = 9;

Servo gateServo;

void setup() {
  pinMode(irSensorPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  gateServo.attach(servoPin);
  gateServo.write(45);  // Start at 45° (gate closed)

  // OLED setup
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(10, 20);
  display.println("System Initializing...");
  display.display();
  delay(2000);
}

void loop() {
  int sensorValue = digitalRead(irSensorPin);

  if (sensorValue == LOW) {
    // Object detected
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    
    gateServo.write(0);  // Open gate (move to 0°)

    display.clearDisplay();
    display.setCursor(0, 10);
    display.println("Vehicle Detected");
    display.setCursor(0, 25);
    display.println("Gate Opening...");
    display.display();

    delay(3000);  // Keep gate open

    gateServo.write(45);  // Close gate (move back to 45°)
    delay(1000);
  }
  else {
    // No object
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    
    gateServo.write(45);  // Ensure gate is in closed position

    display.clearDisplay();
    display.setCursor(10, 20);
    display.println("Parking Available");
    display.display();
  }

  delay(200); // Sensor debounce
}

