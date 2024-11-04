#include <stdio.h>
#include <math.h>
#define MAX_ALLOWED_ERROR 0.000001
double roots[3];
double f(const double x)
{
    return x -tan(x);
}
double fDash(const double x)
{
    return 1- 1/(cos(x) *cos(x));
}
double mod(const double x)
{
    return x >= 0 ? x : -x;
}
void bisection()
{
    double a = 2, b = 3, xi;
    xi = (a + b) / 2;
    while (1)
    {
        if (mod(f(xi)) <= MAX_ALLOWED_ERROR)
        {
            break;
        }
        else if (f(a) * f(xi) < 0)
        {
            b = xi;
            xi = (a + b) / 2;
        }
        else if (f(xi) * f(b) < 0)
        {
            a = xi;
            xi = (a + b) / 2;
        }
    }
    roots[0] = xi;
    if (xi * xi >= 36 / xi)
    {
        roots[1] = 0.5 * (-xi + sqrt(xi * xi - 36 / xi));
        roots[2] = 0.5 * (-xi - sqrt(xi * xi - 36 / xi));
        printf("\nRoots of the polynomial are %lf, %lf and %lf\n", roots[0], roots[1], roots[2]);
        return;
    }
    else
    {
        printf("\nEquation has only one real root: %lf", roots[0]);
        return;
    }
}
void regulaFalsi()
{
    double a = 2, b = 3, xi;
    xi = b - (f(b) * (b - a) / (f(b) - f(a)));
    while (1)
    {
        if (mod(f(xi)) <= MAX_ALLOWED_ERROR)
        {
            break;
        }
        else if (f(a) * f(xi) < 0)
        {
            b = xi;
            xi = b - (f(b) * (b - a) / (f(b) - f(a)));
        }
        else if (f(xi) * f(b) < 0)
        {
            a = xi;
            xi = b - (f(b) * (b - a) / (f(b) - f(a)));
        }
    }
    roots[0] = xi;
    if (xi * xi >= 36 / xi)
    {
        roots[1] = 0.5 * (-xi + sqrt(xi * xi - 36 / xi));
        roots[2] = 0.5 * (-xi - sqrt(xi * xi - 36 / xi));
        printf("\nRoots of the polynomial are %lf, %lf and %lf\n", roots[0], roots[1], roots[2]);
        return;
    }
    else
    {
        printf("\nEquation has only one real root: %lf", roots[0]);
        return;
    }
}
void newtonRaphson()
{
    double b = 7.854, xi;
    xi = b - f(b) / fDash(b);
    while (1)
    {
        if (mod(f(xi)) <= MAX_ALLOWED_ERROR)
        {
            break;
        }
        else
        {
            b = xi;
            xi = b - f(b) / fDash(b);
        }
    }

    roots[0] = xi;
    if (xi * xi >= 36 / xi)
    {
        roots[1] = 0.5 * (-xi + sqrt(xi * xi - 36 / xi));
        roots[2] = 0.5 * (-xi - sqrt(xi * xi - 36 / xi));
        printf("\nRoots of the polynomial are %lf, %lf and %lf\n", roots[0], roots[1], roots[2]);
        return;
    }
    else
    {
        printf("\nEquation has only one real root: %lf", roots[0]);
        return;
    }
}
void main()
{
    unsigned choice;
    while (1)
    {
    repeat:
        printf("\n\nChoose what method to use:\n0. Quit programme\n1. Bisection\n2. Regula Falsi\n3. Newton Raphson\n");
        scanf("%u", &choice);
        switch (choice)
        {
        case 0:
            goto end;
            break;
        case 1:
            bisection();
            break;
        case 2:
            regulaFalsi();
            break;
        case 3:
            newtonRaphson();
            break;

        default:
            printf("Invalid Choice!!");
            goto repeat;
            break;
        }
    }
end:
}
