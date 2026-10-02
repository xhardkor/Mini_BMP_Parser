#include "header.h"

ErrorCodes err;

/*
 * Modes:
 * READ_MODE   = Read
 * WRITE_MODE  = Write
*/
ErrorCodes rw_header(FILE *f, BITMAPFILEHEADER *h, int mode) {
  switch (mode) {
    case READ_MODE:
      err = type_checker(f, h);
      if(err != NO_ERROR) {
        return err;
      }
      fread(&h->size, sizeof(h->size), 1, f);
      fread(&h->res_1, sizeof(h->res_1), 1, f);
      fread(&h->res_2, sizeof(h->res_2), 1, f);
      fread(&h->data, sizeof(h->data), 1, f);
      return NO_ERROR;
      break;
    case WRITE_MODE:
      fwrite(&h->type, sizeof(h->type), 1, f);
      fwrite(&h->size, sizeof(h->size), 1, f);
      fwrite(&h->res_1, sizeof(h->res_1), 1, f);
      fwrite(&h->res_2, sizeof(h->res_2), 1, f);
      fwrite(&h->data, sizeof(h->data), 1, f);
      return NO_ERROR;
      break;
    default:
      printf("That Mode doesn\'t exist\n");
      return ERROR_DIF_MODE;
      break;
  }
}
ErrorCodes type_checker(FILE *f, BITMAPFILEHEADER *h) {
  fread(&h->type, sizeof(h->type), 1, f);
  switch (h->type) {
    case 0x4d42:
      return NO_ERROR;
    default:
      return ERROR_UNSUPPORTED_BITMAP;
  }
}
void print_head(BITMAPFILEHEADER *f) {
  printf("%04X\n", f->type);
  printf("%04X\n", f->size);
  printf("%04X\n", f->res_1);
  printf("%04X\n", f->res_2);
  printf("%04X\n", f->data);
}
