# Bosh&trade; BMP180 Pressure & Temperature Sensor Library

The library provides proper communication between AVR Based microcontrollers and BMP180 sensor. 

#### Usage #1 / Calculation
```C

#include "bmp180/bmp180.c"
#include "uart.c"

/**
* There are 3 modes of operation 
* check the header file bmp180.h for details.
*/

init_sensor(bmp180_mode_0);
calculate();
```

#### Usage #2 / Results
Results is stored in struct. 

| Variable Name | Type |
|---------------|------|
|bmp_180.temperature|`long`|
|bmp_180.pressure|`long`|
|bmp_180.altitude|`float`|



