#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "C:\Users\Trine\Desktop\EmbeddedInterview\linked_list_and_binary_search\Header\binary_search.h"
#include "C:\Users\Trine\Desktop\EmbeddedInterview\linked_list_and_binary_search\Header\sort.h"
#include "C:\Users\Trine\Desktop\EmbeddedInterview\linked_list_and_binary_search\Header\node.h"



void print_list(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;

    srand(time(NULL));  // create a list have 10000 node with random value 
    for (int i = 0; i < 10000; i++) {
        int value = rand() % 10000 + 1;
        add_node(&head, value);
    }

    add_node(&head, 5639);  // add a new node have value 5639 to the list

    print_list(head);   // print the list

    CenterPoint *ptr = centerPoint(head);   // this ptr hold address of the center node of the list

    int value = 5639;
    CenterPoint *result = binarySearch(ptr, value);
    if (result != NULL) {
        printf("Tim thay %d\n", result->value);
    } else {
        printf("Khong tim thay\n");
    }

    return 0;
}