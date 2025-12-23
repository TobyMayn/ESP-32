# ESP-32 Embedded project

This repository documents my journey learning embedded programming using the ESP-32 Wrover dev kit from freenove.
Development kit can be found here: [ESP-32 Dev Kit](https://store.freenove.com/products/fnk0046)

I will do my best to document the project as it comes along. Starting with the tutorial code that comes with the device.

In the end, I will build a final project for a home monitor system that will let me know when to air out the apartment.

## Setup

For the project im using **vs-code** with the *PlatformIO IDE* plugin to build and upload code to the device.

Important Note: As the tutorial code is meant to be run in the Arduino IDE, it is necessary to import the `<Arduino.h>` header file, in order for the Intellisense to recognise the functions provided in the tutorial code.

Additional Note: Some functions from the tutorial has been deprecated and will need to be changed to the newer functions defined in this [readme](https://github.com/espressif/arduino-esp32/blob/master/docs/en/migration_guides/2.x_to_3.0.rst)