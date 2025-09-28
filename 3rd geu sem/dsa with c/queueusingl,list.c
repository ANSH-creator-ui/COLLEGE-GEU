/*#include<stdio.h>
#include<stdlib.h>

  struct node *f=NULL;
    struct node *r=NULL;  
     

struct node{
    int data;
    struct node *next;

};














int dequeue()
{
    int val=-1;
    struct node *ptr=f;
    if(f==NULL)
    {
        printf("queue is empty\n");
        return -1;;
    }
    f=f->next;
    val=ptr->data;
    free(ptr);
    return val; 
}








void enqueue(int val)
{
      struct node *n=(struct node *)malloc(sizeof(struct node));
      if(n==NULL)
      {
        printf("queue is full\n");

      }
      else
      {
        n->data=val;
    n->next=NULL;
       if(f==NULL)
    {
        f=r=n;
    }
    else{ 
         r->next=n;
               r=n;
    }
}
}
void printlist(struct node *ptr)
{
    printf("elements of linklist=\n");
    while(ptr!=NULL)
{
    printf("->%d",ptr->data);
    ptr=ptr->next;
     
}}
int main()
{ 
  //  printlist(f);
    enqueue(12);
        enqueue(11);
            enqueue(32);
                enqueue(42);
printlist(f);
//dequeue();
printf("dequeue element=%d",dequeue());

printlist(f);

}      */


#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Queue structure
struct Queue {
    struct Node *front, *rear;
};

// Function to create a new node
struct Node* createNode(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Initialize Queue
void initQueue(struct Queue *q) {
    q->front = q->rear = NULL;
}

// Enqueue operation
void enqueue(struct Queue *q, int val) {
    struct Node *newNode = createNode(val);

    if (q->rear == NULL) { // First element
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d enqueued to queue.\n", val);
}

// Dequeue operation
void dequeue(struct Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }

    struct Node *temp = q->front;
    printf("%d dequeued from queue.\n", temp->data);
    q->front = q->front->next;

    if (q->front == NULL) { // If queue becomes empty
        q->rear = NULL;
    }
    free(temp);
}

// Peek operation
void peek(struct Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element is: %d\n", q->front->data);
}

// Display operation
void display(struct Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main menu-driven program
int main() {
    struct Queue q;
    initQueue(&q);

    int choice, val;

    do {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                peek(&q);
                break;
            case 4:
                display(&q);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
