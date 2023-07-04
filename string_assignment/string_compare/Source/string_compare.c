/*
* File: string_compare.h
* Author: Phan Hoang Trung
* Date: 03/07/2023
* Description: This is a file to compare 2 string
*/

#include <stdio.h>
#include <stdint.h>
#include "C:\Users\Trine\Desktop\EmbeddedInterview\string_assignment\string_compare\Header\string_compare.h"

// so sanh 2 chuoi - compare 2 char[]
// char arr1[] = "Hello"; char arr2[] = "This is test"; 

/*
* Function: isEqual
* Description: This function will compare 2 string and print to console to check those string are equal or not
* Input:
*   arr1 - an array of char
*   arr2 - an array of char
* Output:
*   if arr1 == arr2, print EQUAL
*   if arr1 > arr2, print BIGGER
*   if arr < arr2, print SMALLER
*/

Compare isEqual(const char arr1[], const char arr2[])
{
   /*   method:
    Check 2 string is equal or not,
    if not then is it bigger or smaller
   */
   uint8_t i = 0;
   while (arr1[i] == arr2[i])
   {
        if (arr1[i] == '\0')
        {
            printf("EQUAL\n");
            return;
        }
        i++;
   }
   if (arr1[i] > arr2[i])
   {
    printf("BIGGER\n");
   }
   else
   {
    printf("SMALLER\n");
   }
}

