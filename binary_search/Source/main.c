/*
* File: main.c
* Author: Phan Hoang Trung
* Date: 02/07/2023
* Description: This is a file for searching a number in an array using method binary search
*/

#include <stdio.h>
#include "C:\Users\Trine\Desktop\EmbeddedInterview\binary_search\Header\binary_search.h"
#include "C:\Users\Trine\Desktop\EmbeddedInterview\binary_search\Header\create_array.h"
#include "C:\Users\Trine\Desktop\EmbeddedInterview\binary_search\Header\sort.h"

int enterNumber()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    return num;
}

int main()
{
   printf("Enter the length of an array \n");
   int length = {enterNumber()};
   uint8_t *array = createArray(length);

   sort(array,length);

   for (uint16_t i = 0; i < length; i++)
   {
    printf("array[%d] = %d\t", i, array[i]);
   }

    printf("Enter a number you want to search \n");
    int numberSearch = {enterNumber()};
   binary_search(array,length, numberSearch);
   free(array);
   
    return 0;
}
