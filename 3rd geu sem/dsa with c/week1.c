/*#include<stdio.h>
int main()
{
    int n;
    printf("enter size=");
    scanf("%d",&n);
    int a[n],i,j,left,right,k;
    printf("enter elements=");
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            left=i,right=j;
            int ispalindrome=1;
            while(left<right)
            {
                if(a[left]!=a[right])
                {
                    ispalindrome=0;
                    break;
                }
                left++;
                right--;
            }
            if(ispalindrome)
            {
                printf("the palindrome sequence found");
                for(k=i;k<=j;k++)
                {
                    printf("%d",a[k]);

                }
                break;
            }
            return 0;
    }

}
printf("no plindromic sequence found");
return 0;
}

*/

/*

#include<stdio.h>
int main()
{
    int n , freq[256]={0},a[100];
   printf("enter size=");
scanf("%d",&n);
  printf("enter elements:=");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
    freq[a[i]]++;
  }



  for(int i=0;i<256;i++)
  {
    if(freq[i]>0)
    {
        printf("%d=%d\n",i,freq[i]);
    }
  }
  return 0;

}

  */
/*
  #include <stdio.h>

int main() {
    int n, a[100], freq[100];
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        freq[i] = -1; // Initialize freq to -1
    }

    // Count frequency
    for(int i = 0; i < n; i++) {
        if(freq[i] != 0) { // If not already counted
            int count = 1;
            for(int j = i + 1; j < n; j++) {
                if(a[i] == a[j]) {
                    count++;
                    freq[j] = 0; // Mark as counted
                }
            }
            freq[i] = count;
        }
    }

    // Print frequencies
    printf("\nFrequency of each element:\n");
    for(int i = 0; i < n; i++) {
        if(freq[i] != 0) {
            printf("%d occurs %d times\n", a[i], freq[i]);
        }
    }

    return 0;
}


#include <stdio.h>

int main() {
    int n, k, count = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[100];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the value of k (target sum): ");
    scanf("%d", &k);

    // Check all pairs (i < j)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] == k) {
                printf("Pair found: (%d, %d)\n", a[i], a[j]);
                count++;
            }
        }
    }

    printf("Total number of pairs with sum %d is: %d\n", k, count);

    return 0;
}

#include <stdio.h>

// Recursive function to find sum of digits
int sumOfDigits(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    int result = sumOfDigits(number);
    printf("Sum of digits = %d\n", result);

    return 0;
}
*/
/*


#include <stdio.h>

int main() {
    int n, a = 0, b = 1, next;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }

    return 0;
}
*/


#include <stdio.h>

// Recursive function to find GCD
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int result = gcd(num1, num2);
    printf("GCD of %d and %d is %d\n", num1, num2, result);

    return 0;
}
