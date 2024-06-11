# Arduino
The arduino, with the help of the SensorsArduino-file allows our different sensors to pick up data from from Marcai's surroundings via the arduino. 
The data will then be sent to our PI pico to be analyzed and interpreted in order for our AI to create songs inspired by the data gathered 
by our sensors.

## Table of Contents- 
- <u>[Features](#features)</u>
- <u>[DHT11 - Temperature and Humidity Sensor](#DHT11---Temperature-and-Humidity-Sensor)</u>
- <u>[APDS 9960 - Gesture, Proximity, RGB and Ambient](#APDS-9960---Gesture,--Proximity,-RGB-and-Ambient)</u>
- <u>[TODO](#TODO)</u>
- <u>[Acknowledgements](#Acknowledgements)</u>

## Features
- **Reads temperature** 
- **Reads level of humidity**
- **Reads colour of surroundings and meassures it in terms of R (red), G (green) and B (blue)**
- **Reads how close the device is to nearest obstacles**
- **Reads degree of brightness**
- **Interprets data and ships it to the Pico W**

## DHT11 - Temperature and Humidity Sensor
![image](https://github.com/ChasVasastan/SensorsArduino/assets/90247610/ff886cdf-08a3-4ff9-8850-492c6f330fd2)
Install DHT_Unified_Sensor library for the Arduino in PlatformIO 
And in order to see the data from the Hum/Temp. Sensor in VSC you also need to install the Serial Montior extension.

## APDS 9960 - Gesture, Proximity, RGB and Ambient
![image](https://github.com/ChasVasastan/SensorsArduino/assets/90247610/bf7ba742-1b05-4729-b156-98e1330615df)

## TODO
- **Add a microphone that works with the Arduino UNO**
- **Find ways to further read surroundings by new means**

## Acknowledgements
- [DHT11](https://learn.adafruit.com/dht/overview) Sensor for humidity and temperature
- [APDS 9960](https://www.adafruit.com/product/3595) Sensor for brightness, proximity and RGB
