#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    double salary;
};

void addEmployee(FILE *file) {
    struct Employee emp;
    printf("Enter employee ID: ");
    scanf("%d", &emp.id);
    fflush(stdin);
    printf("Enter employee name: ");
    gets(emp.name);
    printf("Enter employee salary: ");
    scanf("%lf", &emp.salary);
    
    fseek(file, 0, SEEK_END); // Move the file pointer to the end of file
    fwrite(&emp, sizeof(struct Employee), 1, file); // Write the employee structure to the file
    printf("Employee added successfully.\n");
}

void displayEmployee(FILE *file, int id) {
    struct Employee emp;
    int found = 0; // Flag to check if employee with given ID is found
    
    rewind(file); // Move the file pointer to the beginning of file
    
    while (fread(&emp, sizeof(struct Employee), 1, file)) {
        if (emp.id == id) {
            found = 1;
            printf("Employee ID: %d\n", emp.id);
            printf("Employee Name: %s\n", emp.name);
            printf("Employee Salary: %.2lf\n", emp.salary);
            break;
        }
    }
    
    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}

int main() {
    FILE *file;
    int choice, id;

    file = fopen("employee.dat", "r+b"); // Open the file in binary read/write mode
    
    if (file == NULL) {
        printf("Error in opening the file.\n");
        return 0;
    }
    
    do {
        printf("\n---- Employee Details ----\n");
        printf("1. Add Employee\n");
        printf("2. Display Employee\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addEmployee(file);
                break;
            case 2:
                printf("\nEnter employee ID: ");
                scanf("%d", &id);
                displayEmployee(file, id);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 3);

    fclose(file); // Close the file

    return 0;
}
