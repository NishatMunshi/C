//this program prints given number as product of primes factors
#include <stdio.h>
#include <stdlib.h>
void main()
{
    int num, index = 1;
    printf("Enter any integer bigger than 2: ");
    scanf("%d", &num);
    int *array = (int *)calloc(num, sizeof(int));
    array[0] = 2;
    for (int i = 2; i <= num; i++) // filling array with all primes smaller than or equal to(in case num itself is prime) num
    {
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
            else if (i == j + 1)
            {
                array[index] = i;
                index++;
            }
        }
    }

    int k = 0;
    int *power = (int *)calloc(num, sizeof(int));
    while (array[k] != 0) // finding the power of each of those primes in num
    {
        if (num % array[k] == 0)
        {
            int temp = num;
            while (temp % array[k] == 0)
            {
                power[k]++;
                temp = temp / array[k];
            }
        }
        k++;
    }

    printf("%d = ", num);  // printing the result
    int j = 0;
    while (array[j] != 0) 
    {
        if (power[j]==0)
        {
            j++;
            continue;
        }
        else
        {
            printf("(%d^%d)", array[j], power[j]);
            j++;
        }
    }
}