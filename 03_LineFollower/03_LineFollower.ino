// Simple line follower: 5 QRE1113 sensors, Arduino Nano, TB6612FNG.
// Rule: if the line is on the left, turn left. If on the right, turn right.

const int LEDON = 2;
const int sensorPins[5] = {A0, A1, A2, A3, A4};   // far left ... far right

const int STBY = 4;
const int PWMA = 5, AIN1 = 7, AIN2 = 8;           // left motor
const int PWMB = 6, BIN1 = 9, BIN2 = 10;          // right motor

int THRESHOLD = 500;    // above this = black line (check with 01_SensorTest)
int FAST = 150;         // fast wheel
int SLOW = 60;          // slow wheel when turning gently

void setup() {
  pinMode(LEDON, OUTPUT);
  digitalWrite(LEDON, HIGH);                      // sensor LEDs on

  pinMode(STBY, OUTPUT);
  pinMode(PWMA, OUTPUT); pinMode(AIN1, OUTPUT); pinMode(AIN2, OUTPUT);
  pinMode(PWMB, OUTPUT); pinMode(BIN1, OUTPUT); pinMode(BIN2, OUTPUT);
  digitalWrite(STBY, HIGH);                       // enable the driver
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
  // 1 = sensor sees black, 0 = sees white
  bool s0 = analogRead(sensorPins[0]) > THRESHOLD;   // far left
  bool s1 = analogRead(sensorPins[1]) > THRESHOLD;
  bool s2 = analogRead(sensorPins[2]) > THRESHOLD;   // center
  bool s3 = analogRead(sensorPins[3]) > THRESHOLD;
  bool s4 = analogRead(sensorPins[4]) > THRESHOLD;   // far right

  if (s2) {
    setMotors(FAST, FAST);          // line in the middle: go straight
  }
  else if (s1) {
    setMotors(SLOW, FAST);          // line slightly left: turn left a bit
  }
  else if (s3) {
    setMotors(FAST, SLOW);          // line slightly right: turn right a bit
  }
  else if (s0) {
    setMotors(-SLOW, FAST);         // line far left: sharp left
  }
  else if (s4) {
    setMotors(FAST, -SLOW);         // line far right: sharp right
  }
  else {
    setMotors(0, 0);                // no line found: stop
  }
}