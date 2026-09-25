#include <Servo.h> 

// ----- 설정 -----
// 각 서보모터가 연결된 아두이노의 PWM 핀 번호
const int THUMB_PIN = 9;  // 엄지
const int INDEX_PIN = 10; // 검지
const int MIDDLE_PIN = 3; // 중지 (요청하신 대로 3번으로 변경)
const int RING_PIN = 6;   // 약지
const int PINKY_PIN = 5;  // 새끼

// 각 손가락의 펴고 접는 각도를 정의
const int FINGER_UP = 0;      // 손가락을 완전히 폈을 때의 각도
const int FINGER_DOWN = 180;  // 검지, 중지, 약지, 새끼를 접었을 때의 각도
const int THUMB_UP = 0;       // 엄지를 폈을 때의 각도
const int THUMB_DOWN = 150;   // 엄지를 접었을 때의 각도 (150도로 제한)

// 5개의 서보모터 객체를 생성
Servo thumbServo;
Servo indexServo;
Servo middleServo;
Servo ringServo;
Servo pinkyServo;

void setup() {
  Serial.begin(9600);
  Serial.println("표시할 숫자를 입력하세요 (1~5)");

  // 각 서보 객체에 연결된 핀 번호를 알려줌
  thumbServo.attach(THUMB_PIN);
  indexServo.attach(INDEX_PIN);
  middleServo.attach(MIDDLE_PIN);
  ringServo.attach(RING_PIN);
  pinkyServo.attach(PINKY_PIN);

  // 주먹을 쥔 상태에서 시작.
  foldAllFingers();
}

// ----- 루프 함수 (무한 반복 실행) -----
void loop() {
  // 시리얼 포트에 수신된 데이터가 있는지 확인.
  if (Serial.available() > 0) {
    // 시리얼 포트에서 정수(숫자)를 읽음.
    int number = Serial.parseInt();

    Serial.print("입력된 숫자: ");
    Serial.println(number);

    // 읽어온 숫자에 따라 해당 함수를 호출.
    switch (number) {
      case 1:
        displayOne();
        break;
      case 2:
        displayTwo();
        break;
      case 3:
        displayThree();
        break;
      case 4:
        displayFour();
        break;
      case 5:
        displayFive();
        break;
      default:
        // 1~5 이외의 숫자가 입력되면 주먹을 쥠.
        foldAllFingers();
        break;
    }
    
    while (Serial.available() > 0) {
      Serial.read();
    }
  }
}

// ----- 동작 함수들 -----

// 숫자 1을 표시하는 함수
void displayOne() {
  foldAllFingers();
  indexServo.write(FINGER_UP);
}

// 숫자 2를 표시하는 함수
void displayTwo() {
  foldAllFingers();
  indexServo.write(FINGER_UP);
  middleServo.write(FINGER_UP);
}

// 숫자 3을 표시하는 함수
void displayThree() {
  foldAllFingers();
  indexServo.write(FINGER_UP);
  middleServo.write(FINGER_UP);
  ringServo.write(FINGER_UP);
}

// 숫자 4를 표시하는 함수
void displayFour() {
  foldAllFingers();
  indexServo.write(FINGER_UP);
  middleServo.write(FINGER_UP);
  ringServo.write(FINGER_UP);
  pinkyServo.write(FINGER_UP);
}

// 숫자 5를 표시하는 함수
void displayFive() {
  thumbServo.write(THUMB_UP);
  indexServo.write(FINGER_UP);
  middleServo.write(FINGER_UP);
  ringServo.write(FINGER_UP);
  pinkyServo.write(FINGER_UP);
}

// 모든 손가락을 접어 주먹을 쥐는 함수
void foldAllFingers() {
  thumbServo.write(THUMB_DOWN);
  indexServo.write(FINGER_DOWN);
  middleServo.write(FINGER_DOWN);
  ringServo.write(FINGER_DOWN);
  pinkyServo.write(FINGER_DOWN);
}
