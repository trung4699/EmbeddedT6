#ifndef NODE
#define NODE

/*
* File: node.h
* Author: Phan Hoang Trung
* Date: 17/07/2023
* Description: This is a file to declare a node using in all file
*/

typedef struct Node {
    int data;
    struct Node *next;
} Node;

#endif