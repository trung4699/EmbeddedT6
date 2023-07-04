#ifndef STRING_COMPARE
#define STRING_COMPARE
/*
* File: string_compare.h
* Author: Phan Hoang Trung
* Date: 03/07/2023
* Description: This is a file include everything in preprocessor for string_compare.c
*/


typedef enum {
    SMALLER,
    BIGGER,
    EQUAL
} Compare;

Compare isEqual(const char arr1[], const char arr2[]);

#endif