#include <stdio.h>
int fact_recursive(int num);
int fact_iterative(int num);
int main()
{
    int n;
    printf("Enter the number :");
    scanf("%d", &n);
    printf("%d! = %d", n, fact_iterative(n));
    return 0;
}
int fact_recursive(int num)
{
    if (num == 1 || num == 0)
    {
        return 1;
    }
    else
    {
        return num * fact_recursive(num - 1);
    }
}
int fact_iterative(int num)
{
    int temp = num;
    for (int i = 1; i <= num - 1; i++)
    {
        temp = temp * (num - i);
    }
    return temp;
}