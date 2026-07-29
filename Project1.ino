// Project Industrial Automation Using ESP32

#include <ESP32Servo.h>


Servo servo_pin_14;
int distance = 0;
int mq7val = 0;
int mq6val = 0;

void setup() {
  servo_pin_14.attach(14);
  pinMode(13, INPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  servo_pin_14.write(0);
  pinMode(26, OUTPUT);
  pinMode(25, INPUT);
}

void loop() {
  digitalWrite(12, LOW); delayMicroseconds(2); digitalWrite(12, HIGH); delayMicroseconds(10); digitalWrite(12, LOW);
  long duration_cb_7 = pulseIn(13, HIGH);
  distance = duration_cb_7 * 0.034 / 2;
  Serial.print("distance ");
  Serial.println(distance);
  if (distance < 10) {
    servo_pin_14.write(90);
  } else {
    servo_pin_14.write(0);
  }
  mq7val = analogRead(27);
  Serial.print("mq7val: ");
  Serial.println(mq7val);
  if (mq7val> 2500) {
    digitalWrite(26, HIGH);
    Serial.println("CO detected");
    delay(1000);
  } else {
    digitalWrite(26, LOW);
  }
  mq6val = analogRead(25);
  Serial.print("mq6val: ");
  Serial.println(mq6val);
  if (mq6val > 3100) {
    digitalWrite(26, HIGH);//buzzer
    Serial.println("flamable gass detected");
    delay(1000);
  } else {
    digitalWrite(26, LOW);
  }
  delay(1000);
}