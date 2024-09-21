/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c>
 * @brief C code for stats.c file
 *
 * Implementation of statistical analysis in C language
 *
 * @author Shivam Amin
 * @date 09/02/2024
 *
 */



#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

// double find_mean(unsigned char * arr);
// void sort_array(unsigned char * arr);
// void print_array(unsigned char * arr);
// unsigned char find_maximum(unsigned char * arr);
// unsigned char find_minimum(unsigned char * arr);
// double find_median(unsigned char * arr);
// void print_statistics(unsigned char * arr);

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_array(test, SIZE);
  print_statistics(test);
  return 0;
}

/* Add other Implementation File Code Here */

double find_mean(unsigned char * arr){

  double mean = 0.0;
  int i = 0;
  for (i = 0; i < SIZE; i++){
    mean += arr[i];
  }
  mean /= SIZE;
  return mean;
}

void print_array(unsigned char * arr, unsigned int size) {
    #ifdef VERBOSE
        int i = 0;
        PRINTF("[ ");
        for (i = 0; i < size; i++) {
            PRINTF("%d ", arr[i]);
        }
        PRINTF("]\n");
    #endif
}


void sort_array(unsigned char * arr){
  int i;
  int j;
  for(i = 0; i < SIZE; i++){
    for(j = 0; j < SIZE-i-1;j++){
      if(arr[j] < arr[j+1]){
          char temp = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = temp;
      }
    }
  }
}

unsigned char find_maximum(unsigned char * arr){
  int i;
  unsigned char max = arr[0];

  for(i = 1; i < SIZE; i++){
    if(arr[i] > max){
      max = arr[i];
    }
  }
  return max;
}

unsigned char find_minimum(unsigned char * arr){
  int i;
  unsigned char min = arr[0];

  for(i = 1; i < SIZE; i++){
    if(arr[i] < min){
      min = arr[i];
    }
  }
  return min;
}

double find_median(unsigned char * arr){
  sort_array(arr);
  double median = 0.0;

  if(SIZE % 2 == 0){
    median += arr[SIZE/2];
    median += arr[SIZE/2 + 1];
    median /= 2;
  }else{
    median += arr[SIZE/2];
  }

  return median;
}

void print_statistics(unsigned char * arr) {
    PRINTF("MINIMUM IS : %d\n", find_minimum(arr));
    PRINTF("MAXIMUM IS : %d\n", find_maximum(arr));
    PRINTF("MEAN IS    : %f\n", find_mean(arr));
    PRINTF("MEDIAN IS  : %f\n", find_median(arr));
}
