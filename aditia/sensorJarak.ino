
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 6, en = 7, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int pTrig = 3;
const int pEcho = 2;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  pinMode(pTrig, OUTPUT);
 pinMode(pEcho, INPUT);
}

long durasi = 0;
float jarakCm = 0;
void loop() {
  digitalWrite(pTrig, HIGH);
 delayMicroseconds(10);
 digitalWrite(pTrig, LOW);

 durasi = pulseIn(pEcho, HIGH);
 jarakCm = (durasi *0.034)/2;

if(jarakCm >= 200){
  jarakCm = 200;
}else{
  jarakCm = jarakCm;
}
 
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.clear();
  lcd.print("Halangan (cm) : ");
  lcd.setCursor(0, 1);
   lcd.print(jarakCm);
   delay(2000);
  //lcd.print(millis() / 1000);
}
