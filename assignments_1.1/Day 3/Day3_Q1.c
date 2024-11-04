#include <stdio.h>
#include<math.h>
void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("%d ", j + 1);
        }
        printf("\n");
    }
    printf("\n");
}
void pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            printf("  ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("%d ", j + 1);
        }
        printf("\n");
    }
    printf("\n");
}
void pattern3(int n)
{
    for (int i = 0; i < n; i++)
    { // loop 3
        for (int j = 0; j < n - i - 1; j++)
        {
            printf("  ");
        }
        for (int j = 0; j < 2*i + 1; j++)
        {
            printf("%d ", i + 1-abs(i-j));
        }
        printf("\n");
    }
}
void pattern4(int n)
{
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j <= 2 * (n - i - 1); j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("%d ", j + 1);
        }
        for (int j = 0; j < i; j++)
        {
            printf("%d ", i - j);
        }
        printf("\n");
        for (int j = 0; j < 2 * (n - i - 1); j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("%d ", j + 1);
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("%d ", i - j + 1);
        }
        printf("\n");
    }
}
void pattern5(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n + 1 - 2 * i; j++)
        {
            printf("%d ", n - (i + j));
        }
        printf("\n");
    }
}
void pattern6(int n)
{
    for(int i = 0; i < 2*n-1; i++)
    {
        for(int j = 0; j < abs(n-1-i); j++)
        {
            printf(" ");
        }
        for(int j = 0; j < (2*n-1)-abs(2*n-2-2*i); j++)
        {
            printf("+");
        }
        printf("\n");
    }
}
void pattern7(int n)
{
    for(int i = 0; i < 2*n-1; i++)
    {
        for(int j = 0; j < abs(n-1-i); j++)
        {
            printf(" ");
        }
        for(int j = 0; j < (2*n-1)-abs(2*n-2-2*i); j++)
        {
            printf("%d", i+1-abs(i-j));
        }
        printf("\n");
    }
}
void pattern8(int n)
{
    for(int i = 0; i < 2*n+1; i++)
    {
        printf("+");
    }
    printf("\n");
    for(int i = 0; i < 2*n-1; i++)
    {
        for(int j = 0; j < 1+abs(n-1-i); j++)
        {
            printf("+");
        }
        for(int j = 0; j < 2*n-1-2*abs(i+1-n); j++)
        {
            printf(" ");
        }
        for(int j = 0; j < 1+abs(n-1-i); j++)
        {
            printf("+");
        }
        printf("\n");
    }
    // printf("\n");
    for(int i = 0; i < 2*n+1; i++)
    {
        printf("+");
    }
}
void pattern9(int n)
{
    for(int i = 0; i < n-1; i++)
    {
        printf(" ");
    }
    printf("+\n");
    for(int i = 0; i < 2*n-3; i++)
    {
        for(int j = 0; j < abs(i+2-n); j++)
        {
            printf(" ");
        }
        printf("+");
        for(int j = 0; j < 2*n-3-2*abs(i-n+2); j++)
        {
            printf(" ");
        }
        printf("+");
        printf("\n");
    }
    for(int i = 0; i < n-1; i++)
    {
        printf(" ");
    }
    printf("+\n");
}
int main()
{
    int n, ch = 1, c;
    while (ch)
    {
        printf("Enter the value of n: ");
        scanf("%d", &n);
        printf("Choose the pattern: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            pattern1(n);
            break;
        case 2:
            pattern2(n);
            break;
        case 3:
            pattern3(n);
            break;
        case 4:
            pattern4(n);
            break;
        case 5:
            pattern5(n);
            break;
        case 6:
            pattern6(n);
            break;
        case 7:
            pattern7(n);
            break;
        case 8:
            pattern8(n);
            break;
        case 9:
            pattern9(n);
            break;

        default:
            printf("Invalid choice.\n");
            break;
        }

        printf("\nEnter 1 to continue or Enter 0 to quit: ");
        scanf("%d", &ch);
    }
}