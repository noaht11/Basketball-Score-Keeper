# Basketball Score Keeper

A simple Arduino program to automatically keep score on an indoor mini basketball hoop.

## Required Components:
* Arduino UNO
* Flex Sensor (https://www.sparkfun.com/products/10264)
* Piezo Speaker (https://www.sparkfun.com/products/7950)
* LCD Display (https://www.sparkfun.com/products/9395)
* Toggle switch
* Push button
* 9V Battery
* Breadboard
* Indoor mini basketball hoop

## Circuit:
![Circuit Setup](/docs/Circuit_Setup.png)

## Assembly Instructions:
1. Assemble the circuit as shown in the above diagram
* You will want to have long wires for any components that connect to the Arduino since the Arduino will be positioned far away from the basketball hoop itself
2. Mount the breadboard (with the flex sensor) underneath the basketball hoop, in a position such that a basketball going through the hoop will bend the flex sensor:
!![Mounted Breadboard](/docs/Mounted_Breadboard.jpg)
3. You can construct a container out of wood or plastic to house the Arduino and/or LCD screen. The one I used is shown here:
![Arduino Container](/docs/Arduino_Container_1.jpg)
![Arduino Container](/docs/Arduino_Container_2.jpg)

## Operating Instructions:
1. When the toggle switch is turned on, the LCD screen should turn on and display the following:
![LCD Display](/docs/LCD_Display.jpg)
2. Press the push button to start a 60 second round
3. You should hear a beep when the round starts
4. Everytime you score a basket, you should hear a beep and the score should increase
5. At the end of the round, you will hear three consecutive beeps, and no more baskets will be countede
