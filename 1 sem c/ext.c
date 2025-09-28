/*#include<stdio.h>
void rev(int [],int);
int main()
{
    int a[100],n;
    printf("entr limit");
    scanf("%d",&n);
    printf("enter array vaklus=");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    rev(a,n);
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}



void rev(int a[],int x)
{
    int i,j,temp;
    for(int i=0,j=x-1;i<x/2;i++,j--)

    {
         temp=a[i];
         a[i]=a[j];
         a[j]=temp;    }
         
}


/*
#include<stdio.h>
int main()
{
    int a[100],temp,n;
    printf("enter n=");
    scanf("%d",&n);
    printf("entr values");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n;i++)
    {            for(int j=i+1;j<n;j++)
           {
            if(a[i]<a[j])
            {temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            }

            } printf("%d",a[i]);
            
           }
}*/

/*
#include<stdio.h>
int main()
{
    int a[100],num,n,flag=0;
    printf("enter n=");
    scanf("%d",&n);
    printf("entr values");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter num uwant to search =");
    scanf("%d",&num);
    for(int i=0;i<n;i++)
    {
    if(num==a[i])
    {
        printf("%d",i);
       flag=1;}}
   if(flag==0)
    {printf("no. not exist");}
    }*/

   /*
#include<stdio.h>
int main()
{
    int a[100],n,j;
    printf("enter n=");
    scanf("%d",&n);
    printf("entr values");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter num u want ot delete ");
    scanf("%d",&j);
    for(int i =0;i<n;i++)
    {
        if(a[i]==j)
        {
            for(j=i;j<n;j++)
            {
                a[j]=a[j+1];

            }
        }
    }
    for(int i =0;i<n-1;i++)
    {
      printf("%d",a[i]);

    }}*/


   #include<stdio.h>
int main()
{
    int a[100],n,j,index,i;
    printf("enter n=");
    scanf("%d",&n);
    printf("entr values");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter num u want to insert  and index no. ");
    scanf("%d%d",&j,&index);
     for(i=n-1;i>=index;i--)
     {
        a[i+1]=a[i];
     }
     a[index]=j;
     for(int i=0;i<n+1;i++)
     {
        printf("%d",a[i]);
     }
}
