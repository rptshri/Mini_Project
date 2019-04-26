
const int pwm_1 = 5;
const int pwm_2 = 6;
const int dir1PinA = 3;
const int dir1PinB = 2;
const int dir2PinA = 4;
const int dir2PinB = 7;
int pwm_right = 0;
int pwm_left = 0;
int pwm = 0;

#define pwm_high 150
#define pwm_low 100
#define error 0



void motorA_forward()
{
  analogWrite(pwm_1, pwm_high);
  digitalWrite(3, HIGH);
  digitalWrite(2, LOW);
}
void motorA_backward()
{
  analogWrite(pwm_1, pwm_high);
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);
}

void motorB_forward()
{
  analogWrite(pwm_2, pwm_high);
  digitalWrite(4, LOW );
  digitalWrite(7, HIGH );
}
void motorB_backward()
{
  analogWrite(pwm_2, pwm_high);
  digitalWrite(4, HIGH );
  digitalWrite(7, LOW );
}

void setup() {
  Serial.begin(9600);
  pinMode(pwm_1, OUTPUT);
  pinMode(pwm_2, OUTPUT);
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir1PinB, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(dir2PinB, OUTPUT);
  delay(500);
}

void loop() {
  pwm = pwm_high;
  pwm_right = pwm;
  pwm_left = pwm - error;

  motorA_forward();
  motorB_forward();
  delay(5000);

  motorA_backward();
  motorB_backward();
  delay(5000);

  motorA_forward();
  motorB_backward();
  delay(5000);

  motorA_backward();
  motorB_forward();
  delay(5000);
}
