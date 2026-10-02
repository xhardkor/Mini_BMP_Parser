#ifndef BMP_BITMAPV4HEADER
#define BMP_BITMAPV4HEADER

#include "common.h"
#include <stdint.h>
#include <stdio.h>

// Different sizes = Different versions of BITMAP HEADER
// 40, 108, 124 bytes
typedef struct {
  uint32_t size;
  int32_t width;
  int32_t heigh;
  uint16_t planes;
  uint16_t bpp;
  uint32_t compression;
  uint32_t image_size;
} BITMAPV4HEADER; // size = 108

ErrorCodes rw_header_v4(FILE *f, BITMAPV4HEADER *h, int mode);
ErrorCodes copy_v4(FILE *first_f, FILE *new_f, BITMAPV4HEADER *h);
void invert_image_v4(BITMAPV4HEADER *h, FILE *first_f, FILE *new_f);

#endif
