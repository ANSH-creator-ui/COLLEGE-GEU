/*#include<stdio.h>
int main()
{
    float P,R,T,SI;
    printf("enter the value of P,R,T");
    scanf("%f%f%f",&P,&R,&T);
    SI=(P*R*T)/100;
    printf("SIMPLE INTEREST=%.2f",SI);
    return 0;


}*/


// program no.2 


/*#include<stdio.h>
int main()
{
    float F,C;
    printf("TEMPERATURE IN FAHRENHEIT=");
    scanf("%f",&F);
    C=(F-32)*5/9;
    printf("TEMPERATURE IN CELCIUS=%.2f",C);
    printf("\nENTER THE TEMP. IN CELCIUS= ");
    scanf("%f",&C);
    F=(C*9/5)+32;
    printf("TEMP. IN F =%.2f",F);
    return 0;
    }*/


//PROGRAM NO. 3 

/*#include<stdio.h>
int main()
{
    int A,first,last,middlepart,result;
    printf("ENTER THE 4 DIGIT NO.=");
    scanf("%d",&A);
    first=A/1000;
    last=A%10;
    printf("first digit=%d",first);
    printf("last digit=%d",last);
    middlepart =(A%1000)/10;
    printf("\nMIDDLE PART=%d",middlepart);
    result=last*1000+middlepart*10+first;
    printf("\nAFTER SWAPPING THE RESULT=%d",result);
    return 0;
}
*/


//program no.4 SWAPPING USING BITWISE OPERATOR




/*
#include<stdio.h>
int main()
{
    int a,b;
    printf("ENTER THE VALUE OF A & B=");
    scanf("%d%d",&a,&b);
    a=a^b;
    b=a^b;
    a=a^b;
    printf("THE VALUE OF A & B AFTER SWAPPING =%d , %d",a,b);
    return 0;


}*/

// PROGRAM NO. 5 BANLK NOTES
/*

#include<stdio.h>
int main()
{
    int AMOUNT , N;
    printf("ENTER THE PRINCIPAL=");
    scanf("%d",&AMOUNT);
    N=AMOUNT/500;
    printf("\nNO. OF RS.500 BANK NOTES=%d",N);
    N=AMOUNT/200;
    printf("\nNO. OF RS.200 BANK NOTES=%d",N);
    N=AMOUNT/100;
    printf("\nNO. OF RS.100 BANK NOTES=%d",N);
    N=AMOUNT/50;
    printf("\nnNO. OF RS.50 BANK NOTES=%d",N);
    N=AMOUNT/20;
    printf("\nnNO. OF RS.20 BANK NOTES=%d",N);
    N=AMOUNT/10;
    printf("\nNO. OF RS.10 BANK NOTES=%d",N);
    N=AMOUNT/5;
    printf("\nNO. OF RS.5 BANK NOTES=%d",N);
    N=AMOUNT/1;
    printf("\nNO. OF RS.1 BANK NOTES=%d",N);
    return 0;


}*/
//// prpgram no. 4   else if ladder
/*


#include<stdio.h>
int main()
{
    int n;
    printf("enter the integer=");
    scanf("%d",&n);
    if(n>0)
    {
        printf("NO. IS +VE=%d",n);
        
    }
    else
    {
        if(n==0)
        {
            printf(" no. is zero %d",n);
        }
        else
        {
            printf("NO. IS -VE %d",n);

        }

    }
    return 0;

*/
// ONLY IF
/*

#include<stdio.h>
void main()
{
    int a,b,c,d,max;
      printf("ENTER THE VALUES");
      scanf("%d%d%d%d",&a,&b,&c,&d);
      max=a;
      if(max<b)
      {
          max=b;
      }
       if(max<c)
       {
        max=c;
       }
      if(max<d)
      {
        max=d;

      }
printf("max value=%d",max);
}*/

// IF ELSE
 /*#include<stdio.h>
 void main()
 {
    int NM,bill;
    printf("enter no. of mangoes=");
    scanf("%d",&NM);
    bill=5*NM;
    if(NM>5)
    {
        bill=bill-0.1*bill;
    }
    else
    {
        bill=bill-0.5*bill;
    }
    printf("TOTAL COST=%d",bill);
 }
 */


// days to year month days
/*

#include<stdio.h>
void main()
{
    int days,month,year;
       printf("enter no. of days=");
       scanf("%d",&days);
       month=days/30;
       year=days/365;
       days=days%30;
       printf("month=%d  \nyear=%d  \ndays=%d",month,year,days);


}*/


/*
#include <stdio.h>

int main() {
    printf("Size of char: %zu bytes\n", sizeof(char));
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of long: %zu bytes\n", sizeof(long));
    printf("Size of long long: %zu bytes\n", sizeof(long long));

    return 0;
}*/


/*#include<stdio.h>
void main() 
{

     printf("%zubyte",sizeof(char));
     printf("\n%zubyte",sizeof(float));
     printf("\n%zu",sizeof(double));
     printf("\n%zubyte",sizeof(int));
    
}*/

/*
#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c,s,area;
    printf("enter the sides of triangle=");
    scanf("%f%f%f",&a,&b,&c);
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    printf("area of triangle=%.2fsqunit",area);
    return 0;
    
}*/
#include<stdio.h>
void main()
{ 
    int n;

    for(n=1;n<=10;n++)
    {
        printf("\n%d",n);
    }


}