/*
* File: main.c
* Author: Phan Hoang Trung
* Date: 03/07/2023
* Description: This is a main file for searching a number in a random array using binary search method
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
   int check = binary_search(array,length, numberSearch);
   if (check == -1)
   {
    printf("Your number is not exist in an array");
   }
   else
   {
    printf("Your number is at %d in an array", check);
   }
   
   free(array);
   
    return 0;
}
