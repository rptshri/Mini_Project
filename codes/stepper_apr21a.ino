
#include <Servo.h>
Servo myservo;

int pos = 0;

void setup() {
  myservo.attach(11);
  Serial.begin(9600);
}
void sod()
{
  Serial.println("SOD");
  for (pos = 122; pos >= 45; pos -= 2)
  {
    myservo.write(pos);
    delay(50);
  }
}
void pakad()
{ Serial.println("PAKAD");
  for (pos = 45; pos <= 122; pos += 2)
  {
    myservo.write(pos);
    delay(50);
  }
}
void loop()
{
  //  myservo.write(90);

  sod();
  delay(2000);
  pakad();
  delay(2000);

}
