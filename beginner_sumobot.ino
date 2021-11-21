//TRACK SENSOR
const int trackingPinA3 = A3;
const int trackingPinA4 = A4;
const int trackingPinA5 = A5;

// IR PROXIMITY SENSOR
#define Analogin0 A0
#define Analogin1 A1
#define Analogin2 A2
#define Digital10 10
#define Digital11 11

// motor 
int ENA = 9;
int IN1 = 8;
int IN2 = 7;
int ENB = 3;
int IN3 = 5;
int IN4 = 4;
int SPEED = 390;

void setup() {
  // put your setup code here, to run once:
// Motor
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(ENA,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
pinMode(ENB,OUTPUT);

// IR SENSOR
pinMode(Analogin0, INPUT_PULLUP);
pinMode(Analogin1, INPUT_PULLUP);
pinMode(Analogin2, INPUT_PULLUP);
pinMode(Digital10, INPUT_PULLUP);
pinMode(Digital11, INPUT_PULLUP);

// TRACK SENSOR
pinMode(trackingPinA3, INPUT); 
pinMode(trackingPinA4, INPUT);
pinMode(trackingPinA5, INPUT);

delay(5000);
startRoutine();

}

void forward()
{
analogWrite(ENA, 390); // setting speed for MOTOR A
analogWrite(ENB, 390); // setting speed for MOTOR B
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
digitalWrite(IN4,LOW);
digitalWrite(IN3,HIGH);
}

void backward()
{
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN4,HIGH);
digitalWrite(IN3,LOW);
}
void cleft()
{
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN4,LOW);
digitalWrite(IN3,HIGH);
}
void cright()
{
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
digitalWrite(IN4,HIGH);
digitalWrite(IN3,LOW);
}
void stop()
{
digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);
}

void startRoutine(){
analogWrite(ENA, 390); // setting speed for MOTOR A
analogWrite(ENB, 390); // setting speed for MOTOR B
//cleft
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN4,LOW);
digitalWrite(IN3,HIGH);
delay(2000);

stop();delay(500);

forward(); delay(1000);

stop();delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
// IR proximity sensor
int Ain0 =digitalRead(Analogin0); // left
int Ain1 =digitalRead(Analogin1); // F left
int Ain2 =digitalRead(Analogin2); // F center
int Dgtl10 =digitalRead(Digital10); // F right
int Dgtl11 =digitalRead(Digital11); // Right 

// Track sensor
boolean TPA3 = digitalRead(trackingPinA3); // right 
boolean TPA4 = digitalRead(trackingPinA4); // front
boolean TPA5 = digitalRead(trackingPinA5); // left

//track
if(TPA4 == LOW){
  backward(); delay(1000);
  stop(); delay(100);
  cleft(); delay(500);
}
else if(TPA3 == LOW){
  backward(); delay(1000);
  stop(); delay(100);
  cleft(); delay(500);
}
else if(TPA5 == LOW){
  backward(); delay(1000);
  stop(); delay(100);
  cright(); delay(500);
}
else {
  forward();
  }
  
//IR
if(Ain2 == 0){
    forward();
//  attack();
  }
  else if(Ain1 == 0){
  forward();
//  attack();
  }
  else if(Dgtl10 == 0){
  forward();
//  attack();
  }
  else if(Ain0 == 0){
  cleft();
  }
  else if(Dgtl11 == 0){ 
  cright();
  }
  else{
  cleft();
  }

}
