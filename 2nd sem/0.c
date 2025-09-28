/*#include <stdio.h>

int main() {
    char str[1000];
    int sum = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            sum += str[i] -'0'; // Convert char digit to int
        }
    }

    printf("Sum of digits = %d\n", sum);
    return 0;
}
*/

/*
#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int len = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\n') {
            len++;
        } else if (len > 0) {
            printf("%d ", len);
            len = 0;
        }
    }
    if (len > 0) {
        printf("%d", len);  // for the last word
    }

    return 0;
}*/





#include <stdio.h>
#include <string.h>

struct Employee {
    char employee_name[50];
    int employee_id;
    float employee_salary;
    int employee_year_of_experience;
};

// Function to sort employees in descending order of experience
void sortByExperience(struct Employee emp[], int n) {
    struct Employee temp;
    for (int i = 0; i < n ; i++) {
        for (int j = i+1; j < n; j++) {
            if (emp[i].employee_year_of_experience < emp[j].employee_year_of_experience) {
                // Swap
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }
}

// Function to print employee details
void printEmployees(struct Employee emp[], int n) {
    printf("\nEmployee details in descending order of experience:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s\n", emp[i].employee_name);
        printf("ID: %d\n", emp[i].employee_id);
        printf("Salary: %.2f\n", emp[i].employee_salary);
        printf("Experience: %d years\n\n", emp[i].employee_year_of_experience);
    }
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", emp[i].employee_name);
        printf("ID: ");
        scanf("%d", &emp[i].employee_id);
        printf("Salary: ");
        scanf("%f", &emp[i].employee_salary);
        printf("Years of experience: ");
        scanf("%d", &emp[i].employee_year_of_experience);
    }

    sortByExperience(emp, n);
    printEmployees(emp, n);

    return 0;
}
