//lower traingular matrix
/* #include<stdio.h>
int main()
{
    int a[100][100],i,j,n;
    printf("enter n size");
    scanf("%d",&n);
    printf("enter values");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {  if(i<j)  //for uppper triangular matrix i>j;       
                 {
                a[i][j]=0;
            }
         printf("%d",a[i][j]);
        }}

#include<stdio.h>
#include"merge.c"
#include"out.c"
int main()
{
    int a[100][100],i,j,n;
     input(a,n);
     output(a,n);
     return 0;
}
    */
/*
#include<stdio.h>
void main()
{
    int m,n,i,j;
    printf("enter no. of rows and column");
    scanf("%d%d",&m,&n);
    int a[m][n],b[m*n],r=0,k=0,temp;
    printf("enter values");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            b[r]=a[i][j];
            r++;
        }
}
for(i=0;i<n*m;i++)
{
    for(j=i+1;j<m*n;j++)
{
    if(b[i]>b[j])
    {
        temp=b[j];
        b[j]=b[i];
        b[i]=temp;
    }
}}
for(i=0;i<n*m;i++)
{
    printf("\n%d",b[i]);
}
for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {
        a[i][j]=b[k];
        k++;
        printf("\n%d",a[i][j]);

    }
}}*/

#include<stdio.h>
void main()
{
    int i,j,e=0,n;
    printf("enter no. of rows and column");
    scanf("%d",&n);
    int a[n][n];
    printf("enter elements");
    for(i=0;i<n;i++)
     {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);

        }
     }
     for(i=0;i<n;i++)
     {
        for(j=0;j<n;j++)
        {
            if(i!=j && a[i][j]==0)
            {
              e++;
            
            }
        }}
        printf("count=%d",e);
    if(e==n*n-n)
    {
        printf("\nThe matrix is a diagonal matrix");
    }  
    else{
       printf( "\nThe matrix is not a diagonal matrix");
    }
        
}
    