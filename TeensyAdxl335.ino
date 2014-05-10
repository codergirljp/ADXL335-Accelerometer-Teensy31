// Sketch for the ADXL335 
// Reads the raw X, Y Z values from the accelerometer and normalizes them to +/-1 range.
// Tested on the Teensy 3.1
// For use with project found at 
// http://codergirljp.blogspot.com/2014/05/adxl335-accelerometer-on-teensy-31.html

// Analog Input Pins used for the X,Y,Z 
const int xInput = 0;  // A0 on the Teensy 3.1
const int yInput = 1;  // A1 on the Teensy 3.1
const int zInput = 2;  // A2 on the Teensy 3.1

// min/max values for each axis
// measured from calibration (see the 
const int xMin = 398; // (-1 G)
const int xMax = 596; // (+1 G)

const int yMin = 396; // (-1 G)
const int yMax = 597; // (+1 G)

const int zMin = 413; // (-1 G)
const int zMax = 612; // (+1 G)
    
int xVal=0;
int yVal=0;
int zVal=0;

void setup()
{                
  Serial.begin(38400);
}

void loop()                     
{
  // get a reading
  xVal = analogRead(0);
  yVal = analogRead(1);
  zVal = analogRead(2);
  
  // Convert raw values to 'milli-Gs"
  long xScaled = map(xVal, xMin, xMax, -1000, 1000);
  long yScaled = map(yVal, yMin, yMax, -1000, 1000);
  long zScaled = map(zVal, zMin, zMax, -1000, 1000);
  
  // re-scale to fractional +/- 1 Gs
  float xAccel = xScaled / 1000.0;
  float yAccel = yScaled / 1000.0;
  float zAccel = zScaled / 1000.0;
 
  
 // Send the scaled measurements as a space delimited list x y z
  Serial.print(xAccel);
  Serial.print(" ");
  Serial.print(yAccel);
  Serial.print(" ");
  Serial.println(zAccel); 
  delay(100);
}
