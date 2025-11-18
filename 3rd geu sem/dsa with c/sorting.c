#include <stdio.h>



void displayarray(int a[], int x)
{
    printf("\narray after sorting=");
    for (int y = 0; y < x; y++)
    {
        printf("%d ", a[y]);
    }
    printf("\n");
}

void bubblesort(int b[], int y)
{
    int i, j;
    for (i = 0; i < y - 1; i++)
    {
        int flag = 0;
        for (j = 0; j < y - i - 1; j++)
        {
            if (b[j] > b[j + 1])
            {
                int tmp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = tmp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }    
displayarray(b, y);
}

void selectionsort(int b[], int g)
{

    int i, y;
    for (i = 0; i < g - 1; i++)
    {
        int min_index = i;
        for (y = i + 1; y < g; y++)
        {
            if (b[y] < b[min_index])
            {
                min_index = y;
            }
        }
        if (min_index != i)
        {
            int tmp = b[y];
            b[y] = b[min_index];
            b[min_index] = tmp;
        }
    }
    displayarray(b, g);
}



void insertionsort(int a[],int n)
{
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && key<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    displayarray(a,n);
}

int main()
{
    int n, i;
    printf("enter no. of elements=");
    scanf("%d", &n);

    int a[n];
    printf("enter elements=");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int choice;
    do
    {
        printf("1.Bubble sort\n2.Selection sort\n3.Insertion sort \n.4.exit");
        printf("\nEnter your choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            bubblesort(a, n);
            break;
        case 2:
            selectionsort(a, n);
            break;
        case 3:
            insertionsort(a, n);
            break;
        case 4:
            printf("exiting...");
            break;
        default:
            printf("invalid choice");
            break;
        }

    } while (choice != 4);
    return 0;

}