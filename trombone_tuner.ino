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
    pos = (pos - 1o);

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
