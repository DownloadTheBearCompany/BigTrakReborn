# BigTrakReborn
BigTrak reborn, driving it outdoor.
![img](https://luminousambient.files.wordpress.com/2018/06/bigtrakreborn.jpg)

# Two components to this project
- **User interface**, the iPhone/iPodTouch/iPad and Spectrum Analyzer Shield
- **Drive train interface**, Arduino Uno and the RC car

# 1 - User interface
We want to use the Spectrum Analyzer Shield to process Audio signal that's
generated from the RealSmartz App. First obtain a male to male AUX cable. Plug
one end to the input jack of the shield and the other to the Apple device. For
the newer Apple device you need to obtain an extension cable. Next, launch
the RealSmartz App.

# 2 - Drive train interface
Attach the Spectrum Analyzer Shield to the Arduino Uno and pwm pin 3 to Servo
and 5 to ESC of the RC car. First make sure the pins line up correctly between
the Spectrum Analyzer Shield and Arduino Uno. Push down with slight pressure and the
two parts should fuse into one unit. Next, connect the power of the servo to v3
and ground of the Arduino.

# ✅ Putting everything together
Upload and modify the [driveTrainArduino/driveTrainArduino.ino](https://github.com/DownloadTheBearCompany/BigTrakReborn/blob/master/driveTrainArduino/driveTrainArduino.ino) to the Arduino and test everything out.
The Servo and ESC value is specific to your RC car and may not be the same.

![img](https://luminousambient.files.wordpress.com/2018/06/audioshield.jpeg)

# Materials

- RealSmartz running on Apple device [iPhone, iPad, iPod touch]:
    - https://itunes.apple.com/us/app/real-smartz/id1384290599?ls=1&mt=8
- Spectrum Analyzer Shield:
    - https://www.sparkfun.com/products/13116
    - https://www.ebay.com/itm/Arduino-Uno-Compatible-Dual-MSGEQ7-Spectrum-Analyzer-Breakout-Board-Shield/322619787678
- Male to male AUX(2.5 Audio) cable
- Arduino Uno: https://store.arduino.cc/usa/arduino-uno-smd-rev3
- Arduino Uno drive train program
    - https://github.com/DownloadTheBearCompany/BigTrakReborn/blob/master/driveTrainArduino/driveTrainArduino.ino
- RC Car, **convert the RC car to the point it's drivable with the Arduino**
    - https://www.sparkfun.com/tutorials/348
    - http://www.instructables.com/id/RC-Car-to-Robot/
    - http://www.instructables.com/id/How-to-convert-almost-any-27-or-49-MHz-RC-Car-in/
    - More: https://www.google.com/search?q=convert+rc+car+arduino&oq=convert+rc+car+arduino

# Test it out on the field
Added a few GPS instructions on RealSmartz App. The RC car should be able to
drive towards the GPS way points. If your RC Car is behaving incorrectly. Give
your iPhone a call. It will stop the Car at its track.
