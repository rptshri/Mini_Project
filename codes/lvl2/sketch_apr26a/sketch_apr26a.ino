#include"Bluetooth.h"
//#include"ServoCode.h"


#include <Servo.h>
Servo myservo;
int pos1 = 0;

#define debug
//#define debug1
#define WANT
//#define pwm_high 210
//#define pwm_low 170
//#define pwm_least 140
#define pwm_high 160
#define pwm_low 120
#define pwm_least 70
const int pwm_1 = 5;
const int pwm_2 = 6;
const int dir1PinA = 2;
const int dir1PinB = 3;
const int dir2PinA = 4;
const int dir2PinB = 7;
const int IR = 12;
boolean go = 1;
boolean done = 0;
boolean flag = 0;
boolean Tflag = 0;
boolean Rflag = 0;
boolean Lflag = 0;
boolean blackflag = 0;
boolean Sourceflag = 0;
boolean Destinationflag = 0;
boolean runflag = 0;
int jnCount = 0;
int count = 0;
/////
boolean gotData = 0;
boolean data = 0;
int Sourcedata = 0;
int Destinationdata = 0;
/////
unsigned long int val = 0b00000000;




void serialprint()
{
  //  Serial.println(PINC, BIN);
  Serial.println("_______________________");
  //delay (400);
}


void backward()
{ digitalWrite(4, HIGH);
  digitalWrite(7, LOW );
  digitalWrite(2, HIGH );
  digitalWrite(3, LOW);
}


