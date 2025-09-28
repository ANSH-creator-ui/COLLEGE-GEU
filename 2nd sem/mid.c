/*#include<stdio.h>
void input(int a[100][100], int b[100][100], int m, int n)
{ int i,j;
 for(i=0;i<m;i++)
 {
     for(j=0;j<n;j++)
     {
         scanf("%d",&a[i][j]);
     }
 }
 printf("enter elements for 2nd ");
 for(i=0;i<m;i++)
 {
     for(j=0;j<n;j++)
     {
         scanf("%d",&b[i][j]);
     }

 }
 }

 void sum(int a[100][100], int b[100][100], int m, int n)
 { int i,j,c[100][100];
 for(i=0;i<m;i++)
 {
     for(j=0;j<n;j++)
     {
        c[i][j]=a[i][j]+b[i][j];
     }}
     for(i=0;i<m;i++)
     {
         for(j=0;j<n;j++)
         {
             printf("%d",c[i][j]);

         }   }}
void main()
{
    int a[100][100],b[100][100],c[100][100],m,n;
    printf("enter no. of rows and column =");
    scanf("%d%d",&m,&n);
    printf("enter elements ");
    input(a,b,m,n);
    sum(a,b,m,n);
}
 */
/*
 #include<stdio.h>
 #include<string.h>
 void main()
 {
    char a[100];
    int i,j;
    printf("entter string=");
    gets(a);
    j=strlen(a);
    if(a[0]!=' ')
    putchar(a[0]);
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]==' ' && a[i+1]!=' ')
        {
            putchar(a[i+1]);
        }
    }printf("%d",j);
 }*/
   /* 
 #include<stdio.h>
 #include<string.h>
 void main()
 {
    char a[100];
    int i,j,c;
    printf("entter string=");
    gets(a);
    j=strlen(a);
    if(a[0]==' ')
   { c=0;}
else {
c=1;}
for(i=0;a[i]!='\0';i++)
{
    if(a[i]==' ' && a[i+1]!=' ')
    {
        c++;
    }
}
printf("%d",c);
 }*/
/*
 #include<stdio.h>
 #include<string.h>
 void main()
 {
    char a[100];
    int i=0,sp=0,j;
    printf("enter string=");
    gets(a);
    char b[100];
    printf("enter substring=");    
    gets(b);
    int l1=strlen(a), l2=strlen(b);
    while(a[i]!=' ')
    {i++; 
     sp++;
    }
    for(i=l1;i>=sp;i--)
    {
        a[i+l2+1]=a[i];
    }
    for(i=0,j=sp+1;b[i]!='\0';i++,j++)
    {
        a[j]=b[i];
    }
    puts(a);
}*/
/*
#include<stdio.h>
#include<string.h>
void main()
{
    char a[100],b[100];
    int i,j,p,l1,l2;
    printf("enter string");
    gets(a);
    printf("enter substring=");
    gets(b);
    l1=strlen(a);
    l2=strlen(b);
    printf("enter position =");
    scanf("%d",&p);
    for(i=l1;i>=p;i--)
    {
        a[i+l2]=a[i];

    }
    for(i=0,j=p;b[i]!='\0';i++,j++)
    {
        a[j]=b[i];

    }
    puts(a);
}*/
/*
#include<stdio.h>
void main()
{
    int a[50][50],b[40],i,j,k=0,m,n,tmp;
    printf("enter no. of rows and column=");
    scanf("%d%d",&m,&n);
    printf("enter elements=");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            b[k]=a[i][j];
            k++;
        }
    }     
    for(i=0;i<m*n;i++)
    {
        for(j=0;j<m*n;j++)
        {
            if(b[i]<b[j])
            {
                tmp=b[i];
                b[i]=b[j];
                b[j]=tmp;
            }
        }
    }
    k=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=b[k];
            printf("%d",a[i][j]);
            k++;}
    }
}*/
/*
#include<stdio.h>
void main()
{
    int a[100][100],i,j,m,n=0,sum=0,avg;
    printf("enter no. of rows and column=");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);

        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
        if(i==j && a[i][j]%2==0)
            {
            sum=sum+a[i][j];}
         if(i>j && a[i][j]%2==0)
        {sum=sum+a[i][j];
    }}}
    printf("%d",sum);
}
/*
    for(i=0,j=m-1;i<m;i++,j--)
    {
        if(a[i][j]>99 && a[i][j]<1000)
        {    n++;
            sum=sum+a[i][j];
        }
        else        {
            printf("not a 3 digit no.");
        }
        
    }
    avg=sum/n;
    printf("%d\n%d",sum,avg);
}
/*
#include<stdio.h>
void main()
{
    char a[100];
    int i,j;
    printf("enter string=");
     gets(a);
    if(a[0]!=' ')
    {
        putchar(a[0]);
    }
for(i=0;a[i]!='\0';i++)
{
    if(a[i]==' ' && a[i+1]!=' ')
    {
        putchar(a[i+1]);

    }
}}*/
/*
#include<stdio.h>
#include<string.h>
void main()
{
    char a[100];
    int i,c;
    printf("enter srting=");
    fgets(a,sizeof(a),stdin);
    if(a[0]==' ')
    c=0; 
    else
     c=1;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]==' ' && a[i+1]!=' ')
        {c++;}
    }
    printf("%d",c);
}*/
/*
#include<stdio.h>
void main()
{
    int a[100][100],i,j,r,c,p;
    printf("enter no. of rows and column=");
    scanf("%d%d",&r,&c);
    printf("enter elements=");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter particular column");
    scanf("%d",&p);
    int sum=0;
    for(i=0;i<r;i++)
    {
           sum=sum+a[i][p];
    }
    printf("%d",sum);
}*/
/*
#include <stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100];
    int i=0,j=0,l1,l2,p;
    printf("enter string=");
    gets(a);
    l1=strlen(a);
    printf("enter substring=");
    gets(b);
    l2=strlen(b);
    while(a[i]!=' ')
    {
        i++;
        j++;
    }
    for(i=l1;i>=j;i--)
    {
        a[i+l2+1]=a[i];
    }
    for(i=0,p=j+1;b[i]!='\0';i++,p++)
    {
        a[p]=b[i];
        
    }
    puts(a);
}
     */
