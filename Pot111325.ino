






const int notePinD1 = 12;
const int notePinE1 = 11;
const int notePinF1 = 10;
const int notePinG1 = 9;
const int notePinA = 8;
const int notePinB = 7;
const int notePinC = 6;
const int notePinD2 = 5;
const int notePinE2 = 4;
const int notePinF2 = 3;
const int notePinG2 = 2;


// keep your button pin
const int buttonPin = 13;



#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

//const int trigPin = 9;
//const int echoPin = 10;

//float duration, distance;

int Letter[] = {1,2,3,4,5,6,7,8,9,10,11};


float a=8;
float b = a+4;

//integers for potentiometer
const int potPin = A1;
int potValue;
int mappedValue;

const int redLedPin = 0;
const int blueLedPin = 1;



void setup() {


pinMode(buttonPin, INPUT_PULLUP);

pinMode(notePinD1, OUTPUT);
pinMode(notePinE1, OUTPUT);
pinMode(notePinF1, OUTPUT);
pinMode(notePinG1, OUTPUT);
pinMode(notePinA, OUTPUT);
pinMode(notePinB, OUTPUT);
pinMode(notePinC, OUTPUT);
pinMode(notePinD2, OUTPUT);
pinMode(notePinE2, OUTPUT);
pinMode(notePinF2, OUTPUT);
pinMode(notePinG2, OUTPUT);

digitalWrite(notePinD1, LOW);
digitalWrite(notePinE1, LOW);
digitalWrite(notePinF1, LOW);
digitalWrite(notePinG1, LOW);
digitalWrite(notePinA, LOW);
digitalWrite(notePinB, LOW);
digitalWrite(notePinC, LOW);
digitalWrite(notePinD2, LOW);
digitalWrite(notePinE2, LOW);
digitalWrite(notePinF2, LOW);
digitalWrite(notePinG2, LOW);

    
  //potentiometer serial reading
  Serial.begin(9600);
  
  //pinMode(trigPin, OUTPUT);
  //pinMode(echoPin, INPUT);
  pinMode(A1,INPUT);
  pinMode(blueLedPin,OUTPUT);
  pinMode(redLedPin,OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));

  lcd.init();
  lcd.backlight();


  //lcd.print("Hello World!");
}

int selectedValue = Letter[0];



int cycle() {
  int randomIndex = random(0,10);
  selectedValue = Letter[randomIndex];
  //Serial.println("cycle function");
  delay(1000);
  //Serial.println(selectedValue);
  return randomIndex;
  
}




void loop() {


  //potentiometer reading thorugh serial
  potValue = analogRead(potPin);






if (digitalRead(buttonPin) == LOW) {
  if (selectedValue == 1) digitalWrite(notePinD1, HIGH);
  if (selectedValue == 2) digitalWrite(notePinE1, HIGH);
  if (selectedValue == 3) digitalWrite(notePinF1, HIGH);
  if (selectedValue == 4) digitalWrite(notePinG1, HIGH);
  if (selectedValue == 5) digitalWrite(notePinA, HIGH);
  if (selectedValue == 6) digitalWrite(notePinB, HIGH);
  if (selectedValue == 7) digitalWrite(notePinC, HIGH);
  if (selectedValue == 8) digitalWrite(notePinD2, HIGH);
  if (selectedValue == 9) digitalWrite(notePinE2, HIGH);
  if (selectedValue == 10) digitalWrite(notePinF2, HIGH);
  if (selectedValue == 11) digitalWrite(notePinG2, HIGH);
 
}

if (a < potValue && potValue < b) {
  digitalWrite(notePinD1, LOW);
  digitalWrite(notePinE1, LOW);
  digitalWrite(notePinF1, LOW);
  digitalWrite(notePinG1, LOW);
  digitalWrite(notePinA, LOW);
  digitalWrite(notePinB, LOW);
  digitalWrite(notePinC, LOW);
  digitalWrite(notePinD2, LOW);
  digitalWrite(notePinE2, LOW);
  digitalWrite(notePinF2, LOW);
  digitalWrite(notePinG2, LOW);
  
  cycle();
}





  
    //Ultrasonic Sensor Code
  //digitalWrite(trigPin, LOW);
  //delayMicroseconds(2);
  //digitalWrite(trigPin, HIGH);
  //delayMicroseconds(10);
  //digitalWrite(trigPin, LOW);

  //duration = pulseIn(echoPin, HIGH);
  //distance = (duration*.0343)/2; 
  //Serial.print("Distance: ");
  //Serial.println(distance);
  //delay(100);


  Serial.println(potValue);

  //Serial.println("before if statement");
  if (a < potValue && potValue < b) {
    //Serial.println("if statement is true");
    digitalWrite(blueLedPin,LOW);
    digitalWrite(redLedPin,HIGH);
    cycle();
    //Serial.println(selectedValue);
  } else{
    digitalWrite(blueLedPin,HIGH);
    digitalWrite(redLedPin,LOW);
  }
 

  //Serial.println(selectedValue);
  lcd.clear();

  if (selectedValue == 1){
  lcd.print("Low D");
  a=89;
  
  }

  if (selectedValue == 2){
  lcd.print("Low E");
  a=100;
  }

  if (selectedValue == 3){
  lcd.print("Low F");
  a=114;
  }

  if (selectedValue == 4){
  lcd.print("Low G");
  a=126;
  }

  if (selectedValue == 5){
  lcd.print("A");
  a=139;
  }

  if (selectedValue == 6){
  lcd.print("B");
  a=149;
  }

  if (selectedValue == 7){
  lcd.print("C");
  a=155;
  }
  
if (selectedValue == 8){
  lcd.print("High D");
  a=155;
  }
  
if (selectedValue == 9){
  lcd.print("High E");
  a=155;
  }
  
if (selectedValue == 10){
  lcd.print("High F");
  a=155;
  }
  
if (selectedValue == 11){
  lcd.print("High G");
  a=155;
  }

b=a+3;
a=a-3;

  //Serial.print("Range: (");
  //Serial.print(a);
  //Serial.print(",");
  //Serial.print(b);
  //Serial.println(")");

  delay(100);
}
