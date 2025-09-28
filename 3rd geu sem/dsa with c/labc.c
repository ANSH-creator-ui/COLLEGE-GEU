  #include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *createnode(int val) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void insertatbegin(struct node **head, int val) {
    struct node *temp = createnode(val);
    temp->next = *head;
    *head = temp;
}

void printlist(struct node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


int main() {
    struct node *head = NULL;
    insertatbegin(&head, 1001);  // Passing address of head and a value

    

printlist(head);


}