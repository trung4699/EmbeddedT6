/*
* File: binary_search.c
* Author: Phan Hoang Trung
* Date: 03/07/2023
* Description: This is a file include function to search a number in an array using method binary search
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

int binary_search(uint8_t arr[], uint16_t length, uint8_t num)
{
    /*  method
    *   using 3 variables: min, max, mid
    *   num is a number to search, mid is the middle value between min and max
    *   compare num to mid
    *   if num > mid, num is between mid and max value
    *   if num < mid, num is between min value and mid
    *   repeat until:
    *   if num and mid equal, return mid
    *   
    */
    int min = 0, max = length - 1;
    int mid = (min + max) / 2;
    if (num > arr[max] || num < arr[min])
    {
        return -1;
    }
    while (arr[mid] != num)
    {
        if (num > arr[mid])
        {
            min = mid;
            mid = (min + max) / 2;
        }
        else
        {
            max = mid;
            mid = (min + max) / 2;
        }
        if  (mid == min || mid == max)
        {
           return -1;
        }
    }
    return mid;
}

