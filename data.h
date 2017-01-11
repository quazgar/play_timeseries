#ifndef DATA_H
#define DATA_H

const float framerates[16] = {
   1000, 1000, 1000, 1000,  // 0..3
   1000, 1000, 1000, 1000,  // 4..7
   1000, 1000, 1000, 1000,  // 8..11
   100, 10, 10, 10,         // 12..15
};

#include "data_x.h"
/* extern const unsigned char* data0; */
/* extern const unsigned char* data1; */
/* extern const unsigned char* data2; */
/* extern const unsigned char* data3; */
/* extern const unsigned char* data4; */
/* extern const unsigned char* data5; */
/* extern const unsigned char* data6; */
/* extern const unsigned char* data7; */
/* extern const unsigned char* data8; */
/* extern const unsigned char* data9; */
/* extern const unsigned char* data10; */
/* extern const unsigned char* data11; */
/* extern const unsigned char* data12; */
/* extern const unsigned char* data13; */
/* extern const unsigned char* data14; */
/* extern const unsigned char* data15; */


// we need to use "pgm_get_far_address" to convert the numbers to
// addresses in the larger progmem address space.
uint32_t data[16];

const uint32_t data_lengths[16] = {
   sizeof(data0),  sizeof(data1),  sizeof(data2),  sizeof(data3),
   sizeof(data4),  sizeof(data5),  sizeof(data6),  sizeof(data7),
   sizeof(data8),  sizeof(data9), sizeof(data10), sizeof(data11),
  sizeof(data12), sizeof(data13), sizeof(data14), sizeof(data15)
};

#endif //DATA_H
