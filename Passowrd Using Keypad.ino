#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>


LiquidCrystal_I2C lcd(0x27, 16, 2); 

const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const String password = "1234"; 
String inputPassword = ""; 



void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Enter Pass :");

}

void loop() {
  char key = keypad.getKey();
  if (key) { 
    if(key=='#'){
      if(inputPassword == password){
        
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Welcome!");
        delay(1000);
      }
      else{       
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Incorect!");
        delay(1000);
      }
      inputPassword = "";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter Pass :");
    } 
    else{
    lcd.setCursor(0, 1);           
    inputPassword += key;         
    lcd.print(inputPassword);
    }  
       
  }

}
   