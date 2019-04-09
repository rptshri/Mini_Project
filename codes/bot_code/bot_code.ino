#define debug
#define debug1
#define WANT
#define pwm_high 255
#define pwm_low 215
const int mod1 = 8;
const int mod2 = 9;
const int mod3 = 10;
const int mod4 = 11;
const int mod5 = 12;
const int pwm_1 = 5;
const int pwm_2 = 6;
const int dir1PinA = 2;
const int dir1PinB = 3;


const int dir2PinA = 4;
const int dir2PinB = 7;


void serialprint()
{

  Serial.println(PINB, BIN);
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
void a()
{
  analogWrite(pwm_1, pwm_high);
  analogWrite(pwm_2, pwm_high);
  forward();
}

void b()
{ analogWrite(pwm_1, pwm_high);
  analogWrite(pwm_2, pwm_low);
  forward();
}
void c()
{ analogWrite(pwm_1, pwm_high);
  analogWrite(pwm_2, pwm_high);
  leftBack();
}
//void d()
//{ analogWrite(pwm_1, pwm_high);
//  analogWrite(pwm_2, pwm_high);
//  leftBack();
//}
//void e()
//{ analogWrite(pwm_1, pwm_high);
//  analogWrite(pwm_2, pwm_high);
//  leftBack();
//}
//void f()
//{ analogWrite(pwm_1, pwm_high);
//  analogWrite(pwm_2, pwm_low);
//  forward();
//}
//void g()
//{ analogWrite(pwm_1, pwm_high);
//  analogWrite(pwm_2, pwm_low);
//  forward();
//}
//void h()
//{ analogWrite(pwm_1, pwm_high);
//  analogWrite(pwm_2, pwm_high);
//  leftBack();
//}
//void i1()
//{
//  analogWrite(pwm_1, pwm_high)  ;
//  analogWrite(pwm_2, pwm_high);
//  leftBack();
//}
void j()
{
  analogWrite(pwm_2, pwm_high);
  analogWrite(pwm_1, 160);
  forward();
}
//void k()
//{ analogWrite(pwm_2, pwm_high);
//  analogWrite(pwm_1, pwm_high);
//  rightBack();
//}
void l()
{ analogWrite(pwm_2, pwm_high);
  analogWrite(pwm_1, pwm_high);
  rightBack();
}
//void m()
//{ analogWrite(pwm_2, pwm_high);
//  analogWrite(pwm_1, pwm_low);
//  forward();
//}
//void n()
//{ analogWrite(pwm_2, pwm_high);
//  analogWrite(pwm_1, pwm_high);
//  rightBack();
//}
//void o()
//{ analogWrite(pwm_2, pwm_high);
//  analogWrite(pwm_1, pwm_high);
//  rightBack();
//}
////void p()
//{ analogWrite(pwm_1, pwm_high);
//  analogWrite(pwm_2, pwm_high);
//  forward();
//}
void q1()
{ analogWrite(pwm_1, pwm_high);
  analogWrite(pwm_2, pwm_high);
  backward();
}

/////////////////////////////////////////////

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

  delay(3000);
}

void loop() {
#ifdef debug
  serialprint();
#endif

  uint8_t val = PINB;

#ifdef debug1
  Serial.println(ch);
#endif

  switch (val)
  { //////////////////////////
    case 0b00110001 : a();
#ifdef WANT
      Serial.println("FORWARD");
#endif

      break;
    //////////////////////////
    case 0b00111001 :  b();
#ifdef WANT
      Serial.println("SLEFT");
#endif
      break;
    //////////////////////////
    case 0b00110010  : c();
#ifdef WANT
      Serial.println("angle3");
#endif
      break;
    ///////////////////////////
    //    case 4  : d();
    //    break;
    case 0b00111000  : c();
#ifdef WANT
      Serial.println("hleft");
#endif
      break;
    /////////////////////////////
    //    case 0b00010011  : f();
    //    break;
    case 0b00111100  : b();
#ifdef WANT
      Serial.println("Sleft");
#endif
      break;
    ////////////////////////////////
    case 0b00111110 : c();
#ifdef WANT
      Serial.println("hleft");
#endif
      break;
    /////////////////////////////////
    case 0b00110000 : while (val != 0b00100001 && val != 0b00100011)
      { val = PINB;
        if (val == 0b00100000)
          break;
        c();
#ifdef WANT
        Serial.println("inside hleft");
#endif
      }
#ifdef WANT
      Serial.println("HARD LEFT");
#endif
      break;
    ////////////////////////////////
    case 0b00110011 : j();
#ifdef WANT
      Serial.println("SRIGHT");
#endif

      break;
    ////////////////////////////////////
    case 0b00100011  : while (val != 0b00100011)
      {
        val = PINB;
        if (val == 0b00100000)
          break;
        l();
#ifdef WANT
        Serial.println("inside hright(2)");
#endif
      }
#ifdef WANT
      Serial.println("hRIGHT");
#endif
      break;
    ///////////////////////////////////
    case 0b00101001  : l();
#ifdef WANT
      Serial.println("hRIGHT");
#endif
      break;
    //////////////////////////////////
    case 0b00100111 : b();
#ifdef WANT
      Serial.println("SRIGHT");
#endif
      break;
    //////////////////////////////////
    case 0b00101111 : l();
#ifdef WANT
      Serial.println("hRIGHT");
#endif
      break;
    //////////////////////////////////

    case 0b00100001 : while (val != 0b00110000 && val != 0b00111000)
      {
        val = PINB;
        if (val == 0b00100000)
          break;
        l();
#ifdef WANT
        Serial.println("inside hright");
#endif
      }
#ifdef WANT
      Serial.println("hRIGHT");
#endif
      break;
    //////////////////////////////////
    case 0b00100000 : a();
#ifdef WANT
      Serial.println("ALL UNDER BLACK");
#endif
      break;
    //////////////////////////////////
    default: a();
#ifdef WANT
      Serial.println("ALL UNDER WHITE");
#endif
      /////////////////////////////////
  }

#ifdef SERIAL_DEBUG
  Serial.print("current state :::   ");
  Serial.println(curstate);
#endif
  delay(0);
}
