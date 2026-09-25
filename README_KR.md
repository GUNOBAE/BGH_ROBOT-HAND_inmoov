# InMoov Robot Hand i2 Project

🌐 **언어:** [English](README.md) | **한국어**
<p align="center"> <img width="386" height="386" alt="image" src="https://github.com/user-attachments/assets/6e04e17a-7fab-49e1-aad3-b2d375c3d610" />
<img width="386" height="386" alt="image" src="https://github.com/user-attachments/assets/f5740b94-9786-4861-9dc9-68a33058c4b5" />
</p>

InMoov의 **Hand i2**를 기반으로 제작한 3D 프린팅 로봇 손입니다.

기존 모델을 그대로 출력하는 것에 그치지 않고, 실제 사용한 Servo Motor와 조립 구조에 맞게 일부 3D 모델을 수정했습니다.

특히 **JX PDI-6225MG-300 Servo Motor를 손바닥과 손목 내부에 배치할 수 있도록 구조를 수정**했으며, Pulley, Palm, Hand Cover 등 실제 조립 과정에서 문제가 발생한 부품들도 직접 수정했습니다.

---

# Main Features

완성된 Robot Hand는 다음과 같은 기능을 갖습니다.

- 5개의 손가락 독립 제어
- 5개의 Servo Motor를 이용한 Tendon 구동
- Spring을 이용한 손가락 복원
- Arduino PWM을 이용한 Servo 직접 제어
- Serial Monitor를 통한 손가락 개별 제어
- 숫자 `1 ~ 5` 손동작 표현
- InMoov Hand i2 기반 3D Printed Structure
- Servo Motor를 손바닥 / 손목 내부에 배치

---

# Original Project

본 프로젝트는 InMoov의 **Hand i2**를 기반으로 제작했습니다.

### InMoov Hand i2

https://inmoov.fr/hand-i2/

원본 STL 파일과 기본적인 조립 과정은 공식 사이트에서 확인할 수 있습니다.

다만 실제 출력물의 공차와 사용하는 Servo Motor의 크기 때문에 일부 부품은 그대로 사용하기 어려웠고, 이에 맞춰 여러 부품을 수정했습니다.

---

# 주요 수정 사항

## 1. Servo Motor Mount 수정

사용한 Servo Motor는 다음과 같습니다.

```text
JX PDI-6225MG-300
```

제가 사용한 출력물과 조립 환경에서는 원본 부품에 JX PDI-6225MG-300 Servo Motor가 깔끔하게 맞지 않았습니다.
그래서 제 조립 구조에 맞도록 Servo Supporter 부분을 제거한 모델을 새롭게 만들어 다시 출력했습니다.
<p align="center">
  <img width="386" height="386" alt="image" src="https://github.com/user-attachments/assets/509baa15-84fd-46f1-8942-5ca758c8d4bd" />
  <img width="386" height="386" alt="image" src="https://github.com/user-attachments/assets/d7334ee6-e0d2-47aa-b73c-115c40b2beb8" />
</p>
---

## 2. Pulley 수정

원본에서 제공하는:

```text
i2_PulleyX5V1
```

모델 역시 사용한 Servo Motor에 그대로 장착하기 어려웠습니다.

따라서 다음 부분을 수정했습니다.

- Servo Shaft 결합부
- Pulley 크기
- Wrist 내부 간섭 부분

Servo Shaft에 단단하게 고정되도록 약간 빡빡하게 결합되는 구조로 수정했습니다.
<p align="center">
  <img width="386" height="347" alt="image" src="https://github.com/user-attachments/assets/1dde6dc3-2b1c-4b77-a1e8-ba157a8e7b99" />
  <img width="386" height="386" alt="image" src="https://github.com/user-attachments/assets/e0b056f2-037b-47b1-a85f-efc66a442a43" />
</p>

---

## 3. Palm / Hand Cover 수정
<p align="center">
  <img width="247" height="309" alt="image" src="https://github.com/user-attachments/assets/2bdaed79-cd19-4f2b-ad35-bb5706371c30" />
  <img width="282" height="300" alt="image" src="https://github.com/user-attachments/assets/153aceed-f125-4430-828a-595bc62401e5" />
</p>

Servo Motor를 손 내부에 배치하면서 원본 Palm과 Hand Cover를 그대로 사용하기 어려웠습니다.

원본 부품을 억지로 사용할 수도 있었지만 내부 공간 낭비가 커서 별도의 Palm과 Cover를 제작했습니다.

M3 나사를 이용해 결합할 수 있도록 구성했습니다.

<p align="center">
  <img width="290" height="321" alt="image" src="https://github.com/user-attachments/assets/1a8220f0-73fa-4e14-b355-233a82763b2b" />
  <img width="257" height="310" alt="image" src="https://github.com/user-attachments/assets/5acf6800-f890-4144-a768-4022e2b0873b" />
</p>

