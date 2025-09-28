/*#include<stdio.h>
#include<math.h>
void main()
{
    int c=1,a,b=0;
    printf("enter value ofa= ");
     scanf("%d",&a);
for(c;c<=a;c++)
{
    b=pow(c,3)+b;

}
printf("%d",b);}
     

     #include<stdio.h>g
     int main()
    {
        int a,b=a,s=1;
        printf("enter the  value of a=");
         scanf("%d",&a);
         while(b>=2);

         {
            s=s*b;
            b--;
         }
     printf("%d",s);
     return 0;
     }*/


     #include<stdio.h>
     int main()
     {
        int n,num,c=1;
        int small;
        printf("enter limit");
        scanf("%d",&n);
        printf("enter num");
        scanf("%d",&num);
        small=num;
        while(c<=n-1)
        {
            printf("entger num");
            scanf("%d",&num);
            if(small>num)
            {small = num;
        }
        c++;
     }
     printf("%d",small);
          }     