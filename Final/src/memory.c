/******************************************************************************
 * Copyright (C) 2020 by William Liu
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. William Liu is not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"
/***********************************************************
 Function Definitions
***********************************************************/

/*
S(ource)         1 2 3 4
D(estination)      H X X X
                     H X X X
                       H X X X
we have to copy from S Tail to avoid Source data corruption.

  D Head > S Head && D Head <= S Tail
	  copy from S Tail
	otherwise
		copy from S Head                            
*/

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
  // dst tail is not overlap, move from src tail
	if ( (dst > src && dst <= src+length-1)){
		for (int8_t i=0;i<length;i++){
			*(dst+length-1-i) = *(src+length-1-i);
			*(src+length-1-i) = 0;
		}
	}
	else{
		for (int8_t i=0;i<length;i++){
			*(dst+i) = *(src+i);
			*(src+i) = 0;
		}
	}
  return dst;
}
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
	for (int8_t i=0;i<length;i++){
		*(dst+i) = *(src+i);
	}
  return dst;
}
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
	for (int8_t i=0;i<length;i++){
		*(src+i) = value;
	}
  return src;
}
uint8_t * my_memzero(uint8_t * src, size_t length){
	for (int8_t i=0;i<length;i++){
		*(src+i) = 0;
	}
  return src;
}
uint8_t * my_reverse(uint8_t * src, size_t length){
	uint8_t temp;
	uint8_t * origin_src = src;
	// if *src == 0x45, means it is a "-", just skip it.
	if (*src == 0x45){
		src++;
		length--;
	}
  /* other datas just swap H(ead) and T(ail)
		 EX:1 2 3 4 -> 4 2 3 1
        H     T

        4 2 3 1 -> 4 3 2 1
          H T
  */
	for(uint8_t i=0;i<length/2;i++){
		temp = *(src+i);
		*(src+i) = *(src+(length-1)-i);
		*(src+(length-1)-i)=temp;
	}	
  return origin_src;
}
uint32_t * reserve_words(size_t length){
  uint32_t *reserved_pointer;
  reserved_pointer = malloc(length);
  return reserved_pointer;
}
void free_words(uint32_t * src){
	free(src);
}

void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

