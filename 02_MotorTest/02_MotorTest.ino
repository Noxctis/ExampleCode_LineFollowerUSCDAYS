// Tests both motors with a TB6612FNG: forward, backward, left, right.

const int STBY = 4;
const int PWMA = 5, AIN1 = 7, AIN2 = 8;   // left motor
const int PWMB = 6, BIN1 = 9, BIN2 = 10;  // right motor

void setup() {
  pinMode(STBY, OUTPUT);
  pinMode(PWMA, OUTPUT); pinMode(AIN1, OUTPUT); pinMode(AIN2, OUTPUT);
  pinMode(PWMB, OUTPUT); pinMode(BIN1, OUTPUT); pinMode(BIN2, OUTPUT);
  digitalWrite(STBY, HIGH);               // enable the driver
}

// speed: -255 to 255 (negative = reverse)
void setMotors(int left, int right) {
  digitalWrite(AIN1, left >= 0);
  digitalWrite(AIN2, left < 0);
  analogWrite(PWMA, abs(left));

  digitalWrite(BIN1, right >= 0);
  digitalWrite(BIN2, right < 0);
  analogWrite(PWMB, abs(right));
}

void loop() {
  setMotors(150, 150);   delay(1500);   // forward
  setMotors(0, 0);       delay(500);
  setMotors(-150, -150); delay(1500);   // backward
  setMotors(0, 0);       delay(500);
  setMotors(-150, 150);  delay(1000);   // turn left
  setMotors(0, 0);       delay(500);
  setMotors(150, -150);  delay(1000);   // turn right
  setMotors(0, 0);       delay(2000);
}