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


void insertatend(struct node **head,int val)
{
     struct node *p=createnode(val);

     if(!(*head)) 
     {
        *head=p;
 return ;     }

struct node *q=*head;

while(q->next!=NULL)
{
    q=q->next;
}
q->next=p;

}


void insertatbegin(struct node **head,int val)
{
    struct node *tmp=createnode(val);
    if(*head==NULL)
    {
       * head=tmp;
       return ;

    }
    tmp->next=*head;
    *head=tmp;
}

void insertBeforeK(struct node **head, int val, int k) {
   
    // case 1: empty list
    if (*head == NULL || (*head)->data==k) {
      insertatbegin(head,val);
        return;
    }


    // otherwise search k
    struct node *p = *head;
    while (p->next != NULL && p->next->data != k) {
        p = p->next;
    }

    if (p->next == NULL) {
        // k not found → insert at end
       // curr->next = new;

       insertatbegin(head,val);
    } else {
         struct node *new = createnode(val);
        // k found → inser t before k
        new->next = p->next;
        p->next = new;
    }
}


void insertAfterK(struct node **head, int val, int k) {
   
    // case 1: empty list
    if (*head == NULL || (*head)->data==k) {
      insertatend(head,val);
        return;
    }


    // otherwise search k
    struct node *p = *head;
    while (p->next != NULL && p->next->data != k) {
        p = p->next;
    }

    if (p->next == NULL) {
        // k not found → insert at end
       // curr->next = new;

       insertatend(head,val);
    } else { struct node *new=createnode(val);
              new->next=p->next;
              p->next=new;
    }}



    
void printlist(struct node *head)
{   if(!(head))printf("empty linklist");
    while(head!=NULL)

    {
        printf("%d-> ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main(){
 int k;
    struct node *head=NULL;
int val,choice;
do
{
    printf("^^^LINKLIST MENU^^^^\n");
    printf("1.insert at begin\n 2. insert at end.\n 3. printlist\n");
    printf("4.exit\n 5. insertbeforek\n 6. insert after k\n");
    scanf("%d",&choice);
     switch (choice)
     {
        case 1: printf("enter value to insert at begin=\n");
                scanf("%d",&val);
                insertatbegin(&head,val);
                break;
       case 2:printf("value to insert at end=\n");
             scanf("%d",&val);
                insertatend(&head,val);
                break;
     case 3: printlist(head);
            break;
     case 4: printf("exiting..\n");
             exit(0);
       case 5:
              printf("entter value of k and val1 u want to insert=");
              scanf("%d%d",&k,&val);
              insertBeforeK(&head,val,k);
              break;      
        case 6:
                 printf("enter k and value to insert after k: ");
    scanf("%d%d",&k,&val);
    insertAfterK(&head,val,k);
    break;      
     default: printf("invalid choice\n");
  break;     
     }
}while(choice!=4);
}