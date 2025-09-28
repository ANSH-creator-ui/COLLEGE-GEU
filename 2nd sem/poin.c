/*#include <stdio.h>
void main()
/*{
     int *p,a,b;
     a=12;
     b=55;
     p=&a;
     printf("%d%d%d",a,b,p);
}*/
/*
{
     int a,b,*l,*c;
     a=12;
     b=34;
     c=&a;
     l=&b;
     printf("%d",*c + *l);
}*/


// addition of pointers

/*
{
     int a,b,tmp,*u,*i;
     a=90,b=34;
     u=&a,i=&b;
     tmp=*u, *u=*i,*i=tmp;
printf("a=%d\nb=%d",a,b);}*/
   
/*

#include<stdio.h>
int main()
{
     int i,n,a[100];
     printf("enter limit =");
     scanf("%d",&n);
     printf("enter values=");
     for(i=0;i<n;i++)
     {
          scanf("%d",&a[i]);
     }                             //max(a,n);     // using function
     /*
     void max(int *x, int y)   // definition of function
     { int i,max;
      max=*x;
     for(i=0;i<n;i++)
     {
          if(max>*(x+i))
     {
          max=*(x+i);
     }
}
     return max;} 
     }*/

     /*
     int *p=a;
     int max=*p;
     for(i=0;i<n;i++)
     {
          if(max>*(p+i))
     {
          max=*(p+i);
     }
     }
     printf("%d",max);
     return 0;
}*/
/*

#include<stdio.h>
void reverse( int * ,int);
void main()
{
     int n,a[100]={0},i;
     printf("enter limit =");
     scanf("%d",&n);
     printf("enter values=");
     for(i=0;i<n;i++) 
           {
             scanf("%d",&a[i]);
            }
     reverse(a,n);
     for(i=0;i<n;i++)
     {
          printf("%d",a[i]);
     }
     }  
     
     void reverse(int *x , int y)
     {
          int i,j,t;
          for(i=0,j=y-1;i<y/2;i++,j--)
          {
                t=*(x+i);
               *(x+i)=*(x+j);
               *(x+j)=t;          }
     }
*/

#include<stdio.h>
void sort(int *,int);
void main()
{
        int i,n,*p;
        printf("enter limit=");
        scanf("%d",&n);
        int a[n];
        printf("enter valiues=");
               for(i=0;i<n;i++)
        {
          scanf("%d",a[i]);
        }
        sort(a,n);
        for( i=0;i<n;i++)
        {
          printf("%d",a[i]);
        }
     
}
void sort (int *o,int m)
{
     int i,j,tmp;
     for(i=0;i<m;i++)
     {
          for(j=i+1;j<m;j++)
          {
               if(*(o+i)<*(o+j))
               {
                   tmp=*(o+i);
                   *(o+i)=*(o+j);
                   *(o+j)=tmp;
               }
          }
     }
}