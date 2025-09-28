#include<stdio.h>
#include<stdlib.h>
  struct node{
    int data;
    struct node *next;
  };


struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

















struct node* deleteMultiplesOfK(struct node* head, int k) {
    if (head == NULL || k <= 0) return head;

    struct node* curr = head;
    struct node* prev = NULL;
    int pos = 1;

    while (curr != NULL) {
        if (pos % k == 0) {
            // Delete this node
            struct node* temp = curr;
            if (prev == NULL) {
                // deleting head
                head = curr->next;
                curr = head;
            } else {
                prev->next = curr->next;
                curr = curr->next;
            }
            free(temp);
        } else {
            prev = curr;
            curr = curr->next;
        }
        pos++;
    }

    return head;
}


int main() {
    struct node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(7);
    head->next->next->next->next->next->next->next = createNode(8);

    printf("Original list:\n");
    printList(head);

    int k = 2;
    head = deleteMultiplesOfK(head, k);

    printf("\nList after deleting multiples of %d:\n", k);
    printList(head);

    return 0;
}

