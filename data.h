#ifndef DATA_H
#define DATA_H

const float framerates[16] = {
   1000, 1000, 1000, 1000,  // 0..3
   1000, 1000, 1000, 1000,  // 4..7
   1000, 1000, 1000, 1000,  // 8..11
   100, 10, 10, 10,         // 12..15
};


// 256kB / 16 = 16kB
const unsigned char data0[] PROGMEM = {
  #include "data/data1.h"
  //3, 1, 4, 1, 5, 9, 2, 6, 5, 8, 9, 7, 9
};
const unsigned char data1[] PROGMEM = {
  #include "data/data1.h"
};
const unsigned char data2[] PROGMEM = {
  #include "data/data2.h"
};
const unsigned char data3[] PROGMEM = {
  #include "data/data3.h"
};
const unsigned char data4[] PROGMEM = {
  #include "data/data4.h"
};
const unsigned char data5[] PROGMEM = {
  #include "data/data5.h"
};
const unsigned char data6[] PROGMEM = {
  #include "data/data6.h"
};
const unsigned char data7[] PROGMEM = {
  #include "data/data7.h"
};
const unsigned char data8[] PROGMEM = {
  #include "data/data8.h"
};
const unsigned char data9[] PROGMEM = {
  #include "data/data9.h"
};
const unsigned char data10[] PROGMEM = {
  #include "data/data10.h"
};
const unsigned char data11[] PROGMEM = {
  #include "data/data11.h"
};
const unsigned char data12[] PROGMEM = {
  #include "data/data12.h"
};
const unsigned char data13[] PROGMEM = {
  #include "data/data13.h"
};
const unsigned char data14[] PROGMEM = {
  #include "data/data14.h"
};
const unsigned char data15[] PROGMEM = {
  #include "data/data15.h"
};

const unsigned long data[] = {
  (const unsigned long)data0,  (const unsigned long)data1,
  (const unsigned long)data2,  (const unsigned long)data3,
  (const unsigned long)data4,  (const unsigned long)data5,
  (const unsigned long)data6,  (const unsigned long)data7,
  (const unsigned long)data8,  (const unsigned long)data9,
  (const unsigned long)data10, (const unsigned long)data11,
  (const unsigned long)data12, (const unsigned long)data13,
  (const unsigned long)data14, (const unsigned long)data15,
};

const size_t data_lengths[16] = {
   sizeof(data0),  sizeof(data1),  sizeof(data2),  sizeof(data3),
   sizeof(data4),  sizeof(data5),  sizeof(data6),  sizeof(data7),
   sizeof(data8),  sizeof(data9), sizeof(data10), sizeof(data11),
  sizeof(data12), sizeof(data13), sizeof(data14), sizeof(data15)
};

#endif //DATA_H
