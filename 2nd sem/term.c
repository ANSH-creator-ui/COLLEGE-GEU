#include<stdio.h>
#include<string.h>
void main()
{
    char set[100],aman[100],swati[100];
    int i,count1=0,count2=0;
    int count1[256]=0,count2[256]=0,count3[256]=0;
    printf("enter set of alphabets=");
    scanf("%s",set);
    printf("aman word=");
    scanf("%s",aman);
    printf("enter swati word=");
    scanf("%s",swati);
    for(i=0;set[i]!='\0';i++)
    {
        count1[set[i]]++;
    }
    for(i=0;aman[i]!='\0';i++)
    {
        count2[aman[i]]++;
        
    }
    for(i=0;swati[i]!='\0';i++)
    {
        count3[swati[i]]++;
    }
    for(i=0;i<256;i++)
    {
        if(count1[i]!=count2[i])
        {
        count1=1;
    
        }
    }
    for(i=0;i<256;i++)
    {
          if(count1[i]!=count3[i])
          {
            count2=1;
          }
    }
    if(count1==0 && count2==0)
    {
        printf("both are winners");

    }
    else{
        printf("one of you is winner");
    }
}