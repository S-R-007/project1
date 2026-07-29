// LEDs
int LED1 = 12;
int LED2 = 9;
int LED3 = 6;

// IR Sensors
int irSensor1 = 13;
int irSensor2 = 10;
int irSensor3 = 7;

// One common fan
int fan = 11;
int fan2 = 8;
int fan3 = 5;

// Sensor values
bool isValue1 = HIGH;
bool isValue2 = HIGH;
bool isValue3 = HIGH;

void setup()
{
  // LED pins
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  // IR sensor pins
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);
  pinMode(irSensor3, INPUT);

  // Fan pin
  pinMode(fan, OUTPUT);
  pinMode(fan2, OUTPUT);
  pinMode(fan3, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  // Read sensors
  isValue1 = digitalRead(irSensor1);
  isValue2 = digitalRead(irSensor2);
  isValue3 = digitalRead(irSensor3);

  // Sensor 1
  if (isValue1 == LOW)
  {
    Serial.println("Object detected at Sensor 1");
    digitalWrite(LED1, HIGH);
    digitalWrite(fan, HIGH);
  }
  else
  {
    digitalWrite(LED1, LOW);
    digitalWrite(fan, LOW);
  }

  // Sensor 2
  if (isValue2 == LOW)
  {
    Serial.println("Object detected at Sensor 2");
    digitalWrite(LED2, HIGH);
    digitalWrite(fan2, HIGH);
  }
  else
  {
    digitalWrite(LED2, LOW);
    digitalWrite(fan2, LOW);
  }

  // Sensor 3
  if (isValue3 == LOW)
  {
    Serial.println("Object detected at Sensor 3");
    digitalWrite(LED3, HIGH);
    digitalWrite(fan3, HIGH);
  }
  else
  {
    digitalWrite(LED3, LOW);
    digitalWrite(fan3, LOW);
  }

  // Turn ON fan if ANY sensor detects an object
  //if (isValue1 == LOW || isValue2 == LOW || isValue3 == LOW)
  //{
    //digitalWrite(fan, HIGH);
    //Serial.println("Fan ON");
  //}
  //else
  //{
    //digitalWrite(fan, LOW);
    //Serial.println("Fan OFF");
 // }

  delay(200);
}