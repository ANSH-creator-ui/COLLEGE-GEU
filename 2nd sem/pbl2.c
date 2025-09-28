#include <stdio.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

// Function to register a new user
int register_user() {
    char username[MAX_USERNAME_LENGTH], password[MAX_PASSWORD_LENGTH];
    FILE *user_file = fopen("users.txt", "a+");
    if (!user_file) {
        printf("Error opening users file.\n");
        return 0;
    }

    printf("Enter new username: ");
    scanf("%s", username);
    printf("Enter new password: ");
    scanf("%s", password);

    // Check if username already exists
    char existing_username[MAX_USERNAME_LENGTH], existing_password[MAX_PASSWORD_LENGTH];
    rewind(user_file);
    while (fscanf(user_file, "%s %s", existing_username, existing_password) != EOF) {
        if (strcmp(username, existing_username) == 0) {
            printf("Username already exists. Please choose a different username.\n");
            fclose(user_file);
            return 0;
        }
    }

    fprintf(user_file, "%s %s\n", username, password);
    fclose(user_file);
    printf("Registration successful!\n");
    return 1;
}

// Function to authenticate a user
int login_user(char *logged_in_username) {
    char username[MAX_USERNAME_LENGTH], password[MAX_PASSWORD_LENGTH];
    FILE *user_file = fopen("users.txt", "r");
    if (!user_file) {
        printf("Error opening users file.\n");
        return 0;
    }

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    char stored_user[MAX_USERNAME_LENGTH], stored_pass[MAX_PASSWORD_LENGTH];
    while (fscanf(user_file, "%s %s", stored_user, stored_pass) != EOF) {
        if (strcmp(username, stored_user) == 0 && strcmp(password, stored_pass) == 0) {
            fclose(user_file);
            strcpy(logged_in_username, username);
            printf("Login successful!\n");
            return 1;
        }
    }

    fclose(user_file);
    printf("Authentication failed.\n");
    return 0;
}

// Function to handle user authentication
int authenticate(char *logged_in_username) {
    int choice;
    printf("1. Register\n2. Login\nChoose an option: ");
    scanf("%d", &choice);

    if (choice == 1) {
        return register_user();
    } else if (choice == 2) {
        return login_user(logged_in_username);
    } else {
        printf("Invalid choice.\n");
        return 0;
    }
}

#include <stdio.h>
#include <math.h>

void basic_operations(FILE *file, const char *username) {
    double num1, num2, result;
    char op;

    printf("Enter expression (e.g., 2 + 3): ");
    scanf("%lf %c %lf", &num1, &op, &num2);

    switch (op) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/':
            if (num2 == 0) {
                printf("Division by zero error.\n");
                return;
            }
            result = num1 / num2;
            break;
        default:
            printf("Invalid operator.\n");
            return;
    }

    printf("Result: %.2f\n", result);
    fprintf(file, "User: %s | Operation: %.2f %c %.2f = %.2f\n", username, num1, op, num2, result);
}

void trigonometric_operations(FILE *file, const char *username) {
    double angle, result;
    int choice;

    printf("Choose operation:\n1. sin\n2. cos\n3. tan\nChoice: ");
    scanf("%d", &choice);
    printf("Enter angle in degrees: ");
    scanf("%lf", &angle);

    angle = angle * (M_PI / 180.0); // Convert to radians

    switch (choice) {
        case 1: result = sin(angle); break;
        case 2: result = cos(angle); break;
        case 3: result = tan(angle); break;
        default:
            printf("Invalid choice.\n");
            return;
    }

    printf("Result: %.2f\n", result);
    fprintf(file, "User: %s | Trigonometric Operation: %.2f = %.2f\n", username, angle, result);
}

void logarithmic_operation(FILE *file, const char *username) {
    double num, result;

    printf("Enter number: ");
    scanf("%lf", &num);

    if (num <= 0) {
        printf("Logarithm undefined for non-positive numbers.\n");
        return;
    }

    result = log10(num);
    printf("Result: %.2f\n", result);
    fprintf(file, "User: %s | Logarithm: log10(%.2f) = %.2f\n", username, num, result);
}

void matrix_operations(FILE *file, const char *username) {
    int r, c, i, j;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    double matrix1[r][c], matrix2[r][c], result[r][c];

    printf("Enter elements of matrix 1:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%lf", &matrix1[i][j]);

    printf("Enter elements of matrix 2:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%lf", &matrix2[i][j]);

    // Matrix addition
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            result[i][j] = matrix1[i][j] + matrix2[i][j];

    printf("Matrix Addition Result:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%.2f ", result[i][j]);
        printf("\n");
    }

    // Matrix multiplication
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            result[i][j] = matrix1[i][j] * matrix2[i][j];

    printf("Matrix Multiplication Result:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%.2f ", result[i][j]);
        printf("\n");
    }

    fprintf(file, "User: %s | Performed matrix operations\n", username);
}

#include <stdio.h>
#include <string.h>

void display_user_report(const char *username) {
    char line[256];
    FILE *file = fopen("calculator_results.txt", "r");

    if (!file) {
        printf("Error opening results file.\n");
        return;
    }

    printf("\n--- Report for %s ---\n", username);
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, username)) {
            printf("%s", line);
            found = 1;
        }
    }

    if (!found) {
        printf("No records found for user: %s\n", username);
    }

    fclose(file);
}

#include <stdio.h>
#include <string.h>
#include "authn.c"
#include "calculator.c"
#include "report.c"

int main() {
    char username[50];
    FILE *file = fopen("calculator_results.txt", "a");

    if (!file) {
        printf("Error opening file!\n");
        return 1;
    }

    if (!authenticate(username)) {
        fclose(file);
        return 1;  // Exit if login fails
    }

    int choice;
    do {
        printf("\n=== Calculator Menu ===\n");
        printf("1. Basic (+, -, *, /)\n2. Trigonometry (sin, cos, tan)\n3. Logarithm (base 10)\n4. Matrix (Add, Multiply)\n5. User History\n6. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: basic_operations(file, username); break;
            case 2: trigonometric_operations(file, username); break;
            case 3: logarithmic_operation(file, username); break;
            case 4: matrix_operations(file, username); break;
            case 5: display_user_report(username); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid option!\n");
        }
    } while (choice != 6);

    fclose(file);
    return 0;
}