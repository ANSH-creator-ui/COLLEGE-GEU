#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *createnode(int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->data = val;
    ptr->next = NULL;
    return ptr;
}

struct node *insertatfirst(struct node *head, int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->next = head;
    ptr->data = val;

    return ptr;
}

struct node *insertatindex(struct node *head, int index, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    ptr->data = data;
    p->next = ptr;
    return head;
}

struct node *deleteatfirrst(struct node *head)
{
    struct node *p = head;
    head = head->next;
    free(p);
    return head;
}

struct node *deleteatindex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;

        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}

void printlist(struct node *head)
{
    while (head != NULL)
    {
        printf("->%d", head->data);
        head = head->next;
    }
    printf("\n");
}

struct node *deleteatlast(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct node *insertatend(struct node *head, int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->data = val;
    ptr->next = NULL;
    return head;
}

int main()
{
    struct node *head = NULL;
    struct node *tail = NULL;
    int n, val;
    printf("enter no. of nodes=");  
    scanf("%d", &n);
    printf("enter values of node->\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);

        struct node *newnode = createnode(val);
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }

    printf("linklist->\n");
    printlist(head);
    /*
        int val1, index;
        printf("enter value at first=");
        scanf("%d", &val1);
        head = insertatfirst(head, val1);
        printlist(head);

        int val2;
        printf("enter index and value you want to insert =");
        scanf("%d%d", &index, &val2);
        head = insertatindex(head, index, val2);
        printf("linklist after insertion at index =%d,index");
        printlist(head);

        int val3;
        printf("to insert at end value=\n");

        scanf("%d", &val3);
        head = insertatend(head, val3);
        printf("linklist after inserting node at last=\n");
        printlist(head);


        printf("linklist after deletion of node at first index->\n");
        head  = deleteatfirrst(head);
    printlist(head);

*/
    int k;
    printf("enter index u want to delete");
    scanf("%d",&k);
     head=deleteatindex(head,k);
     printf("linklist after deletion at index %d->\n");
     printlist(head);

    head = deleteatlast(head);
    printf("linklist after deletion at last=");
    printlist(head);

    return 0;
}
