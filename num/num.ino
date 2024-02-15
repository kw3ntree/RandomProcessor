#define swA 2 //4 //초
#define swB 3 //2 //파
#define swC 4 //1  빨
#define swD 5 //-1 노
#define swE 6 //정지 하
//#define swreset 8//reset

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // 0x27 또는 0x3F 둘다 안될경우에는 확인해봐야함

int flag = 0;
int count = 0;
int button_value = 0;

// Function prototype
void buttonInterrupt();

void setup() {
  Serial.begin(9600);
  lcd.begin();

  pinMode(swA, INPUT_PULLUP);
  pinMode(swB, INPUT_PULLUP);
  pinMode(swC, INPUT_PULLUP);
  pinMode(swD, INPUT_PULLUP);
  pinMode(swE, INPUT_PULLUP);
  //pinMode(swreset, INPUT_PULLUP);

  //attachInterrupt(digitalPinToInterrupt(swA), buttonInterrupt, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(swB), buttonInterrupt, CHANGE);
 // attachInterrupt(digitalPinToInterrupt(swC), buttonInterrupt, CHANGE);
 // attachInterrupt(digitalPinToInterrupt(swD), buttonInterrupt, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(swE), buttonInterrupt, CHANGE);
}

void loop() {
  /*if (digitalRead(swA) == LOW && flag == 0) {
    button_value = button_value + 4;
    flag = 1;
  }

  if (digitalRead(swB) == LOW && flag == 0) {
    button_value = button_value + 2;
    flag = 1;
  }*/

  /*
  //30초 타이머 시작
  unsigned long startTime = millis();
  unsigned long duration = 30000;  // 30초 (1000ms * 30)

    // 초기 메시지 출력
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Timer: 30s");

  lcd.clear();
  // 남은 시간 출력
  lcd.setCursor(0, 0);
  lcd.print("Remaining: " + String((duration - (millis() - startTime)) / 1000) + "s");

    delay(200);  // 갱신 간격

  */

  if(digitalRead(swA)==LOW)
    { button_value=button_value+4 ;
        }

  if(digitalRead(swB)==LOW)
    { button_value=button_value+2 ;
        }


  if(digitalRead(swC)==LOW)
    { button_value=button_value+1 ;
        }


  if(digitalRead(swD)==LOW){
      button_value=button_value-1;
    }


  if(digitalRead(swE)==LOW)
    {
      //button_value=button_value-1 ;
        //lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("value : ");
        lcd.print(button_value);
        //delay(10);
 
    }
    Serial.println(button_value);
   }

  /*if(digitalRead(swreset)==LOW){



  }
*/




/*
void buttonInterrupt() {
  flag = 0;
  
}
*/
