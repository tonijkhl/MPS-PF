# Bluetooth-Controlled Arduino Robot Car

This repository contains the complete project for a **4WD robot car controlled via Bluetooth**, integrating an **L298N motor driver**, **HC-SR04 ultrasonic sensor**, **YL-44 buzzer**, red and green indicator LEDs, and an **Android application** developed in **MIT App Inventor 2**. The prototype allows the car to move forward, backward, and turn left and right, with sound feedback proportional to obstacle proximity.

---

## Features

* **Movement control** via Bluetooth from an Android app with Up, Down, Left, and Right buttons.
* Four 9V motors controlled using **L298N Dual H-Bridge** in H-Bridge configuration.
* **Obstacle detection** with HC-SR04, activating the **YL-44 buzzer**, with faster beeps as objects approach.
* Indicator LEDs (2 red, 2 green) for visual signals.
* Powered by **18650 batteries** (7.4V in series, 1800 mAh each) for high motor current.
* Android app developed in MIT App Inventor 2, using **TouchDown and TouchUp events** to send commands to Arduino.

---

## Assembly

* Motors connected in **parallel pairs** to L298N pins IN1-IN2 and IN3-IN4.
* L298N pins connected to Arduino:

  * IN1 → 7
  * IN2 → 6
  * IN3 → 5
  * IN4 → 4
* Power supply: 18650 batteries in series (7.4V) connected to **12V+ on L298N** and **VIN on Arduino**.
* Ultrasonic sensor: TRIG → 10, ECHO → 9
* YL-44 buzzer: pin 3
* LEDs: red → 13, green → 12
* All GND lines connected to a **common ground bus**.

---

## Programming

* **Arduino:** Controls motors, LEDs, buzzer, and ultrasonic sensor.
* **Bluetooth:** Reads characters from the Android app ('U', 'D', 'L', 'R' to move, lowercase to stop).
* **Buzzer:** Beep frequency increases as objects get closer using the map() function.
* **Android App:** Blocks in MIT App Inventor 2 send characters to Arduino via BluetoothClient, with device selection via **ListPicker** using **BeforePicking/AfterPicking** events.

---

## Results

* The car moves **forward and backward**, and turns **left and right**.
* LEDs and buzzer operate correctly with obstacle detection.
* Bluetooth connection is stable and allows real-time control from the app.

1. [Forward and backward movement](/public/beeping.mp4)
2. [Turning left](/public/turning_left.mp4)

### Images

![Mounted Car](/public/mounted_car.jpg)
![L298N Wiring](/public/l298n_wiring.jpg)
![Motors Wiring](/public/motors_wiring.jpg)
![Sensors Wiring](/public/sensors_wiring.jpg)
![LEDs and Buzzer Setup](/public/testing_leds.jpg)

---

## References

* Last Minute Engineers. *L298N DC & Stepper Motor Driver Arduino Tutorial*. [https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/](https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/)
* Ramanuj. *4WD Arduino Car with L298N*. YouTube. [https://www.youtube.com/watch?v=cucp1-EmVRU](https://www.youtube.com/watch?v=cucp1-EmVRU)
* Instructables. *Arduino YL-44 Buzzer module*. [https://www.instructables.com/Arduino-YL-44-Buzzer-module/](https://www.instructables.com/Arduino-YL-44-Buzzer-module/)
* Piddler in the Root. *L298N Dual H-Bridge Raspberry Pi Guide*. [https://piddlerintheroot.com/l298n-dual-h-bridge/](https://piddlerintheroot.com/l298n-dual-h-bridge/)
* MIT App Inventor 2. [https://ai2.appinventor.mit.edu/](https://ai2.appinventor.mit.edu/)
* Ohm’s Law Calculator. *Voltage Divider Calculator*. [https://ohmslawcalculator.com/voltage-divider-calculator](https://ohmslawcalculator.com/voltage-divider-calculator)
* Calculator.net. *Resistor Color Code Calculator*. [https://www.calculator.net/resistor-calculator.html](https://www.calculator.net/resistor-calculator.html)