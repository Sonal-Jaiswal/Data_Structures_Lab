// 1.2 Write a program to create an array of n elements using dynamic memory allocation. Calculate sum of 
// all the prime elements of the array using function and de-allocate the memory of the array after its use.

#include <stdio.h>
#include <stdlib.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int));
    
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            sum += arr[i];
        }
    }
    
    printf("Sum = %d\n", sum);
    
    free(arr);
    
    return 0;
}
