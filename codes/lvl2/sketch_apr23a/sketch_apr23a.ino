#define debug
//#define debug1
#define WANT
//#define pwm_high 210
//#define pwm_low 170
//#define pwm_least 140
#define pwm_high 150
#define pwm_low 110
#define pwm_least 70
//const int mod1 = 8;
//const int mod2 = 9;
//const int mod3 = 10;
//const int mod4 = 11;
//const int mod5 = 12;
const int pwm_1 = 5;
const int pwm_2 = 6;
const int dir1PinA = 2;
const int dir1PinB = 3;
const int dir2PinA = 4;
const int dir2PinB = 7;
boolean flag = 0;
boolean blackflag = 0;
int jnCount = 0;
int count = 0;

void serialprint()
{
  //  Serial.println(PINC, BIN);
  Serial.println("_______________________");
  //delay (400);
}


void backward()
{ digitalWrite(4, HIGH);
  digitalWrite(7, LOW );
  digitalWrite(2, LOW );
  digitalWrite(3, HIGH);
}


void forward()
{
  digitalWrite(4, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(2, HIGH );
  digitalWrite(3, LOW);
}

void leftBack()
{
  digitalWrite(4, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(2, HIGH );
  digitalWrite(3, LOW);
}

void rightBack()
{
  digitalWrite(4, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(2, LOW );
  digitalWrite(3, HIGH);
}



////////////////////////////////////////////

unsigned long int val = 0b00000000;

void setup() {

  Serial.begin(9600);

  pinMode(pwm_1, OUTPUT);
  pinMode(pwm_2, OUTPUT);
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(dir1PinB, OUTPUT);
  pinMode(dir2PinB, OUTPUT);
  DDRB = 0x00;

  delay(500);
}

void loop() {

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
  Serial.print("    blackflag:   "); Serial.println(blackflag);


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
        { val = (PINC | 0b00100000);
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