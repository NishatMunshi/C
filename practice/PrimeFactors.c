#include <stdio.h>
#include <stdlib.h>
void printResult(int array[])
{
    int j = 0;
    while (array[j] != 0)
    {
        if (array[j + 1] == 0)
        {
            printf("%d", array[j]);
            j++;
        }
        else
        {
            printf("%d, ", array[j]);
            j++;
        }
    }
}
void main()
{
    int num, index = 0;
    printf("Enter an integer bigger than 3: ");
    scanf("%d", &num);
    int *array = (int *)calloc(num, sizeof(int));
    for (int i = 2; i <= num; i++)
    {
        if (num % i == 0) // only then we consider if i is a prime or not
        {
            if (i == 2) // if i is 2 (or num is even) we take 2 inside the array already
            {
                array[0] = 2;
                index++;
            }
            for (int j = 2; j < i; j++) // this for loop collects all the prime factors in that array except 2
            {
                if (i % j == 0 && i != 2)
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
    }
    printf("The prime factors of %d are: ", num);
    printResult(array);
}