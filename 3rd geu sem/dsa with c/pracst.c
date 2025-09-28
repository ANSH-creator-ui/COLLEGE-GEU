#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct stack{
    struct node *top;

};
void initialize(struct stack *st)
{
    st->top=NULL;
}
int pop(struct stack *st)
{
    if(st->top==NULL){
        printf("stack is empty\n"); 
    return -1;}
    struct node *tmp=st->top;
    int val=tmp->data;
    st->top=st->top->next;
    free(tmp);
    return val;
}

void printstack(struct stack *st)
{
     if(st->top==NULL){
        printf("stack is empty\n"); 
    return ;}
    struct node *tmp=st->top;
    while(tmp)
    {
        printf("->%d",tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
}
void push(struct stack *st,int val)
{
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=val;
    new->next=st->top;
    st->top=new;
    printf("%d values push to stack\n",val);
}


int main()
{
    struct stack st;
    initialize(&st);
    push(&st,10);
    push(&st,20);
    push(&st,40);
    push(&st,40);
    push(&st,40);
    push(&st,40);
    printstack(&st);
    printf("%d \n",pop(&st));
        printstack(&st);
}