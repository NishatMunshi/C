#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int n; // number of characters in id( variable )
    for (int i = 0; i < 3; i++)
    {
        printf("Employee %d:\n", i + 1);
    repeat:
        printf("\tEnter the number of characters in your eId: ");
        scanf("%d", &n);
        char *ptr = (char *)calloc((n + 1), sizeof(char)); // one more char needed for \0
        printf("\tEnter your id: ");
        scanf("%s", ptr);
        if (strlen(ptr) == n)
        {
            printf("\n\tThe eId for Employee %d is: %s\n\n", i + 1, ptr);
            free(ptr);
        }
        else
        {
            printf("Sorry number of characters did not match.\n\n");
            free(ptr);
            goto repeat;
        }
    }
}