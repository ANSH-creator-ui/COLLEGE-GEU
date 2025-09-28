/*#include<stdio.h>
int main()

{
     int n,i;
     printf("enter th evalue of n =");
     scanf("%d",&n);
     for(i=1;i<=n;i++)
     {
        printf("\n%c",i);
     }
}


{
    int n,j,i;
    printf("engter the value of n=");
    scanf("%d",&n);
    for(i=1;i<=i;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("#");

        }
    printf("\n");}
    return 0;
}


{
    int n,j,i;
    printf("engter the value of n=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("#");

        }
    printf("\n");}
    return 0;
}


{
    int n,i,j;
    printf("enter the value of n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d",j);
        }
        printf("\n");}
        return 0;
        
            }


       #include<stdio.h>
       int main()


            
          {
            int n,i,j,m;
            printf("enter the value of n=");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=i-1;j++)
                {
                    printf(" ");

                }
                for(m=1;m<=n+1-i;m++)
                {
                    printf("*");

                }
                printf("\n");


            }
            return 0;
          } 
 
  /*  
   
{
    int n,i,j;
    printf("enter thevalue of n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("A");

        }
        printf("\n");

    }
    return 0;
}


/*

{
    int n,i,j;
    printf("enter thevalue of n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d",i);

        }
        printf("\n");

    }
    return 0;
}

{
    int n,i,j;
    printf("enter thevalue of n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d", j);

        }
        printf("\n");

    }
    return 0;
}  
{


    int n,i,j;
    printf("enter thevalue of n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%c",i+64);

        }
       printf("\n");

    }
    return 0;
} 



{
    int n,i,j,number=1;
    printf("enter the value of n=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
         {printf("%d",number);
         number++;
         }
         printf("\n");

    }
return 0;
}

 {
    int n,i,j;
    printf("enter the value of n=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
         {printf("%c",j+64);
         
         }
         printf("\n");

    }
return 0;
}
{  
    int i,j,n,number=1;
    printf("enter the value of n=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
         {  
            if (j % 2 == 1) {
                printf("1");
            } else {
                printf("0");
         
         }}
         printf("\n");

    }
return 0;
}*/
/*
{
      int m,i,j,n;
      printf("enter the value of n=");
      scanf("%d",&n);
      for(i=1;i<=n;i++)
      {
        for(m=1;m<=n-i;m++)
        {
            printf(" ");
            
    
        }
        for(j=1;j<=i*2-1;j++)
        {
            printf("&");
        }
        printf("\n");
      }
      return 0;

}*/
/*
#include <stdio.h>

int main() {
    // Printing a dog using ASCII art
    printf("   / \\__\n");
    printf("  (    @\\___\n");
    printf("  /         O\n");
    printf(" /   (_____ / \n");
    printf("/_____/   U\n");

    return 0;
}
*/

#include<stdio.h>
int main()
{
    int n,i,j,k;
     printf("enter n");
     scanf("%d",&n);
     for(i=1;i<=n;i++)
     {
        for(j=1;j<=n-i;j++)
        {
            printf(" ");

        }
        for(k=1;k<=2*i;k++)
        {
            printf("#");
        }
        printf("\n");

     }
     return 0;

}