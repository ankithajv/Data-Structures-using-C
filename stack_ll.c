#include <stdio.h>
#include <stdlib.h>

// 1. Define the Node Structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 2. Global pointer to keep track of the top of the stack
Node *top = NULL;

// 3. Push: Add an element to the top of the stack
void push(int data) {
    // Create a new node, just like in a regular linked list
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    // Check for "Stack Overflow" (when malloc fails to get memory)
    if (newNode == NULL) {
        printf("Heap Overflow! Cannot push item.\n");
        return;
    }

    // Set the data for the new node
    newNode->data = data;
    
    // Point the new node's 'next' to the current top of the stack
    newNode->next = top;
    
    // Update the 'top' pointer to be this new node
    top = newNode;
    
    printf("%d pushed to stack.\n", data);
}

// 4. Pop: Remove an element from the top of the stack
void pop() {
    // Check for "Stack Underflow" (trying to pop from an empty stack)
    if (top == NULL) {
        printf("Stack Underflow! Cannot pop item.\n");
        return;
    }

    // Create a temporary pointer to hold the node we want to delete
    Node* temp = top;
    
    // Get the data from the top node so we can print it
    int poppedData = top->data;
    
    // Move the 'top' pointer down to the *next* node in the list
    top = top->next;
    
    // Free the memory of the original top node
    free(temp);
    
    printf("%d popped from stack.\n", poppedData);
}

// 5. Peek: View the top element without removing it
void peek() {
    // Check if the stack is empty
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        // Just print the data of the 'top' node
        printf("Top element is: %d\n", top->data);
    }
}

// 6. Display: Print all elements in the stack from top to bottom
void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    
    // Create a temporary pointer to traverse the list
    Node* temp = top;
    
    printf("Stack (Top to Bottom):\n");
    
    // Loop through the list until we reach the end (NULL)
    while (temp != NULL) {
        printf("%d\n", temp->data); // Print the data
        temp = temp->next;      // Move to the next node
    }
}

// 7. Main function with a menu to test operations
int main() {
    int choice, data;
    while (1) {
        printf("\n--- Stack using Linked List ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (Show Top)\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}