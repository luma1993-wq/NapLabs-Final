#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 9;
const int echoPin = 10;

float duration, distance;

int Letter[] = {1,2,3,4,5,6,7};

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

  if (8 < distance && distance < 11) {
    digitalWrite(13,LOW);
    digitalWrite(12,HIGH);
  } else{
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
  }
  
  int randomIndex = random(0,7);
  int selectedValue = Letter[randomIndex];

  Serial.println(selectedValue);
  lcd.clear();
  lcd.print(selectedValue);

}