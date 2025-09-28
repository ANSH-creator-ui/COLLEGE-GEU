/*#include<stdio.h>
int main()
{
    int m,n,c;
    printf("enter the valie of m and n=");
    scanf("%d%d",&m,&n);
    for(c=m;c<=n;c++)
    {
        if(c%2!=0) 
        {printf("\n%d",c);
    }

}
return 0;

}

/*
#include<stdio.h>
int main()
{
    int a,b=1,c;
    printf("enter the value of a");
    scanf("%d",&a);
    for(a;b<=10;b++)
    {
        c=a*b;
        printf("\n%d",c);

    }
return 0;
}*/




/*

#include<stdio.h>
int main()
{
    int a=1,c=1,b,s=0;
    printf("enter the value of b=");
    scanf("%d",&b);
    for(a;a<=b;a++)
    {
        c=c*a;
        s=c+s;
    }
    printf("%d\n%d",c,s);
    return 0;
}*/


//We get,  sum of series x + 2x + 3x + 4x .... nx

/*
#include<stdio.h>
int main()
{
    int x,c=1,b,s,sum=0;
    printf("enter the value of x & b =");
    scanf("%d%d",&x,&b);
    while(c<=b)
    {
        s=c*x;
        sum=s+sum;
        c++;

    }
    printf("sum=%d",sum);
    return 0;
}*/

//e have to put character and the program will find out is it a alphabet, special character or digit


/*
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;

    // Prompt user for input
    printf("Enter a character: ");
    scanf("%c", &ch);

    // Check if the character is an alphabet, digit, or special character
    if (isalpha(ch)) {
        printf("The character '%c' is an Alphabet.\n", ch);
    } else if (isdigit(ch)) {
        printf("The character '%c' is a Digit.\n", ch);
    } else {
        printf("The character '%c' is a Special Character.\n", ch);
    }

    return 0;
}

//AISCII

#include <stdio.h>

int main() {
    char ch;

    // Prompt user for input
    printf("Enter a character: ");
    scanf("%c", &ch);

    // Print the ASCII value
    printf("The ASCII value of '%c' is %d.\n", ch, ch);

    return 0;
}

*/
///

#include<stdio.h>
int main()
{
    char x;
    scanf("%c",&x);
    printf("\naiscii=%d",x);
    x=x+32;
    printf("\n%c",x);
    printf("\naiscii=%d",x);
    return 0;

}