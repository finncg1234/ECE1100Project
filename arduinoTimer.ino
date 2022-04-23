// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 2, d5 = 3, d6 = 4, d7 = 5, up = 8, right = 9, down = 10, left = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int x = 0;
int y = 1;


void setup() {
  lcd.begin(16, 2);
  pinMode(up, INPUT_PULLUP);
  pinMode(down, INPUT_PULLUP);
  pinMode(right, INPUT_PULLUP);
  pinMode(left, INPUT_PULLUP);
  lcd.setCursor(0,0);
  lcd.print("Timer");
  lcd.setCursor(0,1);
  lcd.print("Stopwatch");
  lcd.setCursor(5, 0);
  lcd.print("->");*/
}

void loop() {
  if(digitalRead(up) == 0 || digitalRead(down) == 0) {
  if (x % 2 == 0) {
    lcd.setCursor(5,0);
    lcd.print("    ");
    lcd.setCursor(9,1);
    lcd.print("->");
  } else {
    lcd.setCursor(9,1);
    lcd.print("     ");
    lcd.setCursor(5,0);
    lcd.print("->");
  }
  x++;
  delay(50);
  } else if(digitalRead(right) == 0) {
    if (x % 2 == 0) {
      delay(200);
      displayTimer();
    } else {
      delay(200);
      displayStopwatch();
    }
  }
  delay(50);
}

void displayTimer() {
  int first = 0;
  int second = 0;
  int third = 0;
  int fourth = 0;
  String clocker ="";
    clocker += first;
    clocker += second;
    clocker += ":";
    clocker += third;
    clocker += fourth;
  lcd.clear();
  lcd.print("Set time:");
  lcd.setCursor(0,1);
  lcd.print(clocker);
  lcd.cursor();
  while (digitalRead(left) == 1) {
    if(digitalRead(right) == 0) {
      if (y % 4 < 2) {
        lcd.setCursor(y++ % 4, 1);
        delay(200);
      } else {
        lcd.setCursor(3 + (y++ % 2), 1);
        delay(200);
      }
    } else if (digitalRead(up) == 0) {
      if (y % 4 == 1) {
        first++;
        first = first % 10;
      } else if (y % 4 == 2) {
        second++;
        second = second % 10;
      } else if (y % 4 == 3) {
        third++;
        third = third % 6;
      } else if (y % 4 == 0) {
        fourth++;
        fourth = fourth % 10;
      }
      clocker ="";
      clocker += first;
      clocker += second;
      clocker += ":";
      clocker += third;
      clocker += fourth;
      lcd.setCursor(0,1);
      lcd.print(clocker);
      if (y % 4 < 3 && y % 4 > 0) {
        lcd.setCursor(y % 4 - 1, 1);
        delay(200);
      } else {
        lcd.setCursor(4 - (y % 2), 1);
        delay(200);
      }
    } else if (digitalRead(down) == 0) {
        boolean paused = false;
        lcd.noCursor();
        lcd.setCursor(0,0);
        lcd.print("Countdown!  ");
        delay(1000);
        while ((first + second + third + fourth) != 0) {
          if (paused) {
            break;
          }
          if (digitalRead(down) == 0) {
            lcd.setCursor(0,0);
            lcd.print("Paused.    ");
            break;
          }
          while (fourth != 0) {
            if (digitalRead(down) == 0) {
            lcd.setCursor(0,0);
            lcd.print("Paused.   ");
            paused = true;
            break;
            }
            delay(1000);
            fourth--;
            lcd.setCursor(4,1);
            lcd.print(fourth);
          }
          if (third != 0) {
            delay(1000);
            fourth = 9;
            third--;
            lcd.setCursor(3,1);
            lcd.print(third);
            lcd.print(fourth);
          } else if (second != 0) {
            delay(1000);
            third = 5;
            fourth = 9;
            second--;
            lcd.setCursor(1,1);
            lcd.print(second);
            lcd.setCursor(3,1);
            lcd.print(third);
            lcd.print(fourth);
          } else if (first != 0) {
            delay(1000);
            second = 9;
            third = 5;
            fourth = 9;
            first--;
            clocker ="";
            clocker += first;
            clocker += second;
            clocker += ":";
            clocker += third;
            clocker += fourth;
            lcd.setCursor(0,1);
            lcd.print(clocker);
          }
          if (first + second + third + fourth == 0) {
            lcd.clear();
            lcd.print("Timer Done!");
          }
        }
    }
  }
  delay(50);
  y = 0;
  setup();
}

void displayStopwatch() {
  lcd.clear();
  int z = 0;
  lcd.print("Stopwatch:");
  while (digitalRead(down) == 1) {
    delay(1000);
    z++;
    lcd.setCursor(0,1);
    lcd.print(z);
  }
  delay(1000);
  while(digitalRead(down) * digitalRead(up) * digitalRead(right) * digitalRead(left) == 1) {
    
  }
  setup();
}
