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

void printList (node *current) {
    printf("NULL <- ");
    while (current != NULL) {
        printf("%s", current->message);
        current = current->next;
        if (current != NULL) {
            printf(" <-> ");
        }
    }
    printf(" -> NULL");
    printf("\n\n");
}

void insertNode (node *current) {
    node *new, *next;
    new = malloc(sizeof(node));
    
    next = malloc(sizeof(node));
    next = current->next;
    
    printf("Assign a message to the new node: ");
    char str[25];
    scanf("%24[^\n]", str);
    new->message = (char *)malloc((strlen(str) + 1) * sizeof(char));
    memcpy(new->message, str, (strlen(str) + 1) * sizeof(char));
    
    printf("What position would you like to enter the node? ");
    int position;
    scanf("%d", &position);
    while ((getchar() != '\n')) { }
    
    int i = 0;
    while (current != NULL && i < position - 1) {
        current = current->next;
        next = current->next;
        i++;
    }
    current->next = new;
    new->previous = current;
    new->next = next;
    next->previous = new;
    
    printf("Node inserted successfully!\n\n");
}

void findNode (node *current) {
    printf("What is the node's position? ");
    int position;
    scanf("%d", &position);
    while ((getchar() != '\n')) { }
    
    int i = 0;
    while (current != NULL && i < position) {
        current = current->next;
        i++;
    }
    
    printf("\n");
    if (current->previous != NULL) {
        printf("Previous: %s\n", current->previous->message);
    }
    else {
        printf("Previous: NULL\n");
    }
    printf("Current:  %s\n", current->message);
    if (current->next != NULL) {
        printf("Next:     %s\n", current->next->message);
    }
    else {
        printf("Next:     NULL\n");
    }
    printf("\n");
}

void deleteNode (node *current) {
    printf("What is the node's position? ");
    int position;
    scanf("%d", &position);
    while ((getchar() != '\n')) { }
    
    int i = 0;
    while (current != NULL && i < position) {
        current = current->next;
        i++;
    }
    
    current->previous->next = current->next;
    current->next->previous = current->previous;
    free(current);
    
    printf("Node deleted successfully!\n\n");
}

int main() {
    node *head, *tail, *temp;
    
    head = malloc(sizeof(node));
    tail = malloc(sizeof(node));
    temp = malloc(sizeof(node));
    
    head->previous = NULL;
    char *str = "Hello, List!";
    head->message = (char *)malloc((strlen(str) + 1) * sizeof(char));
    memcpy(head->message, str, (strlen(str) + 1) * sizeof(char));
    head->next = tail;
    
    tail->previous = head;
    str = "Goodbye, List!";
    tail->message = (char *)malloc((strlen(str) + 1) * sizeof(char));
    memcpy(tail->message, str, (strlen(str) + 1) * sizeof(char));
    tail->next = NULL;
    
    char command;
    printf("Commands:\n");
    printf("- q: Quit\n");
    printf("- p: Print List\n");
    printf("- i: Insert Node\n");
    printf("- f: Find Node\n");
    printf("- d: Delete Node\n");
    printf("\n");
    do {
        printf("Enter command: ");
        command = getchar();
        while ((getchar() != '\n')) { } // Clear remaining characters
        printf("\n");
        
        switch (command) {
            case 'p':
                printList(head);
                break;
            case 'i':
                insertNode(head);
                break;
            case 'f':
                findNode(head);
                break;
            case 'd':
                deleteNode(head);
                break;
        }
    } while (command != 'q');
    
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
