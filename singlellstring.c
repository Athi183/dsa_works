#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *link;
};

struct node *head = NULL;

// Function to display the list
void display() {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%c", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

// Function to insert at the end to keep the original order
void insertAtEnd(char ele) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = ele;
    new_node->link = NULL;
    
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *ptr = head;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = new_node;
    }
}

// Function to display the reversed list without modifying it
void displayReversed(struct node *node) {
    if (node == NULL) {
        return;
    }
    displayReversed(node->link);
    printf("%c", node->data);
}

int main() {
    while (1) {
        printf("Do you want to insert an element? (y/n): ");
        char ch;
        scanf(" %c", &ch);

        if (ch == 'y') {
            char ele;
            printf("Enter the element into the list: ");
            scanf(" %c", &ele);
            insertAtEnd(ele);  // Insert at the end to keep original order
        } else if (ch == 'n') {
            printf("Original string: ");
            display();
            printf("Reversed string: ");
            displayReversed(head);
            printf("\n");
            return 0;
        } else {
            printf("Invalid choice\n");
        }
    }
}

