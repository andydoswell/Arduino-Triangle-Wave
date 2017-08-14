/* Simple low frequency triangle wave generator

  Output PWM on pin 9 to LPF.
  Pin 7 has a switch connected to ground to select frequency , approx 0.4Hz or 0.04 Hz
  Pin 8 is high for 0.04Hz, low for 0.4Hz
  Frequency switch is only checked at start up. A reset will be required to change frequency.

*/

int period;

void setup() {
  pinMode (9, OUTPUT);
  pinMode (7, INPUT_PULLUP);
  pinMode (8, OUTPUT);

  if (digitalRead (7) == true) {
    period = 50;
    digitalWrite (8, HIGH);
  }
  else {
    period = 5;
    digitalWrite (8, LOW);
  }
}
void loop() {
  for (int i = 0; i < 256; i++) {
    analogWrite (9, i);
    delay (period);
  }
  for (int i = 255; i > 1; i--) {
    analogWrite (9, i);
    delay (period);
  }
}
