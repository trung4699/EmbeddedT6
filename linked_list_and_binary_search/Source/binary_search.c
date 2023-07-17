/*
* File: binary_search.c
* Author: Phan Hoang Trung
* Date: 17/07/2023
* Description: This is a file include function to find a node in a linked list using binary search method
*/


#include "C:\Users\Trine\Desktop\EmbeddedInterview\linked_list_and_binary_search\Header\binary_search.h"
#include <stdio.h>
#include <stdlib.h>


/*
* Function: buildTree
* Description: This function will create a new node have 3 member in it:
* value of the center node in current list
* address of center node of list from 0 to mid - 1
* address of center node of list from mid + 1 to the end of current list
* Input:
*   head - pointer to pointer has datatype is node -  address of pointer which point to first node of linkedlist
*   start - an integer value - the position to start the list
*   end - an integer value - the position at the end of the list
* Output:
*   root - a pointer hold address of a node have centerpoint datatype
* Example:
* we have a pointer type node: node* array = 01;
* we have a list:
*   address of the node:   01   02    0a    0c      0d      06      09      
*   value:                  1   2      3    4       5       6       7       
*   *next:                 02   0a    0c    0d      06      09      NULL     
* Input:
*   head - &array - address of the pointer point to the first node of the list
*   start - 0 
*   end - 6
* Output:
*   root: 
*   root->value = 4;
*   root->left = 02;
*   root->right = 06;
*/
CenterPoint *buildTree(Node *head, int start, int end) {
    if (head == NULL || start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node *node = head;
    for (int i = start; i < mid; i++) { // go to the mid node in current list
        if (node->next == NULL) {
            break;
        }
        node = node->next;
    }

    CenterPoint *root = (CenterPoint *) malloc(sizeof(CenterPoint));
    root->value = node->data;                                   // This is value of the center node in current list
    root->left = buildTree(head, start, mid - 1);               // This is address of the center node of list from 0 to mid - 1 of current list
    root->right = buildTree(node->next, mid + 1, end);          // This is address of the center node of list from mid + 1 to the end of current list

    return root;
}


/*
* Function: centerPoint
* Description: This function will return a new node have 3 member in it:
* value of the center node in current list
* address of center node of list from 0 to mid - 1
* address of center node of list from mid + 1 to the end of current list
* Input:
*   head - pointer to pointer has datatype is node -  address of pointer which point to first node of linkedlist
* Output:
*   root - a pointer hold address of a node have centerpoint datatype 
*/
CenterPoint *centerPoint(Node *head) {
    int length = 0;         // this is a variable use to store the size of list
    Node *node = head;
    while (node != NULL) {  // to determine the size of the list
        node = node->next;
        length++;
    }

    return buildTree(head, 0, length - 1); // return root
}


/*
* Function: binarySearch
* Description: This function will check the input value whether it exist in the list or not
* value of the center node in current list
* address of center node of list from 0 to mid - 1
* address of center node of list from mid + 1 to the end of current list
* Input:
*   root - a pointer has datatype is centerPoint -  address of center node in the list
*   value - an integer value - the value to check
* Output:
*   root - a pointer hold address of a node have value same with value input 
*   root = NULL if the value input doesn't exist in the list
*/
CenterPoint *binarySearch(CenterPoint *root, int value) {
    static int loop = 0;
    loop++;
    printf("so lan lap: %d\n", loop); // to print how many time recursion
    if (root == NULL) {
        return NULL;
    }

    if (root->value == value) {
        return root;
    }

    if (value < root->value) {
        return binarySearch(root->left, value);
    } else {
        return binarySearch(root->right, value);
    }
}