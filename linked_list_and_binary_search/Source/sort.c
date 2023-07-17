/*
* File: sort.c
* Author: Phan Hoang Trung
* Date: 17/07/2023
* Description: This is a file include function to add a new node and sort it value in a linked list from minimum to maximum
*/

#include "C:\Users\Trine\Desktop\EmbeddedInterview\linked_list_and_binary_search\Header\sort.h"
#include <stdio.h>
#include <stdlib.h>

/*
* Function: add_node
* Description: This function will create a new node, add it to a linked list, and then sort it 
* Input:
*   head - pointer to pointer has datatype is node -  address of pointer which point to first node of linkedlist
*   value - an integer value - value of new node
* Output:
*   new list with a new node have been sorted
* Example:
* The linkled list: {1, 2, 3, 6, 7}
* Input:
* head - address of the pointer point to the first node
* value - 5
* Output:
* New list: {1, 2, 3, 5, 6, 7}
*/
void add_node(Node **head, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));  //create a new node with 2 member data and next
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL || (*head)->data >= value) {  // if the list doesn't have any node or data of the first node >= value
        new_node->next = *head;                     // next of new node = address of the first node
        *head = new_node;                           // new node become first node
        return;
    }

    Node *current = *head;
    while (current->next != NULL && current->next->data < value) {  // go to the node ( current node) which the data of next node is >= value of new node
        current = current->next;
    }

    new_node->next = current->next; // next of new node now hold address of the node have value >= value of new node
    current->next = new_node;       // next of current node now hold address of new node
}