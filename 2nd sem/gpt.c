#include <stdio.h>
#include <string.h>

int main() {
    char set[100], aman[100], swati[100];
    int i, flag1 = 1, flag2 = 1;
    int countSet[256] = {0}, countAman[256] = {0}, countSwati[256] = {0};

    printf("Enter the set of alphabets: ");
    scanf("%s", set);
    printf("Enter Aman's word: ");
    scanf("%s", aman);
    printf("Enter Swati's word: ");
    scanf("%s", swati);

    // Count characters in set
    for (i = 0; set[i]; i++)
        countSet[(int)set[i]]++;

    // Count characters in Aman's word
    for (i = 0; aman[i]; i++)
        countAman[(int)aman[i]]++;

    // Count characters in Swati's word
    for (i = 0; swati[i]; i++)
        countSwati[(int)swati[i]]++;

    // Compare Aman's word with set
    for (i = 0; i < 256; i++) {
        if (countSet[i] != countAman[i]) {
            flag1 = 0;
            break;
        }
    }

    // Compare Swati's word with set
    for (i = 0; i < 256; i++) {
        if (countSet[i] != countSwati[i]) {
            flag2 = 0;
            break;
        }
    }

    if (flag1 && flag2)
        printf("Both are winners\n");
    else
        printf("One of you is winner\n");

    return 0;
}
