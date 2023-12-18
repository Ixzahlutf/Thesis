// defines pins
#define stepPin 4
#define dirPin 5 

void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  Serial.begin(250000);
}
void loop() {
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 100; x++) {
    Serial.print("kanan, ");
    Serial.print("nilai x: ");
    Serial.println(x);
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 
   // delay(10); // One second delay
  }
  
  
  digitalWrite(dirPin,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 100; x++) {
    //Serial.print("kiri, ");
    //Serial.print("nilai x: ");
    //Serial.println(x);
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(500);
  }
  delay(1000);
  
}