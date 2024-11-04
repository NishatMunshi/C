#include <stdio.h>
float sum(float a, float b)
{
    return a + b;
}
float dif(float a, float b)
{
    return a - b;
}
float prod(float a, float b)
{
    return a * b;
}
float quo(float a, float b)
{
    return a / b;
}
int modu(int a, int b)
{
    return a % b;
}
int main()
{
    float a, b;
    char c;
    int n, ch = 1;
    while (ch)
    {
        printf("enter the two numbers:\n");
        scanf("%f%f", &a, &b);
        printf("Enter the operation\n");
        scanf(" %c", &c);
        if (a != 0 && b != 0)
        {
            switch (c)
            {
            case '+':
                printf("the sum of the two numbers is %f", sum(a, b));
                break;
            case '-':
                printf("the difference of the two numbers is %f", dif(a, b));
                break;
            case '*':
                printf("the product of the two numbers is %f", prod(a, b));
                break;
            case '/':
                if (b != 0)
                    printf("the qoutient of the two numbers is %f", quo(a, b));
                else
                    printf("cannot divide by 0");
                break;
            case '%':
                if (b != 0)
                    printf("the modulo of the two numbers is %d", modu(a, b));
                else
                    printf("cannot divide by 0");
                break;
            default:
                break;
            }
        }
        printf("\nenter 1 to continue\nenter 0 to quit.\n");
        scanf("%d", &ch);
    }
}