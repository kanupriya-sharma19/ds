//infix to prefix
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

char stack[30];
int top = -1;

void push(char val) {
    stack[++top] = val;
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
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0; 
    }
}
int associativity(char ch) {
    if (ch == '^')
        return 1; // Right-to-left
    else
        return 0; // Left-to-right
}

void infix_to_prefix(char infix[30], char prefix[50]) {
    char temp, x;
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        temp = infix[i];
        if (isalnum(temp)) {
            prefix[j++] = temp;
            prefix[j++] = ' '; 
        } else if (temp == '(') {
            push(temp);
        } else if (temp == ')') {
            while ((x = pop()) != '(') {
                prefix[j++] = x;
                prefix[j++] = ' '; 
            }
        } else { 
            while ((top != -1 && priority(stack[top]) > priority(temp)) ||((associativity(stack[top]))==1 &&priority(stack[top])== priority(temp))) {
                x = pop();
                prefix[j++] = x;
                prefix[j++] = ' ';
            }
          
            push(temp);
        }
        i++;
    }

    //end tak
    while (top != -1) {
        x = pop();
        prefix[j++] = x;
        prefix[j++] = ' '; 
    }
    prefix[j] = '\0'; 
}

void main() {
    char infix[30], revinfix[30];
    char prefix[50];
    int i = 0;
    char ch;

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    strcpy(revinfix, strrev(infix));

    for(i = 0; revinfix[i] != '\0'; i++) {
        if(revinfix[i] == '(')
            revinfix[i] = ')';
        else if(revinfix[i] == ')')
            revinfix[i] = '(';
    }
    infix_to_prefix(revinfix, prefix);
    printf("prefix is: %s\n", strrev(prefix));
}