#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

 struct node *createnode(int val)
 {
    struct  node *ptr=(struct node*) malloc(sizeof(struct node));
        ptr->data=val;
        ptr->next=NULL;
        return ptr;
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

 struct node *deleteatfirst(struct node *head)
{
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}


struct  node *deleteatindex(struct  node *head, int index)
{
    struct node *p=head;
    struct  node *q=head->next;
    int i=0;
    while(i!=index)
     {
        p=p->next;
        q=q->next;
        i++;
     }
     p->next=q->next;
     free(q);
     return head;
}


struct node *deleteatend(struct node*head)
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
int main()
{
    struct node *head=NULL;
    struct node *tail=NULL;
    int n,val;
    printf("enter no . of nodes=");
    scanf("%d",&n);
    printf("enter values=");
    for(int i=0;i<n;i++)
    {   scanf("%d",&val);
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

   // head=deleteatfirst(head);
    printf("linklist after deletion of first node=\n");
    printlist(head);


     int index;
     printf("enter index u wamnt to delete=") ;
     scanf("%d",&index);
     // head=deleteatindex(head,index) ;
        printf("linklist after deletion of given index  node=\n");
    printlist(head);



     head=deleteatend(head) ;
        printf("linklist after deletion of end  node=\n");
    printlist(head);

}
