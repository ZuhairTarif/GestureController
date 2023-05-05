#include "Keyboard.h"

void setup() {
  Serial.begin (9600);

  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {

  int accelerator = analogRead(A0); //Flex Sensor 1
  int brake = analogRead(A1); //Flex Sensor 2
  int x = analogRead(A4); // ADXL335 x
  int y = analogRead(A5); // ADXL335 y

  if (accelerator > 450 ) {
    Keyboard.write('W');
    delay(10);
  }
  if (brake > 400 ) {
    Keyboard.write('S');
    delay(10);
  }
  if (x < 330) { //RIGHT
    Keyboard.press('R');
    delay(250);
    Keyboard.releaseAll();
  }
  if (y < 380) { //LEFT
    Keyboard.press('L');
    delay(250);
    Keyboard.releaseAll();
  }
}
