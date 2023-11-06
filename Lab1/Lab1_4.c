// 1.4 Write a menu driven program to create a structure to represent complex number and perform the 
// following operation using function :

#include <stdio.h>

struct Complex {
    float real;
    float imaginary;
};

void addComplex(struct Complex c1, struct Complex c2, struct Complex *result) {

    result->real = c1.real + c2.real;
    result->imaginary = c1.imaginary + c2.imaginary;
}

void multiplyComplex(struct Complex c1, struct Complex c2, struct Complex *result) {
    
     result->real = (c1.real * c2.real) - (c1.imaginary * c2.imaginary)   ;
     result->imaginary = (c1.real * c2.imaginary) + (c1.imaginary * c2.real);
}

void displayComplex(struct Complex c) {
    if (c.imaginary >= 0) {
        printf("%.2f + %.2fi\n", c.real, c.imaginary);
    } else {
        printf("%.2f - %.2fi\n", c.real, -c.imaginary);
    }
}

int main() {
    struct Complex num1, num2, result;
    int choice;
    
    printf("Enter complex number 1: ");
    scanf("%f %f", &num1.real, &num1.imaginary);
    
    printf("Enter complex number 2: ");
    scanf("%f %f", &num2.real, &num2.imaginary);
    
    printf("MENU\n");
    printf("1. addition \n");
    printf("2. multiplication \n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            addComplex(num1, num2, &result);
            printf("Result of addition: ");
            displayComplex(result);
            break;
        case 2:
            multiplyComplex(num1, num2, &result);
            printf("Result of subtraction: ");
            displayComplex(result);
            break;
        default:
            printf("Invalid choice\n");
    }
    
    return 0;
}
