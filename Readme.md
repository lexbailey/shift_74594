# Arduino Library for 74594 SIPO shift register

## Installation
to install, clone this repo (into a folder called shift_74594) and then copy the folder into the 'libraries' folder in your arduino installation.

## Usage
Instatiate the shift_74594 class near the top of your sketch.
Change the pin names below to the numbers of the arduino pins.
```
    shift_74594 myShifter = shift_74594(SER, SCK, RCK, SCLR, RCLR);
```

In the arduino setup function, call the init function on the shifter instance
```
    myShifter.init();
```

Then you can set the value of a shift register like so:
```
    myShifter.setByte(someOutputchar);
    myShifter.latch();
```

If you have chained multiple shift registers together then you can write each one in sequence and follow with a single latch() call.
```
    myShifter.setByte(someOutputchar0);
    myShifter.setByte(someOutputchar1);
    myShifter.setByte(someOutputchar2);
    myShifter.latch();
```
