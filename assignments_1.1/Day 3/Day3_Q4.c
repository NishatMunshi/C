#include <stdio.h>
int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}
int main()
{
    int n, ch = 1;
    while (ch != -1)
    {
        printf("Enter the number to calculate its factorial.\n");
        scanf("%d", &n);
        printf("The factorial of %d is %d ", n, fact(n));
        printf("\nenter 1 to continue\nenter -1 to quit.\n");
        scanf("%d", &ch);
    }
}
