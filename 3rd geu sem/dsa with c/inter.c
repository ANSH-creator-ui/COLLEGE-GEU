#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createnode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Function to find length of a linked list
int getLength(struct node* head) {
    int len = 0;
    while(head) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find intersection node
struct node* getIntersectionNode(struct node* headA, struct node* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    struct node* a = headA;
    struct node* b = headB;

    // Move the pointer of longer list ahead by difference in lengths
    if(lenA > lenB) {
        int diff = lenA - lenB;
        while(diff--) a = a->next;
    } else {
        int diff = lenB - lenA;
        while(diff--) b = b->next;
    }

    // Traverse both together
    while(a && b) {
        if(a == b) return a;  // intersection found
        a = a->next;
        b = b->next;
    }

    return NULL;  // no intersection
}

int main() {
    // Create two linked lists
    struct node* headB= createnode(10);
    headB->next = createnode(20);
    headB->next->next = createnode(30);
    headB->next->next->next = createnode(40);
    headB->next->next->next->next = createnode(50);

    struct node* headA = createnode(15);
    headA->next = createnode(25);

    // Make intersection (B -> 25 -> 40)
    headA->next->next = headB->next->next->next;

    struct node* inter = getIntersectionNode(headB, headA);

    if(inter)
        printf("Intersection Node: %d\n", inter->data);
    else
        printf("No Intersection\n");

    return 0;
}
