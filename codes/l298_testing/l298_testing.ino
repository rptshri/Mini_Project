
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
  analogWrite(pwm_1, 255);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
}

void motor2_control()
{
  analogWrite(pwm_2, 255);
  digitalWrite(4, LOW );
  digitalWrite(7, HIGH );
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
  motor1_control();
  motor2_control();
}
