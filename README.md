# ExampleCode_LineFollowerUSCDAYS

Example code for the USC Days line follower workshop.
Arduino Nano + 5x QRE1113 sensors + DC motors.

## Sketches
| Folder | What it does |
|---|---|
| 01_SensorTest | Prints the 5 sensor values to Serial Monitor |
| 02_MotorTest | Spins the motors forward, backward, left, right |
| 03_LineFollower | Follows a black line |

## Hardware
- Arduino Nano
- 5x QRE1113 reflectance sensors
- TB6612FNG motor driver
- 2x DC motors
- 2x 18650 batteries (in series)

## Pin Connections
| Part | Nano Pin |
|---|---|
| Sensor 1 (far left) | A0 |
| Sensor 2 | A1 |
| Sensor 3 (center) | A2 |
| Sensor 4 | A3 |
| Sensor 5 (far right) | A4 |
| QRE1113 LEDON | D2 |
| TB6612 STBY | D4 |
| Left motor PWMA / AIN1 / AIN2 | D5 / D7 / D8 |
| Right motor PWMB / BIN1 / BIN2 | D6 / D9 / D10 |

## Power
| From | To |
|---|---|
| Battery (+) | Nano VIN, TB6612 VM |
| Battery (-) | Nano GND, TB6612 GND |
| Nano 5V | TB6612 VCC |

## How to Use
1. Install the Arduino IDE
2. Tools > Board > Arduino Nano, and pick your COM port
3. If upload fails: Tools > Processor > ATmega328P (Old Bootloader)
4. Run 01_SensorTest, open Serial Monitor (9600), and note the black and white values
5. Run 02_MotorTest. If a motor spins the wrong way, swap its two wires
6. Set THRESHOLD in 03_LineFollower to a value between black and white, then upload


## Tuning
- Robot is too fast and overshoots: lower FAST
- Doesn't turn enough on curves: lower SLOW (or make it 0)
- Wrong black/white detection: adjust THRESHOLD, or flip `>` to `<` if your sensors read the opposite way