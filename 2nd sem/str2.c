#include<stdio.h>
#include<string.h>
void main()
//TO PUT A SUBSTRING BETWEEN THE FIRST STRING
/*{
    char a[100],b[100];
    int i,j,l1,l2,sp=0;
    printf("enter string=");
    gets(a);
    printf("enter second string=");
    gets(b);
    l1=strlen(a);
    l2=strlen(b);
    for(i=0;a[i]!=' ';i++)
    {
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
//COUNT A OCCURANCE OF PARTICULAR CHARACTER
  {
     char a[100],temp;
     printf("enter string=");
     gets(a);
     printf("enter character u want to search=");
     scanf("%c",&temp);
     int j=0;
     for(int i=0;a[i]!='\0';i++)
     {
        if(a[i]==temp)
        {
            
            j++;
        }
     }
     printf("%c=%d",temp,j);


  }*/

/*
  {
    char a[100],b[100];
    int i,j,l1,l2,sp;
    printf("enter string=");
    gets(a);
    printf("enter second string=");
    gets(b);
    l1=strlen(a);
    l2=strlen(b);
    printf("enter position u want to search=");
    scanf("%d",&sp);
    for(i=l1;i>=sp;i--)
    {
      a[i+l2]=a[i];
    }  
    for(i=0,j=sp;b[i]!='\0';i++,j++)
    {
        a[j]=b[i];
    }
    puts(a);
  }*/

  
// TO CHECK THE OCCURANCE OF EVERY CHARACTER IN A STRING
  {
       char a[100];
       printf("enter string=");
      // fgets(a,sizeof(a),stdin);
      gets(a);
       int count[256]={0};
       for(int i=0;a[i]!='\0';i++)
       {
           count[a[i]]++;
               }
       for(int i=0;i<256;i++)
       {  if(count[i]>0)
        {
        printf("%c:%d\n",i,count[i]);
}}}
/*
       // ASCII VALUES
       {
         int i;
         for(char ch='a';ch<='z';ch++)
         printf("\n%c:%d",ch,ch);
        for(char ch='A';ch<='Z';ch++)
        printf("\n%c:%d",ch,ch);
       }*/