#include <stdio.h>
int main()
{
    int num;
    printf("Enter 0 to quit\n");
    while (1)
    {
        printf("Enter the number: ");
        scanf("%d", &num);
        if (num == 0)
        {
            break;
        }
        int temp = 1;
        for (int i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                temp = 0;
                break;
            }
            else
            {
                temp = 1;
            }
        }
        if (temp == 0)
        {
            printf("%d is not prime\n", num);
        }
        else
        {
            printf("%d is prime\n", num);
        }
    }
    return 0;
}