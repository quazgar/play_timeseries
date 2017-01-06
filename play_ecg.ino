//#include <avr/pgmspace.h>

#include "data.h"

// rotary encoder
unsigned int bit8 = 11;
unsigned int digits = 4;

// analog output
unsigned int dataPin = 12;

float framerate = 100;

void setup()
{
  // set input and output pins
//  for (unsigned int ii = 0; ii < digits; ++ii) {
//    pinMode(bit8 - ii, INPUT);
//  }

  pinMode(dataPin, OUTPUT);

  Serial.begin(9600);      // open the serial port at 9600 bps
}

void loop()
{
  unsigned char pos = position();
  play_data(pos);
  delay(500);
}

void play_data(unsigned char data_index){
  float framerate = framerates[data_index];
  unsigned int delay_t = round(1000.0/framerate);
  size_t len = data_lengths[data_index];
//  Serial.println(len);
//  Serial.println(data_index);
  unsigned long time1, time2;
  time1 = micros();
  for (size_t ii = 0 ; ii < len; ++ii) {
    // sets the value (range from 0 to 255):
    analogWrite(dataPin, pgm_read_byte(data[data_index] + ii));
    delay(delay_t);
  }
  time2 = micros();
  Serial.print("time[us] per frame: ");
  Serial.println((time2-time1)*1.0/len);

}

unsigned char position() {
  unsigned char result = 0;
  for (unsigned int ii = 0; ii < digits; ++ii) {
    result <<= 1;
    result += digitalRead(bit8 - ii);
  }
  Serial.print("position: ");
  Serial.println(result);
  return result;
}

