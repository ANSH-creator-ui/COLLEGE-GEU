#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
     struct node *next;
};



struct node *createnode(int val)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->next=NULL;
    return ptr;

}


struct node *deletenode(struct node *head)
{
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}


struct node *deleteatindex(struct node *head,int index)
{
    struct node *p=head;
    struct node *q=head->next;
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

struct node* deleteatlast(struct node *head)
{
    struct node *p=head;
    struct node *q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}


struct  node *deleteatvalue(struct node *head , int value)
{
    struct node *p=head;
    struct node *q=head->next;
    while(q->data!=value && q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    if(q->data==value)
    {
        p->next=q->next;
    free(q);
    }
    return head;
}



void printlist(struct node *head)
{
      while(head!=NULL)
      {
        printf("->%d",head->data);
        head=head->next;
      }
      printf("\n");

}

int main()
{
    struct node *head=NULL;
    struct node  *  tail=NULL;
    int n,val;
    printf("enter no. of nodes=");
    scanf("%d",&n);
    printf("enter values=");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&val);
        struct node *newnode=createnode(val);
        if(head==NULL)
        {
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }


    }
    printlist(head);
   head= deletenode(head);
   printf("linklist after 1st node deletion->\n");
    printlist(head);
    int index;
    printf("enter the index u want to delete=");
    scanf("%d",&index);
    head=deleteatindex(head,index);
    printf("linklist after deletion of index %d->\n",index);
    printlist(head);
   
    head=deleteatlast(head);
    printf("linklist after deletion-> \n");
    printlist(head);
  
    int value;
    printf("enter the data values of node you want to delete=");
    scanf("%d",&value);
    head=deleteatvalue(head,value);
    printf("linklist after deletion of value %d->\n",value);
    printlist(head);


    return 0;

}