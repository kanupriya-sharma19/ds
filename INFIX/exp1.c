#include <stdio.h>
#include <ctype.h>

#define MAX 30

char stack[MAX];
int top = -1;

void push(char val) {
    if (top < MAX - 1) {
        stack[++top] = val;
    }
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char ch) {
    switch (ch) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void infix_to_postfix(char infix[], char postfix[]) {
    char temp, x;
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        temp = infix[i];
        if (isalnum(temp)) {
            postfix[j++] = temp;
        } else if (temp == '(') {
            push(temp);
        } else if (temp == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        } else { 
            while (top != -1 && priority(stack[top]) > priority(temp) ||
                   (priority(stack[top]) == priority(temp))) {
                x = pop();
                postfix[j++] = x;
            }
            push(temp);
        }
        i++;
    }

    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; 
}

int main() {
    char infix[MAX];
    char postfix[MAX];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infix_to_postfix(infix, postfix);
    printf("Postfix is: %s\n", postfix);
    return 0;
}
