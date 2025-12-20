#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX 5 //globally

char stack[MAX];
int top = -1; // Fixed missing type

void push(char c){
    if (top == MAX-1){
        printf("Stack overflow!\n");
        return;
    }
    stack[++top]=c;
}

char pop(){
    if (top==-1){
        printf("Stack underflow!\n");
        return -1;
    }
    return stack[top--];
}

char peek(){
    if (top==-1){
        printf("Stack is empty!\n");
        return -1;
    }
    else{
        return stack[top];
    }
    
}

int main(){
    int choice;
    char val;
    while(1){
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter character to push: ");
                scanf("%c", &val);
                push(val);
                break;
            case 2:
                val = pop();
                if(val != -1)
                    printf("Popped: %c\n", val);
                break;
            case 3:
                val = peek();
                if(val != -1)
                    printf("Top: %c\n", val);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}

