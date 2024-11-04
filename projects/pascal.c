#include <stdio.h>
int fact(int num) // defining factorial as a recursive function
{
    if (num == 1 || num == 0)
    {
        return 1;
    }
    else
    {
        return num * fact(num - 1);
    }
}
int comb(int n, int r) // defining combination nCr
{
    return fact(n) / (fact(r) * fact(n - r));
}
void onerow(int n, int i) // This function prints one row given the number of row
{
    for (int k = 0; k < n - i; k++)
    {
        printf("   ");
    }
    for (int r = 0; r < i; r++)
    {
        printf("%d     ", comb(i - 1, r));
    }
    printf("\n");
}
void pascal(int n) // this function repeats onerow to give entire pascal's triangle
{
    for (int i = 1; i < n + 1; i++)
    {
        onerow(n, i);
    }
}
int i;
int main()
{
    int n;
    printf("Enter number of lines of Pascal's triangle you want to see.\n");
    scanf("%d", &n);
    pascal(n);
    return 0;
}