---

# Tendon & Spring Mechanism

손가락은 Servo Motor가 직접 각 관절을 움직이는 방식이 아니라,

**Fishing Line + Spring**

구조를 이용해 움직입니다.

Servo Motor가 Pulley를 회전시키면서 낚싯줄을 당기면 손가락이 접히고, 반대 방향에서는 Spring의 힘으로 손가락이 다시 펴집니다.

```text
Servo Motor
     │
     ▼
   Pulley
     │
     ▼
 Fishing Line
     │
     ▼
 Finger Joint

Spring → Finger Return
```

각 손가락에 맞게 Spring의 길이와 Tendon의 장력을 직접 당기며 조절했습니다.

---

# Servo Calibration

[Servo Calibration Code](arduino/servo_calibration/servo_calibration.ino)

Fishing Line을 연결하기 전에 Servo Motor의 기준 각도를 먼저 맞춰야 합니다.

Servo의 초기 위치가 서로 다른 상태에서 Tendon을 연결하면 손가락의 움직임 범위가 달라지거나 과도한 장력이 발생할 수 있습니다.

따라서 Servo를 동일한 기준 위치로 이동시킨 후 낚싯줄을 연결했습니다.

Tendon의 장력은 손가락을 완전히 편 상태에서 맞춘 뒤 고정했습니다.

---

# ⚠️ Thumb Angle Warning

엄지손가락은 다른 손가락과 동일하게 `180°`까지 움직이면 안 됩니다.

제가 제작한 구조에서는 엄지를 약:

```text
130° ~ 150°
```

정도까지만 움직이도록 제한했습니다.

각도를 너무 크게 설정하면 Pulley가 구조물과 충돌하면서 파손될 수 있습니다.

테스트 코드에서도 엄지의 최대 각도를 `150°`로 제한했습니다.

---

# Hardware

| Category | Component |
| --- | --- |
| Controller | Arduino |
| Servo Motor | 5 × JX PDI-6225MG-300 |
| Power Regulation | Buck Converter |
| Structure | 3D Printed InMoov Hand i2 |
| Tendon | Fishing Line |
| Finger Return | Spring |
| Circuit Board | Universal PCB |
| Fastener | M3 Screws |
| Power Indicator | LED |

Servo Motor는 약 **6V** 전원을 사용하도록 구성했습니다.

회로는 Breadboard 대신 Universal PCB에 직접 납땜하여 제작했습니다.

<p align="center">
  <img width="386" height="386" alt="image" src="https://github.com/user-attachments/assets/89049719-f707-43a6-bda6-30f5b22cffdc" />
  <img width="386" height="386" alt="image" src="https://github.com/user-attachments/assets/e32e834a-e9d3-4301-9a2e-4023cd05d0e5" />
</p>

전원이 정상적으로 공급되고 있는지 확인하기 위해 LED도 추가했습니다.

---

# Circuit
<p align="center">
  <img width="330" height="427" alt="image" src="https://github.com/user-attachments/assets/6d7c4357-734e-4cd7-b2b4-f06636696fe9" />
</p>

이번 버전에서는 별도의 16 Channel Servo Driver를 사용하지 않고 Arduino의 PWM Pin으로 5개의 Servo Motor를 직접 제어했습니다.

> ⚠️ **전원 주의:** 5개의 Servo Motor를 Arduino의 5V Pin에서 직접 구동하지 마세요. Servo에는 충분한 전류를 공급할 수 있는 별도 전원을 사용하고, Servo 전원의 GND와 Arduino GND는 공통으로 연결해야 합니다.

```text
Power Source
     │
     ▼
Buck Converter
     │
     ├── Servo Power
     │
     └── Arduino
              │
              ├── Thumb Servo
              ├── Index Servo
              ├── Middle Servo
              ├── Ring Servo
              └── Pinky Servo
```
<p align="center">
  <img width="400" height="400" alt="image" src="https://github.com/user-attachments/assets/b8b77da1-5583-4ec4-8006-fc395205837d" />
</p>

---

# Software

Arduino의 `Servo.h` 라이브러리를 사용해 기본적인 손가락 동작을 구현했습니다.

테스트 코드는 크게 두 가지입니다.

## 1. Individual Finger Control

[Arduino Code 보기](arduino/individual_finger_control/individual_finger_control.ino)

Serial Monitor에서 `1 ~ 5`를 입력하면 각각의 손가락을 개별적으로 제어할 수 있습니다.

```text
1 → Thumb
2 → Index
3 → Middle
4 → Ring
5 → Pinky
```

같은 번호를 다시 입력하면 해당 손가락의 상태가 반대로 변경됩니다.

---

## 2. Number Gesture Test

[Arduino Code 보기](arduino/number_gesture_test/number_gesture_test.ino)

Serial Monitor에서 `1 ~ 5`를 입력하면 해당 숫자에 맞는 손 모양을 표현합니다.