/*
#include<stdio.h>
#include<string.h>
void main()
{
    char a[100],k;
    printf("enter string=");
    gets(a);
   // printf("enter letter u want to search=");
    //scanf("%c",&k);s
    for(int i=0;a[i]!='\0';i++)
    { for(int j=i+1;a[j]!='\0';j++)
{
    if(a[i]>a[j])
        {
          char t;
          t=a[i];
          a[i]=a[j];
          a[j]=t;
        }
    }
    }
    puts(a);
}*/
/*
#include<stdio.h>
#include<string.h>
void main()
{
    char a[100],b[100];
    int i,j,l1,l2;
    printf("enter string=");
    gets(a);
    printf("enter substring=");
    gets(b);
    l1=strlen(a);
    l2=strlen(b);
    i=0;
    while(a[i]!=' ')
    {
        i++;
    }
    j=i;
    for(i=l1;i>=j;i--)
    {
    a[i+l2+1]=a[i];
    }
    for(i=0,j=j+1;b[i]!='\0';i++,j++)
    {
        a[j]=b[i];
    }
    puts(a);
}*/
/*
#include<stdio.h>
#include<string.h>
void insert( char [], char [], int );
void main()
{
    char a[100],b[100];
    int i,j,l1,l2,p;
    printf("enter string=");
    gets(a);
    printf("enter substring=");
    gets(b);
    l1=strlen(a);
    l2=strlen(b);
    i=0;
    printf("enter position unwant to insert=");
    scanf("%d",&p);
    for(i=l1;i>=p;i--)
  {
    a[i+l2]=a[i];
  
}
insert(a,b,p);
}
void insert(char x[100] , char y[100], int z)
{
    int i,j;
for(i=0,j=z;y[i]!='\0';i++,j++)
{
    x[j]=y[i];
}
puts(x);
}*/
/*
#include<stdio.h>
#include<string.h>
void main()
{
       char a[100],b[200];
       int in;
       printf("enter atrinhg=");
        gets(a);
        printf("enter index u want to change=");
        scanf("%d",&in);
        a[in]='$';
        puts(a);

}*/
/*
#include<stdio.h>
int point( int * , int*);
void main()
{
    int a,b,sum;
    scanf("%d%d",&a,&b);
    sum=point(&a,&b);
    printf("%d",sum);
    }
   int point( int *x,int *y)
    {       int s;
        s= *x + *y;
        return s;
    }*/
/*
    #include<stdio.h>
    #include<string.h>
    void main()
    {
       char a[200];
       gets(a);
       for(int i=0;a[i]!='\0';i++)
       {
              if( a[i]>=65 && a[i]<=90)
              {
                a[i]='$';
              }
              else if(a[i]>=97 && a[i]<=122)
              {
                a[i]='#';
              }
       }
       puts(a);
    }*/

