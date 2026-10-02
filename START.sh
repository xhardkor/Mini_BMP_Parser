#!/bin/bash

IMAGE_FILE="${PWD}/${1#./}"
NEW_IMAGE_FILE="${2/%/.bmp}"
DEBUG=$3
C_FILES=( *.c )

if [[ $DEBUG != "-t" || $DEBUG == "" ]]; then
  mkdir -p out
  cd $_
fi

case $DEBUG in
  "-d")
      gcc -std=c99 -g "${C_FILES[@]/#/../}" -o prog && \
      ./prog $IMAGE_FILE $NEW_IMAGE_FILE && \
      xxd $PWD/$NEW_IMAGE_FILE
    ;;
  "-t")
      printf "IMAGE_FILE: %s\nNEW_IMAGE_FILE: %s\n" $IMAGE_FILE $NEW_IMAGE_FILE
    ;;
  *)
      gcc -std=c99 -g "${C_FILES[@]/#/../}" -o prog && \
      ./prog $IMAGE_FILE $NEW_IMAGE_FILE
    ;;
esac



