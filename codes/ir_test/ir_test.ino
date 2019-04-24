const int mod1 = 8;
const int mod2 = 9;
const int mod3 = 10;
const int mod4 = 11;
const int mod5 = 12;
unsigned long int val = 0b00000000;

void serialprint()
{

  Serial.println(PINB, BIN);
  Serial.println("_______________________");
  //delay (400);
}

void setup() {

  Serial.begin(9600);
  DDRB = 0x00;

  delay(1000);
}

void loop() {

  serialprint();

  uint8_t val = PINB;
  //Serial.println(val);
}
