/*#include <stdio.h>
int main()
{
    FILE *fp=fopen("a.txt","r");
    FILE *fo=fopen("b.txt","r");
    char ch1,ch2;
    if(fp==NULL && fo==NULL)
    {    printf("erroe opening file\n");     
        return 1;
    }
    while((ch1=getc(fp))!=EOF && (ch2=getc(fo))!=EOF)
    {
        if(ch1!=ch2)
        {
            return 1;
            fclose(fp);
            fclose(fo);
        }
    }
    if(feof(fp) && feof(fo))
    {
   
        fclose(fp);
        fclose(fo);
             return 0;

    }
}*/
/*
#include<stdio.h>
void main()
{
    FILE *fp=fopen("a.txt","w+");
    FILE *f=fopen("b.txt","w+");
    int n,i,n1;
    printf("enter limit=");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&n1);
        putw(n1,fp);

    }
    rewind(fp);
   
    while((n1=getw(fp))!=EOF)
    {    int s=0;    
         while(n1>0)
        {
            s=s*10+n1%10;
            n1=n1/10;
        }
        putw(s,f);
            
    }
    rewind(f);
    while((n1=getw(f))!=EOF)
{
    printf("%d ",n1);

}
fclose(f);
fclose(fp);
}*/
/*
#include<stdio.h>
void main()
{
    FILE *fp=fopen("mixed.txt","w+");
    FILE *fi=fopen("alpha.txt","w+");
    FILE *fo=fopen("num.txt","w+");
    FILE *f=fopen("spec.txt","w+");
    char ch;
    while((ch=getchar())!=EOF)
    {
        putc(ch,fp);
    }
    rewind(fp);
     while((ch=getc(fp))!=EOF)
    {
        if(ch>='A' && ch<='Z' || ch>='a' && ch<='z')
        {
            putc(ch,fi);
        }
        else if(ch>='0' && ch<='9')
        {
            putc(ch,fo);
        }
        else{
            putc(ch,f);
                }
    }
    rewind(fp);
    rewind(fi);
    rewind(fo);
    rewind(f);
    while((ch=getc(fi))!=EOF)
    {
        printf("%c ",ch);
    }
    while((ch=getc(fo))!=EOF)
    {  printf("%c ",ch);
    }
    while((ch=getc(f))!=EOF)
    {
        printf("%c ",ch);
    }
    fclose(fp);
    fclose(fi);
    fclose(fo);
    fclose(f);
}
*/

/*#include <stdio.h>

void main() {
    FILE *fp = fopen("mixed.txt", "w+");
    FILE *f_alpha = fopen("alpha.txt", "w+");
    FILE *f_digit = fopen("num.txt", "w+");
    FILE *f_special = fopen("spec.txt", "w+");
    char ch;

    if (fp == NULL || f_alpha == NULL || f_digit == NULL || f_special == NULL) {
        printf("Error opening files.\n");
        return;
    }

    // Input characters and write to mixed.txt
    printf("Enter characters (end with #): ");
    while ((ch = getchar()) != '#') 
        fputc(ch, fp);
    }

    rewind(fp); // Reset pointer to start reading from the beginning

    // Separate characters into different files
    while ((ch = fgetc(fp)) != EOF) {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            fputc(ch, f_alpha);
        } else if (ch >= '0' && ch <= '9') {
            fputc(ch, f_digit);
        } else {
            fputc(ch, f_special);
        }
    }

    // Print contents of all three files
    rewind(f_alpha);
    rewind(f_digit);
    rewind(f_special);

    printf("\nAlphabets: ");
    while ((ch = fgetc(f_alpha)) != EOF) {
        printf("%c ", ch);
    }

    printf("\nDigits: ");
    while ((ch = fgetc(f_digit)) != EOF) {
        printf("%c ", ch);
    }

    printf("\nSpecial characters: ");
    while ((ch = fgetc(f_special)) != EOF) {
        printf("%c ", ch);
    }

    // Close all files
    fclose(fp);
    fclose(f_alpha);
    fclose(f_digit);
    fclose(f_special);
}
*/

/*
#include<stdio.h>
void main()
{
    FILE *fp=fopen("l.txt","w+");
    FILE *f=fopen("i.txt","w+");
    char ch;
    while((ch=getchar())!=EOF)
{
    putc(ch,fp);
}
rewind(fp);
while((ch=getc(fp))!=EOF)

{
    if(ch>=65 && ch<=92)
    {
        ch=ch+32;
        putc(ch,f);
    }
}
rewind(f);
while((ch=getc(f))!=EOF)
{
    printf("%c",ch);

}
fclose(fp);
fclose(f);
}*/
/*
#include <stdio.h>

int main() {
    FILE *f1, *f2, *f3;
    int arr[200];
    int n = 0, temp;

    // Step 1: Write some numbers to data1.txt
    f1 = fopen("data1.txt", "w");
    fprintf(f1, "5 1 9 3");
    fclose(f1);

    // Step 2: Write some numbers to data2.txt
    f2 = fopen("data2.txt", "w");
    fprintf(f2, "6 2 8 4");
    fclose(f2);

    // Step 3: Read numbers from data1.txt
    f1 = fopen("data1.txt", "r");
    while (fscanf(f1, "%d", &arr[n]) != EOF) {
        n++;
    }
    fclose(f1);

    // Step 4: Read numbers from data2.txt
    f2 = fopen("data2.txt", "r");
    while (fscanf(f2, "%d", &arr[n]) != EOF) {
        n++;
    }
    fclose(f2);

    // Step 5: Simple Bubble Sort
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Step 6: Write sorted numbers to data3.txt
    f3 = fopen("data3.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(f3, "%d ", arr[i]);
    }
    fclose(f3);

    printf("Sorted merged numbers written to data3.txt\n");

    return 0;
}
*/

/*
#include<stdio.h>
void main()
{
    FILE *fp=fopen("1.txt","w+");
    FILE *fi=fopen("2.txt","w+");
    FILE *f=fopen("3.txt","w+");
    int n1,n2,i,c=0,n;
    printf("enter limit=");
    scanf("%d",&n1);
    printf("enter values=");
    for(i=0;i<n1;i++)
    {
        scanf("%d",&n);
        putw(n,fp);
    }
    printf("enter limit for 2ndnfile=");
    scanf("%d",&n2);
    printf("enter values=");
    for(i=0;i<n2;i++)
    {
        scanf("%d",&n);
        putw(n,fi);
    }
    rewind(fp);
    rewind(fi);
    int a[n1+n2];
    i=0;
    while((a[i]=getw(fp))!=EOF)
    {
        i++;
    }
    while((a[i]=getw(fi))!=EOF)
    {
        i++;
    }
    //  c=i;
      int j,tmp;
      for(i=0;i<n1+n2;i++)
      {
        for(j=i+1;j<n1+n2;j++)
            {
                if(a[i]>a[j])
                {
                    tmp=a[i];
                    a[i]=a[j];
                    a[j]=tmp;
                }
            }
      }
      for(i=0;i<n1+n2;i++)
      {
        putw(a[i],f);
      }
      fclose(fp);
      fclose(fi);
      rewind(f);
      while((n=getw(f))!=EOF)
      {
        printf("%d ",n);

      }
        fclose(fp);
        fclose(fi);
        fclose(f);

    }
      */
/*
#include<stdio.h>
void main()
{
    FILE *fp=fopen("name.txt","w+");
    FILE *f=fopen("vowels.txt","w+");
    char ch[100];
    printf("%s",ch);
    fprintf(fp,"%s",ch);
    
}*/


