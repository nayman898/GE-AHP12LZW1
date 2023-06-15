# GE-AHP12LZW1
Custom software for Arduino Uno to run your own control module for the AC unit

## Arduino Uno Information:
This setup utilizes a handful of componets available in most Arduino Uno Kits, I used a collection of parts from a couple kits I had. Notably, I used the Temperature Sensor DHT11, the 5V Relays SRD-05VDC-SL-C. The LCD was a standard 16x2 lcd that is also common with the kits. In my final product, I am not using the LCD, but I used it for debugging throughout the process of writing the code.

## Arduino Uno Setup:
For this setup, I used the standard LCD configuration found [here](https://www.circuitbasics.com/how-to-set-up-an-lcd-display-on-an-arduino/)

As well as the Digital port for the Temperature Sensor. I used the D7 port, you can use whichever. The setup for this can be found [here](https://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/)

Now to the fun part, to get this system to work, you'll need to understand what the AC needs to work. The AC runs its components on 5v switches to each fan speed, and to the compressor. Using that information and the readouts on the PCB of the controller board, you can determine that there is a 5v in, and 4 wires to control the rest. They are as follows
- Low speed: Blue
- Medium speed: Green
- High Speed: Yellow
- Compressor: White
- Black: 5V

These are all of the wires I used in my setup. I found that they were the only ones needed to get the AC to run. You are able to do output 5v by changing your Analog Inputs to Outputs on the Arduino, however they do not provide enough consistent power to turn on any of the settings, for that I opted to use the existing 5v power supply that the AC already has, and wire it into 5V switched relays. These relays will switch on when they get the 5v signal from the Arduino, then pass the power through to whichever connection you have hooked up. For my code, I ran A0 to the compressor, then A1-3 to low-high respectively. 

## Wiring the 5v Relays
Wiring these relays took me quite a bit of time to figure out, but what I ended up using was, with the bottom facing you, and the 3 pins at the top:
- Upper left pin is your analog value from the Arduino
- Upper Center is the power from the AC
- Upper Right is Ground
- Lower Left is whatever you are switching on
- Lower Right is unused

I will provide pictures of this layout when I can. 

## Conclusion
This setup is VERY DIY, I have been testing it for the past couple days, and it has worked succesfully for me, however if you do not wire things correctly, or securely, you could run into problems. 

Some things to be aware of with this setup, the fan and compressor will turn off at the same time when they are done, this code was not designed to run one over the other, but if you notice your fan is on, and the compressor is not, it is because the compressor entered its off timer state. This is required to prevent the compressors solenoid from frying, when the compressor turns off, it will stay off for 30 seconds. Similarly, once the fan and compressor reach their target temps they will stay on for an additional 15 seconds, however this value can be customized however you want.

And one last note, this is my first Arduino project. I have worked in Robots before, and am a Software Engineer working in Azure cloud services. While I think this code is functional, it is by no means optimized. Please feel free to make changes and upgrades as you see fit, I am always ready to learn!
