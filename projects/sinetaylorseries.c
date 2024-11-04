#include <stdio.h>
#include <math.h>
double fact(int num)
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
double sine(double num, int acc_sin)
{
    double temp = num;
    for (int i = 1; i <= acc_sin; i++)
    {
        temp = temp + pow(-1, i) * pow(num, 2 * i + 1) / fact(2 * i + 1);
    }
    return temp;
}
double sin_relative_error(double n, int acc_sin)
{
    double t = (sin(n) - sine(n, acc_sin)) / sin(n);
    return t > 0 ? t : -t;
}
double cosine(double num, int acc_sin)
{
    double temp = 1;
    for (int i = 1; i <= acc_sin; i++)
    {
        temp = temp + pow(-1, i) * pow(num, 2 * i) / fact(2 * i);
    }
    return temp;
}
double cosine_relative_error(double n, int acc_sin)
{
    double t = (cos(n) - cosine(n, acc_sin)) / cos(n);
    return t > 0 ? t : -t;
}
int main()
{
    int acc_sin = 0, acc_cos = 0;

    double n;
    printf("Enter number:  ");
    scanf("%lf", &n);
    // printf("Enter number of terms of accuracy\n");
    // scanf("%d", &acc_sin);
    while(sin_relative_error(n, acc_sin) > 1e-5){
        acc_sin++;
    }
    while(cosine_relative_error(n, acc_cos) > 1e-5){
        acc_cos++;
    }
    printf("sin(%lf) = %lf\n", n, sine(n, acc_sin));
    printf("relative error = %lf,  number of terms needed = %d\n", sin_relative_error(n,acc_sin), acc_sin);
    printf("cos(%lf) = %lf\n", n, cosine(n,acc_cos));
    printf("relative error = %lf,  number of terms needed = %d\n", cosine_relative_error(n,acc_cos), acc_cos);

    return 0;
}