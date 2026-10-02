#include <stdint.h>
#include <stdio.h>
#include "common.h"
#include "header.h"
#include "infoheader.h"


//MAIN:
int main(int argc, char **argv) {
  char *file_name = argv[1];
  char *new_file_name = argv[2];
  if(!file_name || !new_file_name) {
    printf("One of 2 files not passed!\n");
    return ERROR_NO_FILES;
  }

  FILE *first_file = fopen(file_name, "rb");
  if (!first_file) {
    printf("File doesn\'t exist: %s\n", file_name);
    return ERROR_FILE_DOESNT_EXIST;
  }

  BITMAPFILEHEADER head;
  BITMAPV4HEADER info;
  ErrorCodes err;

  err = rw_header(first_file, &head, READ_MODE);
  if(err != NO_ERROR) {
    printf("RW header READ error\n");
    return err;
  }

  err = rw_header_v4(first_file, &info, READ_MODE);
  if(err != NO_ERROR) {
    printf("RW info header READ error\n");
    return err;
  }


  FILE *new_file = fopen(new_file_name, "wb");
  err = rw_header(new_file, &head, WRITE_MODE);
  if(err != NO_ERROR) {
    printf("RW header WRITE error\n");
    return err;
  }
  err = rw_header_v4(new_file, &info, WRITE_MODE);
  if(err != NO_ERROR) {
    printf("RW INFO header WRITE error\n");
    return err;
  }
  err = copy_v4(first_file, new_file, &info);
  if(err != NO_ERROR) {
    printf("%d\n", info.size);
    printf("Copy error\n");
    return err;
  }

  invert_image_v4(&info, first_file, new_file);

  fclose(new_file);
  fclose(first_file);
  return EXIT_OK;
}
