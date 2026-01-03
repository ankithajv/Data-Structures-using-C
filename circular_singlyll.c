#include <stdio.h>
#include <stdlib.h>

/* node structure */
typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head = NULL;

/* create node */
Node* createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* insert at front */
void insertFront(int value)
{
    Node *newNode = createNode(value);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

/* insert at end */
void insertEnd(int value)
{
    Node *newNode = createNode(value);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
}

/* insert at specific position (1-based index) */
void insertAtPos(int value, int pos)
{
    if (pos == 1)
    {
        insertFront(value);
        return;
    }

    Node *newNode = createNode(value);
    Node *temp = head;
    int i = 1;

    while (i < pos - 1 && temp->next != head)
    {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

/* delete from front */
void deleteFront()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        Node *last = head;
        Node *temp = head;

        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
        free(temp);
    }
}

/* delete from end */
void deleteEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        Node *temp = head;
        Node *prev = NULL;

        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        free(temp);
    }
}

/* delete from specific position */
void deleteAtPos(int pos)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (pos == 1)
    {
        deleteFront();
        return;
    }

    Node *temp = head;
    Node *prev = NULL;
    int i = 1;

    while (i < pos && temp->next != head)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (i == pos)
    {
        prev->next = temp->next;
        free(temp);
    }
}

/* display */
void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;
    printf("Circular List: ");

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

/* main */
int main()
{
    insertEnd(10);
    insertEnd(20);
    insertFront(5);
    insertAtPos(15, 3);

    display();

    deleteFront();
    deleteEnd();
    deleteAtPos(2);

    display();

    return 0;
}
