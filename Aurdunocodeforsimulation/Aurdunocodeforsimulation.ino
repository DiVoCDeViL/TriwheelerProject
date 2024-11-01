#include <math.h>

const int IN1 = 7; // direction controll of Right motor
const int IN2 = 6; // direction controll of Right motor
const int IN3 = 5; // direction controll of left Motor
const int IN4 = 4; // direction controll of Left Motor

const int ENA = 10; // controll the speed of Right Motor
const int ENB = 9; // controll the speed of Left Motor

const int W = 1; // distence between left and right wheel
const int L = 2; // distence between font tyre and back 
int V  = 40; //current speed of the vehicle
int R; //for converting to v
int vRight; // velocity of right tyre
int vLeft; // velocity of left tyre
int ENAInput;// input to ENA for speed controll
int ENBInput;// same as above
int vLow;// constraints to velocity
int vHigh; // constraints to velocity

int potValue;
int theta;
float degreesToRadians(float degrees) {
    return degrees * (PI / 180.0);
}
void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  //analogWrite(ENA, 100);
  //analogWrite(ENB, 250);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  potValue = analogRead(A1);
  theta = map(potValue,0,1023,-45,45);
  R = L/tan(theta);
  //vRight = V/R*(L/tan(degreesToRadians(theta)) - W/2);
  vRight = V * (1 - (W * tan(degreesToRadians(theta))) / (2 * L));
  vLeft = V * (1 + (W * tan(degreesToRadians(theta))) / (2 * L));

  Serial.print("Vl = ");
  Serial.print(vLeft);
  Serial.print("   ");
  Serial.print("Vr = ");
  Serial.println(vRight);
  //Serial.print("steering Angle = ");
  //Serial.println(theta);
  //delay(500);
  vLow = V * (1 - (W * tan(degreesToRadians(45))) / (2 * L));
  vHigh = V * (1 + (W * tan(degreesToRadians(45))) / (2 * L));
  ENAInput = map(vRight, vLow, vHigh, 0, 254);// speed will vary from v-x to v+x 
  ENBInput = map(vLeft, vLow, vHigh, 0, 254);
  analogWrite(ENA, ENAInput);
  analogWrite(ENB, ENBInput);
  //Serial.println(tan(degreesToRadians(45)));
}