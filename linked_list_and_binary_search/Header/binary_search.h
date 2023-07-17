#ifndef BINARY_SEARCH
#define BINARY_SEARCH
/*
* File: binary_search.h
* Author: Phan Hoang Trung
* Date: 17/07/2023
* Description: This is a file include everything in preprocessor for binary_search.c
*/

#include "C:\Users\Trine\Desktop\EmbeddedInterview\linked_list_and_binary_search\Header\node.h"

typedef struct CenterPoint {
    int value;
    struct CenterPoint *left;
    struct CenterPoint *right;
} CenterPoint;

CenterPoint *buildTree(Node *head, int start, int end);
CenterPoint *centerPoint(Node *head);
CenterPoint *binarySearch(CenterPoint *root, int value);

#endif