/*
    #include<stdio.h>
    void main()
    {
        int a[12][10],i,j,m,n,sum=0,c;
        printf("enter no. of roiws and column");
        scanf("%d%d",&m,&n);
        printf("enter values=");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
               scanf("%d",&a[i][j]);
            }
        }
        printf("enter particular row=");
        scanf("%d",&c);
        sum=a[c][0];
        for(j=1;j<n;j++)
        {
            if(sum<a[c][j])
            {
                sum=a[c][j];
            }
        }
        printf("%d",sum);
    }
    /*
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {  if(i>j && a[i][j]%2==0)
            {  c++;
                sum=sum+a[i][j];
            }}}printf("%d",sum/c);
            printf("%d",sum);
        }*/

        /*
        #include<stdio.h>
        #include<string.h>
        void main()
        {int c;
            char a[100];
            printf("enter string=");
            gets(a);
            if(a[0]==' ')
             c=0;
            else 
            c=1;
        for(int i=0;a[i]!='\0';i++)
        {
            if(a[i]==' ' && a[i+1]!=' ')
            {
                a[i]=a[i+1];
            }
        }
        puts(a);
        }*/

        /*
        #include <stdio.h>

        void main() {
            char a[100];
            int i, j = 0;
        
            printf("Enter string: ");
            fgets(a, sizeof(a), stdin);  // Use fgets for safe input
        
            // Loop through the string
            for (i = 0; a[i] != '\0'; i++) {
                if (a[i] != ' ') {  // If the character is not a space, copy it
                    a[j++] = a[i];
                }
            }
        
            a[j] = '\0';  // Add the null terminator at the end of the modified string
        
            printf("Modified string: ");
            puts(a);  // Print the string without spaces
        }
        */
/*
        #include<stdio.h>
        void main()
            {
               char a[100];
               int i,n=0;
                printf("enter strinhg=");
                gets(a);
                for(i=0;a[i]!='\0';i++)
                {
                    if(a[i]!=' ' )
                    {
                        a[n++]=a[i];
                    }
                }
        a[n]='\0';
        puts(a);
        }*/
/*
        #include<stdio.h>
        void main()
        {
            char a[100];
            int n[256]={0},i,j;
            printf("enter zring=");
            gets(a);
            for(i=0;a[i]!='\0';i++)
            {
                n[a[i]]++;
            }
            for(i=0;i<256;i++)
            {
                if(n[i]>0)
                {
                    printf("%c=%d",i,n[i]);
                }
            }
        }*/

/*
        #include <stdio.h>

int main() {
    int r, c;
    
    // Input rows and columns
    printf("Enter number of rows: ");
    scanf("%d", &r);
    printf("Enter number of columns: ");
    scanf("%d", &c);
    
    // Declare the matrix
    int matrix[r][c];
    
    // Input matrix elements
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Enter element at [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Find the minimum element of each column
    printf("\nMinimum elements of each column:\n");
    for (int j = 0; j < c; j++) {
        int min = matrix[0][j]; // Assume the first element of the column is the minimum
        for (int i = 1; i < r; i++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
        printf("Minimum of column %d: %d\n", j, min);
    }
    
    return 0;
}
*/

/*
#include <stdio.h>
#include<string.h>
void main()
{
char t,s[20]="Graphic Era";
int i,l, j;
l=strlen(s);
for(i=0,j=l-1;i<j;i++,j--)
{ 
t=s[i];
s[i]=s[j];
s[j]=t;
}
printf("The string is: %s\n",s);
} */


/*
 #include <stdio.h>
void main()
{
int a[3] = {10, 20, 40};
int b[3]; 
b=a;
printf("%d", b[0]);
} *//*
 #include<stdio.h>
 void main()
 {
    int a[100][100],i,j,m;
    int flag=0;
    printf("enter size=");
     scanf("%d",&m);
     printf("enyer elemnts=");
     for(i=0;i<m;i++)
     {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);

        }
     }
     for(i=0;i<m;i++)
     {
        for(j=0;j<m;j++)
        {
            if(a[i][i]==1 && a[i][j]==0)
            {
                flag++;
            }
        }
     }
     if(flag==0)
     {
        printf("not");
     }
     else printf("yes");
 }*/
/*
 #include<stdio.h>
 #include<string.h>
 void main()
 {
    char c[100];
    gets(c);
    int i;
    for(i=0;c[i]!='\0';i++)
    {
        if(c[i]=='a')
        { c[i]='i';}
        else if (c[i]=='i')
        {
            c[i]='o';
        }
    }
    puts(c);
 }

*/
#include<stdio.h>
int swap(int *,int);
void main()
{
    int a[100],i,m;
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&a[i]);

    }
    swap(a,m);
    for(i=0;i<m;i++){
    printf("%d",a[i]);
}}

int swap(int *n , int m)
{  int i,j,t;
    for(i=0,j=i+1;i<m/2;i=i+2)
    {
        t= *(n[i]);
       * (n[i])= *(n[j]);
        *(n[j]) =t;
    }
}
