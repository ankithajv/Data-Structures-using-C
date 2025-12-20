#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *tail = NULL;
void isf()
{
    int ele;
    struct node *p = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to be inserted: ");
    scanf("%d", &ele);
    p->data = ele;
    p->next = NULL;
    if (head == NULL)
    {
        head = p;
        printf("%d is inserted\n", head->data);
        return;
    }
    p->next = head;
    head = p;
    printf("%d is inserted\n", head->data);
}
void ise()
{

    int ele;
    struct node *p = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to be inserted: ");
    scanf("%d", &ele);
    p->data = ele;
    p->next = NULL;
    if (head == NULL)
    {
        head = p;
        printf("%d is inserted\n", head->data);
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = p;
    printf("%d is inserted\n", p->data);
}
void isp()
{

    int ele, pos;
    struct node *p = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to be inserted: ");
    scanf("%d", &ele);
    printf("Enter the position: ");
    scanf("%d", &pos);
    p->data = ele;
    p->next = NULL;
    if (pos == 0)
    {
        p->next = head;
        head = p;
        printf("%d is inserted at %d\n", ele, pos);
        return;
    }
    struct node *temp = head;
    int i = 0;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    p->next = temp->next;
    temp->next = p;
    printf("%d is inserted at %d pos\n", ele, pos);
}
void def()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *p;
    p = head;
    printf("%d is deleted\n", p->data);
    head = head->next;
    free(p);
}
void dee()
{
    struct node *ptr, *ptr1;
    if (head == NULL)
    {
        printf("\nlist is empty");
    }
    else if (head->next == NULL)
    {
        /* only one node: save pointer then set head NULL and free the node */
        ptr = head;
        printf("Deleted element: %d\n", ptr->data);
        head = NULL;
        free(ptr);
        printf("\nOnly node of the list deleted\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {

            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        printf("Deleted element: %d\n", ptr->data);
        free(ptr);
        printf("\nDeleted Node from the last\n");
    }
}
void dep()
{
    int pos;
    struct node *p;
    printf("Enter the position to be deleted: ");
    scanf("%d", &pos);
    if (pos == 0)
    {
        p = head;
        head = head->next;
        printf("%d is deleted at %d\n", p->data, pos);
        free(p);
        return;
    }
    struct node *temp = head;
    int i = 0;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    p = temp->next;
    temp->next = p->next;
    printf("%d is deleted at %d\n", p->data, pos);
    free(p);
}
void display()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");

        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int ch;
    printf("1.Insert at the top\n 2.Insert at the end\n 3.Insert at a pos\n 4.Delete at the top\n 5.Delete at the end \n6. Delete at a pos\n7.Display\n 8.Exit\n");
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            isf();
            break;
        case 2:
            ise();
            break;
        case 3:
            isp();
            break;
        case 4:
            def();
            break;
        case 5:
            dee();
            break;
        case 6:
            dep();
            break;
        case 7:
            display();

            break;
        case 8:
            exit(0);
        default:
            printf("Invalid position");
        }
    }
    return 0;
}