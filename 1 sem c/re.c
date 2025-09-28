/*#include<stdio.h>
int fib(int);
int fib(int x)
{     if(x==0 || x==1)
      return x;
      else
      return fib(x-1)+fib(x-2);

}
int main()
{
    int i,n;
    printf("enter nth term =");
    scanf("%d",&n);
    for( i=0;i<n;i++)
   { printf("%d",fib(i));}
    return 0;

}*/
/*
#include<stdio.h>
#include<math.h>
int power(int x, int y)
{
 if ( y==0)
 return 1;
 else
 return x*power(x,y-1);



}
int main()
{
    int n,y;
    printf("enter base and exponent=");
    scanf("%d%d",&n,&y);
    printf("%d",power(n,y));
    return 0;
    }
    */
/*
   #include<stdio.h>
   int sum(int x)
   {
    if (x==0)
    {
        return 0;
    }
    else
    {   return x%10+sum(x/10);
    }
   }

   int main()
   {
     int n;
     printf("entr n=");
     scanf("%d",&n);
     printf("%d",sum(n));
     return 0;

   }*/
/*
  #include<stdio.h>
  int sum(int x)
  {
     if(x==0)
     return 0;
     else
     return x+sum(x-1);

  }
void main()
{
     long int x;
    printf("enter value of n=");
    scanf("%d",&x);
    printf("%d",sum(x));
}*/



  #include<stdio.h>
  int fact(int x)
  {
     if(x==1 || x==0)
     return x;
     else
     return x*fact(x-1);

  }
void main()
{
     unsigned long int x,y;
    printf("enter value of n=");
    scanf("%d",&x);
    printf("%d",y=fact(x));
}