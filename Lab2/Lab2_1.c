// 2.1 WAP to create a 1-D array of n elements and perform the following menu based operations using 
// function.
// a. insert a given element at specific position.
// b. delete an element from a specific position of the array.
// c. linear search to search an element
// d. traversal of the array

#include <stdio.h>

void insertElement(int arr[], int *size, int element, int position) {
    if (*size >= position) {
        for (int i = *size; i >= position; i--) {
            arr[i] = arr[i - 1];
        }
        arr[position - 1] = element;
        (*size)++;
        printf("Element inserted\n");
    } else {
        printf("Invalid position\n");
    }
}

void deleteElement(int arr[], int *size, int position) {
    if (position >= 1 && position <= *size) {
        for (int i = position - 1; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
        printf("Element deleted\n");
    } else {
        printf("Invalid position\n");
    }
}

int linearSearch(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return 0;
}

void traverseArray(int arr[], int size) {
    printf("Array Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter size n: ");
    scanf("%d", &size);
    
    int arr[100]; 
    printf("Enter Array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    // int size = n;
    
    int option, element, position;
    do {
        printf("\n***MENU***\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Linear Search\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Element to insert: ");
                scanf("%d", &element);
                printf("Enter Position: ");
                scanf("%d", &position);
                insertElement(arr, &size, element, position);
                break;
            case 2:
                printf("Enter Position to delete: ");
                scanf("%d", &position);
                deleteElement(arr, &size, position);
                break;
            case 3:
                printf("Element to search: ");
                scanf("%d", &element);
                position = linearSearch(arr, size, element);
                if (position != -1) {
                    printf("Element found at position %d\n", position + 1);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 4:
                traverseArray(arr, size);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option\n");
        }
    } while (option != 5);
    
    return 0;
}
