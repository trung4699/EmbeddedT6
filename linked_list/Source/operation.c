/*
* File: operation.c
* Author: Phan Hoang Trung
* Date: 07/07/2023
* Description: This is a file include some basic operation of linked list
*/

#include "C:\Users\Trine\Desktop\EmbeddedInterview\linked_list\Header\operation.h"


/*
* Function: createNode
* Description: create a node in a linked list have 2 member: value of the node and a pointer hold address of the next node
* Input:
*   value -  an integer value - value of the member 
* Output:
*   ptr - address of the node created
*/
node *createNode(int value)
{
    node *ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}


/*
* Function: push_back
* Description: add a new node at the last position in the linked list
* Input:
*   array - pointer to pointer has datatype is node -  address of pointer array which point to first node of linkedlist
*   value - an integer value - value of the member
* Output:
*   new list with new node at the last position
*/
void push_back(node** array, int value)
{
    node *temp, *p;
    temp = createNode(value);
    
    p = *array;          // use p instead of array because we are using pointer, use array will change the structure of linkedlist

    if (*array == NULL)   // if array doesn't have any node yet
    {
        
        *array = temp;
    }
    else                // if array has some node
    {      
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next;    // check next node until it a last node
            
        }
        
        p->next = temp;     // change it next member point to address of new node have just create
    }
}





/*
* Function: push_front
* Description: add a new node at the beginning of the linked list
* Input:
*   array - pointer to pointer has datatype is node -  address of pointer array which point to first node of linkedlist
*   value - an integer value - value of the member
* Output:
*   new list with a new node at the beginning
*/
void push_front(node **array, int value)
{
    node *temp;
    temp = createNode(value); // address of new node

    if (*array == NULL)      // if there is no node yet, then the node have been add is first node
    {
        *array = temp;
    }
    else                    // if there is already some node, then change member next of new node from NULL to array,
    {                       // which is store address of the first node in the list
        temp->next = *array;
        *array = temp;       // change array to store address of new node
    }
    
}


/*
* Function: pop_back
* Description: delete a node at the last position in linkedlist
* Input:
*   array - pointer to pointer has datatype is node -  address of pointer array which point to first node of linkedlist
* Output:
*   new list without last node ( compare to the input list)
*/
void pop_back(node **array)
{
    node *p, *temp;
    p = *array;
    int i = 0; // to 

    while (p->next != NULL)     // free the last node in the list
    {
        p = p->next;
        i++;
    }
    free(p);

    temp = *array;
    int j;
    for ( j = 0; j < i - 1 ; j++)    // change the next member of the node at the (last - 1) position to NULL
    {
        temp = temp->next;
    }
    
    temp->next = NULL;
}



/*
* Function: pop_front
* Description: delete a node at the beginning of the linkedlist
* Input:
*   array - pointer to pointer has datatype is node -  address of pointer array which point to first node of linkedlist
* Output:
*   new list without the node at the beginning ( compare to the input list)
*/
void pop_front(node **array)
{
    /*  method
    *   use p to store the address of the first node
    *   now change array to store address of the second node
    *   then free the first node
    */
    node *p;
    p = *array;
    *array = p->next;
    free(p);
}




/*
* Function: front
* Description: return the first value of the linked list
* Input:
*   array - pointer to pointer has datatype is node -  address of pointer array which point to first node of linkedlist
* Output:
*   value of the first node - an integer value
*/
int front(node **array)
{
    node *p = *array;
    return p->value;
}


/*
* Function: back
* Description: return value of the last node in linkedlist
* Input:
*   array - pointer to pointer has datatype is node -  address of pointer array which point to first node of linkedlist
* Output:
*   value of the last node - an integer value
*/
int back(node **array)
{
    node *p;
    p = *array;
    while ( p->next != NULL)    // go to the last node, then return it value
    {
        p = p->next;
    }

    return p->value;
}



/*
* Function: insert
* Description: add a new node at position you want
* Input:
*   array - pointer to pointer has datatype is node -  address of pointer array which point to first node of linkedlist
*   value - an integer value - value of the node
*   pos - an interger value - position of the list to add new node
* Output:
*   new list with new node at the position input
*   example:
*   we have a list: {1,2,3,6,8,10}
*   input:
*   address of 1 - address of the first node in list
*   value - 5
*   pos - 4
*   output:
*   new list: {1,2,3,6,4,8,10}
*/
void insert(node **array, int value, int pos)
{
    node *temp, *p;
    temp = createNode(value);   // create a new node
    p = *array;

    int i = 1;      // access to the previous node of the position we want to change
    if (pos == 0) // which mean same with push_front
    {
        temp->next = *array; // change next member of new node from NULL to address of the first node,
                            // which mean array
        *array = temp;       // now change array to address of the new node
    }
    
    while (p->next != NULL && pos != i)   // access to the previous node of the position we want to change
    {
        p = p->next;
        i++;
    }
    temp->next = p->next;   // change the next member of new node to store address of current node in index position
    p->next = temp;         // change the next member of previous node to store address of new node
}


/*
* Function: delete
* Description: delete a node at position you want in linkedlist
* Input:
*   array - pointer to pointer has datatype is node -  address of pointer array which point to first node of linkedlist
* Output:
*   new list without a node have been delete
*/
void deletee(node **array, int pos)
{
    node *temp, *p;
    p = *array;
    int i = 1;      // access to the previous position of the node we want to delete

    while (p->next != NULL && pos != i)   // access to the previous node of the position we want to change
    {
        p = p->next;
        i++;
    }
    temp = p->next;     // store the address of the node we want to delete
    p->next = p->next->next;    // change the next member of the previous node of the node we want to delete 
                                // to store the address of the next node of the node we want to delete
    free(temp);                 // deallocated the node we want to delete

}


/*
* Function: size
* Description: return the size of the linkedlist
* Input:
*   array - pointer to pointer has datatype is node -  address of pointer array which point to first node of linkedlist
* Output:
*   size - an integer value - size of list
*/
int size(node **array)
{
    int count = 1;
    node *p = *array;
    while (p->next != NULL) // count how many node until the last 
    {
        p = p->next;
        count++;
    }
    return count;
}

/*
* Function: get
* Description: return value of the position you want
* Input:
*   array - pointer to pointer has datatype is node -  address of pointer array which point to first node of linkedlist
*   pos - an integer value - position of the node you want to know it value
* Output:
*   value of the node you want to know - an integer value 
*/
int get(node **array, int pos)
{
    int i = 0;
    node *p = *array;
    while (p->next != NULL && pos != i) 
    {
        p = p->next;
        i++;
    }
    int value = p->value;
    return value;
}

/*
* Function: empty
* Description: check whether our list is empty or not
* Input:
*   array - pointer to pointer has datatype is node -  address of pointer array which point to first node of linkedlist
* Output:
*   true if our list is empty
*   false if our list is not empty 
*/
bool empty(node **array)
{
    if (*array == NULL)
    {
        return true;
    }
    else
    {
        return false;
    } 
    
}