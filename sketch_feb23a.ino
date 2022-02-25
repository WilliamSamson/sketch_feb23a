#define IN1 7 //left motor forward
#define IN2 6 //left motor reverse
#define IN3 5 //right motor forward
#define IN4 4 //right motor reverse
#define ENA 9
#define ENB 3

void setup() {
  // left motor
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // right motor
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // motor controller
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // inputs to the motor controller
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char data = Serial.read(); // data coming from bluetooth

    if (data == 'F') {
      digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW); digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW); // move the motors forward
    } else if (data == 'B') {
      digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH); digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH); // move the motors backward
    } else if (data == 'R') {
      digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW); digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH); // move the left motor forward and the right motor backward
    } else if (data == 'L') {
      digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH); digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW); // move the left motor backward and the right motor forward
    } else {
      digitalWrite(IN1, LOW); digitalWrite(IN2, LOW); digitalWrite(IN3, LOW); digitalWrite(IN4, LOW); // stop all the motors
    }
  }
}
