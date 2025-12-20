#include<stdio.h>
#define MAX 5

int queue[MAX];
int front=-1,rear=-1;

int isFull(){
    return rear==MAX-1;
}

int isEmpty(){
    return front==-1||rear==-1;
}

void enqueue(int val){
    if(isFull()){
        printf("Queue is full!\n");
    }
    else{
        if(front==-1){
            front=0;
        }
        queue[++rear]=val;
    }
}

void dequeue(){
    if(isEmpty()){
        printf("Queue is Empty!!\n");
    }else{
        printf("Successfully Enqueued %d\n",queue[front++]);

        if(front>rear) 
            front=rear=-1;
    }
}

void display(){
    if(isEmpty()){
        printf("Queue is empty\n");
    }else{
        for(int i=front;i<=rear;i++){
            printf("%d\n",queue[i]);
        }
    }
}

int main(){
    int choice,val;

    printf("What would you like to do >>");
    while(1){
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter the value to enqueue:");
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
        printf("Exiting...!");
        return 0;
    }
    
}
return 0;

}