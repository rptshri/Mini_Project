#define debug
////#define debug1
#define WANT

const int mod1 = 8;
const int mod2 = 9;
const int mod3 = 10;
const int mod4 = 11;
const int mod5 = 12;
const int pwm_1 = 5;
const int pwm_2 = 6;
const int dir1PinA = 2;
const int dir1PinB = 3;
int val1, val2, val3, val4, val5;

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
  analogWrite(pwm_1, 255);
  analogWrite(pwm_2, 255);
  forward();
}

void b()
{ analogWrite(pwm_1, 255);
  analogWrite(pwm_2, 205);
  forward();
}
void c()
{ analogWrite(pwm_1, 255);
  analogWrite(pwm_2, 255);
  leftBack();
}
void d()
{ analogWrite(pwm_1, 255);
  analogWrite(pwm_2, 255);
  leftBack();
}
void e()
{ analogWrite(pwm_1, 255);
  analogWrite(pwm_2, 255);
  leftBack();
}
void f()
{ analogWrite(pwm_1, 255);
  analogWrite(pwm_2, 205);
  forward();
}
void g()
{ analogWrite(pwm_1, 255);
  analogWrite(pwm_2, 205);
  forward();
}
void h()
{ analogWrite(pwm_1, 255);
  analogWrite(pwm_2, 255);
  leftBack();
}
void i1()
{
  analogWrite(pwm_1, 255)  ;
  analogWrite(pwm_2, 255);
  leftBack();
}
void j()
{
  analogWrite(pwm_2, 255);
  analogWrite(pwm_1, 205);
  forward();
}
void k()
{ analogWrite(pwm_2, 255);
  analogWrite(pwm_1, 255);
  rightBack();
}
void l()
{ analogWrite(pwm_2, 255);
  analogWrite(pwm_1, 255);
  rightBack();
}
void m()
{ analogWrite(pwm_2, 255);
  analogWrite(pwm_1, 205);
  forward();
}
void n()
{ analogWrite(pwm_2, 255);
  analogWrite(pwm_1, 255);
  rightBack();
}
void o()
{ analogWrite(pwm_2, 255);
  analogWrite(pwm_1, 255);
  rightBack();
}
void p()
{ analogWrite(pwm_1, 255);
  analogWrite(pwm_2, 255);
  forward();
}
void q1()
{ analogWrite(pwm_1, 255);
  analogWrite(pwm_2, 255);
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
  {
    case 0b00110001 : a();
#ifdef WANT
      Serial.println("FORWARD");
#endif

      break;
    case 0b00111001 :  b();
#ifdef WANT
      Serial.println("SLEFT");
#endif
      break;
    case 0b00110010  : c();
#ifdef WANT
      Serial.println("angle3");
#endif
      break;
    //    case 4  : d();
    //      break;
    case 0b00111000  : e();
#ifdef WANT
      Serial.println("hleft");
#endif
      break;
    //    case 0b00010011  : f();
    //      break;
    case 0b00111100  : g();
#ifdef WANT
      Serial.println("Sleft");
#endif
      break;
    case 0b00111110 : h();
#ifdef WANT
      Serial.println("hleft");
#endif
      break;
    case 0b00110000 : while (val != 0b00110001) {//LEFT
        i1();
        val = PINB;
      }
#ifdef WANT
      Serial.println("HARD LEFT");
#endif
      break;
    case 0b00110011 : j();
#ifdef WANT
      Serial.println("SRIGHT");
#endif

      break;
    case 0b00100011  :  k();
#ifdef WANT
      Serial.println("hRIGHT");
#endif
      break;
    case 0b00101001  : l();
#ifdef WANT
      Serial.println("anglehRIGHT");
#endif
      break;
    case 0b00100111 :       m();

#ifdef WANT
      Serial.println("SRIGHT");
#endif
      break;
    case 0b00101111 :
      n();
#ifdef WANT
      Serial.println("hRIGHT");
#endif
      break;
    case 0b00100001 : while (val != 0b00110001) {//RIGHT
        o();
        val = PINB;
      }
#ifdef WANT
      Serial.println("hRIGHT");
#endif
      break;
    case 0b00100000 : p();
#ifdef WANT
      Serial.println("ALL UNDER BLACK");
#endif
      break;
    default: a();
#ifdef WANT
      Serial.println("ALL UNDER WHITE");
#endif
  }

#ifdef SERIAL_DEBUG
  Serial.print("current state :::   ");
  Serial.println(curstate);
#endif
  delay(0);
}
