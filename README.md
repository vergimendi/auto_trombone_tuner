# Trombone Tuning Slide Servo Controller

This project is a simple system built using an **Arduino** and a **servo motor** to automatically adjust a trombone tuning slide based on light readings from a tuner. The light intensity detected by two **photoresistors** (Flat and Sharp) is used to adjust the position of the tuning slide. 

## Components Used

- **Arduino (Uno or similar)**
- **Servo Motor**
- **Photoresistors (LDRs)**
- **Trombone Tuning Slide**
- **3D Printed Gears and Components** (sourced from online repositories)
- **Breadboard and Wires**
- **Power Source (e.g., battery or USB)**

## Circuit Overview

- **Flat Sensor**: A photoresistor (LDR) placed in the path of the tuner light. It detects whether the trombone is sharp (needs to move down) based on the light intensity.
- **Sharp Sensor**: Another photoresistor placed near the tuner. It detects whether the trombone is flat (needs to move up).
- **Servo**: Controls the movement of the 3D printed gears attached trombone tuning slide by adjusting its position based on the sensor readings.

## Code Explanation

The following Arduino code reads values from two photoresistors (`Flat` and `Sharp`). If the light intensity from the tuner exceeds a specified threshold, the servo adjusts the position of the trombone tuning slide accordingly.

```cpp
#include <Servo.h>
Servo myservo;

int Flat = A0; 
int Sharp = A3;

int threshold = 150; 

const int Maxpos = 180;
const int Minpos = 0;
int pos = 0; 

void setup(){
    Serial.begin(9600); 
    myservo.attach(3);
    myservo.write(pos);
}

void loop(){
  
  int F = analogRead(Flat);
  int S = analogRead(Sharp);
  Serial.println(F);
  Serial.println(S);
  Serial.println(pos);
  delay(100);
   
  if((S > threshold)){
    pos = (pos + 1);
  }

  if((F > threshold)){
    pos = (pos - 1);
  }

  if(pos >= Maxpos) { 
    pos = 180;
  }

  if(pos <= Minpos) {
    pos = 0;
  }

  myservo.write(pos);
  delay(50);
}
