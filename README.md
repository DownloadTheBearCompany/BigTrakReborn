# BigTrakReborn
BigTrak reborn, driving it outdoor.

# Two components to this project
- **User interface**, the iPhone/iPodTouch/iPad and Spectrum Analyzer Shield
- **Drive train interface**, Arduino Uno and the RC car

# User interface
We want to use the Spectrum Analyzer Shield to process Audio signal that's
generated from the RealSmartz App. First obtain a male to male AUX cable. Plug
one end to the input jack of the shield and the other to the Apple device. For
the newer Apple device you need to obtain an extension cable. Next, launch
the RealSmartz App.

# Drive train interface
Attach the Spectrum Analyzer Shield to the Arduino Uno and pwm pin 3 to Servo
and 5 to ESC of the RC car. First make sure the pins line up correctly between
the Spectrum Analyzer Shield and Arduino. Push down with slight pressure and the
two parts should fuse into one unit. Next, connect the power of the servo to v3
and ground of the Arduino

# Putting everything together
Upload the driveTrainArduino/driveTrainArduino.ino to the Arduino and test
everything out.

# Test it out on the field
Added a few GPS instructions on RealSmartz App. The RC car should be able to
drive towards the GPS way points. If you RC Car is behaving incorrectly. Give
your iPhone a call. It will stop the Car at its track.
