#include <Servo.h>

// ----- 설정 -----
// 각 서보모터가 연결된 아두이노의 PWM 핀 번호
const int THUMB_PIN = 9;  // 1번: 엄지
const int INDEX_PIN = 10; // 2번: 검지
const int MIDDLE_PIN = 3; // 3번: 중지
const int RING_PIN = 6;   // 4번: 약지
const int PINKY_PIN = 5;  // 5번: 새끼

// 각 손가락의 펴고 접는 각도
const int FINGER_UP = 0;
const int FINGER_DOWN = 180;
const int THUMB_UP = 0;
const int THUMB_DOWN = 150; // 엄지는 150도로 제한

// 5개의 서보모터 객체 생성
Servo servo[5];

// 각 손가락의 현재 상태를 저장하는 배열 (true: 펴진 상태, false: 접힌 상태)
bool isFingerUp[5];

void setup() {
  Serial.begin(9600);
  Serial.println("제어할 손가락 번호를 입력하세요 (1:엄지 ~ 5:새끼)");

  // 서보 객체에 핀 번호를 연결
  servo[0].attach(THUMB_PIN);
  servo[1].attach(INDEX_PIN);
  servo[2].attach(MIDDLE_PIN);
  servo[3].attach(RING_PIN);
  servo[4].attach(PINKY_PIN);

  // 모든 손가락을 접은 상태로 시작
  for (int i = 0; i < 5; i++) {
    isFingerUp[i] = false; // 모든 손가락 상태를 '접힘'으로 초기화
    if (i == 0) { // 엄지
      servo[i].write(THUMB_DOWN);
    } else { // 나머지 손가락
      servo[i].write(FINGER_DOWN);
    }
  }
}

void loop() {
  if (Serial.available() > 0) {
    int fingerNumber = Serial.parseInt(); // 1~5 사이의 숫자 입력받기

    // 입력값이 1~5 사이일 때만 작동
    if (fingerNumber >= 1 && fingerNumber <= 5) {
      // 배열 인덱스는 0부터 시작하므로 입력값에서 1을 뺌
      int index = fingerNumber - 1;

      Serial.print(fingerNumber);
      
      // 현재 손가락 상태 확인하고 반대로 동작시키기
      if (isFingerUp[index]) { // 만약 펴져 있다면(true)
        Serial.println("번 손가락을 접습니다.");
        if (index == 0) { // 엄지
          servo[index].write(THUMB_DOWN);
        } else { // 나머지 손가락
          servo[index].write(FINGER_DOWN);
        }
        isFingerUp[index] = false; // 상태를 '접힘'으로 변경
      } 
      else { // 만약 접혀 있다면(false)
        Serial.println("번 손가락을 폅니다.");
        if (index == 0) { // 엄지
          servo[index].write(THUMB_UP);
        } else { // 나머지 손가락
          servo[index].write(FINGER_UP);
        }
        isFingerUp[index] = true; // 상태를 '펴짐'으로 변경
      }
    }
    
    // 시리얼 버퍼에 남아있는 찌꺼기 데이터 제거
    while (Serial.available() > 0) {
      Serial.read();
    }
  }
}
