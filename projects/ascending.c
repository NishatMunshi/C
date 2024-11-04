#include <stdio.h>
void main()
{
    int a[10], b[11];
    b[0] = 2147483647;
    printf("Enter your numbers.\n");
    for (int i = 0; i < 10; i++)
    {
        printf("a%d = ", i + 1);
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        b[i + 1] = 0;
        for (int j = 0; j < 10; j++)
        {
            if (b[i + 1] < a[j] && a[j] < b[i])
            {
                b[i + 1] = a[j];
            }
        }
    }
    for (int i = 0; i < 10; i++) // prints the result
    {
        printf("%d  ", b[i + 1]);
    }
}