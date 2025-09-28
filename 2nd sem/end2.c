/*#include<stdio.h>
int max(int *x, int y)
{
    int m,i;
    m=*x;
    for(i=0;i<y;i++)
    {
        if(m<*(x+i))
    {
        m=  *(x+i);
    }    }
return m;
}
void main()
{
     int n,a[100]={0};
     printf("enter limit=");
     scanf("%d",&n);
     int i,*x;
     printf("enter values=");
     for(i=0;i<n;i++)
     {
        scanf("%d",&a[i]);

     }
     printf("%d",max(a,n));
}*/

/*
#include<stdio.h>
void reverse(int *x , int y)
{
    int i,j,tmp;
    for(i=0,j=y-1;i<y/2;i++,j--)
    {
        tmp=*(x+i);
        *(x+i)=*(x+j);
        *(x+j)=tmp;
    }
}
void main()
{
    int n,i;
    printf("enter limit=");
    scanf("%d",&n);
    int a[n];
    printf("enter values=");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    reverse(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}*/
/*
#include<stdio.h>
void sort(int *u, int y)
{
int i,j,tmp;
for(i=0;i<y;i++)
{
    for(j=i+1;j<y;j++)
    {
        if(*(u+i)<*(u+j))
        {   
            tmp=*(u+i);
            *(u+i)=*(u+j);
            *(u+j)=tmp;
        }
    }
}
}

void main()
{
    int n,i;
    printf("enter limit=");
    scanf("%d",&n);
    int a[n];
    printf("enter values=");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}*/

/*
#include<stdio.h>
void main()
{
    int n,*x,i,j;
    printf("enter limit=");
    scanf("%d",&n);
    int a[100];
    x=a;
    printf("enter valies=");
    for(i=0;i<n;i++)
    {
        scanf("%d",x+i);

    }
    int index,k;
    printf("enter index and no =");
    scanf("%d%d",&index,&k);
    for(i=n-1;i>=index;i--)
    {
        *(x+i+1)=*(x+i);

    }
   // x=a;
    *(x+index)=k;
 for(i=0;i<n+1;i++)
    {
        printf("%d ",*(x+i));
    }   

}*/
/*
#include<stdio.h>
#include<string.h>
void main()
{
    char name[50],tmp;
    printf("enter name=");
    gets(name);
    int l=strlen(name);
    printf("%d\n",l);
    for(int i=0,j=l-1;i<j;i++,j--)
    {
            tmp=name[i];
            name[i]=name[j];
            name[j]=tmp;
    }
    puts(name);
}*/
/*
#include<stdio.h>
#include<string.h>
void main()
{
    char name[50];
    printf("enter name in upper case=");
    gets(name);
    int i;
    for(i=0;name[i]!='\0';i++)
    {
        if(name[i]>=65 && name[i]<=91)
        {
            name[i]=name[i]+32;
        }

    }
    puts(name);
}*/
/*
#include<stdio.h>
#include<string.h>
void main()
{
    char a[50],tmp;
    printf("enter string=");
    gets(a);
    int l=strlen(a);
    int i,j,c=0;
    for(i=0,j=l-1;i<l/2;i++,j--)
    {
        if(a[i]!=a[j])
        {
            c++;
            break;
        }
    }
    if(c==0)
    printf("string is palindrome");
        else
    printf("not a palinjdrome");
}*/
/*
#include<stdio.h>
#include<string.h>
void main(){
    char a[50];
    printf("enter name=");
    gets(a);
    int i;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]<=90 && a[i]>=65)
        {
            a[i]=a[i]+32;
        }
        else if(a[i]>=97 && a[i]<=122)
        {
            a[i]=a[i]-32;
        }
    }
    puts(a);
}*/
/*
#include<string.h>
#include<stdio.h>
void main()
{
    char a[50];
    int i,c=0;
    printf("enter name=");
    gets(a);
    int l=strlen(a);
    if(a[0]==' ')
    c=0;
else 
c=1;
putchar(a[0]);
   for(i=0;a[i]!='\0';i++)
   {
          if(a[i]==' ' && a[i+1]!=' ' )
          { putchar(a[i+1]);
            c++;
          }
   }
printf("%d",c);}
*/

#include<stdio.h>
#include<string.h>
void main()
{
    char a[50];
    int i,l ;
    printf("enter string of two words=");
    gets(a);
    l=strlen(a);
    char b[50];
    printf("enter insert string=");
    gets(b);
    int c=0;
    int l2=strlen(b);
    i=0;
    while(a[i]!=' ')
    {
        i++;
        c++;
    }
    for(i=l;i>=c;i--)
    {
     a[i+l2+1]=a[i];
        }
        int j;
        for(i=0,j=c;b[i]!='\0';i++,j++)
        {
            a[j]=b[i];

        }
    printf("%s",a);
    }