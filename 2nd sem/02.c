#include <stdio.h>

struct Employee {
    char emp_name[50];
    int emp_id;
    float basic_salary;
    char gender;
};

int main() {
    struct Employee emp[10];
    FILE *fp;
    float DA, HRA, gross;

    // Writing to file
    fp = fopen("INPUT_DATA.txt", "w");
    for (int i = 0; i < 3; i++) {
        printf("Enter details for Employee %d:\n", i+1);
        printf("Name: ");
        scanf("%s", emp[i].emp_name);
        printf("ID: ");
        scanf("%d", &emp[i].emp_id);
        printf("Basic Salary: ");
        scanf("%f", &emp[i].basic_salary);
        printf("Gender (M/F): ");
        scanf(" %c", &emp[i].gender);
        fprintf(fp, "%s %d %.2f %c\n", emp[i].emp_name, emp[i].emp_id, emp[i].basic_salary, emp[i].gender);
    }
    fclose(fp);

    // Reading and displaying with Gross Salary
    fp = fopen("INPUT_DATA.txt", "r");
    printf("\nEmployee Details with Gross Salary:\n");
    printf("Name\tID\tGender\tGross Salary\n");

    while (fscanf(fp, "%s %d %f %c", emp[0].emp_name, &emp[0].emp_id, &emp[0].basic_salary, &emp[0].gender) != EOF) {
        DA = 0.3 * emp[0].basic_salary;
        HRA = 0.2 * emp[0].basic_salary;
        gross = emp[0].basic_salary + DA + HRA;
        printf("%s\t%d\t%c\t%.2f\n", emp[0].emp_name, emp[0].emp_id, emp[0].gender, gross);
    }

    fclose(fp);
    return 0;
}
