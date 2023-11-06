#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;

void push(int data)
{
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    if (top == NULL)
        top = new;
    else
    {
        new->next = top;
        top = new;
    }
}

void pop()
{
    if (top == NULL)
        printf("Stack Underflow!");
    else
    {
        int x = top->data;
        top = top->next;
        printf("%d deleted from Stack", x);
    }
}

void IsEmpty()
{
    if (top == NULL)
        printf("Stack empty: True");
    else
        printf("Stack empty: False");
}

void traverse()
{
    struct Node *temp2 = top;
    printf("Stack: ");
    while (temp2 != NULL)
    {
        printf("%d ", temp2->data);
        temp2 = temp2->next;
    }
}

int main()
{
    int ch, x;
    printf("Main Menu \n");
    printf("1. Push \n");
    printf("2. Pop \n");
    printf("3. IsEmpty \n");
    printf("4. Traverse \n");
    printf("5. Exit \n");
    do
    {
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
            traverse();
            break;
        case 5:
            break;
        }
    } while (ch != 5);
    return 0;
}