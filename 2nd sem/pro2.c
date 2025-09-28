#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void basic_operation(int);
void trigno(int );
void log_(int);
void matrix(int);
int main()
{
     int choice;
        do
        {
            printf("1. Basic (+, -, *, /)\n2. Trigonometry (sin, cos, tan)\n3. Logarithm (base 10)\n4. Matrix (Add, Multiply)\n5. Exit\n");
            printf("choice=");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:basic_operation(choice);
             break;
                /*  case 2:trigno(choice);
                break;
                case 3:log_(choice);
                break;
                case 4: matrix(choice);
                break;*/
                case 5:printf("exiting...\n");
                break;
                default:printf("invalid choice");
                break;
            }
        }while(choice!=5);
        return 0;
    }
    void basic_operation(int x)
    {
        int a,b;
        int ch;
        printf("enter 1 for add\n2for -\n3 for *\n4 for /\n");
        scanf("%d",&ch);
        printf("enter a&b=");
        scanf("%d%d",&a,&b);
        switch(ch)
        {
            case 1:printf("%d\n",a+b);
            break;
            case 2:printf("%d\n",a-b);
            break;
            case 3:printf("%d\n",a*b);
            break;
            case 4: printf("%d\n",a/b);
            break;
            default:printf("invalid choice");
            break;
        }
    }

    