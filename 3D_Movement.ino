#include <Servo.h>
#define stepPin 4
#define dirPinmotor 5
#define Lswitch 2

Servo servo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position 
boolean motorRotated = false;
boolean motorRotated2 = false;


int dist; //actual distance measurements of LiDAR
int strength; //signal strength of LiDAR
float temprature;
int check;  //save check value
int i;
int uart[9];  //save data measured by LiDAR
const int HEADER=0x59;  //frame header of data package


void setup()
{
  Serial.begin(9600); 
  Serial2.begin(115200);  //set bit rate of serial port connecting LiDAR with Arduino
  servo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(Lswitch, INPUT_PULLUP);  
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPinmotor,OUTPUT);
}
 
void loop()
{
  while(!motorRotated)
  {
    
    if((digitalRead(Lswitch) == HIGH))
    {
      servo.write(pos); 
      digitalWrite(dirPinmotor,LOW);
      motorstep(); 
      delay(10);
    } 
     else
    {
     motorRotated = true;
    }
   return;
  }


   while(!motorRotated2)
  {
    if(pos < 100)
    {
      digitalWrite(dirPinmotor,HIGH); // Enables the motor to move in a particular direction
      // Makes 200 pulses for making one full cycle rotation
      for(int x = 0; x < 100; x++) 
      {
        Serial.print("kanan, ");
        Serial.print("nilai x: ");
        Serial.println(x);
        motorstep(); 
        // delay(10); // One second delay
      }
      pos += 10;
      servo.write(pos);
      Serial.println(pos);
      //delay(1000);  
    
      digitalWrite(dirPinmotor,LOW); //Changes the rotations direction
      // Makes 400 pulses for making two full cycle rotation
      for(int x = 0; x < 100; x++) 
      {
        Serial.print("kiri, ");
        Serial.print("nilai x: ");
        Serial.println(x);
        motorstep(); 
      }
      pos += 10;
      servo.write(pos);
      Serial.println(pos); 
      //delay(1000);  
      } 
      else
     {
     motorRotated2 = true;
      }
     return;
    }

 }

void motorstep(){
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500);  
 }



