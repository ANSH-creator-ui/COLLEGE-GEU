#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

 struct node *createnode (int val)
{
   struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=val;
    new->next=NULL;
    return new;
}

void insertatfirst(struct  node **head,int val)
{
   struct  node *new=createnode(val);
    if(!*head) 
    {
        *head=new;
        return ;
    }
    new->next=*head;
    *head=new;
}

void insertatlast(struct node **head,int val)
{
  struct  node *ptr=createnode(val);
   struct node *curr=*head;
   if(!*head)
   {
    *head=ptr;
    return;
   }
    while(curr->next)
    {
        curr=curr->next;
    }
    curr->next=ptr;
}



void insertatindex(struct node **head, int index, int data)
{
    struct node *ptr = createnode(data);
    struct node *p = *head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    //ptr->data = data;
    p->next = ptr;
   
}

void insertatk(struct node **head,int k,int val)
{
    
    if(!*head) {
        insertatfirst(head,val); 
        return ;
    }
  struct node *p=createnode(val);
      struct node *u=*head;
     int i=0;
     while(i!=k-1)
    {
        u=u->next;
      i++;
    }
    p->next=u->next;
    u->next=p;

}

void deleteatfirst(struct node **head)
{
    struct node *ptr=*head;
    
    *head=(*head)->next;
    free(ptr);
    return;

}

void deleteatend(struct node **head)
{
    struct node *ptr=*head;
    struct node *ptr2=(*head)->next;
         while(ptr2->next)
         {
            ptr=ptr->next;
            ptr2=ptr->next;
         }
        ptr->next=NULL;
        free(ptr2);
}

struct node * rotatelist(struct node *head,int k)
{
    if(!head || !head->next ||k==0)return head;
    struct node *tail= head;
    int l=1;
    while(tail->next)
    {    l++;
        tail=tail->next;

    }

    tail->next=head;
    k=k%l;
    int stepstonewtail=l-k;
 struct node *newtail=tail;
    while(stepstonewtail--)
{
    newtail=newtail->next;
}
struct node *newhead=newtail->next;
newtail->next=NULL;

return newhead;
}

void printmiddle(struct node *head)
{
    struct node *slow=head;
    struct node *fast=head;
    while(slow && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    printf(" %d\n",slow->data );
}
void deleteNafterM(struct node *head,int m,int n )
{
    struct node *curr=head;
    while(curr)
    {

        for(int i=1;i<m && curr!=NULL;i++)
        {
            curr=curr->next;
        }
        if(!curr)break;
        struct node *tmp=curr->next;
    for(int j=0;j<n && tmp!=NULL;j++)
    {
        struct node *del=tmp;
        tmp=tmp->next;
        free(del);
    }
    curr->next=tmp;
    curr=tmp;
    
}
}

void printlist(struct node *head)
{
     struct node *p=head;
     if(!head)
     {printf("list is empty"); return;
     }
     while(p)
    {
        printf("->%d",p->data);
        p=p->next;
    }
    printf("\n");

}


struct node* morn(struct node *list1, struct node *list2)
{

   if(!list1)return list2;
   if(!list2)return list1;
   struct node *curr1=list1;
    struct node *curr2=list2;
     struct node *next1;
      struct node *next2;
while(curr1 && curr2)
{
    next1=curr1->next;
    next2=curr2->next;

    curr1->next=curr2;

  //full   if(!next1)break;
    curr2->next=next1;
     
    curr1=next1;
    curr2=next2;

}
return list1;
}



void deletemultipleofk(struct node **head, int k)
{
    if(!*head || k<=0) return ;
    if(k==1)
    {
        while(*head)
        {
            struct node *tmp=*head;
          *head=(*head)->next;
            free(tmp);
          
        }
        return;
    }
    struct node *curr=*head;
    struct node *prev=NULL;
    int count=1;
    while(curr)
    {
        if(count%k==0)
        {
            struct node *tmp=curr;
            if(prev)
            {
            prev->next=curr->next;
            }else{

             *head=curr->next;
            }
            curr=curr->next;
            free(tmp);
        }else{
        prev=curr;
        curr=curr->next;
        }

        count++;

    }
  }


int main()
{   struct node *head0=createnode(10);
    head0->next=createnode(20);
    head0->next->next=createnode(30);
     head0->next->next->next=createnode(40);
 head0->next->next->next->next=createnode(50);
 head0->next->next->next->next->next=createnode(60);

 printlist(head0);

   struct  node *head=createnode(5);
  head->next=createnode(10);
 head->next->next=createnode(15);
 head->next->next->next=createnode(20);
 head->next->next->next->next=createnode(25);

printlist(head);
struct node *merged=morn(head,head0);
//printlist(merged);
deletemultipleofk(&head0,3);
printlist(head0);


             // printlist(head);
             // printmiddle(head);
// insertatindex(&head,3,38);
//head=rotatelist(head,2);
//printlist(head);
//deleteNafterM(head,1,1);
//printlist(head0);
              return 0;

}