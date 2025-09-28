/*      NAME                :   ANSH SINGH NEGI     
       UNIVERSITY ROLL NO. :   24021905
       SECTION             :   K

 Q1. The length and breadth of a rectangle and radius of a circle are input through the keyboard. Write a program to calculate the area and perimeter of the rectangle, and the area and the circumference of the circle.   

#include<stdio.h>
int main()
{
    float l,b,r,ac,cc,ar,pr;
    printf("Enter the length & breadth of rectangle=");
    scanf("%f%f",&l,&b);
    printf("Enter the radius of circle= ");
    scanf("%f",&r);
    ar=l*b;
    pr=2*(l+b);
    ac=3.14*r*r;
    cc=2*3.14*r;
    printf("\nThe area of rectangle=%.2fsq.unit",ar);
    printf("\nThe perimeter of rectangle=%.2funit",pr);
    printf("\nThe area of circle=%.2fsq.unit",ac);
    printf("\nThe circumference of circle =%.2funit",cc);
    return 0;

     }
                                
     
    ///Q2. 2. Mr. X’s basic salary is input through the keyboard. If the basic salary exceeds 50000, his dearness
    //        allowance is 30% of the basic salary, and the house rent allowance is 15% of basic salary otherwise
    //        his dearness allowance is 20% of the basic salary, and the house rent allowance is 10% of basic salary.
    //        Write a program to calculate his gross salary. 
*/
#include<stdio.h>
int main() 
{
    float b, d, h, g;
    printf("Enter the basic salary: ");
    scanf("%f", &b);

    if (b > 50000) 
    {
        d = 0.3 * b;
        h = 0.15 * b;
    } 
    else 
    {
        d = 0.2 * b;
        h = 0.1 * b;
    }
    g = b + d + h;
    printf("Gross Salary:Rs.%.3f", g);
    return 0;
}
//  Q3.The following calculates value of f(x) if x has different ranges of value as below.
// F( x) =x2+2 if 0<=x<=10
// F(x) =x2+2x if 11<=x<=20
// F(x) =x3+2x2 if 21<=x<=30
// F(x) =0 if x>30

