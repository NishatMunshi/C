#include <stdio.h>
#include <math.h>
int noOfDigits(int num)
{
    if (num == 0)
        return 1;
    int digits = 0;
    while (num != 0)
    {
        digits++;
        num = num / 10;
    }
    return digits;
}
int isArmstrong(int n)
{
    int d = noOfDigits(n);
    int t = 0, temp = n;
    int ptr[d];
    // printf("%d\n",n);
    for (int i = 0; i < d; i++)
    {
        ptr[i] = n % 10;
        n = n / 10;
    }
    for (int i = 0; i < d; i++)
    {
        t += pow(ptr[i], d);
    }
    // printf("\nTotal %d", t);
    if (t == temp)
        return 1;
    else
        return 0;
}
int main()
{
    int a, b, ch = 1;
    while (1)
    {
        printf("\nEnter the range:\n");
        scanf("%d\n%d", &a, &b);
        if (a==0&&b==0)
        {
            break;
        }
        
        for (int i = a; i <= b; i++)
        {
            if (isArmstrong(i))
            {
                printf("\n%d is Armstrong", i);
            }
        }
    }
    return 0;
}