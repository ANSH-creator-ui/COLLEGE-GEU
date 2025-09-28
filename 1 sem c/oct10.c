/*#include<stdio.h>
int main()
{
    int n,sum=0;
    printf("enter the valuenof n=");
    scanf("%d",&n);
    while(n>0)
    {
        sum=sum+n%10;
        n=n/10;

    }
    printf("sum=%d",sum);
    return 0;
}
/// unpacked reverse no,.
{
    int n,y;
    printf("enter the value of n=");
    scanf("%d",&n);
    while(n>0)
    {
        y=n%10;
        printf("%d",y);
        n=n/10;
    }
    return 0;
}

{
    int n,rev=0;
    printf("enter the value of n=");
    scanf("%d",&n);
    while(n>0)
    {
        rev=rev*10+n%10;
        n=n/10;
    }
printf("rev=%d",rev);
return 0;
}*/
// palindorem 
/*#include<stdio.h>
int main()
{
    int  n,org,rev=0;
    scanf("%d",&n);
    org=n;
    while(n>0)
    {
        rev=rev*10+n%10;
        n=n/10;
     
    }
    printf("rev=%d",rev);
    if(org==rev)
    {
        printf("\npalindrome");
    }
    else{
        printf("\nnot a palindrome no.");

    }
    return 0;
}*/

#include<stdio.h>
#include<math.h>
int main()
{
    int n,temp,dc=0,sum=0;
    scanf("%d",&n);
    temp=n;
    while(temp>0)
    {
        dc++;
        temp=temp/10;

    }
    printf("\n%d",dc);
    if(temp>0)
    {
        sum=sum+pow(temp%10,dc);
        temp=temp/10;
    }
    printf("\n%d",sum);
 if (temp==sum)
    {
        printf("\narmnstrong np.");
    }  
    else
    {
        printf("\nnt a armstrong");

    }
    return 0;
}