void forward()
{
  digitalWrite(4, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(2, LOW );
  digitalWrite(3, HIGH);
}

void leftBack()
{
  digitalWrite(4, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(2, LOW );
  digitalWrite(3, HIGH);
}

void rightBack()
{
  digitalWrite(4, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(2, HIGH );
  digitalWrite(3, LOW);
}
void Stop()
{
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  digitalWrite(2, LOW );
  digitalWrite(3, LOW);
}

////////////////////////////////////////////
void ModLeft()
{
  Serial.println("INSIDE MOD LEFT ");
  while (val != 0b00111000)
  {
    val = (PINC | 0b00100000);
    analogWrite(pwm_1, pwm_high);
    analogWrite(pwm_2, pwm_high);
    leftBack();
    Serial.println("inside till left IR on LINE");
  }
  while (val != 0b00110011 )
  {
    val = (PINC | 0b00100000);
    analogWrite(pwm_1, pwm_high);
    analogWrite(pwm_2, pwm_high);
    leftBack();
    Serial.println("inside till all centre1");
  }
  while (val != 0b00110001 )
  { val = (PINC | 0b00100000);
    analogWrite(pwm_1, pwm_high);
    analogWrite(pwm_2, pwm_high);
    leftBack();
    Serial.println("inside till all centre2");
  }
}
////////////////////////////////////////////
void ModRight()
{
  Serial.println("INSIDE MOD Right ");
  while (val != 0b00100011)
  {
    val = (PINC | 0b00100000);
    analogWrite(pwm_1, pwm_high);
    analogWrite(pwm_2, pwm_high);
    rightBack();
    Serial.println("inside till right IR on LINE");
  }
  while (val != 0b00111001 )
  {
    val = (PINC | 0b00100000);
    analogWrite(pwm_1, pwm_high);
    analogWrite(pwm_2, pwm_high);
    rightBack();
    Serial.println("inside till all centre1");
  }
  while (val != 0b00110001 )
  { val = (PINC | 0b00100000);
    analogWrite(pwm_1, pwm_high);
    analogWrite(pwm_2, pwm_high);
    rightBack();
    Serial.println("inside till all centre2");
  }
}

void make180()
{
  while (val != 0b00111001 )
  {
    val = (PINC | 0b00100000);
    analogWrite(pwm_1, pwm_high);
    analogWrite(pwm_2, pwm_high);
    leftBack();
    Serial.println("inside till all centre1");
  }
  while (val != 0b00110001 )
  { val = (PINC | 0b00100000);
    analogWrite(pwm_1, pwm_high);
    analogWrite(pwm_2, pwm_high);
    leftBack();
    Serial.println("inside till all centre2");
  }
}
//////////////////////////////servo///////////////
void sod()
{
  myservo.attach(11);
  delay(100);
  Serial.println("SOD");

  for (pos1 = 122; pos1 >= 45; pos1 -= 2)
  {
    Serial.println(pos1);
    myservo.write(pos1);
    delay(50);
  }
}
/////////////////
void pakad()
{
  myservo.attach(11);
  delay(100);
  Serial.println("PAKAD");
  for (pos1 = 45; pos1 <= 122; pos1 += 2)
  {
    Serial.println(pos1);
    myservo.write(pos1);
    delay(50);
  }
}
//////////////////////////////////////////


void setup() {

  Serial.begin(9600);
  myservo.attach(11);

  pinMode(pwm_1, OUTPUT);
  pinMode(pwm_2, OUTPUT);
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(dir1PinB, OUTPUT);
  pinMode(dir2PinB, OUTPUT);
  pinMode(IR, OUTPUT);
  DDRB = 0x00;
  mySerial.begin(9600);
  mySerial.println("welcome ");
  sod();

  delay(500);
}

void loop()
{

  while (Sourceflag != 1)
  {
    mySerial.println("Enter Source data....");
    delay(500);
    Sourceflag = 0;
    Sourcedata = 0;
    Serial.println("Getting Source Data over BLE.");
    Sourcedata = getData();
    delay(100);
    if (Sourcedata > 0)
    {
      Serial.print("Received Data:  "); Serial.println(Sourcedata);
      Sourceflag = 1;
      gotData = 0;
    }
    data = 0;
  }
  while (Destinationflag != 1)
  {
    mySerial.println("Enter Destination data....");
    delay(500);
    Destinationdata = 0;
    Destinationflag = 0;
    Serial.println("Getting Destination Data over BLE.");
    Destinationdata = getData();
    delay(100);
    if (Destinationdata > 0)
    {
      Serial.print("Received Data:  "); Serial.println(Destinationdata);
      Destinationflag = 1;
      gotData = 1;
    }
    Serial.print("Source Data:  "); Serial.println(Sourcedata);
    Serial.print("Destination Data:  "); Serial.println(Destinationdata);
    delay(2000);
  }

  if (Sourceflag & Destinationflag == 1)
    data = 1;

  //  if (go == 1)                          //
  //  {
  //    Tflag = Sourcedata % 2;
  //  }
  //  else
  //  {
  //    if (Destinationdata > Sourcedata)
  //      Tflag = Destinationdata % 2;
  //    else
  //      Tflag != (Destinationdata % 2);
  //  }

  uint8_t val = PINC;
  val = (PINC | 0b00100000);

#ifdef debug
  Serial.println(val, BIN);
  serialprint();
#endif


  if (flag == 1)
  {
    Serial.println("inside count");
    count = 0;
    jnCount = jnCount + 1;
    flag = 0;
    Serial.print("jnCount:   "); Serial.print(jnCount);
    Serial.print("Count:   "); Serial.println(count);
  }
  count = count + 1;
  if (count >= 10)
    blackflag = 0;

  if (count > 1000)
    count = 0;

  Serial.print("jnCount:   "); Serial.print(jnCount);
  Serial.print("    Count:   "); Serial.print(count);
  Serial.print("    blackflag:   "); Serial.print(blackflag);
  Serial.print("    Rflag:   "); Serial.print(Rflag);
  Serial.print("    Lflag:   "); Serial.println(Lflag);
  Serial.print("    Tflag:   "); Serial.println(Tflag);
  Serial.print("    Dread(IR):   "); Serial.println(digitalRead (IR));

  //  if (jnCount == Sourcedata && done == 0)     //
  //  {
  //    if (Tflag == 1)
  //    {
  //      ModRight();
  //      done = 1;
  //    }
  //    else
  //    { ModLeft();
  //      done = 1;
  //    }
  //  }
  //======================================

  if (Sourcedata == 3 && Destinationdata == 2 )
  {
    if (done == 0)
    {
      if (jnCount == 3)
      {
        ModRight();
        done = 1;
      }
    }
    Tflag = (Destinationdata - jnCount + 1) % 2;
    Serial.print("Tflag     "); Serial.println(Tflag);

    if (runflag == 1)
    {
      if (flag == 1 && Tflag == 1)
      {
        ModLeft();
      }
      if (flag == 1 && Tflag == 0)
      {
        ModRight();
      }
    }
  }
  //==========================================

  if (digitalRead (IR) == 1 && runflag == 0)           //t
  {
    jnCount = 0;
    runflag = 1;
    //    go = 0;
    Stop();
    pakad();
    make180();
  }


  //  if (jnCount == 2 && done == 0)    //
  //  {
  //    done = 0;
  //    Lflag = 1;
  //  }
  //  else
  //  {
  //    Lflag = 0;
  //  }
  //
  //  if (Lflag == 1)
  //  {
  //    ModLeft();
  //    done = 1;
  //  }



  //////////////////////////////////////////////////////////////////////
  if (data == 1)
  {
    switch (val)
    {
      //////////////////////////
      case 0b00110001 : {                   //centre
          analogWrite(pwm_1, pwm_high);
          analogWrite(pwm_2, pwm_high);
          forward();
        };
#ifdef WANT
        Serial.println("FORWARD");
#endif

        break;
      ////////////////////////
      case 0b00111001 :  {                   //soft right
          analogWrite(pwm_1, pwm_low);
          analogWrite(pwm_2, (pwm_high + 10));
          forward();
        };
#ifdef WANT
        Serial.println("SRight");
#endif
        break;

      ///////////////////////////
      case 0b00111000  :                              //right turn1
        {
          Serial.println("right turn 1");
          while (val != 0b00111111 )
          {
            val = (PINC | 0b00100000);
            if (val == 0b00100000 || blackflag == 1)
            {
              break;
            }
            analogWrite(pwm_1, pwm_low);
            analogWrite(pwm_2, pwm_low);
            forward();
            Serial.println("inside till all white");
          }
          while (val != 0b00111001 )
          {
            val = (PINC | 0b00100000);
            if (val == 0b00100000 || blackflag == 1)
            {
              break;
            }
            analogWrite(pwm_1, pwm_high);
            analogWrite(pwm_2, pwm_high);
            rightBack();
            Serial.println("inside till all centre1");

          }
          while (val != 0b00110001 )
          {
            val = (PINC | 0b00100000);
            if (val == 0b00100000 || blackflag == 1)
            {
              break;
            }
            analogWrite(pwm_1, pwm_high);
            analogWrite(pwm_2, pwm_high);
            rightBack();
            Serial.println("inside till all centre2");
          }
        }
#ifdef WANT
        Serial.println("hright");
#endif
        break;
      /////////////////////////////
      case 0b00111100  : {                                  //rightback
          analogWrite(pwm_1, pwm_high);
          analogWrite(pwm_2, pwm_high);
          rightBack();
        };
#ifdef WANT
        Serial.println("Hright");
#endif
        break;
      ////////////////////////////////
      case 0b00111110 : {                               //rightback
          analogWrite(pwm_1, pwm_high);
          analogWrite(pwm_2, pwm_high);
          rightBack();
        };
#ifdef WANT
        Serial.println("hright");
#endif
        break;
      ////////////////////////////////
      case 0b00111101 : {                               //rightback
          analogWrite(pwm_1, pwm_high);
          analogWrite(pwm_2, pwm_high);
          rightBack();
        };
#ifdef WANT
        Serial.println("hright");
#endif
        break;
      ///////////////////////////////
      case 0b00110000 :                             //right turn 2.
        {
          Serial.println("right turn 2 ");
          while (val != 0b00111111 )
          {
            val = (PINC | 0b00100000);
            if (val == 0b00100000 || blackflag == 1)
            {
              break;
            }
            analogWrite(pwm_1, pwm_low);
            analogWrite(pwm_2, pwm_low);
            forward();
            Serial.println("inside till all white");
          }
          while (val != 0b00111001 )
          {
            val = (PINC | 0b00100000);
            if (val == 0b00100000 || blackflag == 1)
            {
              break;
            }
            analogWrite(pwm_1, pwm_high);
            analogWrite(pwm_2, pwm_high);
            rightBack();
            Serial.println("inside till all centre1");

          }
          while (val != 0b00110001 )
          {
            val = (PINC | 0b00100000);
            if (val == 0b00100000 || blackflag == 1)
            {
              break;
            }
            analogWrite(pwm_1, pwm_high);
            analogWrite(pwm_2, pwm_high);
            rightBack();
            Serial.println("inside till all centre2");
          }
        }

#ifdef WANT
        Serial.println("HARD Right");
#endif
        break;

      ////////////////////////////////////        //left codes

      case 0b00110011 : {                       //soft left
          analogWrite(pwm_1, pwm_high);
          analogWrite(pwm_2, pwm_low);
          forward();
        };
#ifdef WANT
        Serial.println("sleft");
#endif
        break;
      //////////////////////////////////
      case 0b00100011  :                         //left turn 1
        {
          Serial.println("left turn 1 ");
          while (val != 0b00111111 )
          {
            val = (PINC | 0b00100000);
            if (val == 0b00100000 || blackflag == 1)
            {
              break;
            }
            analogWrite(pwm_1, pwm_low);
            analogWrite(pwm_2, pwm_low);
            forward();
            Serial.println("inside till all white");
          }
          while (val != 0b00110011 )
          { val = (PINC | 0b00100000);
            if (val == 0b00100000 || blackflag == 1)
            {
              break;
            }
            analogWrite(pwm_1, pwm_high);
            analogWrite(pwm_2, pwm_high);
            leftBack();
            Serial.println("inside till all centre1");
          }
          while (val != 0b00110001 )
          { val = (PINC | 0b00100000);
            if (val == 0b00100000 || blackflag == 1)
            {
              break;
            }
            analogWrite(pwm_1, pwm_high);
            analogWrite(pwm_2, pwm_high);
            leftBack();
            Serial.println("inside till all centre2");
          }
        }
#ifdef WANT
        Serial.println("hleft");
#endif
        break;

      //////////////////////////////////
      case 0b00100111 : {                       //leftback
          analogWrite(pwm_2, pwm_low);
          analogWrite(pwm_1, pwm_high);
          leftBack();
        };
#ifdef WANT
        Serial.println("hleft");
#endif
        break;
      //////////////////////////////////
      case 0b00101111 : {                       //leftback
          analogWrite(pwm_1, pwm_high);
          analogWrite(pwm_2, pwm_low);
          leftBack();
        };
#ifdef WANT
        Serial.println("sleft");
#endif
        break;
      //////////////////////////////////
      case 0b00110111 : {                     //leftback
          analogWrite(pwm_1, pwm_high);
          analogWrite(pwm_2, pwm_low);
          leftBack();
        };
#ifdef WANT
        Serial.println("sleft");
#endif
        break;
      //////////////////////////////////

      case 0b00100001 :                       //left turn 2
        {
          Serial.println("left turn 2 ");
          while (val != 0b00111111 )
          {
            val = (PINC | 0b00100000);
            if (val == 0b00100000 || blackflag == 1)
            {
              break;
            }
            analogWrite(pwm_1, pwm_low);
            analogWrite(pwm_2, pwm_low);
            forward();
            Serial.println("inside till all white");
          }
          while (val != 0b00110011 )
          { val = (PINC | 0b00100000);
            if (val == 0b00100000 || blackflag == 1)
            {
              break;
            }
            analogWrite(pwm_1, pwm_high);
            analogWrite(pwm_2, pwm_high);
            leftBack();
            Serial.println("inside till all centre1");
          }
          while (val != 0b00110001 )
          {
            val = (PINC | 0b00100000);
            if (val == 0b00100000 || blackflag == 1)
            {
              break;
            }
            analogWrite(pwm_1, pwm_high);
            analogWrite(pwm_2, pwm_high);
            leftBack();
            Serial.println("inside till all centre2");
          }
        }
#ifdef WANT
        Serial.println("hleft");
#endif
        break;
      //////////////////////////////////
      case 0b00100000 :
        {
          while (val == 0b00100000)
          {
            Serial.println("ALL UNDER B");
            val = (PINC | 0b00100000);
            blackflag = 1;
            flag = 1;
            analogWrite(pwm_1, pwm_high);
            analogWrite(pwm_2, pwm_high);
            forward();
          }
        };
#ifdef WANT
        Serial.println("ALL UNDER BLACK");
#endif
        break;
      //////////////////////////////////
      default: {
          if (count < 10)
            break;
          analogWrite(pwm_1, pwm_high);
          analogWrite(pwm_2, pwm_high);
          forward();
        };
#ifdef WANT
        Serial.println("Default");
#endif
        break;
        /////////////////////////////////

        /////////////////////////////////

        delay(0);
    }
  }
}
