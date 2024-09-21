/******************************************************************************
 * Copyright (C) 2024 by Your Name
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about basic data manipulation. 
 *
 *****************************************************************************/
/**
 * @file data.c
 * @brief Basic data manipulation functions implementation
 *
 * This implementation file provides functions to convert integers to ASCII
 * strings and vice versa.
 *
 * @author Your Name
 * @date September 2024
 *
 */
#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
    if (base < 2 || base > 16) return 0;

    uint8_t is_negative = 0;
    uint8_t index = 0;
    
    if (data < 0) {
        is_negative = 1;
        data = -data; // Make data positive for conversion
    }

    do {
        uint32_t remainder = data % base;
        *(ptr + index) = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        index++;
        data /= base;
    } while (data > 0);

    if (is_negative) {
        *(ptr + index) = '-';
        index++;
    }

    // Null-terminate the string
    *(ptr + index) = '\0';

    // Reverse the string
    for (uint8_t start = 0, end = index - 1; start < end; start++, end--) {
        uint8_t temp = *(ptr + start);
        *(ptr + start) = *(ptr + end);
        *(ptr + end) = temp;
    }

    return index + 1; // Length including null terminator
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
    if (base < 2 || base > 16) return 0;

    int32_t result = 0;
    uint8_t is_negative = 0;
    uint8_t start_index = 0;

    // Check for negative sign
    if (*ptr == '-') {
        is_negative = 1;
        start_index++;
    }

    for (uint8_t i = start_index; i < digits; i++) {
        uint8_t value = *(ptr + i);

        // Convert character to numeric value
        if (value >= '0' && value <= '9') {
            value -= '0';
        } else if (value >= 'A' && value <= 'F') {
            value = value - 'A' + 10;
        } else if (value >= 'a' && value <= 'f') {
            value = value - 'a' + 10;
        } else {
            continue; // Skip invalid characters
        }

        // Ensure the character value is valid for the given base
        if (value >= base) {
            continue; // Invalid digit for this base
        }

        result = result * base + value;
    }

    return is_negative ? -result : result;
}
