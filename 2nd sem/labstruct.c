/*#include<stdio.h>
struct cricket
{
    char name[50],team[50];
    float avg;
};
void main()
{
    int n,i,j;
    printf("enter limit=");
    scanf("%d",&n);
    struct cricket x[n];
    printf("enter info=\n");
    for(i=0;i<n;i++)
    {
        printf("entr name and team name =");
        scanf("%s%s",x[i].name,x[i].team);
        getchar();
        printf("enter avg=");
        scanf("%f",&x[i].avg);
        getchar();
    }
    float tmp;
    for(i=0;i<n;i++)
    {
         for(j=i+1;j<n;j++)
        { 
             if(x[i].avg>x[j].avg)
             {
                tmp=x[i].avg;
                x[i].avg=x[j].avg;
                x[j].avg=tmp;
             }
        }
    }
    printf("%f",x[n-2].avg);

}*/
/*
#include<stdio.h>
#include<string.h>
struct emp{
    char name[50],desig[50];
    int id ,sal,yoj;
};
void main()
{
    int n,c=0,d;
    printf("enter n=");
    scanf("%d",&n);
    struct emp x[n];
    printf("ente details\n");
    for(int i=0;i<n;i++)
    {
        printf("enter name= && designation=");
        scanf("%s%s",x[i].name,x[i].desig);
        getchar();
        printf("enter id and sal and year o joining-");
        scanf("%d%d%d",&x[i].id,&x[i].sal,&x[i].yoj);
        getchar();

    }
    int i;
    for(i=0;i<n;i++)
    {
        if(strcmp(x[i].desig,"ACCOUNTANT")==0)
        {   puts(x[i].name);"\n";
            printf("%d \n",x[i].sal);
        }
        if(strcmp(x[i].desig,"MANAGER")==0)
        {
            x[i].sal=x[i].sal+(0.1*x[i].sal);
        }
        if(x[i].yoj>2012)
        {
            c++;
        }
        d=2025-x[i].yoj;
        if(d>12)
        {
            puts(x[i].name);"\n";
            x[i].sal=x[i].sal+15000;
        }
    }
    printf("c=%d\n",c);
    for(i=0;i<n;i++)
    {
        puts(x[i].name);"\n";
        printf("%d %d ",x[i].id,x[i].sal);
    }
}
*/
/*
#include<stdio.h>
struct student{
    char name[50],gender;
    int id,mark;

};
void main(){

    int n,i;
    printf("enter id=");
    scanf("%d",&n);
    struct student x[n];
    
        for(i=0;i<n;i++)
    {
        printf("enter name= ");
        scanf("%s",x[i].name);
        getchar();
        printf("enter gender in M or F=");
        scanf("%c",&x[i].gender);
        getchar();
      printf("enter roll no. and mrks=");
     scanf("%d%d",&x[i].id,&x[i].mark);  
      getchar();
    }
    int m=0,f=0;
    for(i=0;i<n;i++)
{
    if(x[i].mark>80)
    {
        puts(x[i].name);
    }
    if(x[i].gender=='M')
    {
        m++;
    }
    else if(x[i].gender=='F')
    {    f++;

    }
}

printf("%d%d",m,f);
}*/
/*
#include<stdio.h>
#include<string.h>
struct book
{
    char name[50],publisher[50],author[50];
    int price;
};

void main()

{
    int n,i;
    printf("enter limit=");
        scanf("%d",&n);
       struct book x[n];
       for(i=0;i<n;i++)
       {
        printf("enter all details=");
        scanf("%s%s%s",x[i].name,x[i].publisher,x[i].author);
        getchar();
        printf("enter price=");
        scanf("%d",&x[i].price);
      getchar();

    
    } 
char pub[50];
printf("enter publisher name=");
gets(pub);
int c=0,j=0;
int max=x[0].price;
for(i=0;i<n;i++)
{
    if(strcmp(x[i].publisher,pub)==0)
    {
        c++;
    }
    if(max>x[i].price)
    {
        j=i;
    }
}
puts(x[j].name);
printf("%d",c);


}*/
/*
#include<stdio.h>
struct info{
    char name[50],dep[50],course[50];
        int roll,yoj;
};
void year( struct info y[],int z)
{
int i;
for(i=0;i<z;i++)
{
    if(y[i].yoj==2013)
    {
        puts(y[i].name);
    }
}
}
  

void range( struct info y[],int x,int a, int b)
{
int i;
for(i=0;i<x;i++)
{
    if(y[i].roll>=a && y[i].roll<=b)
    {
        puts(y[i].name);
    }
}
}


void main()



{

int n,i;
printf("enter limit=");
scanf("%d",&n);
struct info x[n];
for(i=0;i<n;i++)
{
    printf("enter details =");
    scanf("%s%s%s",x[i].name,x[i].dep,x[i].course);
    getchar();
    printf("enter roll and joinging=");
    scanf("%d%d",&x[i].roll,&x[i].yoj);
    getchar();
}
year(x,n);
int r1,r2;
printf("ente rrange in r1 and r2");
scanf("%d%d",&r1,&r2);
range(x,n,r1,r2);



}*/

#include <stdio.h>
#include <string.h>

struct employee {
    char emp_name[50];
    int emp_ID;
    char address[100];
};

int main() {
    int n, i, j;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct employee emp[n], temp;

    // Input employee details
    for (i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);

        printf("Enter name: ");
        scanf("%s", emp[i].emp_name);  // Note: names with spaces won't work

        printf("Enter ID: ");
        scanf("%d", &emp[i].emp_ID);

        printf("Enter address: ");
        scanf(" %[^\n]", emp[i].address);  // To accept full line with spaces
    }

    // Sort based on emp_name (alphabetical order)
    for (i = 0; i < n ; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(emp[i].emp_name, emp[j].emp_name) > 0) {
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }

    // Display sorted employee records
    printf("\nSorted Employee Records (by Name):\n");
    for (i = 0; i < n; i++) {
        printf("Name: %s\n", emp[i].emp_name);
        printf("ID: %d\n", emp[i].emp_ID);
        printf("Address: %s\n", emp[i].address);
        printf("---------------------------\n");
    }

    return 0;
}
