#include<stdio.h>
int sum(int);
int main()
{
    int r,n;
    printf("enter n=:");
    scanf("%d",&n);
    printf("%d",r=sum(n));
    return 0;
}

int sum(int x)
{
    if(x==0)
    return 0;
    else
    return x%10+sum(x/10);
}
/*
#include<stdio.h>
int sum(int);
int main()
{
    int n;
    printf("enter n=:");
    scanf("%d",&n);
    printf("%d",sum(n));
    return 0;
}

int sum(int x)
{
    if(x==1)
    return 1;
    else
    return x+sum(x-1);
}

#include<stdio.h>
int check_assendingd_desending(int [],int);
void main()
{
    int a[20],i,n;
    printf("enter limit=");
    scanf("%d",&n);
    printf("enter values=");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);

    }
check_assendingd_desending(a,n);

}
int check_assendingd_desending(int a[],int y)
{   int i,j,temp;
     for(i=0;i<y;i++)
    { 
        for(j=i+1;j<y;j++)
        {
            if(a[j]<a[i])
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;

            }}
            printf("\n ""%d",a[i]);
        }
            
        
        
    }
*/