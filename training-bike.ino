const int controlPin1 = 2; // connected to pin 7 on the H-bridge
const int controlPin2 = 3; // connected to pin 2 on the H-bridge
const int rightSwitchPin = 4;  // connected to the switch for direction
const int leftSwitch = 5; // connected to the switch for turning the motor on and off

int leftSwitchState = LOW;
int rightSwitchState = LOW;

void setup() {
  pinMode(rightSwitchPin, INPUT);
  pinMode(leftSwitch, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);

  //Serial.begin(9600);
}

void loop() {
  leftSwitchState = digitalRead(leftSwitch);
  rightSwitchState = digitalRead(rightSwitchPin);

  if (rightSwitchState == HIGH) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  } else if (leftSwitchState == HIGH) {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  } else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, LOW);    
  }
 
  delay(250);
}
