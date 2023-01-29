# Tachyon Robot

## What is Tachyon?
Tachyon is a Remote Controlled Obstacle Avoiding Robot.
It is Bluetooth Controlled, i.e. Wireless Controller. 
It uses [TachyonController](https://github.com/SujalChoudhari/TachyonController) application as a Bluetooth Controller.

*Note: Address of HC-05 is hard codded in the application, rebuild the application for personal use-cases.

## Third-party Applications
Third party Controllers are Supported as well. 
These applications are needed to be configured as per the `Constants.h` or vise versa. 


## Libraries Used
1. AFMotor.h 
2. Servo.h

## Components
1. Arduino UNO
2. L293D Motor Shield. (Four motors + 2 servos)
3. Servo Motor SG-90
4. HC-SR04 Ultrasonic Sensor
5. HC-05 Bluetooth Module
6. Chassis (4WD)
7. 4x Gear Motors + Wheels 

## Setting Up
Again only `Constants.h` file is needed to setup. As per dimentions and turning radius of the vehicle. 
You can achive personalisation.