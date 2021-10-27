#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 4);

const int pinotrig = 10;
const int pinoecho = 11;
long duracao;

void setup() {
  pinMode(pinotrig, OUTPUT);
  pinMode(pinoecho, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.print("Distancia: ");
  Serial.begin(9600);
}

void loop() {
  digitalWrite(pinotrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig, LOW);
  duracao = pulseIn(pinoecho, HIGH);
  double distancia = duracao * 0.034 / 2;
  lcd.setCursor(0, 1);
  Serial.println(distancia);
  delay(100);
  lcd.print(distancia);
  lcd.print(" cm  ");
  lcd.setCursor(0, 2);
  lcd.print(distancia / 2.54);
  lcd.print(" in  ");
  delay(100);
}

int sensor(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  return pulseIn(echo, HIGH)/58;
}
