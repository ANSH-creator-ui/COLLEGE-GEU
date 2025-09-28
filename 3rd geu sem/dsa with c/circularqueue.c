#include<stdio.h>
#include<stdlib.h>

struct circular_queue{
    int size;
    int f,r;
    int *arr;

};


int isEmpty(struct  circular_queue *q)
{
    if(q->r==q->f)
    {return 1;}
return 0;

}



int isFull(struct  circular_queue *q)
{
    if((q->r+1)%q->size==q->front)
    {return 1;}
return 0;

}


void enqueue(struct  circular_queue *q,int val)
{
    if(isFull(q))
    {
        printf("queue is full\n");
        return;
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
        printf("enquing element is %d\n", q->arr[q->r]);
        return;
    }
}


int dequeue(struct  circular_queue *q)
{
     if(isEmpty(q))
    {
      printf("queue is empty");

    }
    q->f=(q->f+1)%q->size;
   int val=  q->arr[q->f];
   printf("dequing element is %d\n",val);
   return val;
}
int main()
{
    struct circular_queue q;
    q.size=4;
    q.f=q.r=0;
    q.arr=(int *)malloc(q.size*sizeof(int));
 
    
    //ENQUEUE  
    enqueue(&q,12);
    enqueue(&q,15);
    
enqueue(&q,15);
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