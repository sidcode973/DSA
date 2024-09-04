#include<stdio.h>
#include <stdlib.h>


struct Employee {
    int id;
    char name[50];
    char designation[50];
    float basic_salary;
    float hra_percent;
    float da_percent;
    float gross_salary;
};
void calculateGrossSalary(struct Employee *emp) {
    emp->gross_salary = emp->basic_salary + (emp->basic_salary * emp->hra_percent / 100) + (emp->basic_salary * emp->da_percent / 100);
}


void displayEmployeeInfo(struct Employee *emp) {
    printf("Employee ID: %d\n", emp->id);
    printf("Name: %s\n", emp->name);
    printf("Designation: %s\n", emp->designation);
    printf("Basic Salary: %.2f\n", emp->basic_salary);
    printf("HRA Percent: %.2f%%\n", emp->hra_percent);
    printf("DA Percent: %.2f%%\n", emp->da_percent);
    printf("Gross Salary: %.2f\n", emp->gross_salary);
    printf("-------------------------\n");
}

int main() {
    int n;
    struct Employee *employees ;


    printf("Enter the number of employees: ");
    scanf("%d", &n);
    employees = (struct Employee *)malloc(n * sizeof(struct Employee));
    
    for (int i = 0; i < n; i++) {
        printf("Enter information for employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &employees[i].id);
        printf("Name: ");
        scanf(" %[^\n]%*c", employees[i].name); 
        printf("Designation: ");
        scanf(" %[^\n]%*c", employees[i].designation);
        printf("Basic Salary: ");
        scanf("%f", &employees[i].basic_salary);
        printf("HRA Percent: ");
        scanf("%f", &employees[i].hra_percent);
        printf("DA Percent: ");
        scanf("%f", &employees[i].da_percent);

        
        calculateGrossSalary(&employees[i]);
    }

    
    printf("\nEmployee Information with Gross Salary:\n");
    printf("-------------------------\n");
    for (int i = 0; i < n; i++) {
        displayEmployeeInfo(&employees[i]);
    }


    free(employees);

    return 0;
}
