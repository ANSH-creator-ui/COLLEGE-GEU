/*#include<stdio.h>
#include<string.h>
#include"merge.c"
void main()
{   char a[50],b[50];
     input(a);
    printf("enter 2nd string");
    fgets(b,sizeof(b),stdin);
    int flag=0;
    input(a);
    for(int i=0;a[i]!='\0';i++)
    {
        if(b[i]!=a[i])
      {  flag=1;
      break;}
        
    }
    if (flag==0)
    printf("equal");
  else printf("not equal");
}*/
/*

#include<stdio.h>
#include<string.h>
#include"merge.c"
void main()
{ 
  char a[50],c[100];
  int i,j,temp,flag=0;
  input(a);
  //strcpy(c,a);
  for(i=0,j=strlen(a)-1;i<strlen(a)/2;i++,j--)
{  //temp=a[j];   
    //a[j]=a[i];
    //a[i]=temp;
    if(a[i]!=a[j])  
    flag=1;
    break;
  }
/*for(i=0;c[i]!='\0';i++)
{
  if(c[i]!=a[i])
  flag=1;
break;
}
if (flag==0)
{printf("palindro,e");}
else{ printf("not equal");}
}
*/
//copy
/*
#include<string.h>
#include<stdio.h>
#include"merge.c"
void main()
{
   char a[50],b[50];
   int i;
   input(a);
   for(i=0;a[i]!='\0';i++)
   {
      b[i]=a[i];
  
   }
   b[i]='\0';
   puts(b);
}*///concatinate
/*
#include<stdio.h>
#include<string.h>
#include"merge.c"
void main()
{
   char a[50],b[50];
   input(a);
   printf("enter 2nd string");
   gets(b);
   int i,l;
   l=strlen(b);
   for(i=0;b[i]!='\0';i++)
   {
       b[i+l]=a[i];
   }
   b[i+l]='\0';
   puts(b);



}*/
///TOGLE FORM
/**
#include<stdio.h>
#include<string.h>
#include"merge.c"
void main()
{
  char a[50];
  input(a);
  int i;
  for(i=0;a[i]!='\0';i++)
  {
    if(a[i]>=65 && a[i]<=90)
    {
      a[i]=a[i]+32;
    }
    else if( a[i]>=97 && a[i]<=122)
    {
      a[i]=a[i]-32;
    }
  }
  puts(a);
}*/
///check for vowels consonants and special characters 
/*#include<stdio.h>
#include<string.h>
void main()
{c



#include<stdio.h>
void main()
{
   char a[50],b[50;
  int i,l=0,d;
  printf("enter string=");
  fgets(a,sizeof(a),stdin);
  if(a[0]==0)
   l=0;
  else l=1;
  printf("enterposition and string" );
  printf("%c",temp);
  printf("enter posiotn=");
  
  for(i=l-1;i>j;i--)
  {
    if(a[i]==32 && a[i+1]!=32)
    {l=1;}
    if(l)

  }
}*/

// WORD COUNT IN A SETENCE
/*
#include<stdio.h>
#include<string.h>
void main()
{
  char ch[100];
  int i,j=0;
  fgets(ch,sizeof(ch),stdin);
  if(ch[0]==' ')
  j=0;
else
j=1;
  for(i=0;ch[i]!='\0';i++)
 { if(ch[i]==' ' && ch[i+1]!=' ' )
  {
    j++;
  }

}
printf("%d",j);
}*/

