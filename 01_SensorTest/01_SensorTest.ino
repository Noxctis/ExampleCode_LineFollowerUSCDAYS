// Reads the 5 QRE1113 sensors and prints values.
// Use this to see what "black" and "white" look like on your track.

const int LEDON = 2;                          // QRE1113 LEDON pin
const int sensorPins[5] = {A0, A1, A2, A3, A4};

void setup() {
  Serial.begin(9600);
  pinMode(LEDON, OUTPUT);
  digitalWrite(LEDON, HIGH);                  // turn the sensor LEDs on
}

void loop() {
  for (int i = 0; i < 5; i++) {
    Serial.print(analogRead(sensorPins[i]));
    Serial.print("\t");
  }
  Serial.println();
  delay(100);
}