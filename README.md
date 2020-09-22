#Light Control Script for use with arduino

## Requirments
	- Arduino Nano
	- NeoPixel Led Light Strip
	- Computer with python

## Setup
	- Flash Code to arduio
	- install pySerial
		> pip install pyserial
## Example
```python

import serial
usb = 0
s = serial.Serial(f'/dev/ttyUSB{usb}')
# serail data format 1byte Red 1byte Green 1byte Blue 1byte delay
s.write(b'\xf3\x06\x58\x03\xff')	

```	
