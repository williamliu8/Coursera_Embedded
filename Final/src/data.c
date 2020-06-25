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
 * @file data.c 
 * @brief This file is to handle
 *  ASCII to int and int to ASCII
 *  please see data.h for more detail
 * @author William Liu
 * @date June 22, 2020
 *
 * ASCII
   0~9 -> 0x30~0x39
   A~B -> 0x41~0x46
   - -> 0x45
   NULL -> 0x00
*/
#include <stdint.h> // for uint8_t,int32_t
#ifdef DEBUG
#include "platform.h"
#endif
#include "memory.h"
#include "data.h"
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
  uint8_t digits=0;
  uint8_t ascii_code,remainder;
	uint8_t * start_ptr=ptr;

  // if data < 0, put "-" sign to the first address
  if (data < 0){
		data *= -1;
		*ptr = 0x45;
    ptr++;
		digits++;
  }
  //transfer each digit to ASCII
	while(data/base || data % base){
    remainder = data % base;
	  if(remainder < 10){
			ascii_code = 0x30+remainder;  // for 0~9
		}
		else{
			ascii_code = 0x41 + (remainder - 10); // for A~F
		}
		*ptr = ascii_code;
		ptr++;
    data /= base;
		digits++;
	}
	*ptr = 0x00;
	digits++;
	ptr = my_reverse(start_ptr , digits-1); // because -4096 will be saved to memory as:-6904, so we have to reverse "digit parts".
#ifdef DEBUG
 //for debug, can see each digit in memory
	for(int i=0;i < digits;i++){
		PRINTF("%x\n",*(ptr+i));
	}
	PRINTF("\n digits %d",digits);
#endif
  return digits; //return digits include "-" and "0x00"
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
	int32_t result=0;
	int8_t negative=1;
	int32_t pow_temp=0;
  // if first address in memory is 0x45, just skip it and set negative to -1
	if(*ptr==0x45){
		ptr++;
		digits--;
		negative=-1;
	}

	for(int8_t i = digits-2 ;i >=0 ;i--){
    //transfer each address to number
		if(*ptr >= 0x41){
			*ptr -= 0x41;
		}
		else{
			*ptr -= 0x30;
		}
		// calculate the real value of the number with power of base
		// ex hex *ptr x x x  -> pow_temp = *ptr*16^3
		pow_temp = (*ptr);
		for(uint8_t j=0;j<i;j++){
			pow_temp*=base;
		}
		//ex hex 1 0 0 0  -> result = 1*16^3 + 0*16^2 + 0*16 + 0x1
		result += pow_temp;
		ptr++; // check next address
	}
  return result*negative;
}


