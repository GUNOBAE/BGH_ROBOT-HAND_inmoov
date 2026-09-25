#include <Servo.h>

Servo myservo;
int servoPin = 3;

void setup() {

  myservo.attach(servoPin);
  Serial.begin(9600);

  Serial.println("각도(0~180)를 입력하고 Enter를 누르세요.");
  myservo.write(90); // 90도에서 시작
}

void loop() {
  if (Serial.available() > 0) {
    // 시리얼 포트에서 정수(숫자)를 읽어옴.
    int angle = Serial.parseInt();
    angle = constrain(angle, 0, 180); // 안전하게 0~180도 범위로 제한

    Serial.print("입력된 각도: ");
    Serial.println(angle);

    // 읽어온 각도 값으로 서보모터를 움직임.
    myservo.write(angle);

    //serial 통신간 쓰레기 글자 제거
    while (Serial.available() > 0) {
      Serial.read();
    }
  }
}
