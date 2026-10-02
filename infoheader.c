#include "infoheader.h"

ErrorCodes rw_header_v4(FILE *f, BITMAPV4HEADER *h, int mode) {
  switch (mode) {
    case READ_MODE:
      fread(&h->size, sizeof(h->size), 1, f);
      fread(&h->width, sizeof(h->width), 1, f);
      fread(&h->heigh, sizeof(h->heigh), 1, f);
      fread(&h->planes, sizeof(h->planes), 1, f);
      fread(&h->bpp, sizeof(h->bpp), 1, f);
      fread(&h->compression, sizeof(h->compression), 1, f);
      fread(&h->image_size, sizeof(h->image_size), 1, f);
      return NO_ERROR;
      break;
    case WRITE_MODE:
      fwrite(&h->size, sizeof(h->size), 1, f);
      fwrite(&h->width, sizeof(h->width), 1, f);
      fwrite(&h->heigh, sizeof(h->heigh), 1, f);
      fwrite(&h->planes, sizeof(h->planes), 1, f);
      fwrite(&h->bpp, sizeof(h->bpp), 1, f);
      fwrite(&h->compression, sizeof(h->compression), 1, f);
      fwrite(&h->image_size, sizeof(h->image_size), 1, f);
      return NO_ERROR;
      break;
    default:
      printf("That Mode doesn\'t exist\n");
      return ERROR_DIF_MODE;
      break;
  }
}

ErrorCodes copy_v4(FILE *first_f, FILE *new_f, BITMAPV4HEADER *h) {
  if(h->size != 108 && h->size != 40) {
    return ERROR_DIFFERENT_SIZE;
  }
  uint32_t buf_size = h->size - sizeof(*h);
  uint8_t buf[buf_size];
  fread(buf, buf_size, 1, first_f);
  fwrite(buf, sizeof(buf), 1, new_f);
  return NO_ERROR;
}


void invert_image_v4(BITMAPV4HEADER *h, FILE *first_f, FILE *new_f) {

  uint32_t row_size = ((h->width * h->bpp + 31)/32) * 4;
  uint32_t act_row = (h->width * h->bpp) >> 3;
  uint32_t dif = row_size - act_row;

  uint32_t using;
  if(dif != 0) {
    using = act_row;
  } else {
    using = row_size;
  }

  for(int i = 0; i < h->heigh; i++) {
    uint8_t buf[row_size];
    fread(buf, row_size, 1, first_f);

    for(int j = 0; j < using; j++){
      buf[j] = 255 - buf[j];
    }
    fwrite(buf, sizeof(buf), 1, new_f);
  }
}
