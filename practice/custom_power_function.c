#include "custom_log_function.c"
float power(const float a, const float b)
{
    if (a == 0)
    {
        if (b <= 0)
        {
            printf("ERROR!\n");
        }
        else
        {
            return 0;
        }
    }
    else if (a != 0 && b == 0)
    {
        return 1;
    }
    else if (a == 1)
    {
        return 1;
    }
    else if (b == 1)
    {
        return a;
    }
    else
    {
        return (expo(b * ln(a)));
    }
}
void main()
{
    float a, b;
    printf("Enter any two numbers a & b: ");
    scanf("%f %f", &a, &b);
    printf("a^b = %.2f", power(a, b));
}