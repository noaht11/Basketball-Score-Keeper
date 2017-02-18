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
* Breadboard (optional)
* Indoor mini basketball hoop

## Circuit:
![alt tag](/Circuit_Setup.png)

## Assembly Instructions:
1. Assemble the circuit as shown in the above diagram (optionally using the breadboard to make it easier).
* You will want to have long wires for any components that connect to the Arduino since the Arduino will be positioned far away from the basketball hoop itself
2. Mount the flex sensor (and possibly the breadboard as well)  underneath the basketball hoop, in a position so that a basketball going through the hoop will bend the flex sensor.
3. You can make a box or container for the Arduino or LCD screen out of wood or plastic. The one I used is shown here:

## Operating Instructions:
1. When the toggle switch is turned on, the LCD screen should turn on and display the following:
(Insert picture)
2. Press the push button to start a 60 second round
3. You should hear a beep when the round starts
4. Everytime you score a basket, you should hear a beep and the score should increase
5. At the end of the round, you will hear three consecutive beeps, and no more baskets will be countede
