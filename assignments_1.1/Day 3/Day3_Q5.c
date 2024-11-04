#include <stdio.h>
int fib(int o)
{
    if (o == 0)
        return 0;
    else if (o == 1)
        return 1;
    else
        return fib(o - 1) + fib(o - 2);
}
int main()
{
    int n, ch = 1;
    while (ch != -1)
    {
        printf("Enter the number of terms.\n");
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            printf("%d\t", fib(i));
        }

        printf("\nenter 1 to continue\nenter -1 to quit.\n");
        scanf("%d", &ch);
    }
}
