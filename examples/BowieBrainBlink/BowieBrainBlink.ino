// Bowie Brain blink test program
// Barebones test, without any libraries
// Run this first to make sure connection with the Teensy 3.6 works properly

int led = 2;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}
