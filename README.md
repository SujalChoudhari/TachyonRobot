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


## How does it works?

### BluetoothManager.h
Bluetooth Manager has few functions which are used to communicate between the controller and vehicle.
- `Next` method returns a character(input) if any or returns `STATE_NULL`.
- `Send` method is used to send any character to the controller.

### Constants.h
Constants.h is a simple config file which can be used to customize robot as per useage

### DetectionManager.h
Detection Manager manages the HC-SR04 Sensor. It only has one method `GetDistance` 
which returns the distance in cm.

### MotorManager.h
To manage Motors MotorManager can be used. it uses `MOTOR_` constants from Constants.h to setup motors.
It has functions to `MoveForward`, `MoveBackward`, `MoveLeft`, `MoveRight` and `Stop  which 
operates motors at max speed.

## ServoManager.h
This Class manages the servo and keeps track of the `currentAngle` of the servo motor.
It has a method `RotateTowards` which rotates towards a specific angle with respect to the body,
and not relative to current rotation angle. 

### Robot.h
Robot controls all the Managers and uses the mentioned Methods as per logic and States.
#### STATES
  Robot works on the principle of state machines. The Robot can be either of one state mentioned in  `Constants.h`.
  As per Input th switches between states and works accordingly.

Robot  `pollsInputs` and assigns the `currentState`, as per the inputs and `handleInputs` based on the current state.
Also depending upon the `currentState`, it automatically switches between states as per requirnment.  