






const int notePinD1 = 8; 
const int notePinE1 = 7; 
const int notePinF1 = 3; 
const int notePinG1 = 6; 
const int notePinA = 9; //or 5
const int notePinB = 4; 
const int notePinC = 2; 
const int notePinD2 = 5; //or 9
const int notePinE2 = 10; 
const int notePinF2 = 11; 
const int notePinG2 = 12;

//don't work: 5,9


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
const int potPin = A0;
int potValue;
int mappedValue;

const int blueLedPin = A1;
const int redLedPin = A3;



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
  
  pinMode(A0,INPUT);
  pinMode(blueLedPin,OUTPUT);
  pinMode(redLedPin,OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));

  lcd.init();
  lcd.backlight();
}


int selectedValue = Letter[0];


int cycle() {
  int randomIndex = random(1,11);
  selectedValue = Letter[randomIndex];
  //Serial.println("cycle function");
  //delay(100);
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





  Serial.println(potValue);


  
  if (a < potValue && potValue < b) {
    
    cycle();
     digitalWrite(redLedPin, LOW);
     digitalWrite(blueLedPin, HIGH);   
     delay(1000);
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
     
  } else{
    digitalWrite(redLedPin,HIGH);
    digitalWrite(blueLedPin,LOW);
  }
 

  lcd.clear();

  if (selectedValue == 1){
  lcd.print("Low D");
  a=152;
  
  }

  if (selectedValue == 2){
  lcd.print("Low E");
  a=154;
  }

  if (selectedValue == 3){
  lcd.print("Low F");
  a=143;
  }

  if (selectedValue == 4){
  lcd.print("Low G");
  a=132;
  }

  if (selectedValue == 5){
  lcd.print("A");
  a=119;
  }

  if (selectedValue == 6){
  lcd.print("B");
  a=104;
  }

  if (selectedValue == 7){
  lcd.print("C");
  a=91;
  }
  
if (selectedValue == 8){
  lcd.print("High D");
  a=81;
  }
  
if (selectedValue == 9){
  lcd.print("High E");
  a=69;
  }
  
if (selectedValue == 10){
  lcd.print("High F");
  a=61;
  }
  
if (selectedValue == 11){
  lcd.print("High G");
  a=54;
  }

b=a+5;
a=a-5;

  delay(100);
}
