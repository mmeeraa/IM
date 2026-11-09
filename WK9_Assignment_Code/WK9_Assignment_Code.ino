int led = 9; // green LED uses pin9
int led2 = 8; // yellow LED uses pin8
int button = 13; // push button uses pin13

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  // using A2, the potentiometer controls the brightness of the green LED connected pin 9
  int potValue = analogRead(A2);
  analogWrite(led, potValue / 4);
  // this checks the potentiometer values from 0 to 1023
  Serial.println(potValue);


  int buttonValue = digitalRead(button);
  // this checks the push button values from 0 to 1
  // added it after the led would not light up after pushing the button
  // wanted to check what was the error and if it was just the LED
  Serial.println(buttonValue); 

  // using the button, 
  if (buttonValue == HIGH) { // if it's pressed, 
    digitalWrite(led2, HIGH); // yellow LED lights up 1
  } else { // if not,
    digitalWrite(led2, LOW); // yellow LED does not light up 0
  }

  delay(30);
}