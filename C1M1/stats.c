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
 * @file stats.c
 * given an array,
 * We have functions below to process the data in the array(please see stats.h for detail parameters description)
 * 1.void sort_array(BYTE *array,BYTE length)
 *   can make a descended sorted array in place
 * 2.void print_statistics(BYTE min,BYTE max,BYTE mean,BYTE median)
 *   print it's max,min,mean,median
 * 3.void print_array(BYTE *array,BYTE length):
 *   print content of the array
 * 4.BYTE find_median(BYTE *d_sorted_array,BYTE length)
 *   return it's median
 * 5.BYTE find_mean(BYTE *array,BYTE length)
 *   return it's mean
 * 6.BYTE find_maximum(BYTE *d_sorted_array,BYTE length)
 *   reutrn it's maximum(index 0)
 * 7.BYTE find_minimum(BYTE *d_sorted_array,BYTE length)
 *   return it's minimum(index length-1)
 *
 * @author William Liu
 * @date 06/11/2020
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  BYTE test[SIZE] = {  34, 201, 190, 154,   8, 194,   2,   6,
                      114,  88,  45,  76, 123,  87,  25,  23,
                      200, 122, 150 , 90,  92,  87, 177, 244,
                      201,   6,  12,  60,   8,   2,   5,  67,
                        7,  87, 250, 230,  99,   3, 100,  90};

  BYTE mean,median,min,max;
  sort_array(test,SIZE);
  print_array(test,SIZE);
  max = find_maximum(test,SIZE);
  min = find_minimum(test,SIZE);
  mean = find_mean(test,SIZE);
  median = find_median(test,SIZE);
  print_statistics(min,max,mean,median);
}

/*
*Selection sort
*Index 0 should be the largest value.
*i = 0 to length-2 (for(i=0;i<length-1;i++){})
*each i
*  compare array[i] with array[i+1] to array[length-1] (for(j=i+1;j<length-1;j++){})
     record the largest value and index that is larger than array[i]
*if the largest value that larger than array[i] found:
*  swap array[i] with it
*array[i] now has the largest velue, check next i....
*/
void sort_array(BYTE *array,BYTE length){
  BYTE i,j,max,max_index,temp;
  for (i = 0; i < length-1 ; i++){
    max = array[i];
    max_index = i;
    for (j = i + 1 ; j < length ; j++){
      if (max < array[j]){
        max = array[j];
        max_index = j;
      }      
    }
    if(max_index != i){
      temp = array[i];
      array[i] = array[max_index];
      array[max_index] = temp;
    }
  }
}

void print_statistics(BYTE min,BYTE max,BYTE mean,BYTE median){
  // %3d means to reserve 3 digits for the value
  printf("The maximum value of the array is:%3d\n",max);
  printf("The minimum value of the array is:%3d\n",min);
  printf("The mean value of the array is:%3d\n",mean);
  printf("The median value of the array is:%3d\n",median);
  printf("Thank you so much! By William Liu 2020\n");
}

void print_array(BYTE *array,BYTE length){
  BYTE i,j;
  printf("Hello! How are you?\n");
  printf("Data in the Sorted Array (Descended order) :\n");
  for (i=0;i < length;i++){
    printf("%3d ",array[i]); // BYTE values are 0~255(<= 3 digits)
                             // %3d means to reserve 3 digits for every value,
                             // so that it can align perfectly.

    if ((i+1)%8 == 0){ // each row shows 8 values
      printf("\n");
    }
  }
  printf("\n");
}
/* Median number
  if length of array is odd number
  EX : 1 2 3 4 5 6 7
    middle index:(BYTE)7/2 = 3
    median is array[3] = 4

  if length of array is even number
  EX : 1 2 3 4 5 6 7 8
    middle index:(BYTE)8/2 = 4
    but the median is between index 4 and 3
    median is (array[3]+array[4])/2 = 4.5 -> nearest integer is 5
*/
BYTE find_median(BYTE *d_sorted_array,BYTE length){
  BYTE middle_index = length/2;
  BYTE median;

  if (length%2==0){
    //Round to the nearest interger
    median = (d_sorted_array[middle_index] + d_sorted_array[middle_index - 1])/2;
  }
  else{
    median = d_sorted_array[middle_index];
  }
  return median;
}

BYTE find_mean(BYTE *array,BYTE length){
  BYTE i;
  float sum=0;
  for (i=0;i<length;i++){
    sum += array[i];
  }
  //Round to the nearest interger
  return sum/length;
}

BYTE find_maximum(BYTE *d_sorted_array,BYTE length){
  return d_sorted_array[0];
}

BYTE find_minimum(BYTE *d_sorted_array,BYTE length){
  return d_sorted_array[length-1];	
}

