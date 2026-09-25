# InMoov Robot Hand i2 Project

🌐 **Language:** **English** | [한국어](README_KR.md)

<p align="center">
  <img width="386" height="386" alt="image" src="https://github.com/user-attachments/assets/6e04e17a-7fab-49e1-aad3-b2d375c3d610" />
  <img width="386" height="386" alt="image" src="https://github.com/user-attachments/assets/f5740b94-9786-4861-9dc9-68a33058c4b5" />
</p>

This is a 3D-printed robotic hand based on the **InMoov Hand i2**.

Rather than simply printing and assembling the original model, I modified several 3D parts to fit the servo motors and the actual assembly structure I used.

In particular, I modified the design so that the **JX PDI-6225MG-300 servo motors could be placed inside the palm and wrist**, and I also redesigned several parts that caused problems during assembly, including the Pulley, Palm, and Hand Cover.

---

# Main Features

The completed Robot Hand includes the following features:

- Independent control of all 5 fingers
- Tendon-driven finger movement using 5 Servo Motors
- Finger return using Springs
- Direct Servo control using Arduino PWM
- Individual finger control through the Serial Monitor
- Number gestures from `1 ~ 5`
- 3D Printed Structure based on the InMoov Hand i2
- Servo Motors placed inside the palm / wrist

---

# Original Project

This project is based on the **InMoov Hand i2**.

### InMoov Hand i2

https://inmoov.fr/hand-i2/

The original STL files and basic assembly instructions can be found on the official website.

However, due to actual print tolerances and the size of the Servo Motors I used, some parts could not be used as-is, so I modified several components to fit my build.

---

# Main Modifications

## 1. Servo Motor Mount Modification

The Servo Motor used in this project is:

```text
JX PDI-6225MG-300
```

The original Hand i2 model did not have enough space for this Servo Motor.

So I created and reprinted a modified version with the Servo Supporter section removed.

<p align="center">
  <img width="386" height="386" alt="image" src="https://github.com/user-attachments/assets/509baa15-84fd-46f1-8942-5ca758c8d4bd" />
  <img width="386" height="386" alt="image" src="https://github.com/user-attachments/assets/d7334ee6-e0d2-47aa-b73c-115c40b2beb8" />
</p>

---

## 2. Pulley Modification

The original:

```text
i2_PulleyX5V1
```

also did not fit the Servo Motor properly.

So I modified the following parts:

- Servo Shaft connection
- Pulley size
- Interference with the Wrist structure

I intentionally designed the Pulley to fit slightly tight so that it would stay firmly attached to the Servo Shaft.

<p align="center">
  <img width="386" height="347" alt="image" src="https://github.com/user-attachments/assets/1dde6dc3-2b1c-4b77-a1e8-ba157a8e7b99" />
  <img width="386" height="386" alt="image" src="https://github.com/user-attachments/assets/e0b056f2-037b-47b1-a85f-efc66a442a43" />
</p>

---

## 3. Palm / Hand Cover Modification

<p align="center">
  <img width="247" height="309" alt="image" src="https://github.com/user-attachments/assets/2bdaed79-cd19-4f2b-ad35-bb5706371c30" />
  <img width="282" height="300" alt="image" src="https://github.com/user-attachments/assets/153aceed-f125-4430-828a-595bc62401e5" />
</p>

Because the Servo Motors were placed inside the hand, it was difficult to use the original Palm and Hand Cover as they were.

It was technically possible to force them into the original structure, but it wasted too much internal space, so I designed a separate Palm and Cover.

They were designed to be assembled using M3 screws.

<p align="center">
  <img width="290" height="321" alt="image" src="https://github.com/user-attachments/assets/1a8220f0-73fa-4e14-b355-233a82763b2b" />
  <img width="257" height="310" alt="image" src="https://github.com/user-attachments/assets/5acf6800-f890-4144-a768-4022e2b0873b" />
</p>

---

# Tendon & Spring Mechanism

The fingers are not driven by directly rotating each joint with a Servo Motor.

Instead, they use a:

**Fishing Line + Spring**

mechanism.

When the Servo Motor rotates the Pulley, it pulls the fishing line and bends the finger.

In the opposite direction, the Spring pulls the finger back into its extended position.

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

I manually adjusted the Spring length and Tendon tension for each finger by pulling and testing them repeatedly.

---

# Servo Calibration

Before connecting the Fishing Line, the Servo Motors must first be moved to the same reference angle.

If the Servos start from different positions when the Tendons are connected, the fingers may have different ranges of motion or excessive tension.

So I first moved all Servos to the same reference position and then connected the fishing lines.

The Tendon tension was adjusted and fixed while each finger was fully extended.

---

# ⚠️ Thumb Angle Warning

The thumb should **not** be moved through the same `180°` range as the other fingers.

In my build, I limited the thumb movement to approximately:

```text
130° ~ 150°
```

If the angle is too large, the Pulley can collide with the structure and break.

The maximum thumb angle is also limited to `150°` in the test code.

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

The Servo Motors were configured to run at approximately **6V**.

Instead of using a Breadboard, I soldered the circuit directly onto a Universal PCB.

