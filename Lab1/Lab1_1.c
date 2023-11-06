// 1.1 Write a program to read two numbers and compare the numbers using function call by address.

#include <stdio.h>

void compareNumbers(int *num1, int *num2) {
    if (*num1 < *num2) {
        printf("%d is smaller than %d\n", *num1,*num2);
    } else if (*num1 > *num2) {
        printf("%d is greater than %d\n", *num1, *num2);
    } else {
        printf("Both numbers are same\n");
    }
}

int main() {
    int num1, num2;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    compareNumbers(&num1, &num2);
    
    return 0;
}
