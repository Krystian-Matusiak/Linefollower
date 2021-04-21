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

<img src="https://user-images.githubusercontent.com/62670083/115558073-a3bec900-a2b2-11eb-996d-28144064d336.PNG" width="1200" height="600">

### Mechanical structure
<img src="https://user-images.githubusercontent.com/62670083/115558298-e1bbed00-a2b2-11eb-9e51-73908bf1ae6d.jpg" width="600" height="300"> 
<img src="https://user-images.githubusercontent.com/62670083/115558300-e2ed1a00-a2b2-11eb-83ec-ea6341b9fce7.jpg" width="600" height="300">


### Documentation
