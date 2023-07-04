/*
* File: main.c
* Author: Phan Hoang Trung
* Date: 04/07/2023
* Description: This is a main file to print input string in reverse
*/


#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "C:\Users\Trine\Desktop\EmbeddedInterview\string_assignment\string_reverse\Header\string_reverse.h"



int main()
{
    char arr[] = " This is the first and that are the second "; // array arr is your string 
    int8_t length = strlen(arr);
    string_reverse(arr,length);

    return 0;
}