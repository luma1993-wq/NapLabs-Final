#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 9;
const int echoPin = 10;

float duration, distance;

int Letter[] = {1,2,3,4,5,6,7};
// char letter[] = {"C","D","E","F","G", "A","B"}

float a=8;
float b = a+4;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));

  lcd.init();
  lcd.backlight();


  lcd.print("Hello World!");
}

int selectedValue = Letter[0];

void cycle() {
  int randomIndex = random(0,7);
  selectedValue = Letter[randomIndex];
  Serial.println("cycle function");
  delay(1000);
  Serial.println(selectedValue);
  return randomIndex;
  
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2; 
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);

  //Serial.println("before if statement");
  if (a < distance && distance < b) {
    //Serial.println("if statement is true");
    digitalWrite(13,LOW);
    digitalWrite(12,HIGH);
    cycle();
    //Serial.println(selectedValue);
  } else{
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
  }
 

  //Serial.println(selectedValue);
  lcd.clear();

  if (selectedValue == 1){
  lcd.print("A");
  a=14.25;
  
  }

  if (selectedValue == 2){
  lcd.print("B");
  a=12.5;
  }

  if (selectedValue == 3){
  lcd.print("C");
  a=11.5;
  }

  if (selectedValue == 4){
  lcd.print("D");
  a=9;
  }

  if (selectedValue == 5){
  lcd.print("E");
  a=6;
  }

  if (selectedValue == 6){
  lcd.print("F");
  a=17;
  }

  if (selectedValue == 7){
  lcd.print("G");
  a=16.25;
  }

a=a-.5;
b=a+1;

  Serial.print("Range: (");
  Serial.print(a);
  Serial.print(",");
  Serial.print(b);
  Serial.println(")");
}


