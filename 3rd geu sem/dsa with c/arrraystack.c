#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int *arr;      // Pointer to array (dynamic allocation)
    int top;
    int capacity;
};

// Initialize stack
void initialize(struct Stack *st, int size) {
    st->top = -1;
    st->capacity = size;
    st->arr = (int *)malloc(size * sizeof(int));
    if (!st->arr) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

// Push operation
void push(struct Stack *st, int val) {
    if (st->top == st->capacity - 1) {
        printf("Stack Overflow! Cannot push %d\n", val);
        return;
    }
    st->arr[++st->top] = val;
    printf("%d pushed to stack\n", val);
}

// Pop operation
int pop(struct Stack *st) {
    if (st->top == -1) {
        printf("Stack Underflow! Stack is empty\n");
        return -1;
    }
    return st->arr[st->top--];
}

// Peek operation
int peek(struct Stack *st) {
    if (st->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return st->arr[st->top];
}

// Display operation
void display(struct Stack *st) {
    if (st->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (int i = st->top; i >= 0; i--) {
        printf("%d ", st->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack st;
    int size, val, choice;

    printf("Enter stack capacity: ");
    scanf("%d", &size);

    initialize(&st, size);

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(&st, val);
                break;
            case 2:
                val = pop(&st);
                if (val != -1)
                    printf("%d popped from stack\n", val);
                break;
            case 3:
                val = peek(&st);
                if (val != -1)
                    printf("Top element is %d\n", val);
                break;
            case 4:
                display(&st);
                break;
            case 5:
                free(st.arr); // Free allocated memory
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
