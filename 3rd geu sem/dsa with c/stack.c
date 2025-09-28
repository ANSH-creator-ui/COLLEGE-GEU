/*#include<stdio.h>
#include<stdlib.h>
 

struct stack {
    int top;
    int cap;
    int *arr;

}st;

void initialize(struct stack *st,int size)
{
    st->top=-1;
    st->cap=size;
    st->arr=(int *)malloc(size*sizeof(struct stack));
    if(!st->arr)
    {
        printf("memory allocation failed\n");
        exit(1);

    }
}

void push(struct stack *st,int val)
{
    if(st->top==st->cap-1){
        printf("stack overflow\n");
        printf("cannot pust %d\n",val);

        return ;
    }
    else
    {
        st->top++;
        st->arr[st->top]=val;
    }
}

int pop(struct stack *st)
{
    if(st->top==-1)
    {
        printf("stack underflow\n");
        return -1;

    }
     int v= st->arr[st->top];
     st->top--;
     return v;
}

void display(struct stack *st)
{
    if(st->top==-1)
  { printf("stack is empty");
return ;}
else{
for(int i=st->top;i>=0;i--)
{
    printf("%d ",st->arr[i]);
}
printf("\n");
}
}


int main()
{
    int size;
    printf("enter size=");
    scanf("%d",&size);
    initialize(&st,size);
    int val,choice;
    while(1)
    {
    printf("****STACK MENU****\n");
    printf("1.PUSH \n 2.POP \n 3.DISPLAY \n 4.EXIT \n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("enter values to push=\n");
                  scanf("%d",&val);
                  push(&st,val);
                  break;
              
       case 2:  val=pop(&st);
                 if(val!=-1)
                 {
                    printf("%d values popped from stack",val);

                 }  
                 break;
                 
       case 3: display(&st);
                break;
       case 4: free(st.arr);
               return 0;
           //        break;
          default : printf("invalid choice");
                           break;
    }
    }
}*/



#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node *next;

};

struct stack{
    struct node *top;
}st;

void initialize(struct stack *st)
{  
    st->top=NULL;

}

void push(struct stack *st,int val)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode)
    {
          printf("memory allocation failed\n");
          return ;

    }
    newnode->data=val;
    newnode->next=st->top;
    st->top=newnode;
    printf("%d pusehed to stack \n",val);

}

int pop(struct stack *st)
{
    if(st->top==NULL)
    {
        printf("stack is underflow \n");
        return -1;
    }
    struct node *temp=st->top;
    int v=temp->data;
    st->top=st->top->next;
    free(temp);
    return v;

}


void display(struct stack *st)
{
    if(st->top==NULL){
        printf("empty stack\n");
        return ;

    }
    struct node *temp=st->top;
    while(temp!=NULL)
{   printf("%d ",temp->data);
    temp=temp->next;


}
printf("\n");




}




int main()
{
    int val,choice;
    initialize(&st);
    while(1)
    {
        printf("^^^STACK MENU^^^^\n");
        printf(  "1.PUSH  \n  2.POP \n 3. DSIPLAY \n4.EXIT\n");
        scanf("%d",&choice);
        switch (choice)

{

     case 1:
     printf("enter values to push=\n");
     scanf("%d",&val);
     push(&st,val);
     break;

     case 2: val=pop(&st);
             if(val!=-1) 
              printf("%d popped from stack",val);
            break;

         case 3: display(&st);
         break;
         
         case 4: while(st.top!=NULL)
         {
            pop(&st);
         }
         return 0;

         default: printf("invalid choice \n");
         break;
        }}}