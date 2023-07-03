/*
* File: binary_search.c
* Author: Phan Hoang Trung
* Date: 28/06/2023
* Description: This is a file for searching a number in an array using method binary search
*/

#include "C:\Users\Trine\Desktop\EmbeddedInterview\binary_search\Header\sort.h"

/*
* Function: sort
* Description: This function will sort an array from minimum value to maximum value
* Input:
*   arr - an array of unsigned 8 bit integer value 
*   length - an unsigned 16 bit integer value - length of an array
* Output:
*   an array have been sort from minimum to maximum value
*/

void sort(uint8_t arr[], uint16_t length){
    /*  method: burble sort
    *   compare 1 number to all number after it index
    *   if it bigger, swap it with number it compare 
    */

    int temp = 0;   // this variables use to swap 2 number
    for (uint16_t i = 0; i < length; i++)
    {
        for (uint16_t j = i + 1; j< length; j++)
        {
           if (arr[i] > arr[j])
           {
             temp = arr[i];     // assign arr[i] to temp
             arr[i] = arr[j];   // assign arr[j] to arr[i]
             arr[j] = temp;     // assign temp to arr[j]
           }
        }
    }
}