/*
#include<stdio.h>
int main() 
{
    int x;
    float f;
    printf("Enter the value of x: ");
    scanf("%d",&x);

    if (x>=0 && x<=10)
    {
        f=x*x+2;
    }
    else if (x>=11 && x<=20)
    {
        f=x*x+2*x;
    }
    else if (x>=21 && x<=30)
    {    f=x*x*x+2*x*x;
    }else
    {   f= 0;
    } 
    printf("F(x) = %.2f\n", f);
    return 0;
}

// Q4. Write a program to input a three-digit number and print it in words using switch case.

#include<stdio.h>
int main()  
{
    int n,d1,d2,d3;
    printf("Enter a three-digit number: ");
    scanf("%d",&n);
    d1 = n/100;
    d2 = (n/10) % 10;
    d3 = n%10;
    switch (d1) 
    {
        case 1: printf("One ");   break;
        case 2: printf("Two ");   break;
        case 3: printf("Three "); break;
        case 4: printf("Four ");  break;
        case 5: printf("Five ");  break;
        case 6: printf("Six ");   break;
        case 7: printf("Seven "); break;
        case 8: printf("Eight "); break;
        case 9: printf("Nine ");  break;
    }

    switch (d2) 
    {
        case 1: printf("One ");   break;
        case 2: printf("Two ");   break;
        case 3: printf("Three "); break;
        case 4: printf("Four ");  break;
        case 5: printf("Five ");  break;
        case 6: printf("Six ");   break;
        case 7: printf("Seven "); break;
        case 8: printf("Eight "); break;
        case 9: printf("Nine ");  break;
    }

    switch (d3) 
    {
        case 1: printf("One");   break;
        case 2: printf("Two");   break;
        case 3: printf("Three"); break;
        case 4: printf("Four");  break;
        case 5: printf("Five");  break;
        case 6: printf("Six");   break;
        case 7: printf("Seven"); break;
        case 8: printf("Eight"); break;
        case 9: printf("Nine");  break;
    }

    return 0;
}

//Q5.Write a program to find the nth term in the given series.
//    0, 0, 2, 1, 4, 2, 6, 3, 8, 4, 10, 5, 12, 6, 14, 7, 16, 8


#include<stdio.h>
int main() 
{
    int n, res;
    printf("Enter the n term = ");
    scanf("%d", &n);
    if (n % 2 == 0)
    {
        res = (n / 2) - 1;
    }
    else
    {
        res = (n - 1);
    }
    printf("The %dth term is= %d\n", n, res);
    return 0;}






//Q6.Write a program to print the sum of the given series: 1!+2!-3!+4!-5!...n!

#include<stdio.h>
int main()
{
    int n,i,f=1,sum=1;
    printf("enter the n number=");
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {


           f=f*i;
           if(i%2==0)
           {
              sum=sum+f;
           }
           else
           {
            sum=sum-f;
           }
    }
    printf("sum of series=%d",sum);
    return 0;
}




 // Q7.Write a program to print all prime numbers between a given range p and q.

#include<stdio.h>
int main()
{
    int p,q,i,j;
    printf("Enter the range p and q=");
    scanf("%d%d",&p,&q);
    for(i=p;i<=q;i++)
    {
      for(j=2;j<=i;j++)
      {
        if(i%j==0)
        break;
      }    
      if(i==j)
      {      printf("%d ",i);
        }
      }
      
      return 0;
    }


//Q8.Write a user-defined function to create a game where the player checks if the sum of three input numbers is odd or even.
#include <stdio.h>
int checkSumEven(int,int,int);
int checkSumEven(int num1, int num2, int num3) {
    int sum = num1 + num2 + num3;
    return sum % 2 == 0;  // Return 1 if the sum is even, otherwise 0
}

int main() {
    int num1, num2, num3;
    int points = 0;
    int chances = 0;
    
    // Loop until the player either wins or loses
    while (points <= 3) {
        printf("Enter three numbers (close your eyes and input): ");
        scanf("%d %d %d", &num1, &num2, &num3);
        
        // Check if the sum of the numbers is even
        if (checkSumEven(num1, num2, num3)) {
            points++;
            printf("Sum is even! You score a point. Total points: %d\n", points);
        } else {
            points = 0;  // Reset points if the sum is not even
            printf("Sum is odd! No points. You lost all points.\n");
        }
        
        chances++;
        
        // If the player scored 3 points, they win
        if (points == 3) {
            printf("Congratulations! You won the game.\n");
            break;
        }

        // If the chances exceed 5, the player loses
        if (chances >= 3) {
            printf("You lost! Too many tries without winning.\n");
            break;
        }
    }

    return 0;
}



// Q9.Write a code to input a number and check if it is an Armstrong number or not.
/*
#include <stdio.h>
#include <math.h>
int main()
 {
    int n,temp,sum=0,dc=0;
    printf("Enter a number: ");
    scanf("%d", &n);
    temp = n;
    while(temp > 0)
    {   dc++;
        temp = temp/10;
    }
    temp=n;
    while(temp > 0) 
    {
        sum = sum + pow(temp % 10, dc);
        temp = temp/10;
    }
     if(sum==n)
    {
        printf("%d is an Armstrong number.\n", n);
    }
    else
    {
        printf("%d is not an Armstrong number.\n", n);
    }
    return 0;
}


//Q10.Write a program to print the given patterns-:
//A
//B C
//D E F
//G H I J
//K L M N O


#include<stdio.h>
int main()
{
    int n=5,r,c;
    char i='A';
    for(r=1;r<=n;r++)
    {
        for(c=1;c<=r;c++)
    {
            printf("%c ",i);
            i++;
    }
    printf("\n");
 
    }
    return 0;
}



//  Q11. Write a program to print the given patterns-:


                 #include<stdio.h>
                 int main()
                 {
                    int n,i,j,k;
                    n=5;
                    for(i=1;i<=n;i++)
                    {
                        for(j=1;j<=5-i;j++)
                        {
                            printf(" ");
                        }
                        for(k=1;k<=i;k++)
                        {
                            printf("*");

                        }
                        printf("\n");
                        return 0;
                    }
                 } 



              //   Question 12.
//Write a user defined function to check a number is Armstrong or not using function.

#include<stdio.h>
#include<math.h>
int check_Armstrong(int);
void main()
{
    int n,r;
    printf("enter n=");
    scanf("%d",&n);
    r=check_Armstrong(n);
    if(r==n)
        { printf(" %d is an armstrong no.",n);}
    else
        { printf("%d is not an armstorng no. ",n);   }
     
}

int check_Armstrong(int x)
{
    int sum=0,dc=0,t;
    t=x;
    while(t>0)
    {     dc++;
        t=t/10;
    }
    t=x;
    while(t>0)
    {
        sum=sum+pow(t%10,dc);
        t=t/10;
    }
return sum;
}*/
                  