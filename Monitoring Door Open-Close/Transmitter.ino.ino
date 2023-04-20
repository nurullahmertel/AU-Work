void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 7, 8 as an input and enable the internal pull-up resistor
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  //read the pushbutton value into a variable
  int sensorVal1 = digitalRead(7);
  int sensorVal2 = digitalRead(8);  
  //print out the value of the pushbutton
  Serial.println(sensorVal1);
  Serial.println(sensorVal2);

  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 11 when the
  // button's pressed, and off when it's not:
  if (sensorVal1 == HIGH) {
    digitalWrite(11, LOW);
  } else {
    digitalWrite(11, HIGH);
  }

  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 12 when the
  // button's pressed, and off when it's not:
  if (sensorVal2 == HIGH) {
    digitalWrite(12, LOW);
  } else {
    digitalWrite(12, HIGH);
  }
}
