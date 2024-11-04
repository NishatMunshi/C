// This programme finds the 3N+1 chain given the root N
#include <stdio.h>
unsigned long long list[100000];
unsigned long long next(unsigned long long n) // finds next number given a number n
{
    switch (n)
    {
    default:
        if (n % 2 == 0)
        {
            return n / 2;
        }
        else
        {
            return 3 * n + 1;
        }
        break;
    }
}
void main()
{
    unsigned long long n;
    unsigned long long r;
    while (1)
    {
        printf("\n\nEntering 0 quits the app. Enter the root: ");
        scanf("%lld", &n);
        if (n > 0)
        {
            printf("\nAny specific term you want to see? :");
            scanf(" %lld", &r);
            unsigned long long list[100000];
            int i = 0;
            printf("\n");
            do
            {
                list[0] = n;
                printf("%lld ,  ", list[i]);
                i++;
                list[i] = next(list[i - 1]);
            } while (list[i - 1] != 1);
            unsigned long long max = list[0];
            int k = 0;
            while (list[k] != 1)
            {
                k++;
                if (list[k] > max)
                {
                    max = list[k];
                }
                else
                {
                    continue;
                }
            }
            printf("\n\nT%d is %lld", r, list[r - 1]);
            printf("\n\nThe biggest number in the sequence is %lld", max);
        }
        else
        {
            break;
        }
    }
    printf("Quitting programme....");
}