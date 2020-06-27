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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author William Liu
 * @date June 22 2020
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__
#include <stdint.h> // for uint8_t,int32_t
#include <stddef.h> // for size_t
#include <stdlib.h>
/*
  my_memmove
  @brief:
   move (length) from (source) to (destination) in memory
  
  @param:
   source(byte pointers)
   destination(byte pointers)
   length(size_t): length to move from the source location to the destination
  
  @return:
   pointer to the destination (dst)

  @requirements
   The behavior should handle overlap of source and destination.
   Copy should occur, with no data corruption.
   All operations need to be performed using pointer arithmetic, not array indexing.
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/*
  my_memcopy
  @brief:
   copy (length) from (source) to (destination) in memory
  
  @param:
   source(byte pointers)
   destination(byte pointers)
   length(size_t): length to copy from the source location to the destination
  
  @return:
   pointer to the destination (dst)

  @requirements
   The behavior is undefined if there is overlap of source and destination.
   Copy should still occur, but will likely corrupt your data.
   All operations need to be performed using pointer arithmetic, not array indexing.
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/*
  my_memset
  @brief:
   set (length) with (value) to (source) in memory
  
  @param:
   source(byte pointers)
   length (size_t)
   value(byte): bytes to move from the source location to the destination
  
  @return:
   pointer to the source (src)

  @requirements
   All operations need to be performed using pointer arithmetic, not array indexing
   should NOT reuse the set_all() function
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/*
  my_memzero
  @brief:
   set (length) with zero to (source) in memory
  
  @param:
   source(byte pointers)
   length (size_t)
  
  @return:
   pointer to the source (src)

  @requirements
   All operations need to be performed using pointer arithmetic, not array indexing
   should NOT reuse the clear_all() function
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/*
  my_reverse
  @brief:
   reverse the (length) content order from (source) in memory
  
  @param:
   source(byte pointers)
   length (size_t)
  
  @return:
   pointer to the source (src)

  @requirements
   All operations need to be performed using pointer arithmetic, not array indexing
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/*
  reserve_words
  @brief:
   allocate (length) dynamically in memory
  
  @param:
   length (size_t) (include '-', exclude '0x00')
  
  @return:
   a pointer to memory if successful, or a Null Pointer if not successful

  @requirements
   All operations need to be performed using pointer arithmetic, not array indexing
 */
uint32_t * reserve_words(size_t length);

/*
  free_words
  @brief:
   free a dynamic memory allocation by providing the pointer src to the function
  
  @param:
   source (int32_t)
  
  @return:
   src

  @requirements
   All operations need to be performed using pointer arithmetic, not array indexing
 */
void free_words(uint32_t * src);


/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

#endif /* __MEMORY_H__ */
