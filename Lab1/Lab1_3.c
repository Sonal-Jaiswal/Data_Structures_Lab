// 1.3 Write a program to create a structure to store the information of n number of Employees. Employee’s 
// information includes data members: Emp-id, Name, Designation, basic_salary, hra%, da%. Display the 
// information of employees with gross salary. Use array of structure. 

#include <stdio.h>

struct Employee {
    int empId;
    char name[50];
    char designation[50];
    float basicSalary;
    float hraPercent;
    float daPercent;
};

void displayEmployee(struct Employee emp) {
    printf("Name: %s\n", emp.name);
    printf("Designation: %s\n", emp.designation);
    printf("Basic Salary: %.2f\n", emp.basicSalary);
    printf("HRA %%: %.2f%%\n", emp.hraPercent);
    printf("DA %%: %.2f%%\n", emp.daPercent);
    float grossSalary = emp.basicSalary + (emp.basicSalary * emp.hraPercent / 100) + (emp.basicSalary * emp.daPercent / 100);
    printf("Gross Salary: %.2f\n", grossSalary);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    
    struct Employee employees[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter employee %d information:\n", i + 1);
       
        scanf("%s", employees[i].name);    
        scanf("%s", employees[i].designation);
        scanf("%f", &employees[i].basicSalary);
        scanf("%f", &employees[i].hraPercent);
        scanf("%f", &employees[i].daPercent);
        printf("\n");
    }
    
    printf("Employee Information:\n");
    for (int i = 0; i < n; i++) {
        displayEmployee(employees[i]);
    }
    
    return 0;
}
