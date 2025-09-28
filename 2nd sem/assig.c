/*#include<stdio.h>
#include<string.h>
void string(char ch)
{
    switch(ch)
    {   default     choice: printf("einvalid");break;
        case '1':printf("one ");
        break;
        case '2': printf("two ");
        break;
        case '3':printf("three ");
        break;
        case '4':printf("four ");
        break;
        case '5':printf("five ");
        break;
        case '6':printf("six ");
        break;
        case '7':printf("seven ");
        break;
        case '8':printf("eight ");
        break;
        case '9':printf("nine ");
        break;
        case '0':printf("zero ");
        break;   
    }
}
void main()
{
    char a[100];
    int i;
    printf("enter string=");
    gets(a);
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]>=48 && a[i]<=57)
        {
            string(a[i]);
        }
        else
        {
           putchar(a[i]);
        }
    }
}
*/
/*
#include<stdio.h>
void main()
{
    int a[100][100],i,j,m,n,flag=0;
    printf("enter no. of rows and column=");
    scanf("%d%d",&m,&n);
    printf("enter elements=");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==0)
            {
                flag++;
            }
        }
    }
    if(flag>(m*n)/2)
    {
        printf("Sparse Matrix");
    }
    else{
        printf("Not a Sparse Matrix");
    }
}*/
/*
#include<stdio.h>
void main()
{
    int a[100][100],i,j,m,n,x,y,temp;
    printf("enter no. of rows and column=");
    scanf("%d%d",&m,&n);
    printf("enter elements=");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter Row 1 index & Row 2 index:");
    scanf("%d%d",&x,&y);
    for(j=0;j<n;j++)
    {   temp=a[y][j];
        a[y][j]=a[x][j];
        a[x][j]=temp;
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",a[i][j]);
        }
    }
}

*/    
  #include<stdio.h>
void main()
{
    int a[10][20],i,j,n,m,max;
    printf("enter no. of row:");
    scanf("%d",&n);
    printf("enter no. of column:");
    scanf("%d",&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
   
    for(j=0;j<m;j++)
    {
        max=a[0][0];
        for(i=0;i<n;i++)
        {
            if(max<a[i][j])
            {
                max=a[i][j];
            }
        }
        printf("maximum of column %d:%d\n",j+1,max);
    }
}
    /*
    #include<stdio.h>
    void main()
    {
       int a[100],b[100],c[100],i,*p,j,m,n;
       int k=0;
       printf("enter limit for a & b array:");
       scanf("%d%d",&m,&n);
       printf("enter elements=");
       for(i=0;i<m;i++){
        scanf("%d",&a[i]);
       }
       printf("enter elements for 2nd array:");
       for(i=0;i<n;i++)
       {
        scanf("%d",&b[i]);
       }
      p=a;
      int *l=b;
      int *t=c;
       for(i=0;i<m;i++)
       {  for(j=0;j<n;j++)
        {
           if(*(p+i)==*(l+j))
           {  
               c[k]=*(l+j);
               
                 k++;
           }          
       }}
       for(i=0;i<k;i++)
       {
        printf("%d",*(t+i));
       }
    }
    */