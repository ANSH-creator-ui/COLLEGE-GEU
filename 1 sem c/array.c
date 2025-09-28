#include<stdio.h>
int main()
/*{
    int a[5];
    int i,mult;
    printf("enter values");
    for(i=0;i<5;i++)
    { scanf("%d",&a[i]);
    }
    mult=a[1]*a[3];
    printf("%d",mult); }   */

    {
        float a[20],sum;
        int n,i;
        printf("enter limit");
        scanf("%d",&n);
        printf("enter values =");
        for(i=0;i<n;i++)
        {
            scanf("%f",&a[i]);
            sum=sum+a[i];

        }
       printf("%f",sum);
       return 0;


    }