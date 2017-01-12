// -*- mode:c++; -*-
#include <avr/pgmspace.h>

#include "data.h"

// rotary encoder
unsigned int bit8 = 11;
unsigned int digits = 4;

// analog output
unsigned int dataPin = 12;

float framerate = 100;

void setup()
{
  Serial.begin(9600);      // open the serial port at 9600 bps

  init_data();
  for (unsigned int ii = 0; ii < digits; ++ii) {
    pinMode(bit8 - ii, INPUT);
  }
  pinMode(dataPin, OUTPUT);
  // Set PWM timer for pins 11 and 12
  // https://arduino-info.wikispaces.com/Arduino-PWM-Frequency
  TCCR1B = TCCR1B & B11111000 | B00000010;

};

void init_data() {
  data[0] = pgm_get_far_address(data0);
  data[1] = pgm_get_far_address(data1);
  data[2] = pgm_get_far_address(data2);
  data[3] = pgm_get_far_address(data3);
  data[4] = pgm_get_far_address(data4);
  data[5] = pgm_get_far_address(data5);
  data[6] = pgm_get_far_address(data6);
  data[7] = pgm_get_far_address(data7);
//  data[8] = pgm_get_far_address(data8);
//  data[9] = pgm_get_far_address(data9);
//  data[10] = pgm_get_far_address(data10);
//  data[11] = pgm_get_far_address(data11);
//  data[12] = pgm_get_far_address(data12);
//  data[13] = pgm_get_far_address(data13);
  data[14] = pgm_get_far_address(data14);
  data[15] = pgm_get_far_address(data15);

  Serial.println("");
//  for (size_t ii = 0; ii < 16; ++ii) {\
//    String s = "";
//    s += ii;
//    s += "  ";
//    s += data[ii];
//    s += "  ";
//    s += data_lengths[ii];
//    s += "  ";
//    s += data[ii] + data_lengths[ii];
//    Serial.println(s);
//  }
}

void loop()
{

  unsigned char pos = position();
//  Serial.println((unsigned long)data[pos]);
  play_data(pos);
//  delay(1000);
}

void play_data(unsigned char data_index){
  float framerate = framerates[data_index];
  unsigned int delay_t = round(1000.0/framerate);
  uint32_t len = data_lengths[data_index];
  uint32_t base_ii = data[data_index];
  unsigned long time1, time2;
  time1 = micros();
  for (uint32_t ii = 0 ; ii < len; ++ii) {
    if ((data[data_index] + ii) < data[data_index]) {
      Serial.print("overflow! ");
      Serial.print(ii);
      Serial.print("  ");
      Serial.println(data[data_index]);
    }
    uint32_t pgm_pos = base_ii + ii;
    // sets the value (range from 0 to 255):
    unsigned char value = pgm_read_byte_far(pgm_pos);
    analogWrite(dataPin, value);
    // Serial.println(value);
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
    Serial.print(digitalRead(bit8 - ii));
  }
  Serial.print("\tposition: ");
  Serial.println(result);
  return result;
}


