#include <Servo.h>
Servo myServo;  

int trigPin = 9;
int echoPin = 10;
long duration;
int distance;

void setup()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    myServo.attach(8);
    Serial.begin(9600);
}

void loop()
{
    for (int pos = 0; pos <= 180; pos += 5) {
      myServo.write(pos);
      delay(15);
      distance = distancer();
      while (distance <= 10) {
        myServo.write(myServo.read());
        distance = distancer();
        delay(100);
      }
    }
  
    for (int pos = 180; pos >= 0; pos -= 5) { 
      myServo.write(pos);
      delay(15);
      distance = distancer();
      while (distance <= 10) {
        myServo.write(myServo.read());
        distance = distancer();
        delay(100);
      }
    }
    Serial.print("distance:");
    Serial.println(distance);
}

int distancer() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}
