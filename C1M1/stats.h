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
 * @file stats.h
 * @brief header file of stats.c
 *   Declare functions for stats.c to describe and call
 *
 * @author William Liu
 * @date June 11 2020
 *
 */

#ifndef __STATS_H__
#define __STATS_H__
typedef unsigned char BYTE;

void sort_array(BYTE *array,BYTE length);
//Given an array of data and a length, sorts the array from largest to smallest.
//@2 params: *array,length (all BYTE)
//Will make a descended array with a pointer *array
//using selection sort
//(index 0 = max, index length-1 = min)
//@output none,will modified array in place

void print_statistics(BYTE min,BYTE max,BYTE mean, BYTE median);
//prints the statistics of an array including minimum, maximum, mean, and median
//@4 params: min, max, mean, median(all BYTE)
//@ output: print min, max, mean, median

void print_array(BYTE *array,BYTE length);
//Given an array of data and a length, prints the array to the screen
//@2 params *array,length (all BYTE)
//@output print all datas in array[]

BYTE find_median(BYTE *d_sorted_array,BYTE length);
//Given an descended,sorted array of data and a length, returns the median value
//@2 params: d_sorted_array[],length (all BYTE)
//@output: return median value of array

BYTE find_mean(BYTE *array,BYTE length);
//Given an array of data and a length, returns the mean
//@2 params: *array,length (all BYTE)
//@output: return mean value of array

BYTE find_maximum(BYTE *d_sorted_array,BYTE length);
//Given an descended sorted array of data and a length, returns the maximum
//@2 params: d_sorted_array[],length (all BYTE)
//@output: return maximum of array (index = 0)

BYTE find_minimum(BYTE d_sorted_array[],BYTE legnth);
//Given an descended sorted array of data and a length, returns the minimum
//@2 params: d_sorted_array[],length (all BYTE)
//@output: return minimum of array (index = length-1)

#endif
