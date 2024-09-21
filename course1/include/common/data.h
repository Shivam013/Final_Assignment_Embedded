/******************************************************************************
 * Copyright (C) 2024 by Your Name
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about basic data manipulation. 
 *
 *****************************************************************************/
/**
 * @file data.h
 * @brief Basic data manipulation functions
 *
 * This header file provides functions to convert integers to ASCII
 * strings and vice versa.
 *
 * @author Your Name
 * @date September 2024
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

/**
 * @brief Converts an integer to an ASCII string.
 *
 * @param data The integer to convert.
 * @param ptr Pointer to the buffer to store the ASCII string.
 * @param base The base for conversion (2 to 16).
 *
 * @return The length of the converted string, including null terminator.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts an ASCII string to an integer.
 *
 * @param ptr Pointer to the ASCII string.
 * @param digits The number of digits in the string.
 * @param base The base for conversion (2 to 16).
 *
 * @return The converted signed 32-bit integer.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
