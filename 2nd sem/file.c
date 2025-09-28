#include<stdio.h>
void main()
{
    FILE *fp;
    fp=fopen("hello.txt","w+");
    char ch;
    printf("enter wordds=");
    while((ch=getchar())!=EOF)
    {
        putc(ch,fp);
    }
    rewind(fp);
    while((ch=getc(fp))!=EOF)
    {
        putchar(ch);
    }
    fclose(fp);
}
/*
#include<stdio.h>
void main()
{
    FILE *ip;
    ip=fopen("hello.txt","w+");
    char ch;
    int c=0;
    while((ch=getchar())!=-1)
{
     putc(ch,ip);

}
rewind(ip);
while((ch=getc(ip))!=-1)
{
   if(ch=='a' || ch=='e' || ch=='i' ||ch=='u' || ch=='o')
   {  c++;
    
}}
fclose(ip);
printf("the vowels are =%d",c);

}*/
/*
#include<stdio.h>
int fact(int x)
{
    int f=1,i;
    for(i=2;i<=x;i++)
    {
        f=f*i;

    }
    return f;
}
void main()
{
    int n,num;
    FILE *op;
    op=fopen("int.txt","w+");
    printf("enter n=");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num);
        putw(num,op);
    }
    rewind(op);
    FILE *fp=fopen("fact.txt","w+");
    while((num=getw(op))!=EOF)
{
    putw(fact(num),fp);

}
rewind(fp);
rewind(op);
while((num=getw(op))!=-1)
{
    printf("integer no=%d",num);
}
while((num=getw(fp))!=-1)
{
printf("fact=%d",num);
}
fclose(op);
fclose(fp);
}*/


/*
#include<stdio.h>
void main()
{
    int num,i,n;
    FILE *op=fopen("no.txt","w+");
    FILE *ev=fopen("even.txt","w+");
    FILE *odd=fopen("odd.txt","w+");
    printf("enter total no. limit=");
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
        scanf("%d",&num);
        putw(num,op);
     }
     rewind(op);
     while((num=getw(op))!=-1)
        {
            if(num%2==0)
            {
                putw(num,ev);

            }
            else
            {
                putw(num,odd);

            }
        }
        rewind(op);
        rewind(ev);
        rewind(odd);
        while((num=getw(op))!=-1)
        {
            printf("\n%d",num);
        }
        fclose(op);
         while((num=getw(ev))!=-1)
        {
            printf("\n%d",num);
        }
        fclose(ev);
         while((num=getw(odd))!=-1)
        {
            printf("\n%d",num);
        }
        fclose(odd);

}*/
/*
#include<stdio.h>
void main()
{
    FILE *op=fopen("inventory.txt","w+");
    char name[50];
    int quan;
    float price;
    int n;
    printf("enter total no. of customer=");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter name== && enter quantnity && price=");
        scanf("%s%d%f",name,&quan,&price);
       fprintf(op,"%s%d%f",name,quan,price);

    }
    rewind(op);
    for(int i=0;i<n;i++)
    {
        fscanf(op,"%s%d%f",name,&quan,&price);
       //S rewind(op);
        printf("%s%f",name,quan*price);
    }
    ftell(op);
    fclose(op);

}*/
/*
#include<stdio.h>
struct info
{
    char x[20];
    int i;
};
void main()
{
 struct info a;
 FILE *op=fopen("struct.txt","w+");
 printf("enter string and int vslie=");
 scanf("%s%d",a.x,&a.i);
 fwrite(&a,sizeof(struct info),1,op);
 rewind(op);
 fread(&a,sizeof(struct info),1,op);
 printf("%s%d",a.x,a.i);
 fclose(op);

}*/
/*
#include<stdio.h>
struct info
{
    char x[20];
    int y;
};
void main()
{
    int i;
    struct info A[2],B[2];
    FILE *fp;
    fp=fopen("data.txt","w+");
    for(i=0;i<2;i++)
    {
        scanf("%s%d",A[i].x,&A[i].y);
    }
    fwrite(&A,sizeof(struct info),2,fp);
rewind(fp);
fread(&B,sizeof(struct info),2,fp);
for(i=0;i<2;i++)
{
    printf("%s%d",B[i].x,B[i].y);
}
fclose(fp);
}*/
/*
#include<stdio.h>
void main()
{
    char ch;
    FILE *fp=fopen("rev.txt","w+");
    printf("enter chracters=");
    while((ch=getchar())!=EOF)
    {
        putw(ch,fp);
    }
    int c=ftell(fp);
    fseek(fp,-1,2);
    while(c>=1)
    {
        putchar(getc(fp));
       // fseek(fp,-2,1);
        c--;
    }
}v#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[] = "data.txt";
    char ch;
    long file_size, pos;

    // Open file for writing
    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    printf("Enter characters (press Enter then Ctrl+D or Ctrl+Z to end input):\n");
    while ((ch = getchar()) != EOF) {
        fputc(ch, fp);
    }
    fclose(fp);

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    // Get file size
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    pos = file_size - 1;

    printf("\nReversed content:\n");

    // Read file in reverse using while loop
    while (pos >= 0) {
        fseek(fp, pos, SEEK_SET);
        ch = fgetc(fp);
        putchar(ch);
        pos--;
    }

    fclose(fp);
    return 0;
}
*/
/*
#include<stdio.h>
void main()
{
    FILE *fp=fopen("wp.txt","w+");
    char ch;
    printf("enter characters=");
    while((ch=getchar())!=EOF)
{
    putc(ch,fp);

}
//rewinfd(fp);
int c=ftell(fp);
fseek(fp,-1,2);
while(c>=1)
{
    putchar(getc(fp));
    fseek(fp,-2,1);
    c--;

}
}*/
