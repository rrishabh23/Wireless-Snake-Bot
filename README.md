# Wireless-Snake-Bot

The snake contains 12 segments actuated by servo motors and joined with metal brackets. The servos are controlled by an Arduino Mega and
powered by a LiPo battery. It uses NodeMCU(ESP8266) for wireless control.
An Android device is used to control the bot with the use of this [app](https://github.com/rrishabh23/Wireless-Snake-Bot/blob/master/SnakeBot%20Control.apk).

The Simulation Folder contains a rough simulation of motors connected with arduino Mega. It contains a different code to be uploaded on the virtual arduino for the visualisation of motion. The simulation is done on Proteus Design Suite.

The Actual Code is divided into two parts.
The two seperate codes in the Codes folder are to be uploaded on Arduino Mega and NodeMCU respectively.



![Working](/Results.gif)

Clarification: The wire is for power supply, controlling is done via an Android Device. Even though the bot runs on 7.4V supply, we had to use a 12V LiPo battery which is heavier and slows the bot a bit which is why we decided not to mount it on the bot itself.

This is based on the work of [joesinstructables](https://www.instructables.com/member/joesinstructables/).