```text
1 → Index
2 → Index + Middle
3 → Index + Middle + Ring
4 → Index + Middle + Ring + Pinky
5 → All Fingers
```

그 외의 숫자를 입력하면 다시 주먹을 쥔 상태로 초기화됩니다.

<!-- 동작 GIF 또는 영상 추가 -->

---

# 3D Modeling & Printing

프로젝트에서 사용한 수정 모델은 Thingiverse에 업로드했습니다.

### Thingiverse

https://www.thingiverse.com/thing:7171875

주요 수정 부품은 다음과 같습니다.

- Servo Supporter가 제거된 Hand / Wrist
- Modified Pulley
- Modified Palm
- Modified Hand Cover

---

# Printing Notes

Hand i2는 작은 관절과 내부 구조가 많아 Support 제거가 생각보다 어렵습니다.

제가 사용했던 출력 조건은 대략 다음과 같습니다.

```text
Layer Height : 0.3 mm
Infill       : 30%
Line Width   : 0.45 mm
Support      : Normal Support
```

사용하는 Printer와 Material에 따라 설정은 달라질 수 있습니다.

Support를 너무 강하게 만들면 제거 과정이 어려워질 수 있으며, 일부 작은 구멍이나 관절 부분은 출력 후 드릴이나 사포를 이용해 추가 가공이 필요할 수 있습니다.

---

# Assembly Tips

실제 제작하면서 도움이 되었던 부분들을 간단히 정리했습니다.

## 1. 먼저 가조립하기

Servo Motor와 Spring을 장착하기 전에 M3 나사만 이용해 전체 구조가 정상적으로 조립되는지 확인하는 것을 권장합니다.

## 2. Servo Calibration을 먼저 하기

Tendon을 연결한 이후 Servo의 기준 위치를 수정하면 장력을 다시 맞춰야 합니다.

먼저 Servo 위치를 맞춘 뒤 줄을 연결하는 것이 훨씬 편합니다.

## 3. 필요한 가공은 조립 전에 하기

Servo Motor의 돌출부나 출력물의 일부를 갈아야 한다면 최종 조립 전에 작업하는 것을 추천합니다.

## 4. Tendon은 길게 남겨두기

Fishing Line은 처음부터 정확한 길이로 자르기보다 충분히 길게 남겨두고 장력을 조절한 후 마지막에 정리하는 것이 편합니다.

## 5. 엄지는 작은 각도부터 테스트하기

엄지는 다른 손가락보다 동작 범위가 작기 때문에 처음부터 `180°`로 테스트하지 않는 것을 권장합니다.

---

# 제작 과정에서 발생한 문제

## Servo Motor Fit

원본 STL에서는 제가 사용한 Servo Motor가 들어가지 않았습니다.

처음에는 출력물을 직접 가공하려 했지만 수정해야 할 양이 많아 결국 모델 자체를 변경했습니다.

실제 부품과 STL의 치수가 맞는지 출력 전에 확인하는 것이 중요했습니다.

---

## Pulley Fit

Pulley도 Servo Shaft와 공차가 맞지 않아 직접 수정해야 했습니다.

특히 작은 부품은 CAD상의 치수뿐 아니라 실제 Printer 출력 공차까지 고려해야 한다는 것을 알 수 있었습니다.

---

## Tendon Tension

Fishing Line이 너무 느슨하면 손가락이 제대로 접히지 않고, 너무 팽팽하면 Servo와 Pulley에 과도한 부하가 걸립니다.

각 손가락을 반복해서 움직이면서 적절한 장력을 직접 조절했습니다.

---

## Support Removal

작은 관절과 복잡한 구조 때문에 Support 제거 과정에서도 시간이 많이 걸렸습니다.

너무 강한 Support 설정은 출력에는 도움이 될 수 있지만, 조립 과정에서는 오히려 불편할 수 있습니다.

---

# Credits

본 프로젝트는 **InMoov Hand i2**를 기반으로 제작했습니다.

오픈소스로 모델과 제작 자료를 공개해주신 InMoov 프로젝트 제작자분들께 감사드립니다.

또한 제작에 금전적 지원을 해주신 부모님께 무한한 감사 인사를 올립니다. 

### Original Project

https://inmoov.fr/hand-i2/

---

# Detailed Build Logs

보다 자세한 제작 과정, 사진 및 테스트 영상은 개인 블로그에 정리해 두었습니다.

### 1. InMoov Robot Hand : 프롤로그

https://blog.naver.com/zmmm777/224026442422

### 2. InMoov Robot Hand : 3D 모델링 및 조립

https://blog.naver.com/zmmm777/224042406776

### 3. InMoov Robot Hand : 회로 및 테스트 코드

https://blog.naver.com/zmmm777/224043492200

> 블로그에는 README보다 자세한 실제 제작 과정과 시행착오, 작동 영상이 포함되어 있습니다.
