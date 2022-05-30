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

void printList (struct Node *current) {
    while (current != NULL) {
        printf("%s", current->message);
        current = current->next;
        if (current != NULL) {
            printf(" <-> ");
        }
    }
    printf("\n");
}

//void printNode (struct Node *temp) {
//    printf("%s", temp->message);
//}

int main() {
    node *head, *tail, *temp;
    
    head = malloc(sizeof(struct Node));
    tail = malloc(sizeof(struct Node));
    
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
    
    temp = malloc(sizeof(struct Node));
    
    char command;
    printf("Commands:\n");
    printf("- q: Quit\n");
    printf("- p: Print List\n");
    printf("\n");
    do {
        printf("Enter command: ");
        command = getchar();
        while ((getchar() != '\n')) { } // Clear remaining characters
        
        switch (command) {
            case 'p':
                printList(head);
                break;
            case 'i':
                printf("insert\n");
                break;
            case 'f':
                printf("find\n");
                break;
            case 'd':
                printf("delete\n");
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
