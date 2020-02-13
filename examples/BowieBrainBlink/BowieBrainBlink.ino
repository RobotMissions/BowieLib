// Bowie Brain blink test program
// Barebones test, without any libraries
// Run this first to make sure connection with the Teensy 3.6 works properly

int led = 2;
int board_led = 13;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(board_led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);
  digitalWrite(board_led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  digitalWrite(board_led, LOW);
  delay(1000);
}
