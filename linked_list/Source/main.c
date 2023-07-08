/*
* File: operation.c
* Author: Phan Hoang Trung
* Date: 07/07/2023
* Description: This is a main file using to test some basic operation of linked list
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "C:\Users\Trine\Desktop\EmbeddedInterview\linked_list\Header\operation.h"

void printEmpty(bool check)
{
    if (check)
    {
        printf("Our list is empty\n");
    }
    else
    {
        printf("Our list is not empty\n");
    }
}

int main()
{
    node *array = NULL;

    printEmpty(empty(&array));
    
    push_back(&array,7);
    
    push_back(&array,11);

    push_back(&array,15);
   
    push_back(&array,19);

    push_back(&array,26);

    int length = size(&array);

    printf("This is size of our list: %d\n",length);
    printf("This is our list: \n");
    for (int i = 0; i < size(&array); i++)
    {
        printf("%d ",get(&array,i));
    }
    printf("\n");

    printf("This is value of first node in our list: %d", front(&array));
    printf("\n");
    printf("This is value of last node in our list: %d", back(&array));
    printf("\n");
    printf("Add a new node have value 100 in the beginning of our list\n");
    push_front(&array,100);

    printf("Delete a last node in our list\n");
    pop_back(&array);

    printf("This is our new list: \n");
   
    for (int i = 0; i < size(&array); i++)
    {
        printf("%d ",get(&array,i));
    }
    printf("\n");

    printf("Add a new node have value 30 in the last of our list\n");
    push_back(&array,30);

    printf("Delete a node at the beginning of our list\n");
    pop_front(&array);

    printf("Add a new node have value 200 in position 3 of our list\n");
    insert(&array,200,3);


    printf("This is our new list: \n");
    for (int i = 0; i < size(&array); i++)
    {
        printf("%d ",get(&array,i));
    }
    printf("\n");

    printf("Delete a node at position 4\n");
    deletee(&array,4);

    printf("This is our new list: \n");
    for (int i = 0; i < size(&array); i++)
    {
        printf("%d ",get(&array,i));
    }
    printf("\n");

    printEmpty(empty(&array));

    free(array);

    return 0;
}