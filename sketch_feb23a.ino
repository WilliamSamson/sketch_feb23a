#define xAxis A0
#define yAxis A1
#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4
#define ENA 9
#define ENB 3

void setup() {
  Serial.begin(9600);
  
  // joystick control
  pinMode(xAxis, INPUT);
  pinMode(yAxis, INPUT);

  // left motor
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // right motor
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // inputs to the motor controller
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
}

void loop() {
  fowardAndBackwardMovement(analogRead(xAxis)); leftAndRightMovement(analogRead(yAxis));
}

void fowardAndBackwardMovement(int xMove) {
  if (xMove <= 450) {
    digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW); digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
    Serial.println("front");
  } else if (xMove > 450 && xMove < 573) {
    digitalWrite(IN1, LOW); digitalWrite(IN2, LOW); digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
  } else {
    digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH); digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
    Serial.println("back");
  }
}

void leftAndRightMovement(int yMove) {
  if (yMove <= 450) {
    digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH); digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
    Serial.println("right");
  } else if (yMove > 450 && yMove < 573) {
    digitalWrite(IN1, LOW); digitalWrite(IN2, LOW); digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
  } else {
    digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW); digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
    Serial.println("left");
  }
}
