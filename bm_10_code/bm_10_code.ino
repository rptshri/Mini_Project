#include <SoftwareSerial.h>
#define LED_PIN 13

SoftwareSerial mySerial(8, 9); // RX, TX for arduino
// Connect HM10      Arduino Uno
//     Pin 1/TXD          Pin 8
//     Pin 2/RXD          Pin 9

  
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  mySerial.begin(9600);
  mySerial.println("welcome ");
}

void loop()
{
  char c;

  if (mySerial.available()) 
  {
    c = mySerial.read();
   


        if (c != '0' && c != '\n' && c != '\r'&& c!=' ')
        {delay(1);
        // Serial.println("char received");
        }

    if (c == 'a' || c == 'A')
    {
      Serial.println("A received");led();
    }
    else if (c == 'b' || c == 'B')
    {
      Serial.println("B received");led();
    }
    else if (c == 'c' || c == 'C')
    {
      Serial.println("C received");led();
    }
    else if (c == 'd' || c == 'D')
    {
      Serial.println("D received");led();
    }
    else if (c == 'E' || c == 'e')
    {
      Serial.println("E received");led();
    }
    else if (c == 'F' || c == 'f')
    {
      Serial.println("f received");led();
    }
    else if (c == 'g' || c == 'G')
    {
      Serial.println("G received");led();
    }

//    else 
//    {
      if ((c >= 14 && c <= 64)||(c >=73 && c <= 96)||(c>=104))
      {
        Serial.println("Invalid Input!");
        mySerial.println("Invalid Input!");
      }
//      //  mySerial.println("Invalid Input!");
//        if (c >=67 && c <= 96) 
//        Serial.println("Invalid Input!");
//       // mySerial.println("Invalid Input!");
//        if (c>=104)
//         Serial.println("Invalid Input!");
//        // mySerial.println("Invalid Input!");
//    }
    }

  }


void led()
{int i;
  for (i=0;i<5;i++)

{digitalWrite(LED_PIN, HIGH);
delay(50);
digitalWrite(LED_PIN,LOW);
delay(50);}
}
