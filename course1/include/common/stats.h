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
 * @file stats.h
 * @brief header file for stats.c
 *
 * Header file which contains the headers of methods implemented in stats.c
 *
 * @author Shivam Amin
 * @date 09/02/2024
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Calculates the mean of an array of unsigned characters.
 *
 * This function computes the arithmetic mean of an array of unsigned characters by summing 
 * all elements in the array and then dividing by the total number of elements.
 *
 * @param arr Pointer to the array of unsigned characters.
 *
 * @return The mean of the array as a double.
 */
double find_mean(unsigned char * arr);

/**
 * @brief Prints the elements of an array.
 *
 * This function prints all the elements of an array of unsigned characters in a formatted way.
 *
 * @param arr Pointer to the array of unsigned characters.
 */
void print_array(unsigned char * arr);

/**
 * @brief Sorts an array in descending order.
 *
 * This function sorts an array of unsigned characters in descending order using the bubble sort algorithm.
 *
 * @param arr Pointer to the array of unsigned characters.
 */
void sort_array(unsigned char * arr);

/**
 * @brief Finds the maximum value in an array.
 *
 * This function iterates through an array of unsigned characters to find the maximum value.
 *
 * @param arr Pointer to the array of unsigned characters.
 *
 * @return The maximum value in the array.
 */
unsigned char find_maximum(unsigned char * arr);

/**
 * @brief Finds the minimum value in an array.
 *
 * This function iterates through an array of unsigned characters to find the minimum value.
 *
 * @param arr Pointer to the array of unsigned characters.
 *
 * @return The minimum value in the array.
 */
unsigned char find_minimum(unsigned char * arr);

/**
 * @brief Calculates the median of an array.
 *
 * This function calculates the median value of an array of unsigned characters. 
 * The array is sorted in descending order before calculating the median.
 *
 * @param arr Pointer to the array of unsigned characters.
 *
 * @return The median value as a double.
 */
double find_median(unsigned char * arr);

/**
 * @brief Prints statistics of an array.
 *
 * This function prints the minimum, maximum, mean, and median of an array of unsigned characters.
 *
 * @param arr Pointer to the array of unsigned characters.
 */
void print_statistics(unsigned char * arr);


#endif /* __STATS_H__ */
