#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;



Node *head = NULL;

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

void insertFront(int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

void insertEnd(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertSpecificPos(int data, int pos) {
    Node* newNode = createNode(data);

    if (pos <= 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    int i = 1;

    // Traverse to the node *before* the target position
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteFront() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (head->next == NULL) { // only one node
        printf("Deleted: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // temp is last node
    Node* prev = head;
    while (prev->next != temp) prev = prev->next;
    prev->next = NULL;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

void deleteSpecificPos(int pos) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (pos <= 1) {
        deleteFront();
        return;
    }
    Node* temp = head;
    int i = 1;
    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Invalid position. Position %d is out of bounds.\n", pos);
        return;
    }
    // temp is node to delete
    if (temp->next == NULL) { // last node
        deleteEnd();
        return;
    }
    // middle node
    Node* prev = head;
    while (prev->next != temp) prev = prev->next;
    prev->next = temp->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

int main() {
    int choice, data, pos;
    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Display List\n");
        printf("5. Delete at Front\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Specific Position\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertFront(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position (1-based): ");
                scanf("%d", &pos);
                insertSpecificPos(data, pos);
                break;
            case 4:
                display();
                break;
            case 5:
                deleteFront();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                printf("Enter position (1-based) to delete: ");
                scanf("%d", &pos);
                deleteSpecificPos(pos);
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}