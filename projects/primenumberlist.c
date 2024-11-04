#include <stdio.h>
int main()
{
    int limit;
    printf("Enter the upper limit. ");
    scanf("%d", &limit);
    int prime;
    printf("2  ");
    for (int i = 2; i < limit; i++)
    {
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
            else if (i == j + 1)
            {
                printf("%d  ", i);
            }
        }
    }

    return 0;
}