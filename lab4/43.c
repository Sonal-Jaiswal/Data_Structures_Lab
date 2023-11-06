// WAP to represent the polynomial equation of a single varaible using a singly linked list and perform the addition of two polynomial equations

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head1 = NULL, *head2 = NULL, *head3 = NULL;

void traverse(struct node *temp, int n)
{

    while (temp != NULL)
    {
        printf("%dx^%d ", temp->data, n--);
        temp = temp->next;
        if (temp != NULL)
            printf(" + ");
    }
    printf("\n");
}

void add()
{
    struct node *temp1 = head1, *temp2 = head2;
    struct node *temp3 = (struct node *)malloc(sizeof(struct node));
    temp3->data = temp1->data + temp2->data;
    temp3->next = NULL;
    head3 = temp3;
    temp1 = temp1->next;
    temp2 = temp2->next;
    while (temp1 != NULL && temp2 != NULL)
    {
        struct node *curr = (struct node *)malloc(sizeof(struct node));
        curr->data = temp1->data + temp2->data;
        curr->next = NULL;
        temp3->next = curr;
        temp3 = temp3->next;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
}

void makeEven(int n1, int n2)
{
    struct node *temp1 = head1, *temp2 = head2;
    if (n1 < n2)
    {
        while (temp1->next != NULL)
            temp1 = temp1->next;
        for (int i = 0; i < n2 - n1; i++)
        {
            struct node *curr = (struct node *)malloc(sizeof(struct node));
            curr->data = 0;
            curr->next = head1;
            head1 = curr;
        }
    }
    else if (n1 > n2)
    {
        while (temp2->next != NULL)
            temp2 = temp2->next;
        for (int i = 0; i < n1 - n2; i++)
        {
            struct node *curr = (struct node *)malloc(sizeof(struct node));
            curr->data = 0;
            curr->next = head2;
            head2 = curr;
        }
    }
}

int main()
{
    int n1, n2;
    struct node *temp1 = (struct node *)malloc(sizeof(struct node)), *temp2 = (struct node *)malloc(sizeof(struct node));
    printf("Polynomial 1\n");
    printf("Enter maximum power of x : ");
    scanf("%d", &n1);
    printf("Enter the coefficient of degree %d : ", n1);
    scanf("%d", &temp1->data);
    temp1->next = NULL;
    head1 = temp1;
    for (int i = n1 - 1; i >= 0; i--)
    {
        struct node *curr = (struct node *)malloc(sizeof(struct node));
        printf("Enter the coefficient of degree %d : ", i);
        scanf("%d", &curr->data);
        curr->next = NULL;
        temp1->next = curr;
        temp1 = temp1->next;
    }
    printf("\nPolynomial 2\n");
    printf("Enter maximum power of x : ");
    scanf("%d", &n2);
    printf("Enter the coefficient of degree %d : ", n2);
    scanf("%d", &temp2->data);
    temp2->next = NULL;
    head2 = temp2;
    for (int i = n2 - 1; i >= 0; i--)
    {
        struct node *curr = (struct node *)malloc(sizeof(struct node));
        printf("Enter the coefficient of degree %d : ", i);
        scanf("%d", &curr->data);
        curr->next = NULL;
        temp2->next = curr;
        temp2 = temp2->next;
    }
    makeEven(n1, n2);
    add();
    printf("Sum : ");
    traverse(head3, (n1 > n2) ? n1 : n2);
}