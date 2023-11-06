#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* head = NULL;

// Function to insert a node at a specific position
void insertNode(int element, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = element;
    
    if (position == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        int i;
        for (i = 1; i < position - 1; i++) {
            if (temp == NULL) {
                printf("Position not found.\n");
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Node inserted\n");
}

// Function to delete a node from a specific position
void deleteNode(int position) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        printf("Node deleted\n");
    } else {
        Node* temp = head;
        Node* prev = NULL;
        int i;
        for (i = 1; i < position; i++) {
            if (temp == NULL) {
                printf("Position not found.\n");
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
        printf("Node deleted\n");
    }
}

// Function to count the nodes in the linked list
int countNodes() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to traverse and display the linked list
void traverseList() {
    Node* temp = head;
    printf("The list is: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Function to search for an element in the linked list
int searchElement(int element) {
    Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == element) {
            printf("Element found at node-%d\n", position);
            return 1;
        }
        temp = temp->next;
        position++;
    }
    printf("Element not found in the list.\n");
    return 0;
}

// Function to sort the linked list in ascending order
void sortList() {
    if (head == NULL) {
        printf("List is empty. Cannot sort.\n");
        return;
    }

    Node* current = head;
    Node* index = NULL;
    int temp;

    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}

// Function to reverse the linked list
void reverseList() {
    Node *prev = NULL, *current = head, *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    int choice, element, position;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        insertNode(element, i + 1);
    }
        

        printf("MENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Count\n");
        printf("4. Traverse\n");
        printf("5. Search\n");
        printf("6. Sort\n");
        printf("7. Reverse\n");
        printf("8. Exit\n");
        
    while (1) {
        
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                printf("Enter position: ");
                scanf("%d", &position);
                insertNode(element, position);
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteNode(position);
                break;

            case 3:
                printf("The total number of nodes: %d\n", countNodes());
                break;

            case 4:
                traverseList();
                break;

            case 5:
                printf("Enter element to be searched: ");
                scanf("%d", &element);
                searchElement(element);
                break;

            case 6:
                sortList();
                printf("List sorted\n");
                break;

            case 7:
                reverseList();
                printf("Reverse list: ");
                traverseList();
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
