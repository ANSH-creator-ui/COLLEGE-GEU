#include <stdio.h> 
int start();
int sum(int a,int b,int c);
int main() { 
    start();
     }
int sum(int a,int b,int c)
{ 
    int p=a+b+c; 
    a=p%2;
    return a;
    printf("a");
} 
int start()
{ 
    int n1,n2,n3,c;
    for(c=1;c<=3;c++)
    { 
        printf("Enter three numbers with a blindfold\n"); 
        scanf("%d %d %d",&n1,&n2,&n3); 
        if (sum(n1,n2,n3) == 0)
        { 
            printf("You score %d point\n",c); 
            if (c==3) { 
                printf("you won\n");
            }
        }
        else 
        { 
            printf("You lose\n"); 
            break;
        } 
    } 
}