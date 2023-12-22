#include <Servo.h>
#define stepPin 4
#define dirPinmotor 5
#define Lswitch 2

Servo servo;  // create servo object to control a servo
int pos = 50;    // variable to store the servo position 
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
  Serial.begin(115200); 
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
      digitalWrite(dirPinmotor,HIGH);
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
      digitalWrite(dirPinmotor,LOW); // Enables the motor to move in a particular direction
      //Serial.println("COUNTERCLOCKWISE----> ");
      lidar();
      motorstep();  
    
      digitalWrite(dirPinmotor,HIGH); //Changes the rotations direction
      //Serial.println("CLOCKWISE<---- ");
      lidar();

      } 
    
    }



void motorstep(){
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500);  
 }

void lidar(){
  float motor_angle = 0;
  for(int x = 0; x <100;) {
  if (Serial2.available()) {  //check if serial port has data input
    if(Serial2.read() == HEADER) {  //assess data package frame header 0x59
      uart[0]=HEADER;
      if (Serial2.read() == HEADER) { //assess data package frame header 0x59
        uart[1] = HEADER;
        for (i = 2; i < 9; i++) { //save data in array
          uart[i] = Serial2.read();
        }
        check = uart[0] + uart[1] + uart[2] + uart[3] + uart[4] + uart[5] + uart[6] + uart[7];
        if (uart[8] == (check & 0xff)){ //verify the received data as per protocol
          // Cek nilai sudut
          //  if (ams5600.detectMagnet() == 1 ) {
          //   if (angle_in != Angle()) {
          //   angle_in = Angle();
          //   //Serial.print("Sudut = ");
          //   //Serial.println(angle_in);
          // }}

        //  if (motor_angle == 0){
          motor_angle = motor_angle + 1.8;
        //  }
        //  else{
        //    motor_angle = motor_angle - 1.8;
        //  }
          Serial2.print(x); 
          Serial2.print(". Sudut = ");
          Serial2.print(motor_angle);
       
         motorstep();
        

          dist = (uart[2] + uart[3] * 256);     //calculate distance value
          //strength = uart[4] + uart[5] * 256; //calculate signal strength value
          //temprature = uart[6] + uart[7] *256;//calculate chip temprature
          //temprature = temprature/8 - 256;
          Serial.print("  dist = ");
          Serial.println(dist); //output measure distance value of LiDAR
          x++;
      
          // delay(100);
        }
      }
    }
  }
  else{
    Serial2.println("Sensor Not Detected");
    // delay(100);
  }
}
}



