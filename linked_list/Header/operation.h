#ifndef OPERATION
#define OPERATION

/*
* File: operation.h
* Author: Phan Hoang Trung
* Date: 07/07/2023
* Description: This is a file include everything in preprocessor for operation.c
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct node
{
    int value;
    struct node *next;
}node ;

node *createNode(int value);
void push_back(node** array, int value);
void push_front(node **array, int value);
void pop_back(node **array);
void pop_front(node **array);
int front(node **array);
int back(node **array);
void insert(node **array, int value, int pos);
void deletee(node **array, int pos);
int size(node **array);
int get(node **array, int pos);
bool empty(node **array);


#endif