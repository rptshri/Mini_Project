 
#include <Servo.h>
Servo myservo;   
 
int pos = 0;    

void setup() {
  myservo.attach(8);   
}
void pakad()
{
  for (pos = 90; pos >= 45; pos-=10)
  { 
    myservo.write(pos);             
    delay(150);                      
  }
}
void sod()
{
  for (pos = 45; pos <= 90; pos+=10)
  { 
    myservo.write(pos);             
    delay(150);                      
  }
}
void loop()
{ myservo.write(90); 
  
//  sod();
//  delay(2000);
//  pakad();
//  delay(2000);
 
}
 
