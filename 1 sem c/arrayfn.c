// TO REVERSE NUMBER IN ARRAY 
/*#include<stdio.h>
void rev(int [],int );
int main()
{
    int a[100],i,n;
    printf("enter limit;");
    scanf("%d",&n);
    printf("enter values");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    rev(a,n);
 for(int i=0;i<n;i++)
{
printf("%d",a[i]);
}return 0;

}   

void rev(int b[],int x)
{ int temp,i,j;
    for(i=0,j=x-1;i<x/2;i++,j--)
    { temp=b[i];
     b[i]=b[j];
     b[j]=temp;
    }}
*/
// TO MERGE TWO ARRAY IN ONE ARRAY
/*
#include<stdio.h>
int main()

{
    int a[100],b[100],i,n,m;
    printf("enter limit for array a & b=");
    scanf("%d%d",&n,&m);
    printf("values");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("values of b array");
    for(i=0;i<m;i++)
    scanf("%d",&b[i]);
    for(i=0;i<m;i++)
    a[i+n]=b[i];
    for(i=0;i<m+n;i++)
    printf("%d",a[i]);
    return 0;

}*/
// program to delete an value  of array
/*
#include<stdio.h>
int main()
  {
    int a[100],n,i,num;
    printf("enter limit");
    scanf("%d",&n);
    printf("enter values of array");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    printf("enter position want to delete=");
    scanf("%d",&num);
    for(i=0;i<n;i++)
    {
        if(a[i]==num)
        {
            for(num=i;num<n-1;num++)
            {
                a[num]=a[num+1];
            }
            
        }
    }
    for(i=0;i<n-1;i++)
    printf("%d",a[i]);

  }*/

  //TO DELETE AN INDEX VALU FROM THE ARRAY
/*
  #include<stdio.h>
  int main()
  {
    int i,j,a[40],n,num;
    printf("enter limit;");
    scanf("%d",&n);
    printf("enter values=");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
            }
    printf("enter inderx wale u wan tto delete=");
    scanf("%d",&num);
    for(i=0;i<n;i++)
    {
        if(a[i]==num)
         {
              for(j=i;j<n;j++)
           {
             a[j]=a[j+1];
            }
        }
        }
        for(i=0;i<n-1;i++){
        printf("%d",a[i]);}
        }*/


 // to insert an values in an array
 
#include<stdio.h>
int main()
{
    int i,j,a[100],num,n;
    printf("enter limit ");
    scanf("%d",&n);
    printf("enter values");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    printf("enter no. and index no. u want to insert= ");
    scanf("%d%d",&num,&j);
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
////SEARCH AN VALUEIN ARRAY AND PRINT INDEX N0
/*
#include<stdio.h>
int main()
{
  int a[100],n,i,j,flag=0;
  printf("enter limit");
  scanf("%d",&n);
  printf("enter valuesmof aray");
  for(i=1;i<=n;i++)
{    scanf("%d",&a[i]);


} printf("enter no. u want to searxh ");
scanf("%d",&j);
for(i=1;i<=n;i++)
{
     if(a[i]==j)
     printf("%d",i);
    flag++;

    if(flag==0)
    printf("NO NOT EXIST");

}
}*/

// TO REPLACE INDEX VALUES NY==BY ITS SYM OF DIGIT
/*#include<stdio.h>

int sum(int x)
{
    int i=0;
   while(x>0)
    {
        i=i+x%10;
        x=x/10;
    }
    return i;
}
int main()
{
    int a[20],n,i,j;
    printf("enter limit;");
    scanf("%d",&n);
    printf("enter the vaues of array ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    for(i=0;i<n;i++)
    {
        a[i]=sum(a[i]);
         printf("%d",a[i]);
     }
    }*/
     



/// PROGRAM TO PRINT ARRAY VALUES IN ASSCENDING AND DECSCENDING 

/*
#include<stdio.h>
int asscending(int b[],int x)
{
    int i,j,temp;
    for(i=0;i<x;i++)
    {
        for(j=i+1;j<x;j++)
        {  if(b[i]>b[j])
        {
            temp=b[i];
            b[i]=b[j];
            b[j]=temp;
        }
    }
}}
int descending(int c[],int y)
{
    int i,j,temp;
    for(i=0;i<y;i++)
    {
        for(j=i+1;j<y;j++)
        {  if(c[i]<c[j])
        {
            temp=c[i];
            c[i]=c[j];
            c[j]=temp;
        }
    }
}}


int main()
{
    int a[50],n,i,j;
    printf("enter limit=");
    scanf("%d",&n);
    printf("enter valuesz");
    for(i=0;i<n;i++)
    {
    
    scanf("%d",&a[i]);
}
asscending(a,n);
for(i=0;i<n;i++)
    {
    
    printf("%d ",a[i]);
}
descending(a,n);
for(i=0;i<n;i++)
    {
    
    printf("%d ",a[i]);
}
return 0;
}*/


////two user define function to calculate power and factorial in main fucntuon
/*

#include<stdio.h>
#include<math.h>
int fact(int j)
{
    int c=1,s=1;
    while(c<=j)
    {
        s=s*c;
        c++;
    }
    return s;
}
int power(int j)
{
    int r;
    r=pow(j,j);
    return r;
}
int main()
{
    int n,i,r=0;
    printf("enter n=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        r=r+(power(i)/fact(i));

    }
    printf("%d",r);
    return 0;

}*/