/*#include <stdio.h>

int reverseNumber(int num, int rev) {
    if (num == 0)
        return rev;
    return reverseNumber(num / 10, rev * 10 + num % 10);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Reversed number: %d\n", reverseNumber(num, 0));
    return 0;}



    #include <stdio.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int terms;
    printf("Enter number of terms: ");
    scanf("%d", &terms);
    for (int i = 0; i < terms; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}


#include <stdio.h>

int factorial(int num) {
    if (num <= 1)
        return 1;
    return num * factorial(num - 1);
}

void checkOddEven(int num) {
    if (num % 2 == 0)
        printf("%d is even.\n", num);
    else
        printf("%d is odd.\n", num);
}

int reverseNumber(int num) {
    int rev = 0;
    while (num != 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}

int main() {
    int choice, num;
    printf("Enter a number: ");
    scanf("%d", &num);
    do {
        printf("\n1. Factorial\n2. Odd/Even\n3. Reverse\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Factorial: %d\n", factorial(num));
                break;
            case 2:
                checkOddEven(num);
                break;
            case 3:
                printf("Reverse: %d\n", reverseNumber(num));
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}

#include <stdio.h>

int main() {
    int n, countAbove = 0, countBelow = 0;
    printf("Enter number of students: ");
    scanf("%d", &n);
    int ages[n];
    int sum = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter age of student %d: ", i + 1);
        scanf("%d", &ages[i]);
        sum += ages[i];
    }

    double average = (double)sum / n;
    for (int i = 0; i < n; i++) {
        if (ages[i] > average)
            countAbove++;
        else if (ages[i] < average)
            countBelow++;
    }

    printf("Average age: %.2f\n", average);
    if (countAbove > countBelow)
        printf("More students are above average age.\n");
    else
        printf("More students are below average age.\n");

    return 0;
}
#include <stdio.h>

void insertElement(int arr[], int *n, int pos, int elem) {
    for (int i = *n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = elem;
    (*n)++;
}

void deleteElement(int arr[], int *n, int pos) {
    for (int i = pos; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n + 1]; // +1 for possible insertion
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int choice, pos, elem;
    printf("1. Insert\n2. Delete\nEnter choice: ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter position and element to insert: ");
        scanf("%d %d", &pos, &elem);
        insertElement(arr, &n, pos - 1, elem);
    } else if (choice == 2) {
        printf("Enter position to delete: ");
        scanf("%d", &pos);
        deleteElement(arr, &n, pos - 1);
    }

    printf("Final array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}*/


#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}