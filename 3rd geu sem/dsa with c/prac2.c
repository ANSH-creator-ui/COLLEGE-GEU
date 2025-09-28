#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;

};


struct node *createnode(int val)
{
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=val;
    new->next=NULL;
    return new;

}

void deletek(struct node **head,int k)

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
        return ;
       }
       struct node *curr=*head;
       struct node *prev=NULL;
       int count=1;
       while(curr)
       {
        if(count%k==0)
        {
            struct node *p=curr;
            prev->next=curr->next;
            curr=curr->next;
            free(p);
        }
        else{
            prev=curr;
            curr=curr->next;
        }
        count++;


       }
    }

    struct node *swapp(struct node *head)
    {
        if(!head || !head->next) return head;
        struct node *first=head;
        struct node *second=head->next;
        struct node *prev=NULL;
        while(first && second)
        {
            struct node *third=second->next;
            second->next=first;
            first->next=third;
            if(prev)
            {
                prev->next=second;
            }
            else{
                head=second;
            }
            prev=first;
            first=third;
            if(third)
            {
                second=third->next;

            }
            else{
                second=NULL;

            }

        }
        return head;

    }

    struct node* reverseFromHalf(struct node* head);
    

void printlist(struct node *head)
{
    struct node *curr=head;
    while(curr)
    {
        printf("->%d",curr->data);
        curr=curr->next;
    }
    printf("\n");
}


void sorting(struct node **head)
{
    if(!*head || !(*head)->next )return;
    int swapped;
      do{ 
    struct node *ptr=*head;
     swapped=0;
    while(ptr->next)
    {
        if(ptr->data<ptr->next->data)
        {
            int tmp=ptr->next->data;
            ptr->next->data=ptr->data;
            ptr->data=tmp;
            swapped=1;

        }
        ptr=ptr->next;
    }
   }while(swapped);

}

    int main()
    {
        struct node *head=createnode(10);
        head->next=createnode(20);

         head->next->next=createnode(30);
         head->next->next->next=createnode(40);
         head->next->next->next->next=createnode(50);
        
   //shead->next->next->next->next->next=createnode(60);
    printlist(head);

    //deletek(&head,1);
    //struct node *hi=swapp(head);
   // printlist(hi);

   sorting(&head);
   printlist(head);
   
    return 0;
    }

        

/*
struct node *hi;
    hi=reverseFromHalf(head);
        printlist(hi);









        struct node* reverseFromHalf(struct node* head) {
    if (!head || !head->next) return head;

    struct node *slow = head, *fast = head;

    // Step 1: Find middle
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }printf("%d \n",slow->data);

    // Step 2: Reverse the second half starting from slow->next
    struct node *prev = NULL, *curr = slow->next, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Step 3: Connect first half with reversed second half
    slow->next = prev;

    return head;
}*/