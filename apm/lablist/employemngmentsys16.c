/* 
Name: Aswin K U 
Roll No: CS06
Date: 18/09/2026

Experiment No : 16
 
Heading: Employee Management System
 
AIM: Create an application to manage employee data using structures. The program should allow input, display, and update employee details such as name, ID, salary, and department.

ALGORITHM

1. Start.

2. Define a structure named Employee with the following members:
   a. ID  
   b. Name  
   c. Salary  
   d. Department

3. Declare an array of Employee structures.

4. Read the number of employees.

5. For each employee, read the following details:
   a. Employee ID  
   b. Employee Name  
   c. Employee Salary  
   d. Employee Department

6. Display the details of all employees.

7. Read the Employee ID whose details are to be updated.

8. Search for the employee with the given ID.

9. If the employee is found:
   a. Read the updated salary.  
   b. Read the updated department.  
   c. Modify the corresponding employee details.  
   d. Display the updated employee details.

10. If the employee is not found, display an appropriate message.

11. Stop.

SOURCE CODE
*/
#include <stdio.h>

#define MAX 10

struct Employee {
    int id;
    char name[50];
    float salary;
    char department[30];
};

int main() {
    struct Employee emp[MAX];
    int n, i, id, choice;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    /* Input employee details */
    for(i = 0; i < n; i++) {
        printf("\nEnter details of employee %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &emp[i].id);

        printf("Name: ");
        scanf(" %[^\n]", emp[i].name);

        printf("Salary: ");
        scanf("%f", &emp[i].salary);

        printf("Department: ");
        scanf(" %[^\n]", emp[i].department);
    }

    /* Display employee details */
    printf("\n--- Employee Details ---\n");

    for(i = 0; i < n; i++) {
        printf("\nEmployee %d\n", i + 1);
        printf("ID: %d\n", emp[i].id);
        printf("Name: %s\n", emp[i].name);
        printf("Salary: %.2f\n", emp[i].salary);
        printf("Department: %s\n", emp[i].department);
    }

    /* Update employee */
    printf("\nEnter employee ID to update: ");
    scanf("%d", &id);

    for(i = 0; i < n; i++) {
        if(emp[i].id == id) {
            printf("\nEnter new salary: ");
            scanf("%f", &emp[i].salary);

            printf("Enter new department: ");
            scanf(" %[^\n]", emp[i].department);

            printf("\nEmployee details updated successfully.\n");

            printf("\nUpdated Details:\n");
            printf("ID: %d\n", emp[i].id);
            printf("Name: %s\n", emp[i].name);
            printf("Salary: %.2f\n", emp[i].salary);
            printf("Department: %s\n", emp[i].department);

            break;
        }
    }

    if(i == n) {
        printf("\nEmployee ID not found.\n");
    }

    return 0;
}

/*
OUTPUT

Enter number of employees: 2

Enter details of employee 1:
ID: 101
Name: Arun
Salary: 25000
Department: IT

Enter details of employee 2:
ID: 102
Name: Rahul
Salary: 30000
Department: HR

--- Employee Details ---

Employee 1
ID: 101
Name: Arun
Salary: 25000.00
Department: IT

Employee 2
ID: 102
Name: Rahul
Salary: 30000.00
Department: HR

Enter employee ID to update: 101

Enter new salary: 28000
Enter new department: Development

Employee details updated successfully.

Updated Details:
ID: 101
Name: Arun
Salary: 28000.00
Department: Development
*/