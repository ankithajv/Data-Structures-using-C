#include <stdio.h>
#include <stdlib.h>

// Queue using linked list
// Front -> Dequeue
// Rear -> Enqueue

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(int data) {
    Node* newNode = createNode(data);
    if (rear == NULL) { // empty queue
        front = rear = newNode;
        printf("%d enqueued.\n", data);
        return;
    }
    rear->next = newNode;
    rear = newNode;
    printf("%d enqueued.\n", data);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Nothing to dequeue.\n");
        return;
    }
    Node* temp = front;
    int val = temp->data;
    front = front->next;
    if (front == NULL) // queue became empty
        rear = NULL;
    printf("Dequeued: %d\n", val);
    free(temp);
}

void peek() {
    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    Node* temp = front;
    printf("Queue (front -> rear): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("\n--- Queue using Linked List ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek (Front)\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
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