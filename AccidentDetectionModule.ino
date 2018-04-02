#include <Wire.h>
#include <ADXL345.h>

ADXL345 adxl; //variable adxl is an instance of the ADXL345 library
 /* 5v - CS
  *  GND - GND
  *  A4 - SDA
  *  A5-SCL
 
 
 */
int x, y, z;
int rawX, rawY, rawZ;
int mappedRawX, mappedRawY;




void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
    adxl.powerOn();
}

void loop() {
  // put your main code here, to run repeatedly:
  adxl.readAccel(&x, &y, &z); //read the accelerometer values and store them in variables  x,y,z

  rawX = x - 7;
  rawY = y - 6;
  rawZ = z + 10;

  mappedRawX = map(rawX, -255, 255, 0, 180);
  mappedRawY = map(rawY, -255, 255, 0, 180);

   Serial.print(" mappedRawX = "); Serial.print(mappedRawX); // raw data with offset
  Serial.print(" mappedRawY = "); Serial.println(mappedRawY); // raw data with offset

  if( mappedRawY < 50 || mappedRawX > 130 || mappedRawX < 50){

     Serial.print(" Accident Detected"); 
    
    }

   

  delay(2000);
  

}
