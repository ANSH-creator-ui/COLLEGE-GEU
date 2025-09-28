/*#include<stdio.h>
int main()
{
    int a[100],i,b[100],j,n;
    printf("enter limit for a abd b=");
    scanf("%d%d",&n,&j);
    printf("enter values");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter values for b=");
    for(i=0;i<j;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0;i<j;i++)
    {
        a[i+n]=b[i];
    }
    for(i=0;i<n+j;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}


#include<stdio.h>
int main()
{
    int a[100],n,i,num,j;
    printf("enter limit of a=");
    scanf("%d",&n);

    printf("ebter values=");
        for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter index no. and number=");
    scanf("%d%d",&j,&num);
    for(i=n-1;i>=j;i--)
    {
            a[i+1]=a[i];
        }
    a[j]=num;
    for(i=0;i<n+1;i++)
    {
        printf("%d ",a[i]);
    }
}


#include<stdio.h>
int main()
{
    int a[200],n,i,j,flag=0;
    printf("enter limit ");
    scanf("%d",&n);
    printf("enter values");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("no u want to search ");
    scanf("%d",&j);
    for(i=0;i<n;i++)
    {
        if(a[i]==j)
       { printf("%d",i);
        flag=1;}
  

    }
    if(flag==0)
    {   
        printf("no not exist ");
}}*/

#include<stdio.h>
int sum( int x[],int y)
{
    int i=0,sum=0;
  for(i=1;i<y;i+2)
  sum=sum+x[i];
   return sum;
}

int main()
{
      int a[100],n,i,s;
      printf("enter limit ");
      scanf("%d",&n);
      printf("enter values");
      for(i=0;i<n;i++)
      {
          scanf("%d",&a[i]);
      }
      s=sum(a,n);
     printf("%d",s);
      return 0;
}


