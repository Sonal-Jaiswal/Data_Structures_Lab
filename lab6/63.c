#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int isFull(int top) {
    return top == MAX_SIZE - 1;
}

int isEmpty(int top) {
    return top == -1;
}

void push(char stack[], int* top, char op) {
    if (isFull(*top)) {
        return;
    }
    stack[++(*top)] = op;
}

char pop(char stack[], int* top) {
    if (isEmpty(*top)) {
        return '\0';
    }
    return stack[(*top)--];
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return -1;
}

void infixToPostfix(char* expression) {
    char stack[MAX_SIZE];
    int top = -1;
    int i = 0, k = 0;
    char ch;
    printf("Enter infix expression: ");
    while ((ch = getchar()) != '\n') {
        expression[i++] = ch;
    }
    expression[i] = '\0';
    for (i = 0; expression[i] != '\0'; ++i) {
        if ((expression[i] >= 'a' && expression[i] <= 'z') ||
            (expression[i] >= 'A' && expression[i] <= 'Z')) {
            expression[k++] = expression[i];
        }
        else if (expression[i] == '(') {
            push(stack, &top, expression[i]);
        }
        else if (expression[i] == ')') {
            while (!isEmpty(top) && stack[top] != '(')
                expression[k++] = pop(stack, &top);
            if (!isEmpty(top) && stack[top] != '(')
                return;
            else
                pop(stack, &top);
        }
        else {
            while (!isEmpty(top) && precedence(expression[i]) <= precedence(stack[top]))
                expression[k++] = pop(stack, &top);
            push(stack, &top, expression[i]);
        }
    }

    while (!isEmpty(top))
        expression[k++] = pop(stack, &top);

    expression[k] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    infixToPostfix(infix);
    printf("Postfix expression: %s\n", infix);
    return 0;
}