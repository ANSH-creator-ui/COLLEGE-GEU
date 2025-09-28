#include <stdio.h>
#include <stdlib.h>

// TO CREATE NODE"S DATA AND NEXT NODE ADDRESSS SECTION
struct node
{
    int data;
    struct node *next;
};

// TO CREATE A NODE

struct node *createnode(int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = NULL;
    return ptr;
}

// TO PRINT LINKLIST
void printlist(struct node *head)
{
    while (head != NULL)
    {
        printf("->%d", head->data);
        head = head->next;
    }
    printf("\n");
}

// TO INSERT NODE IN BEGINNEING
struct node *insertatbegin(struct node *head, int dat)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    // isme nhi krte yeh
    //   struct node *p=head;

    ptr->next = head;
    ptr->data = dat;
    return ptr;
}

// TO INSERT A NODE AT ANY INDEX

struct node *insertatindex(struct node *head, int i, int val2)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int k = 0;
    while (k != i - 1)
    {
        p = p->next;
        k++;
    }
    ptr->data = val2;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// TO INSERT AN END

struct node *insertatend(struct node *head, int end)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->data = end;
    ptr->next = NULL;
    return head;
}

// INSERT AFTER TARGET
void insertaftertarget(struct node *head, int target, int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    while (p != NULL)
    {
        if (p->data == target)
        {
            struct node *newnode = createnode(val);
            //    newnode->data=val;
            newnode->next = p->next;
            p->next = newnode;
            return;
        }
        if (p->next == NULL)
            break;
        p = p->next;
    }

    struct node *newnode = createnode(val);
    p->next = newnode;
}

// MAIN FN
int main()
{
    struct node *head = NULL;
    struct node *tail = NULL;

    int n, val;
    printf("enter the no. of nodes=");
    scanf("%d", &n);
    printf("enter values=");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        struct node *newnode = createnode(val);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    int val1;
    printf("enter value to insert at begin=");
    scanf("%d", &val1);
    head = insertatbegin(head, val1);
    //   printf("linklist\n");

    // printf("linklist\n");
    int val2, index;
    printf("enter index and value of a node=");
    scanf("%d%d", &index, &val2);
    head = insertatindex(head, index, val2);

    // printf("linklist\n");
    int valend;
    printf("enter val at end=");
    scanf("%d", &valend);
    head = insertatend(head, valend);

    printf("linklist\n");
    int val3, target;
    printf("enter target and val=");
    scanf("%d%d", &target, &val3);
    insertaftertarget(head, target, val3);

    printlist(head);
    return 0;
}
