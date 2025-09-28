/*#include<stdio.h>
#define max 10
int main()
{
    int a[max][max],i,j,n;
    printf("enter rows ");
    scanf("%d",&n);
    printf("enter values of first matrix");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    // digonal elements
for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                printf("%d",a[i][j]);
            }
        }}
        // principal secondsry elements
        for(i=0,j=2;i<n;i++,j--)
        {
             printf("%d",a[i][j]);
        }
        // upper triangular diagonal elements
        for(i=0;i<n-1;i++)
          {
        for(j=0;j<n-1-i;j++)
        {
                printf("\n%d",a[i][j]);
            }
        }
        //lower triangular (i>j) diagonal elements  or upper triangular secondary (i<j) diagonal elements
        for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i<j)
            {
                printf("%d",a[i][j]);
            }
        }}
        // for lower triangular secondary elements
         for(i=1;i<n;i++)
          {
        for(j=n-i;j<n;j++)
        {
                printf("\n%d",a[i][j]);
            }
        } return 0;
        }

*/
/*
#include<stdio.h>
int main()
{
     int a[10][12],b[10][12],c[10][12],i,j,k,r1,c1,r2,c2;
     printf("enter no , of rows and column ");
     scanf("%d%d",&r1,&c1);
     printf("enter values");
     for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter values for r2 and c2");
    scanf("%d%d",&r2,&c2);
    printf("enter values");
      for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    if(c1==r2)
    {
         for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        { c[i][j]=0;
            for(k=0;k<c1;k++)
            {  
                c[i][j]+=a[i][k]*b[k][j];
            }

    }}}
for(i=0;i<r1;i++)
{
    for(j=0;j<c2;j++)
{
printf("%d\n",c[i][j]);
}}}

#include<stdio.h>
int main()
{
    int a[10][12],b[10][12],r,c,i,j,sum=0;
    printf("enter no. of rows and column");
    scanf("%d%d",&r,&c);
    printf("enter values");
    for(i=0;i<r;i++)
    {
     for(j=0;j<c;j++)
     {
            scanf("%d",&a[i][j]);
            }}
     printf("enter valuses of 2nd array");
     for(i=0;i<r;i++)
    {
     for(j=0;j<c;j++)
     {  scanf("%d",&b[i][j]);
     }}
     for(j=0;j<c;j++)
     {  sum+=a[j][j]+b[j][j];
     }       
     printf("%d",sum);
     return 0;
     }

     #include<stdio.h>
int main()
{
    int a[10][12],b[10][12],r,i,j,sum=0;
    printf("enter no. of rows and column");
    scanf("%d",&r);
    printf("enter values");
    for(i=0;i<r;i++)
    {
     for(j=0;j<r;j++)
     {
            scanf("%d",&a[i][j]);
            }}
    for(i=0,j=r-1;i<r;i++,j--)
    {
        printf("%d",a[i][j]);
    }        }

 #include<stdio.h>
float array(float a[10][12], float b[10][12], int r, int c  )
{
    int i,j;
    for(i=0;i<r;i++)
    {
     for(j=0;j<c;j++)
     {
            scanf("%f",&a[i][j]);
            }}
    printf("enter values for 2nd array");
    for(i=0;i<r;i++)
    {
     for(j=0;j<c;j++)
     {
            scanf("%f",&b[i][j]);
            }}}
  float sum(float a[10][12],float b[10][12],float d[10][12],int r,int c)
  {  int i,j;
   for(i=0;i<r;i++)
    {
     for(j=0;j<c;j++)
     { d[i][j]=a[i][j]+b[i][j]; 
     printf("%f",d[i][j]);
  }          }}
int main()
{
    float a[10][12],b[10][12],d[10][12];
    int c,r,i,j;
    printf("enter no. of rows and column");
    scanf("%d%d",&r,&c); 
    printf("enter values");
    array(a,b,r,c);
    sum(a,b,d,r,c);
    }
    


     #include<stdio.h>
int main()
{
    int a[10][12],r,c,i,j,n;
     printf("enter no. of rows and column");
    scanf("%d%d",&r,&c);
    printf("enter values");
    for(i=0;i<r;i++)
    {
     for(j=0;j<c;j++)
     {
            scanf("%d",&a[i][j]);
            }}
     for(i=0;i<c;i++)
    {
     for(j=0;j<r;j++)
     {   printf("%d",a[j][i]);
     }}}
#include<stdio.h>
void main()
 {int a[10][12],r,c,i,j,n=0,sum=0;
     printf("enter no. of rows and column");
    scanf("%d",&r);
    printf("enter values");
    for(i=0;i<r;i++)
    {
     for (j=0;j<r;j++)
     {
            scanf("%d",&a[i][j]);
            
            if(i==j)
            {    sum=sum+a[i][j];
               
            }
        }}
    
                printf("%d",sum);
                for(i=0,j=r-1;i<r;i++,j--)
                {
n=n+a[i][j];
                }
                printf("%d",n);

            }
        */
        /*
#include<stdio.h>
void main()
{
    int a[10][12],i,j,r,c,max,small;
    printf("enter no of rows and column ");
    scanf("%d%D",&r,&c);
    printf("enter vvalues");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
             
        }
    }
    max=a[0][0];
    small=a[0][0];
     for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {  
            if(max<a[i][j])
            {
                max=a[i][j];
            }
         if(small>a[i][j])
            {
                small=a[i][j];
            }
}        }
printf("%d%d",max,small);
}
*/
#include<stdio.h>
#include<string.h>
void main()
{
char str[30],a[20];
int i,c=0,k,j;
gets(str);
for(i=0;str[i]!='\0';i++)
{  if(str[i]!=' ')
    {
    a[c]=str[i];
    c++;
} 
else{
    a[c]='\0';
    if(c>=3)
    {
        puts(a);
    }
    c=0;}
}
if(c>3)
a[c]='\0';
puts(a);}

