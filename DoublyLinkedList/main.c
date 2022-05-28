//
//  main.c
//  DoublyLinkedList
//
//  Created by Sean Hammell on 5/26/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    struct Node *previous;
    char *message;
    struct Node *next;
} typedef node;

int main() {
    node *head, *tail, *temp;
    
    head = malloc(sizeof(struct Node));
    head->previous = NULL;
    head->message = NULL;
    
    tail = malloc(sizeof(struct Node));
    head->message = NULL;
    head->next = NULL;
    
    temp = malloc(sizeof(struct Node));
    
    free(head);
    free(tail);
    free(temp);
    
//    temp->previous = NULL;
//    char *str = "Hello, List!";
//    temp->message = (char *)malloc((strlen(str) + 1) * sizeof(char));
//    memcpy(temp->message, str, (strlen(str) + 1) * sizeof(char));
//    temp->next = NULL;
//
//    printNode(temp);
//
//    free(temp->message);
    
    return 0;
}
