/*#include<stdio.h>
struct student {
    char name[50];
    int id;
    float per;
    struct marks 
    {  int m[3];
    }y;

};
void main()
{
   int i,j,n;
   printf("enter n=");
   scanf("%d",&n);
   struct student x[n];
   getchar();
   for(i=0;i<n;i++)
   {    int sum=0;
      printf("enter name=");
      fgets(x[i].name,sizeof(x[i].name),stdin);
      printf("enter id=");
      scanf("%d",&x[i].id);
      getchar();
      printf("enter marks=");
       for(j=0;j<3;j++)
      { 
              scanf("%d",&x[i].y.m[j]);
              getchar();
                sum=sum+x[i].y.m[j];
      }
      x[i].per=sum/3; 
}
for(i=0;i<n;i++)
{
    if(x[i].per>80)
    {
        "\n";puts(x[i].name);
        printf("%d\n",x[i].id);
        printf("%.2f\n",x[i].per);
    }
}
}
*/
/*
#include<stdio.h>
struct info
{
    char name[50];
    int id;
    float sal;

};
void main()
{
    int n,i;
    printf("total no. of employees=-");
   scanf("%d",&n);
      struct info x[n];
      getchar();
      for(i=0;i<n;i++)
      {
        printf("enter name=");
        gets(x[i].name);
        printf("enter id=");
        scanf("%d",&x[i].id);
        //getchar();
        printf("enter salary=");
        scanf("%f",&x[i].sal);
       // getchar();

      }
      float max=x[0].sal;
      int j;
      for(i=0;i<n;i++)
      {
        if(max<x[i].sal)
        {
            max=x[i].sal;
             j=i;
        }
      }
      puts(x[j].name);
      printf("%d",x[j].id);
}

*/
/*
#include<stdio.h>
struct emp{
    char name[50];
    int id;
    float sal;
    struct doj
    {
        int d,m,y;
    }l;
};
void main()
{
    int n,i,j;
    printf("enter total no. of employees=");
    scanf("%d",&n);
    getchar();
    struct emp x[n];
    printf("enter details\n");
    for(i=0;i<n;i++)
    {
        printf("enter name=");
      gets(x[i].name);
       //etchar();
        printf("enter id and salary= ");
        scanf("%d%f",&x[i].id,&x[i].sal);
        getchar();
        printf("enter date of joining (in dd/mm/yy) format=");
        scanf("%d%d%d",&x[i].l.d ,&x[i].l.m,&x[i].l.y);
        getchar();

    }
    for(i=0;i<n;i++)
    {
        if(x[i].l.y<2000)
        {
         printf("%s",x[j].name);
        }
    }
}*/
/*
#include<stdio.h>
struct emp{
    char name[50];
    int id;
    float sal;
};
void class( float , int );
void main()
{
    int n,i;
    printf("enter n=");
    scanf("%d",&n);
    struct emp x[n];
    getchar();
    for(i=0;i<n;i++)
    {
        printf("enter name=");
        fgets(x[i].name,sizeof(x[i].name),stdin);
        printf("enter id and salary=");
        scanf("%d%f",&x[i].id,&x[i].sal);
        getchar();
    }
    for(i=0;i<n;i++)
    {
        puts(x[i].name);
        class(x[i].sal,n);
    }
}

void class(float y , int x)
{ 
        if(y<=10000)
        {
            printf("lower slab");

        }
         else if(y<=20000)
         {
            printf("middle slab");
         }
         else {
            printf("higher slab");
         }
    }
*/