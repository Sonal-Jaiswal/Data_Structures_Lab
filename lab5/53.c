#include<stdio.h>
#include<stdlib.h>

struct Node {
    int row;
    int col;
    int val;
    struct Node* next;
};

void traverseList(struct Node* head) {
    printf("The list is: \n");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d %d %d\n", temp->row, temp->col, temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main() {

    int r, c;
    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &r, &c);

    int arr[r][c];

    int count = 0;
    printf("Enter elements of sparse matrix: ");

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] != 0) count++;
        }
    }

    struct Node* head, * new, * temp;
    new = (struct Node*)malloc(sizeof(struct Node));
    new->next = NULL;

    new->row = r;
    new->col = c;
    new->val = count;

    head = new;
    temp = new;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] != 0) {

                new = (struct Node*)malloc(sizeof(struct Node));
                new->next = NULL;
                temp->next = new;

                new->row = i;
                new->col = j;
                new->val = arr[i][j];

                temp = temp->next;
            }
        }
    }

    printf("\n");
    traverseList(head);

    return 0;
}