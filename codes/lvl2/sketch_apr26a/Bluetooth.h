#include <SoftwareSerial.h>
#define LED_PIN 13

SoftwareSerial mySerial(9, 8); // RX, TX for arduino
// Connect HM10      Arduino Uno
//     Pin 1/TXD          Pin 8
//     Pin 2/RXD          Pin 9

//boolean gotData = 0;
////////////////////////////////////////////////
void led()
{ int i;
  for (i = 0; i < 5; i++)

  { digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
  }
}

/////////////////////////////////////////////////
int getData()
{
  Serial.println("Inside GetData");
  char c = '0';

  if (mySerial.available() > 0)
  {
    Serial.println("Serial got available.");

    while (c != 'a' || c != 'A' || c != 'b' || c != 'B' || c != 'c' || c != 'C')
    {
      c = mySerial.read();
      Serial.println(c);

      if (c != '0' && c != '\n' && c != '\r' && c != ' ')
      { delay(1);
        // Serial.println("char received");
      }

      if (c == 'a' || c == 'A')
      {
        Serial.println("A received"); led();
        return 1;
      }
      else if (c == 'b' || c == 'B')
      {
        Serial.println("B received"); led();
        return 2;
      }
      else if (c == 'c' || c == 'C')
      {
        Serial.println("C received"); led();
        return 3;
      }

      if ((c >= 14 && c <= 64) || (c >= 73 && c <= 96) || (c >= 104))
      {
        Serial.println("Invalid Input!");
        mySerial.println("Invalid Input!");
      }
    }
  }
}
/////////////////////////////////////////////////
//int getData2()
//{
//  char ch = '0';
//
//  if (mySerial.available() > 0)
//  {
//    ch = mySerial.read();
//    Serial.println(ch);
//
//    if (ch != '0' && ch != '\n' && ch != '\r' && ch != ' ')
//    { delay(1);
//      // Serial.println("char received");
//    }
//
//    if (ch == 'a' || ch == 'A')
//    {
//      Serial.println("A received"); led();
//      return 1;
//    }
//    else if (ch == 'b' || ch == 'B')
//    {
//      Serial.println("B received"); led();
//      return 2;
//    }
//    else if (ch == 'c' || ch == 'C')
//    {
//      Serial.println("C received"); led();
//      return 3;
//    }
//
//    if ((ch >= 14 && ch <= 64) || (ch >= 73 && ch <= 96) || (ch >= 104))
//    {
//      Serial.println("Invalid Input!");
//      mySerial.println("Invalid Input!");
//      getData2();
//    }
//  }
//}
