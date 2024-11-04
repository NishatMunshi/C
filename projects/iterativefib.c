#include <stdio.h>
unsigned int fib_iterative(int n) // faster bc loops take less time to run
{
    int a = 0;
    int b = 1;
    for (int i = 0; i < n - 1; i++)
    {
        b = b + a; // new b = old b + old a
        a = b - a; // new a = old b = new b(look b is updated before this line) - old a
    }
    return a;
}
unsigned int fib_recursive(int n) // way slower appraoch due to internal function calling loops
{
    switch (n)
    {
    case 1:
        return 0;
        break;
    case 2:
        return 1;
        break;

    default:
        return fib_recursive(n - 1) + fib_recursive(n - 2);
        break;
    }
}
float golden_ratio(int n)
{
    return (float)fib_iterative(n + 1) / (float)fib_iterative(n);
}


int main()
{
    int num;
    printf("Enter number of terms: ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        printf("T%d = %u    ", i + 1, fib_iterative(i + 1));
        printf("Local golden ratio= %f\n", golden_ratio(i + 1));
    }
    // printf("T%d = %u\n", num, fib_recursive(num));
    return 0;
}
/*highest you can go with unsigned int is 2^32-1
doesn't work for big inputs. higest you can go is 48
*/