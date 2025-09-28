#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node *next;
};

// Stack structure (stores pointer to top node)
struct Stack {
    struct Node *top;
};

// Initialize stack
void initialize(struct Stack *st) {
    st->top = NULL;
}

// Push operation (insert at beginning)
void push(struct Stack *st, int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = val;
    newNode->next = st->top;  // Link new node to previous top
    st->top = newNode;        // New node becomes top
    printf("%d pushed to stack\n", val);
}

// Pop operation (remove from beginning)
int pop(struct Stack *st) {
    if (st->top == NULL) {
        printf("Stack Underflow! Stack is empty\n");
        return -1;
    }
    struct Node *temp = st->top;
    int val = temp->data;
    st->top = st->top->next; // Move top pointer to next node
    free(temp);              // Free the popped node
    return val;
}

// Peek operation (view top element)
int peek(struct Stack *st) {
    if (st->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return st->top->data;
}

// Display stack (top to bottom)
void display(struct Stack *st) {
    if (st->top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node *temp = st->top;
    printf("Stack (top to bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Stack st;
    int choice, val;

    initialize(&st);

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
                // Free all nodes before exit
                while (st.top != NULL)
                    pop(&st);
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
