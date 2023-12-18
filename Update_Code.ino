#include <Servo.h>
#define stepPin 4
#define dirPinmotor 5 
#define Lswitch 2

Servo servo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position 
boolean motorRotated = false;
boolean motorRotated2 = false;

void setup() {
  // Sets the two pins as Outputs
  servo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(Lswitch, INPUT_PULLUP); 
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPinmotor,OUTPUT);
  Serial.begin(250000);
}
void loop() {
{
  while(!motorRotated)
  {
    Serial.println(1);
    if((digitalRead(Lswitch) == HIGH))
    {
      servo.write(pos); 
      digitalWrite(dirPinmotor,LOW);
      motorstep(); 
    } 
     else
    {
     motorRotated = true;
    }
   return;
  }
}

  {
  while(!motorRotated2)
  {
    if(pos<100)
    {
    Serial.println(2);
    if((digitalRead(Lswitch) == HIGH))
    {
      digitalWrite(dirPinmotor,LOW);
      for(int x = 0; x < 100; x++)
      {
        motorstep(); 
      }
      pos += 10;
      servo.write(pos);
      delay(1000);
      Serial.println(pos);
      //servo.write(pos); 
      digitalWrite(dirPinmotor,HIGH);
      for(int x = 0; x < 100; x++)
      {
        motorstep(); 
      } 
      pos += 10;
      servo.write(pos);
      delay(1000);
      Serial.println(pos);
      
    } 
    }
     else
    {
     motorRotated = true;
    }
   return;
  }
}
}

void motorstep(){
  digitalWrite(stepPin,HIGH); 
  delayMicroseconds(500); 
  digitalWrite(stepPin,LOW); 
  delayMicroseconds(500);  
 }