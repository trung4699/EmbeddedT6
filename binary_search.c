/*
* File: binary_search.c
* Author: Phan Hoang Trung
* Date: 30/06/2023
* Description: This is a file for searching a number in an array using method binary search
*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>

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
    /*  method
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


int main(int argc, char const *argv[])
{
   uint8_t *array = createArray(10000);

   sort(array,10000);

   for (uint16_t i = 0; i < 10000; i++)
   {
    printf("array[%d] = %d\t", i, array[i]);
   }

   binary_search(array,10000,180);
   
    return 0;
}
