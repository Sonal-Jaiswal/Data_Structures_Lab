#include<stdio.h>

int top = -1;
int stack[100];

void push(int data) {
    if (top > 100) {
        printf("Stack Overflow!");
        return;
    }
    else {
        top++;
        stack[top] = data;
    }
}

void pop() {
    if (top < 0) {
        printf("Stack Underflow!");
        return;
    }
    else {
        int x = stack[top];
        top--;
        printf("%d deleted from Stack", x);
    }
}

void IsEmpty() {
    if (top == -1) {
        printf("Stack Empty: True");
    }
    else {
        printf("Stack Empty: False");
    }
}

void IsFull() {
    if (top == 100) {
        printf("Stack Full: True");
    }
    else {
        printf("Stack Full: False");
    }
}

void traverse() {
    printf("Stack: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {

    int ch;
    printf("Main Menu \n");
    printf("1. Push \n");
    printf("2. Pop \n");
    printf("3. IsEmpty \n");
    printf("4.IsFull \n");
    printf("5. Traverse \n");
    printf("6.Exit \n");

    int x;

    while (1) {

        printf("\nEnter option: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter element to be pushed into the stack: ");
            scanf("%d", &x);
            push(x);
            break;

        case 2:
            pop();
            break;

        case 3:
            IsEmpty();
            break;

        case 4:
            IsFull();
            break;

        case 5:
            traverse();
            break;

        case 6:
            break;
        }

        if (ch == 6)break;
    }


    return 0;
}