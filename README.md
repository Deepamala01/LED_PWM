# LED_PWM
LED Fade using PWM with Arduino Uno – LED brightness smoothly increases and decreases using Pulse Width Modulation. A simple beginner Arduino project demonstrating analogWrite().
---

## Components Required

- Arduino Uno
- LED
- 220Ω Resistor
- Breadboard
- Jumper Wires

## Circuit Connection

- Connect LED Anode (+) to Pin 9 of Arduino.
- Connect LED Cathode (-) to 220Ω resistor.
- Connect the resistor to GND.

## How It Works

- The Arduino uses the analogWrite() function to generate a PWM signal.
- PWM varies the duty cycle of the signal to control the brightness of the LED.
- 0 → LED OFF
- 255 → Maximum brightness

The program gradually increases and decreases the brightness value to create a fading effect.
---

## Arduino Code
```cpp
int led = 9;
int brightness = 0;
int fadeAmount = 5;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  analogWrite(led, brightness);
  brightness = brightness + fadeAmount;

  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  delay(30);
}
```
---
## Code Explanation
###1. Declare Variables
```cpp
int led = 9;
int brightness = 0;
int fadeAmount = 5;
```
### Explanation:

*led = 9*
- The LED is connected to pin 9, which is a PWM pin on the Arduino.

*brightness = 0*
- This variable stores the current brightness level of the LED.
- PWM values range from 0 to 255.

*fadeAmount = 5*
- This determines how much the brightness changes each time the loop runs.

### 2. Setup Function
```cpp
void setup() {
  pinMode(led, OUTPUT);
}
```
### Explanation:

- setup() runs only once when the Arduino starts.
- pinMode(led, OUTPUT); sets pin 9 as an output pin so it can send signals to the LED.

### 3. Loop Function
```cpp
void loop() {
```
### Explanation:

- loop() runs continuously after setup().
- This allows the LED to fade repeatedly.

### 4. Set LED Brightness
```cpp
analogWrite(led, brightness);
```
### Explanation:

- analogWrite() sends a PWM signal to the LED.
- PWM controls brightness by rapidly turning the LED ON and OFF.
- The value of brightness determines the duty cycle.

|Value	LED |Brightness|
|-----------|----------|
|0	|OFF|
|128	|Medium brightness|
|255	|Maximum brightness|

### 5. Increase Brightness
```cpp
brightness = brightness + fadeAmount;
```
### Explanation:

- The brightness value increases by 5 each cycle.
- This makes the LED gradually brighter.

### 6. Reverse the Fade Direction
```cpp
if (brightness <= 0 || brightness >= 255) {
  fadeAmount = -fadeAmount;
}
```
### Explanation:

- If brightness reaches 255 (maximum) or 0 (minimum):
- The value of fadeAmount becomes negative.
- This causes the brightness to start decreasing instead of increasing.

### Example:

|Brightness|fadeAmount	|Result|
|----------|------------|------|
|250|	+5	|Increase|
|255	|-5	|Start decreasing|

### 7. Delay
```cpp
delay(30);
```
### Explanation:

- Adds a 30 millisecond pause between brightness changes.
- This makes the fading smooth and visible.
---
## Overall Working

- LED starts with brightness = 0.
- Brightness gradually increases until it reaches 255.
- Then the direction reverses and brightness decreases.
- The process repeats continuously, creating a smooth fade effect.
---
## Output

- The LED brightness smoothly fades from dim to bright and back to dim continuously.
- Brightness gradually increases until it reaches 255.
- Then the direction reverses and brightness decreases.
- The process repeats continuously, creating a smooth fade effect.
---
