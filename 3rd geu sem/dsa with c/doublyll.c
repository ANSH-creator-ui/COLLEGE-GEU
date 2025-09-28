#include <stdio.h>
#include <stdlib.h>

// Structure for Doubly Linked List node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(struct Node** head, int val) {
    struct Node* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// Insert at end
void insertAtEnd(struct Node** head, int val) {
    struct Node* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete from beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Delete from end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL; // only one node
    }
    free(temp);
}

// Traverse forward
void printlist(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Traverse backward
void traverseBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Reverse the doubly linked list
void reverseList(struct Node** head) {
    struct Node* curr = *head;
    struct Node* temp = NULL;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev; // move to next (which is prev before swap)
    }

    if (temp != NULL) {
        *head = temp->prev;
    }
}

// Driver Code (Menu-driven)
int main() {
    struct Node* head = createNode(90);
    head->next=createNode(45);
   head->next->next=createNode(35);
   head->next->next->next=createNode(453);
  printlist(head);
  
/*    int choice, val;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Traverse Forward\n");
        printf("6. Traverse Backward\n");
        printf("7. Reverse List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertAtBeginning(&head, val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertAtEnd(&head, val);
                break;
            case 3:
                deleteAtBeginning(&head);
                break;
            case 4:
                deleteAtEnd(&head);
                break;
            case 5:
                printf("List (Forward): ");
                traverseForward(head);
                break;
            case 6:
                printf("List (Backward): ");
                traverseBackward(head);
                break;
            case 7:
                reverseList(&head);
                printf("List reversed successfully!\n");
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }*/




    return 0;
}
