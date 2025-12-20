#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c){
    if (top == MAX-1){
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = c;
}

char pop(){
    if (top == -1){
        printf("Stack underflow!\n");
        return -1;
    }
    return stack[top--];
}

char peek(){
    if (top == -1){
        return -1;
    }
    return stack[top];
}

int isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c){
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char* infix, char* postfix){
    int i, j = 0;
    char c;
    for (i = 0; infix[i] != '\0'; i++){
        c = infix[i];
        if (isalnum(c)){
            postfix[j++] = c;
        }
        else if (c == '('){
            push(c);
        }
        else if (c == ')'){
            while (peek() != '(' && top != -1){
                postfix[j++] = pop();
            }
            pop(); // Remove '('
        }
        else if (isOperator(c)){
            while (top != -1 && precedence(peek()) >= precedence(c)){
                postfix[j++] = pop();
            }
            push(c);
        }
    }
    while (top != -1){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main(){
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression:");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
        return 0;
}