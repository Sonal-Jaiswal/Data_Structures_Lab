#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void create(struct Node** head, int element, int pos) {

    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = element;
    new->next = NULL;
    struct Node* temp = *head;

    if (pos == 1) {
        *head = new;
        new->next = *head;
        return;
    }

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(new);
    }
    else {
        temp->next = new;
        new->next = *head;
    }
}

void traverse(struct Node* head) {

    struct Node* temp = head;
    printf("%d ", temp->data);
    temp = temp->next;
    while (temp != head && temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

}

int main() {
    struct Node* head = NULL;
    int n, element, position;

    printf("Enter no. of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter info of node %d: ", i + 1);
        scanf("%d", &element);
        create(&head, element, i + 1);
    }

    printf("\nClickedlist: ");
    traverse(head);
    printf("\n");

    return 0;
}