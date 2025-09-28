#include <stdio.h>

int main()
{
    int x;
    printf("Enter an integer: ");
    scanf("%d", &x);
    if (x > 0)
    {
        printf("Positive\n");
    }
    else if (x < 0)
    {
        printf("Negative\n");
    }
    else
    {
        printf("Zero\n");
    }
    printf("Done\n");
    return 0;
}