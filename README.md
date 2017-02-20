# Basketball Score Keeper

A simple Arduino program to automatically keep score on an indoor mini basketball hoop.

**Completed Project:**

<img src="/docs/img/Overall.jpg" width="512">

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

<img src="/docs/img/Breadboard_Mount_Unshielded.jpg" width="256">

3. You can construct a container out of wood or plastic to house the Arduino and/or LCD screen. The one I used is shown here:

<img src="/docs/img/Arduino_Container_Outside.jpg" width="256">
<img src="/docs/img/Arduino_Container_Inside.jpg" width="256">

## Operating Instructions:
1. When the toggle switch is turned on, the LCD screen should turn on and display the following:

<img src="/docs/img/LCD_Display.jpg" width="256">

2. Press the push button to start a 60 second round
3. You should hear a beep when the round starts
4. Everytime you score a basket, you should hear a beep and the score should increase
5. At the end of the round, you will hear three consecutive beeps, and no more baskets will be counted

## Customization/Troubleshooting:
For the most part any customization you may need can be done by adjusting the constants at the top of the source code. In particular, the following things might need to be adjusted:
* ```FLEX_TOLERANCE```
 * This value is added to the initial reading of the flex sensor to determine the "unflexed position"
* ```FLEX_THRESHOLD```
 * This is the minimum change in flex from the "unflexed position" that will be considered a basket.
* ```ROUND_TIME```
 * This can be adjusted to change the length of a single round (measured in seconds).
 
**Other tips**
* If you are finding some baskets are going in without triggering the flex sensor then you can extend the sensor itself by taping on a strip of cardboard
* If you want to protect the breadboard components from the basketball, you can add a shield in front of the breadboard. I used a piece of scrap sheet metal as pictured here:
 
 <img src="/docs/img/Breadboard_Mount_Shielded.jpg" width="256">
