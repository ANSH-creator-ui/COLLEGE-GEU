

//using dma




/*#include <stdio.h>
#include <stdlib.h>

void shiftRight(int *arr, int start, int end) {
    int temp = arr[end];
    for (int i = end; i > start; i--) {
        arr[i] = arr[i - 1];
    }
    arr[start] = temp;
}

int main() {
    int *p, n;
    printf("Enter size: ");
    scanf("%d", &n);

    p = (int *)malloc(n * sizeof(int));

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", p+i);  // Read elements into dynamic array
    }

    int index = 0;

    // Step 1: Move all negatives to the front
    for (int i = 0; i < n; i++) {
        if (*(p+i) < 0) {
            shiftRight(p, index, i); // Right shift elements between index and i
            index++;
        }
    }

    // Step 2: Move all zeros just after the negatives
    for (int i = index; i < n; i++) {
        if (*(p+i)== 0) {
            shiftRight(p, index, i);
            index++;
        }
    }

    printf("Rearranged array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(p+i));  // Print the final array
    }

    free(p);  // Free allocated memory
    return 0;
}


*/

//ARRAAY SE

/*
#include<stdio.h>

void shiftelement(int a[],int start,int end)
{
    int temp=a[end];
    for(int i=end;i>start;i--)
    {
        a[i]=a[i-1];
    }
    a[start]=temp;
}

void main()
{
    int n;
    printf("enter n=");
    scanf("%d",&n);
    int a[n],index=0;
    printf("enter elements=");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            shiftelement(a,index,i);
             index++;
        }
    }
     for(int i=0;i<n;i++)
    {
         if(a[i]==0){

        shiftelement(a,index,i);
        index++;}
    }

    for(int j=0;j<n;j++)

{
    printf("%d\n",a[j]);
}


}*/

//DECIMAL TO BINARYYY
/*
#include<stdio.h>
void dec(int x)
{
    if(x==0)
    {
        return;
    }
   
    dec(x/2);
    printf("%d",x%2);
}



void main()
{
    int n;
    printf("enter n=");
    scanf("%d",&n);
    dec(n);
}*/

//REVERSE OF ARRRAY USING RECURSION

/*

#include<stdio.h>
void reverse(int a[],int n)
{
    
    if(n<1)
   { return ;}
   else{
    printf("%d\n",a[n]);
    reverse(a,n-1);
}}
void main()
{
      int n;
      printf("enter n=");
      scanf("%d",&n);
      int a[n];
      printf("enter elements=");
      for(int i=1;i<=n;i++)
      {
        scanf("%d",&a[i]);

      }
    reverse(a,n);
   //  for(int i=0;i<n;i++)
     // {
       // printf("%d",a[i]);

      
}*/


// gp teRM MISSING AP

/*
#include<stdio.h>
void main()
{
    int n,k,i;
    printf("enter n=");
    scanf("%d",&n);
    int a[n];
    printf("enter k=");
    scanf("%d",&k);
   printf("enter elements=");
   for(i=0;i<n;i++)
   {
    scanf("%d",&a[i]);

   }
   int tmp,j;
   for(i=0,j=n-1;i<j;i++,j--)
   {
    tmp=a[j];
    a[j]=a[i];
    a[i]=tmp;
   }
   for(i=0,j=k-1;i<j;i++,j--)
   {
    tmp=a[j];
    a[j]=a[i];
    a[i]=tmp;

   }

   for(i=k,j=n-1;i<j;i++,j--)
   {
    tmp=a[j];
    a[j]=a[i];
    a[i]=tmp;

   }
for(i=0;i<n;i++)
   {
    printf("% d",a[i]);

   }

}
*/
/*
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);

    // Check all substrings of length >= 2
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int left = i, right = j;
            int isPalindrome = 1;

            while (left < right) {
                if (str[left] != str[right]) {
                    isPalindrome = 0;
                    break;
                }
                left++;
                right--;
            }

            if (isPalindrome) {
                printf("Palindrome substring found: ");
                for (int k = i; k <= j; k++) {
                    printf("%c", str[k]);
                }
                printf("\n");
                return 0;  // Stop after finding first
            }
        }
    }

    printf("No palindrome substring found.\n");
    return 0;
}
/*