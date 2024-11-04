#include <stdio.h>
#include <math.h>
unsigned digits(const unsigned n)
{
    if (n == 0)
    {
        return 1;
    }
    unsigned i = 0;
    while (1)
    {
        if (n / (unsigned)pow(10, i) != 0)
        {
            i++;
        }
        else if (n / (unsigned)pow(10, i) == 0)
        {
            return i;
        }
    }
}
void main()
{
    unsigned n = 1;
    while (n != 0)
    {
        printf("\nEnter the integer: ");
        scanf("%u", &n);
        printf("The integer %u has %u digits.", n, digits(n));
    }
}