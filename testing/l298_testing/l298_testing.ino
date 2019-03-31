
const int pwm_1 = 5;
const int pwm_2 = 6;
const int dir1PinA = 3;
const int dir1PinB = 2;
const int dir2PinA = 4;
const int dir2PinB = 7;
int pwm_right = 0;
int pwm_left = 0;
int pwm = 0;

#define pwm_high 200
#define pwm_low 200
#define error 0



void motor1_control()
{
  analogWrite(pwm_1, pwm_right);
  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir1PinB, LOW);
}

void motor2_control()
{
  analogWrite(pwm_2, pwm_left);
  digitalWrite(dir2PinA, HIGH );
  digitalWrite(dir2PinB, LOW );
}
//----------------------------
void BOT_rev()
{
  analogWrite(pwm_1, pwm_right);
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir1PinB, HIGH);
  analogWrite(pwm_2, pwm_left);
  digitalWrite(dir2PinA, LOW );
  digitalWrite(dir2PinB, HIGH );
}


void bot_RR()
{
  analogWrite(pwm_1, pwm_right);
  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir1PinB, LOW);
  analogWrite(pwm_2, pwm_left);
  digitalWrite(dir2PinA, LOW );
  digitalWrite(dir2PinB, HIGH );
}

void bot_RL()
{ analogWrite(pwm_2, pwm_left);
  analogWrite(pwm_1, pwm_right);
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir1PinB, HIGH);
  analogWrite(pwm_2, pwm_left);
  digitalWrite(dir2PinA, HIGH );
  digitalWrite(dir2PinB, LOW );
}
void bot_WAIT()
{ analogWrite(pwm_2,0);
  analogWrite(pwm_1,0);
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir1PinB, HIGH);
  analogWrite(pwm_2, pwm_left);
  digitalWrite(dir2PinA, HIGH );
  digitalWrite(dir2PinB, LOW );
  delay(250);
}
//----------------------------

void setup() 
{
  Serial.begin(9600);
  pinMode(pwm_1, OUTPUT);
  pinMode(pwm_2, OUTPUT);
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir1PinB, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(dir2PinB, OUTPUT);
  delay(500);
}

void loop() 
{
  //pwm = pwm_high;
  pwm_right = 255;//pwm;
  pwm_left = 255; //pwm - error;
  motor1_control();
  motor2_control();
  delay(3000);
  bot_RL();
  delay(2000);
  bot_WAIT();
  bot_RR();
  delay(2000);
  bot_WAIT();
  BOT_rev();
  delay(3000);
}

 
