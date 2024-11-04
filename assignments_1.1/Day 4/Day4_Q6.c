#include <stdio.h>

void intToString(int n)
{
    char s[100];
    int r = 0, j = 0;

    while (n > 0)
    {
        r = r * 10 + (n % 10);
        n /= 10;
    }
    while (r > 0)
    {
        s[j++] = (char)(r % 10 + 48);
        r /= 10;
    }
    printf("The desired string is:%s\n", s);
}
int strToInt(char s[])
{
    int n = 0, i;
    for (i = 0; s[i] != '\0'; i++)
    {
        n = n * 10 + (int)(s[i]) - 48;
    }
    printf("The desired integer is: %d", n);
}
int main()
{
    int ch = 1, n;
    char s[100];
    while (ch == 1 || ch == 2)
    {
        printf("\nPress 1 to convert string to integer\nPress 2 to convert integer to string\nPress 0 to quit\nenter choice: ");
        scanf("%d", &ch);
        if (ch == 2)
        {
            printf("enter an integer:  \n");
            scanf("%d", &n);
            intToString(n);
        }
        else if (ch == 1)
        {
            printf("Enter the string: \n");
            scanf("%s", &s);
            strToInt(s);
        }
        else
        {
            printf("Program Terminated....");
        }
    }
}
