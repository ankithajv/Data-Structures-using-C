#include <stdio.h>
#include <string.h>
#define MAX 50

int top = -1;
char stack[MAX];

void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = ch;
    }
}

char pop() {
    if (top == -1) {
        return '\0'; 
    } else {
        return stack[top--];
    }
}

int isBalanced(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }

        else if (ch == ')' || ch == '}' || ch == ']') {
            char c = pop(); 

            if ((ch == ')' && c != '(') ||
                (ch == '}' && c != '{') ||
                (ch == ']' && c != '[')) {
                return 0; 
            }
        }
    }
    return (top == -1);
}

int main() {
    char str[MAX];
    printf("Enter the bracket string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; 

    if (isBalanced(str)) {
        printf("Balanced bracket sequence\n");
    } else {
        printf("Not balanced\n");
    }
    return 0;
}

