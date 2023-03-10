//importing neccessary librarys 
#include <Keypad.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

//setting background color on lcd to 
const int colorR = 255;
const int colorG = 255;
const int colorB = 255;

const byte ROWS = 4;
const byte COLS = 4;

//initializing array of keys
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

//corresponding rows and columns of arduino
byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {9, 8, 7, 6};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

char customKey;

//arrays that store the morse code using 0s and 1s
//0 for dots
//1 for dashes
int original[5] = {2, 2, 2, 2, 2};
int *checker = original;
int array0[] = {1, 1, 1, 1, 1};
int array1[] = {0, 1, 1, 1, 1};
int array2[] = {0, 0, 1, 1, 1};
int array3[] = {0, 0, 0, 1, 1};
int array4[] = {0, 0, 0, 0, 1};
int array5[] = {0, 0, 0, 0, 0};
int array6[] = {1, 0, 0, 0, 0};
int array7[] = {1, 1, 0, 0, 0};
int array8[] = {1, 1, 1, 0, 0};
int array9[] = {1, 1, 1, 1, 0};

//function to display morse code with LED
void morseCode(int array[]) {
  for (int i = 0; i < 5; i++) {
    if (array[i] == 0) {
      digitalWrite(13, HIGH);
      delay(500);
    } else if (array[i] == 1) {
      digitalWrite(13, HIGH);
      delay(1500);
    }
    digitalWrite(13, LOW);
    delay(1000);
  }
}

//Clears screen and asks for user input
void enterNumber(){
  lcd.setCursor(0,0);
  lcd.print("Enter Number: ");
  lcd.setCursor(0,1);
  }

//setting up the lcd display and led light
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      void setup()
{
  //setting up the led light
  pinMode(13, OUTPUT);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  //LCD background
  lcd.setRGB(colorR, colorG, colorB);
  // Print a message to the LCD.
  lcd.print("Enter Number: ");

}

//main code that asks for user input and displays output with LED
void loop()
{
  pinMode(12, OUTPUT);
  int doneLoop = 0;
  while (doneLoop == 0) {
    char customKey = customKeypad.getKey();
    switch (customKey) {
      case '0':
        lcd.setCursor(0, 1);
        lcd.clear();
        enterNumber();
        lcd.print('0');
        checker = array0;
        morseCode(checker);
        break;
      case '1':
        lcd.setCursor(0, 1);
        lcd.clear();
        enterNumber();
        lcd.print('1');
        checker = array1;
        morseCode(checker);
        break;
      case '2':
        lcd.setCursor(0, 1);
        lcd.clear();
        enterNumber();
        lcd.print('2');
        checker = array2;
        morseCode(checker);
        break;
      case '3':
        lcd.setCursor(0, 1);
        lcd.clear();
        enterNumber();
        lcd.print('3');
        checker = array3;
        morseCode(checker);
        break;
      case '4':
        lcd.setCursor(0, 1);
        lcd.clear();
        enterNumber();
        lcd.print('4');
        checker = array4;
        morseCode(checker);
        break;
      case '5':
        lcd.setCursor(0, 1);
        lcd.clear();
        enterNumber();
        lcd.print('5');
        checker = array5;
        morseCode(checker);
        break;
      case '6':
        lcd.setCursor(0, 1);
        lcd.clear();
        enterNumber();
        lcd.print('6');
        checker = array6;
        morseCode(checker);
        break;
      case '7':
        lcd.setCursor(0, 1);
        lcd.clear();
        enterNumber();
        lcd.print('7');
        checker = array7;
        morseCode(checker);
        break;
      case '8':
        lcd.setCursor(0, 1);
        lcd.clear();
        enterNumber();
        lcd.print('8');
        checker = array8;
        morseCode(checker);
        break;
      case '9':
        lcd.setCursor(0, 1);
        lcd.clear();
        enterNumber();
        lcd.print('9');
        checker = array9;
        morseCode(checker);
        break;
      case '#':
        lcd.setCursor(0, 1);
        lcd.print("Numbers Only!");
        doneLoop = 1;
        break;
      case '*':
        lcd.setCursor(0, 1);
        lcd.print("Numbers Only!");
        doneLoop = 1;
        break;
      case 'A':
        lcd.setCursor(0, 1);
        lcd.print("Numbers Only!");
        doneLoop = 1;
        break;
      case 'B':
        lcd.setCursor(0, 1);
        lcd.print("Numbers Only!");
        doneLoop = 1;
        break;
      case 'C':
        lcd.setCursor(0, 1);
        lcd.print("Numbers Only!");
        doneLoop = 1;
        break;
      case 'D':
        lcd.setCursor(0, 1);
        lcd.print("Numbers Only!");
        doneLoop = 1;
        break;
    }
  }
}
