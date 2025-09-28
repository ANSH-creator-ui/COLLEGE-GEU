/*#include<stdio.h>
void main()
{
    int c;
    for(c=0;c<=256;c++)
    {printf("\n%d-%c",c,c);
    }
}*/
/*
#include<stdio.h>
int main()
{
    int n,c=2;
    printf("enter the value of n=");
    scanf("%d",&n);
    for(c=2;c<=n;c+=2)
    { 
        printf("\n%d",c);

    }
}*/
/*
#include<stdio.h>
void main()
{
    char ch;
    printf("enter the value of character =");
    scanf("%c",&ch);
    if(ch=='a' || ch=='A'|| ch=='E'|| ch=='e' || ch=='I'|| ch=='i'|| ch=='U'||ch=='u'||ch=='O' || ch=='o')
    { printf("vowel");
    }
    else{
        printf("constant");

    }
}*/

/*
#include<stdio.h>
void main()
{
    int n,vc=0,c=1;
    char ch;
    printf("ente rthe value of n=");
    scanf("%d",&n);
    while(c<=n)
    {
      printf("enter the value of character =");
        scanf("%c",&ch);
     if(ch=='a' || ch=='A'|| ch=='E'|| ch=='e' || ch=='I'|| ch=='i'|| ch=='U'||ch=='u'||ch=='O' || ch=='o')
    {
        vc=vc+1;

    }
    c++;
    }
    printf("%d",vc);


    }*/


   #include<stdio.h>
void main()
     {
        int a,c=1,s=1,t=0;
        printf("enter the  value of a=");
        scanf("%d",&a);
        while(c<=a)
        {
           s=s*c+t;
           c++;
           t++;

         }
         printf("%d",s);
         printf("%d",t);        }
#include<stdio.h>
int main()

{
   char a[100];
    int i,vc=0,n;
    printf("enter limit");
    scanf("%d",&n);
    printf("enter characters =");
    for( i=0;i<n;i++)
    {scanf("%s",&a[i]);}
     for( i=0;i<n;i++)
    {printf("%c",a[i]);}
   for(i=0;i<n;i++)
    {
          if (a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o'  || a[i]=='u' )
          {
            vc++;
          }
    }
     
printf("%d",vc);
return 0;
}