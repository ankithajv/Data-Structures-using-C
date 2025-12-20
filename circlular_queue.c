#include<stdio.h>
#define MAX 5

int queue[MAX];
int front = -1 , rear =-1;

int isFull(){
    return front == (rear+1)%MAX;
}

int isEmpty(){
    return front==-1;
}


void enqueue(int val){
    if(isFull()){
        printf("Queue is full!");
    }
    else{
        if(front==-1){
            front=rear=0;
        } 
        else{
            rear=(rear+1)%MAX;
        }
        queue[rear]=val;
        printf("Enqueued %d\n",val);
    }
}

void dequeue(){
    if(isEmpty()){
        printf("Queue is empty!\n");
        return;
    }
    printf("Dequeued %d\n",queue[front]);
    if (front == rear){
        front = rear = -1;
    }
    else{
        front = (front+1)%MAX;
    }
}

void display(){
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:");
    
    int i = front;
    while(1){
        printf("%d\n",queue[i]);
        if(i==rear)
            break;
        i=(i+1)%MAX;
    }
    printf("\n");
}

int main(){
    int choice,val;
    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter you choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter the element to enqueue:");
            scanf("%d",&val);
            enqueue(val);
            break;

            case 2:
            dequeue();
            break;

            case 3:
            display();
            break;

            case 4:
            printf("Exiting....");
            return 0;

            default:
            printf("Invalid entry!\n");
        }
    }
    return 0;
}