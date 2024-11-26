// prefix evaluation

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

int stack[30];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

void main() {
    int ans, i = 0, a, b;
    char ch;
    char prefix[30],revinfix[30];

    printf("Enter the prefix expression: ");
    scanf("%s", prefix);
strcpy(revinfix, strrev(prefix));
    while (revinfix[i] != '\0') {
        ch = revinfix[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '/' || ch == '*') {
            a = pop();
            b = pop();
            switch (ch) {
                case '+': ans = a + b; break;
                case '-': ans = a - b; break;
                case '/': 
                    if (b == 0) {
                        printf("Error: Division by zero!\n");
                        return;
                    }
                    ans = a / b;
                    break;
                case '*': ans = a * b; break;
            }
            push(ans);
        }
        i++;
    }

    ans = pop();
    printf("The evaluation of the given postfix expression is %d\n", ans);
}
