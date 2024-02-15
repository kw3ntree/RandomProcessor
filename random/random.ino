#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD 설정
LiquidCrystal_I2C lcd(0x27, 16, 2);  // 주소 0x27, 16x2 LCD

// 버튼 핀 설정
const int buttonPin = 2;

// 난수 생성 여부를 나타내는 플래그
bool randomNumberGenerated = false;

// 한 번 생성한 난수 값
int generatedRandomNumber;
int buzzer = 3;

int melody[] = {392, 392, 440, 440, 392, 392, 330};

void setup() {
  // 시리얼 통신 초기화
  Serial.begin(9600);

  // 버튼 풀업 설정
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);

  // LCD 초기화
  lcd.begin(16, 2);
  lcd.backlight();  // 백라이트 켜기

  // 초기 메시지 출력
  lcd.print("Let's Play!");
  lcd.setCursor(0, 1);
  lcd.print("Random Num Game");
}

void loop() {
  // 버튼을 누를 때까지 대기
  while (digitalRead(buttonPin) == HIGH) {
    delay(50);
  }

  // 난수를 한 번만 생성
  if (!randomNumberGenerated) {
    generatedRandomNumber = random(1000, 4001);
    randomNumberGenerated = true;
  }

  // 버튼이 눌리면 30초 타이머 시작
  unsigned long startTime = millis();
  unsigned long duration = 15000;  // 30초 (1000ms * 30)

  // 초기 메시지 출력
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Timer: 15s");

  while (millis() - startTime < duration) {
    // 생성된 난수를 상단에 표시
    lcd.setCursor(0, 1);
    lcd.print("Random: " + String(generatedRandomNumber));

    // 남은 시간 출력
    lcd.setCursor(0, 0);
    lcd.print("Remaining: " + String((duration - (millis() - startTime)) / 1000) + "sec");
   
    delay(200);  // 갱신 간격
    lcd.clear();
  }
  for (int i=0; i<=6; i++) {
       tone(3, melody[i], 250);
       delay(50);
       noTone(3);
  }

  // 타이머 종료 후 "Time's up!" 출력
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Time's up!");
  lcd.clear();
  lcd.print("Random: " + String(generatedRandomNumber));
  delay(5000);
  
  // 백라이트 끄기
  lcd.noBacklight();

  // 버튼이 떼질 때까지 대기
  while (digitalRead(buttonPin) == LOW) {
    delay(50);
  }

  // 백라이트 다시 켜기
  lcd.backlight();

  // 잠시 대기 후 초기 메시지 출력
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Let's Play!");
  lcd.setCursor(0, 1);
  lcd.print("Random Num Game");

  // 다음 루프에서 난수를 다시 생성할 수 있도록 플래그 초기화
  randomNumberGenerated = false;
}
