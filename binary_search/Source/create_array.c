/*
* File: create_array.c
* Author: Phan Hoang Trung
* Date: 02/07/2023
* Description: This is a file for searching a number in an array using method binary search
*/


#include "C:\Users\Trine\Desktop\EmbeddedInterview\binary_search\Header\create_array.h"

/*
* Function: random_number
* Description: This function will return a number between minimum and maximum value
* Input:
*   minN - an integer value - minimum value
*   maxN - an integer value - maximum value
* Output:
*   number - an interger value - random from minimum to maximum value
*/

int random_number(int minN, int maxN){
 return minN + rand() % (maxN + 1 - minN);
}

/*
* Function: createArray
* Description: This function will create an array with value of each element in array is randomly
* Input:
*   length - an unsigned 16 bit integer value - length of an array
* Output:
*   an array with value of each element is randomly
*   each element in array - an unsigned 8 bit integer value
*/

uint8_t *createArray(uint16_t length){
    uint8_t *ptr = (uint8_t*)malloc(sizeof(uint8_t)*length);
    srand((int)time(0));
    for (uint16_t i = 0; i < length; i++)
    {
        ptr[i] = random_number(1, 200);
    }
    return ptr; 
}
