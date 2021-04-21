# Linefollower

## Introduction
The object of the project is Linefollower - mobile robot equipped with six reflective optical sensors. Each of them allows to detect black line. Thanks to these data we can make him follow the line automatically. Additionally all informations related with linefollower will be visualized. 

### Hardware
To process data from sensors I used STM32F303K8. This microcontroller provides all needed peripherals:
* ADC -- to gathering signals from sensors,
* Timers -- to set pulse width modulation (PWM),
* Serial communication -- to connect stm32 with Raspberry Pi,
* GPIO -- to set directory, enable other devices etc.

Moreover Raspberry Pi will be used to send data via sockets to remote PC. These informations will be visualised due to Qt framework.


### Mechanical structure

### Documentation
