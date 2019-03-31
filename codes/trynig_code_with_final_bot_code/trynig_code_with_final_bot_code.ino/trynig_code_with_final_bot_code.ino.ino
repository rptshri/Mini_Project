//#define debug
//////#define debug1
//#define WANT
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

void j()
{
  analogWrite(pwm_2, pwm_high);
  analogWrite(pwm_1, 160);
  forward();
}

void l()
{ analogWrite(pwm_2, pwm_high);
  analogWrite(pwm_1, pwm_high);
  rightBack();
}


void q1()
{ analogWrite(pwm_1, pwm_high);
  analogWrite(pwm_2, pwm_high);
  backward();
}

/////////////////////////////////////////////

unsigned long int val = 0b00111111;

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
    case 0b00101110 : a();
#ifdef WANT
      Serial.println("FORWARD");
#endif

      break;
    //////////////////////////
    case 0b00100110 :  b();
#ifdef WANT
      Serial.println("SLEFT");
#endif
      break;
    //////////////////////////
    case 0b00101101  : c();
#ifdef WANT
      Serial.println("angle3");
#endif
      break;

    case 0b00100111  : c();
#ifdef WANT
      Serial.println("hleft");
#endif
      break;

    case 0b00100011  : b();
#ifdef WANT
      Serial.println("Sleft");
#endif
      break;
    ////////////////////////////////
    case 0b00100001 : c();
#ifdef WANT
      Serial.println("hleft");
#endif
      break;
    /////////////////////////////////
    case 0b00101111 : while (val != 0b00111110 && val != 0b00111100)
      { val = PINB;
        if (val == 0b00111111)
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
    case 0b00101100 : j();
#ifdef WANT
      Serial.println("SRIGHT");
#endif

      break;
    ////////////////////////////////////
    case 0b00111100  : l(); while (val != 0b00111100)
      {
        val = PINB;
        if (val == 0b00111111)
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
    case 0b00110110  : l();
#ifdef WANT
      Serial.println("hRIGHT");
#endif
      break;
    //////////////////////////////////
    case 0b00111000 : b();
#ifdef WANT
      Serial.println("SRIGHT");
#endif
      break;
    //////////////////////////////////
    case 0b00110000 : l();
#ifdef WANT
      Serial.println("hRIGHT");
#endif
      break;
    //////////////////////////////////(2 codes)
    case 0b00111011 : a();
    #ifdef WANT
      Serial.println("2c");
#endif
    break;
    case 0b00111001 : a();
    #ifdef WANT
      Serial.println("2c");
#endif
     break;
    case 0b00110011 : a();
    #ifdef WANT
      Serial.println("2c");
#endif
     break;

    //////////////////////////////////

    case 0b00111110 : while (val != 0b00101111 && val != 0b00100111)
      {
        val = PINB;
        if (val == 0b00111111)
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
    case 0b00111111 : a();
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
