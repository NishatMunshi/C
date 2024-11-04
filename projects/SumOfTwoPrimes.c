// This program represents an integer as a sum of two prime numbers
#include <stdio.h>
#include <stdlib.h>
int *prime;
void MakeList(int num)
{
    prime = (int *)calloc(num - 3, sizeof(int)); // we're gonna store all primes smaller than num in this array.
    int index = 0;
    prime[0] = 2;
    for (int i = 3; i < num; i++)
    {
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
            else if (i == j + 1)
            {
                prime[index + 1] = i;
                index++;
            }
        }
    }
}
void PrintAsSum(int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (prime[i] + prime[j] == num)
            {
                printf("%d = %d + %d\n", num, prime[i], prime[j]);
            }
        }
    }
    printf("\n");
}
// void PrintAsProd(int num)
// {
//     for (int i = 0; i < num; i++)
//     {
//         for (int j = 0; j <= i; j++)
//         {
//             if (prime[i] * prime[j] == num)
//             {
//                 printf("%d = %d * %d\n", num, prime[i], prime[j]);
//             }
//         }
//     }
//     printf("\n");
// }
void main()
{
    int num;
repeat:
    printf("Enter any integer bigger than 3.\n");
    scanf("%d", &num);
    if (num > 3)
    {
        MakeList(num);
    }
    else
    {
        goto repeat;
    }
    PrintAsSum(num);
    // PrintAsProd(num);
}