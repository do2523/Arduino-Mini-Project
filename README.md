# Mini Project

## Description
This Arduino project uses a servo motor and an ultrasonic sensor to scan for objects. The servo sweeps from 0 to 180 degrees and back, pausing if an object is detected within 2 inches.

## Components Needed
- Arduino board
- Servo motor
- Ultrasonic sensor (HC-SR04)
- Jumper wires
- Fan

## How It Works
1. The servo sweeps from 0 to 180 degrees.
2. The ultrasonic sensor measures distance.
3. If an object is detected within 2 inches, the servo stops until the object moves away.
4. Distance values are printed to the Serial Monitor.
