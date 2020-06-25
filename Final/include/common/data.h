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
 * @file data.h
 * @brief Abstraction of Interger-to-ASCII and vise versa
 *
 * @author William Liu
 * @date June 22 2020
 *
 */
#ifndef __DATA_H__
#define __DATA_H__
#include <stdint.h> // for uint8_t,int32_t

/*
  my_itoa
  @brief:
   convert (data) to ASCII
  
  @param:
   data(int32_t)
     number you wish to convert is passed in as a signed 32-bit integer.	  		
   ptr (byte pointer)
     Copy the converted character string to the uint8_t* pointer passed in as a parameter (ptr)
   base(uint32_t)
     be able to support bases 2 to 16  
  @return:
   the length of the converted data (including a negative sign).
   Example my_itoa(ptr, 1234, 10)
   should return an ASCII string length of 5(including the null terminator).

  @requirements
   The number you wish to convert is passed in as a signed 32-bit integer.
   All operations need to be performed using pointer arithmetic, not array indexing.
   The signed 32-bit number will have a maximum string size (Hint: Think base 2).
   You must place a null terminator at the end of the converted c-string.
   This function needs to handle signed data.
   You may not use any string functions or libraries.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/*
  my_atoi
  @brief:
   ASCII-to-Integer needs to convert data back from an ASCII represented string into an integer type.
  
  @param:
   digits(int8_t)
     The number of digits in your character set is passed in as a uint8_t integer.
   ptr (byte pointer)
     character string to convert
   base(uint32_t)
     be able to support bases 2 to 16  
  @return:
	 converted 32-bit signed integer should be returned.
  @requirements
   All operations need to be performed using pointer arithmetic, not array indexing.
   This function needs to handle signed data.
   You may not use any string functions or libraries.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);


#endif /* __DATA_H__ */
