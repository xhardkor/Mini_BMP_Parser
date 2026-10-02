#ifndef BMP_HEADER
#define BMP_HEADER

#include "common.h"
#include <stdint.h>
#include <stdio.h>

#define HEADER_SIZE 14

typedef struct {
  uint16_t type;  // Identifier "B" and "M"
  uint32_t size;  // File Size
  uint16_t res_1; // Reserved bytes (both must be 0)
  uint16_t res_2; // Reserved bytes (both must be 0)
  uint32_t data;  // Pixel data Start
} BITMAPFILEHEADER;


ErrorCodes rw_header(FILE *f, BITMAPFILEHEADER *h, int mode);
ErrorCodes type_checker(FILE *f, BITMAPFILEHEADER *h);
void print_head(BITMAPFILEHEADER *f);

#endif
