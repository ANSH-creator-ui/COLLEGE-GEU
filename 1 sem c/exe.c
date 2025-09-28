#include<stdio.h>
#include<math.h>
int main()
{
    int n,c=1,sm=0;
    printf("enter the value=");
    scanf("%d,&n");
    while(c<=n)
    {
        sm=sm+pow(c,2);
        c++;
    }       
    printf("%d",sm);
    return 0;

}