# DigitalThermometer
This is a pet project. I have created a digital thermometer using Arduino NANO, DS18B20 digital temperature sensor and 1602A LCD, which measures temperature in four different scales. I.e., Celsius, Kelvin, Fahrenheit and Réaumur.

## Features
- Measures temperature in Celsius, Kelvin, Fahrenheit and Reaumur
- Uses Arduino NANO as the main controller
- Utilizes DS18B20 digital temperature sensor for accurate readings
- Displays temperature on 1602A LCD
- Supports temperature conversion between scales

## Construction
You can use any construction approach you like (breadboard, pcb, suspended installation, etc.).
I have used a suspended installation for prototyping and testing.
The components you'll need are as follows:
- Arduino NANO microcontroller debugging board
- DS18B20 digital temperature sensor
- 1602A LCD display
- 2 x LiIon 18650 batteries (Is very comfortable to construct with 2 18650 batteries as 2 batteries have almost the same size as 1602A LCD )
- 2 x 18650 battery holders
- Any TP4056 charger module
- Any MT3608 DC→DC Step UP module
- 1 x 300 Ohm 1/4 W 1% resistor
- 1 x 1k 1/4 W 1% resistor
- 1 x 4k7 1/4 W 1% resistor
- 1 x 100k 1/4 W 1% resistor
- Wires
- Soldering iron
- Solder
- Flux

## Device assembly
To assemble all parts appropriately, use the [Schematic](https://github.com/EugenStadnik/DigitalThermometer/blob/master/DigitalThermometerScheme.jpg)

## Flash microcontroller
First to flash the microcontroller you need to install the https://github.com/GyverLibs/microDS18B20 library.
Then figure out your DS18B20 digital temperature sensor unique address using following steps
https://github.com/GyverLibs/microDS18B20?tab=readme-ov-file#%D1%87%D1%82%D0%B5%D0%BD%D0%B8%D0%B5-%D0%B0%D0%B4%D1%80%D0%B5%D1%81%D0%B0 
and edit the ```uint8_t addr[] = {0x28, 0x7F, 0xB2, 0xBF, 0x0, 0x0, 0x0, 0x65};``` variable with appropriate velue.
Use either Arduino IDE or Xgpro with any applicable T48, T56 or any other flasher.
