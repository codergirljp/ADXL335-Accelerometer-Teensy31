ADXL335-Accelerometer Teensy3.1
=================================

This repository contains code to calibrate and obtain values from the ADXL335 Accleerometer using the Teensy 3.1 board. 


ADXL335Calibration.ino
This is a sketch modified from the Adafruit calibration code to allow calibration of the accelerometer through serial data input and avoid additional hardware setup for the calibration procedure.


TeensyAdxl335.ino
This is a small sketch that used the measured values from the calibration of the accelerometer 
to noralize x y z values to +/- 1 G's 
The sketch sends normalized measured values as a space delimited list to the serial port over a USB connection.

