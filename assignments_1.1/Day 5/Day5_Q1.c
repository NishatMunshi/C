#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("How many numbers? ");
    scanf("%d", &n);

    int *ptr = (int *)malloc(n + sizeof(int));
    printf("Enter %d numebrs:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d is located at %x\n", *(ptr + i), ptr + i);
    }
}