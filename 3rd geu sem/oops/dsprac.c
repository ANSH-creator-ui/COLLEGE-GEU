#include <stdio.h>
#include <stdlib.h>
//structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertEnd(Node *head, int data) {
    Node *newNode = createNode(data);
    if (head == NULL)
        return newNode;
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

void displayList(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf("->");
        temp = temp->next;
    }
    printf("->NULL\n");
}

Node* reverseList(Node *head) {
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* addLists(Node *list1, Node *list2) {
//reversing both the lists.
    list1 = reverseList(list1);
    list2 = reverseList(list2);

    Node *result = NULL;
    int carry = 0, sum;

    while (list1 != NULL || list2 != NULL || carry != 0) {
        int val1 = (list1 != NULL) ? list1->data : 0;
        int val2 = (list2 != NULL) ? list2->data : 0;

        sum = val1 + val2 + carry;
        carry = sum / 10;
        result = insertEnd(result, sum % 10);
	
        if (list1 != NULL) list1 = list1->next;
        if (list2 != NULL) list2 = list2->next;
    }
//again reverse the result
    result = reverseList(result);
    return result;
}

int main() {
    Node *list1 = NULL, *list2 = NULL, *sumList = NULL;
    int choice, data;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Insert in List 1\n");
        printf("2. Insert in List 2\n");
        printf("3. Display Lists\n");
        printf("4. Add Lists\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter digit to insert in List 1: ");
                scanf("%d", &data);
                list1 = insertEnd(list1, data);
                break;

            case 2:
                printf("Enter digit to insert in List 2: ");
                scanf("%d", &data);
                list2 = insertEnd(list2, data);
                break;

            case 3:
                printf("List1: ");
                displayList(list1);
                printf("List2: ");
                displayList(list2);
                break;

            case 4:
                sumList = addLists(list1, list2);
                printf("Resultant List after addition: ");
                displayList(sumList);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}



