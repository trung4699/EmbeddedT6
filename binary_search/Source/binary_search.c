/*
* File: binary_search.c
* Author: Phan Hoang Trung
* Date: 30/06/2023
* Description: This is a file for searching a number in an array using method binary search
*/

#include "C:\Users\Trine\Desktop\EmbeddedInterview\binary_search\Header\binary_search.h"
#include <stdio.h>

/*
* Function: binary_search
* Description: This function will check a number if it exist in an array or not
* Input:
*   arr - an array of unsigned 8 bit integer value
*   length - an unsigned 16 bit integer value - length of array arr
*   num - number to check
* Output:
*   print an index of number in array if it exist in array
*/

void binary_search(uint8_t arr[], uint16_t length, uint8_t num)
{
    /*  method
    *   using 3 variables: min, max, i
    *   number num is between min and max value, i is the middle value between min and max
    *   compare num to i
    *   if num > i, num is between i and max value
    *   if num < i, num is between min value and i
    *   repeat until:
    *   num and i have the same value, print num exist in array at index i
    *   or min and max have the same value, print num doesn't exist in array
    */
    int min = 0, max = length - 1;
    int i = (min + max) / 2;
    if (num > arr[length - 1] || num < arr[0])
    {
        printf("Your number is not exist in this array");
    }
    while (arr[i] != num)
    {
        if  (min == max )
        {
            printf("Your number is not exist in this array");
            return;
        }
        if (num > arr[i])
        {
            min = i;
            i = (min + max) / 2;
        }
        else
        {
            max = i;
            i = (min + max) / 2;
        }
    }
    printf("Your number is at %d", i);
}