<p align="center">
  <img width="386" height="386" alt="image" src="https://github.com/user-attachments/assets/89049719-f707-43a6-bda6-30f5b22cffdc" />
  <img width="386" height="386" alt="image" src="https://github.com/user-attachments/assets/e32e834a-e9d3-4301-9a2e-4023cd05d0e5" />
</p>

I also added an LED so that I could easily check whether power was being supplied correctly.

---

# Circuit

<p align="center">
  <img width="330" height="427" alt="image" src="https://github.com/user-attachments/assets/6d7c4357-734e-4cd7-b2b4-f06636696fe9" />
</p>

In this version, I did not use a separate 16 Channel Servo Driver.

Instead, the five Servo Motors were controlled directly through the Arduino PWM Pins.

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

I implemented the basic finger movements using Arduino's `Servo.h` library.

There are two main test programs.

## 1. Individual Finger Control

By entering a number from `1 ~ 5` in the Serial Monitor, each finger can be controlled independently.

```text
1 → Thumb
2 → Index
3 → Middle
4 → Ring
5 → Pinky
```

Entering the same number again changes that finger to the opposite state.

---

## 2. Number Gesture Test

By entering a number from `1 ~ 5` in the Serial Monitor, the robotic hand forms the corresponding number gesture.

```text
1 → Index
2 → Index + Middle
3 → Index + Middle + Ring
4 → Index + Middle + Ring + Pinky
5 → All Fingers
```

If any other number is entered, the hand returns to a closed-fist position.

<!-- Add GIF or video here -->

---

# 3D Modeling & Printing

The modified models used in this project are uploaded to Thingiverse.

### Thingiverse

https://www.thingiverse.com/thing:7171875

The main modified parts include:

- Hand / Wrist with the Servo Supporter removed
- Modified Pulley
- Modified Palm
- Modified Hand Cover

---

# Printing Notes

The Hand i2 has many small joints and internal structures, so removing the Support material was harder than I expected.

The approximate printing settings I used were:

```text
Layer Height : 0.3 mm
Infill       : 30%
Line Width   : 0.45 mm
Support      : Normal Support
```

These settings are not necessarily the best settings for every printer.

I recommend adjusting them depending on your Printer and Material.

If the Support is generated too strongly, it can become very difficult to remove.

Some small holes and joint areas may also require additional post-processing using a drill, sandpaper, or similar tools.

---

# Assembly Tips

Here are a few things that helped during the actual build.

## 1. Test Assemble Everything First

Before installing the Servo Motors and Springs, I recommend assembling the entire structure with only the M3 screws first.

This makes it much easier to check whether everything fits correctly.

## 2. Calibrate the Servos First

If you change the Servo reference position after connecting the Tendons, you will need to adjust the tension again.

It is much easier to set the Servo positions first and connect the Tendons afterward.

## 3. Do Any Required Grinding Before Final Assembly

If you need to grind down any protruding parts on the Servo Motor or printed parts, I recommend doing it before final assembly.

## 4. Leave the Tendons Longer Than Needed

Instead of cutting the Fishing Line to the exact length from the beginning, leave some extra length.

Adjust the tension first, secure it, and trim the remaining line afterward.

## 5. Start With a Small Thumb Angle

The thumb has a smaller range of motion than the other fingers.

Do not immediately test it at `180°`.

Start with a smaller range and slowly increase it while checking for interference.

---

# Problems Encountered During the Build

## Servo Motor Fit

The Servo Motors I used did not fit inside the original STL model.

At first, I tried manually grinding the printed part, but there was too much material to remove, so I eventually modified the model itself.

This made me realize how important it is to check the dimensions of the actual components against the STL before printing.

---

## Pulley Fit

The Pulley also did not properly fit the Servo Shaft, so I had to modify it.

Especially for small mechanical parts, I learned that you need to consider not only the CAD dimensions but also the actual tolerance of the 3D printer.

---

## Tendon Tension

If the Fishing Line is too loose, the finger does not bend properly.

If it is too tight, unnecessary load is placed on the Servo and Pulley.

I repeatedly tested each finger and manually adjusted the Tendon tension until the motion felt right.

---

## Support Removal

Because of the small joints and complex internal structures, removing the Support material took quite a bit of time.

A stronger Support setting may help during printing, but it can actually make the assembly process much harder.

---

# Credits

This project is based on the **InMoov Hand i2**.

A huge thank you to the InMoov creators for sharing the models and build information as open-source resources.

I would also like to give a huge thank you to my parents for financially supporting this project.

### Original Project

https://inmoov.fr/hand-i2/

---

# Detailed Build Logs

More detailed build steps, photos, troubleshooting notes, and operation videos are available on my personal blog.

### 1. InMoov Robot Hand: Prologue

https://blog.naver.com/zmmm777/224026442422

### 2. InMoov Robot Hand: 3D Modeling & Assembly

https://blog.naver.com/zmmm777/224042406776

### 3. InMoov Robot Hand: Circuit & Test Code

https://blog.naver.com/zmmm777/224043492200

> The blog posts contain more detailed build steps, troubleshooting notes, and operation videos than this README.
