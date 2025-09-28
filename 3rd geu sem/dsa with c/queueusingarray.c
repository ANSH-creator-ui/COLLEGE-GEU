#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f,r;
    int *arr;

};


int isEmpty(struct queue *q)
{
    if(q->r==q->f)
    {return 1;}
return 0;

}



int isFull(struct queue *q)
{
    if(q->r==q->size-1)
    {return 1;}
return 0;

}


void enqueue(struct queue *q,int val)
{
    if(isFull(q))
    {
        printf("queue is full\n");
        return;
    }
    else{
        q->r=q->r+1;
        q->arr[q->r]=val;
        return;
    }
}


int dequeue(struct queue *q)
{
     if(isEmpty(q))
    {
      printf("queue is empty");

    }
    q->f++;
   return  q->arr[q->f];
}
int main()
{
    struct queue q;
    q.size=4;
    q.f=q.r=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));
 
    
    //ENQUEUE  
    enqueue(&q,12);
    enqueue(&q,15);
    enqueue(&q,12);
    enqueue(&q,12);
    printf("dequeing element is%d\n",dequeue(&q));
    printf("dequeing element is%d\n",dequeue(&q));
    printf("dequeing element is%d\n",dequeue(&q));
    printf("dequeing element is%d\n",dequeue(&q));
    //    printf("dequeing element is%d\n",dequeue(&q));
    if(isEmpty(&q))
    {
      printf("queue is empty");

    }

    if(isFull(&q))
    {
      printf("queue is full");

    }
    
    
    
    
    
    
        return 0;

}