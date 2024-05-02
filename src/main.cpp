#include <Arduino.h>

void setup()
{
  // Initialize LED pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // Set the LED HIGH
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("Light is on");

  // Wait for a second
  delay(1000);

  // Set the LED LOW
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("Light is off");

   // Wait for a second
  delay(1000);
}