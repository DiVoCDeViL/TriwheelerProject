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

int potValue;
int theta;

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
  vRight = V/R*(L/tan(theta) - W/2);
  vLeft = V/R*(L/tan(theta) + W/2);

  Serial.print("Vr = ");
  Serial.print(vRight);
  Serial.print("   ");
  Serial.print("Vl = ");
  Serial.println(vLeft);
  Serial.print("steering Angle = ");
  Serial.println(theta);
  delay(100);
}