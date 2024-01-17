# Hand Gesture Controlled Wheelchair With Obstcale Detection  
:pushpin:  Here in this project we have built a prototype of wheelchair whose movement can be controlled by the gestures of the hand and the wheelchair will itself detect the obstacle while moving backward and stop automatically with ringing buzzer.

> :point_right: [Click here to view the working video of the prototype](https://youtu.be/21VLSIWCLYs)

---

:pushpin:  To built this prototype we have used following technologies  
- **ESP32 Microcontroller board**
- **MPU6050 Accelerometer Sensor** for gesture recognition
- **L298N Motor Driver** for controlling motors 
- **HC-SR04 Ultrasonic Sensor** for obstacle detection
- **Lithium ion Batteries** for supplying power to other components 
- **DC Motors** for the movement of wheelchair
- **ESP-NOW protocol** for wireless communication
- **Arduino IDE** for programming microcontroller


---
:pushpin:  This protoytpe consist of two circuits as explained below

### Gesture Recognition Circuit
This circuit is responsible for the detection of gestures made by users hand using accelerometer sensor and then transmitting signals to the wheelchair moving circuit by using ESP-NOW communication protocol.

### Wheelchair Moving Circuit 
This circuit is responsible for the movement of the wheelchair on the basis of signals came from gesture recogniton circuit, this circuit controls the direction of motors using motor driver which results in the desired movement of the wheelchair and this circuit is also responsible for the detection of obstacle using ultrasonic sensor. 
