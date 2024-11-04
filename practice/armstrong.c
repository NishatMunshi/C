#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int countDigits(int number)
{
    if (number == 0)
        return 1;
    else
    {
        int digits = 0;
        while (number != 0)
        {
            number = number / 10;
            digits++;
        }
        return digits;
    }
}
int isArmstrong(int i)
{
    const int d = countDigits(i);
    const int temp = i;
    int sum = 0;
    int *ptr = (int *)calloc(d, sizeof(int));
    for (int j = 0; j < d; j++)
    {
        ptr[j] = i % 10;
        i = i / 10;
    }
    for (int j = 0; j < d; j++)
        sum += (int)pow(ptr[j], d);
    free(ptr);
    if (sum == temp)
        return 1;
    else
        return 0;
}
void main()
{
    int a, b;
    printf("Enter the range [a,b]:\na = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    for (int i = a; i < b + 1; i++)
    {
        if (isArmstrong(i))
            printf("%d\t", i);
    }
}