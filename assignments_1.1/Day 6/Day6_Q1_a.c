#include <stdio.h>
int noe;
void takeInput(float data[noe][2]) // takes first two x inputs and fills the rest of x's.
{
    for (int i = 0; i < noe; i++)
    {
        printf("x%d = ", i + 1);
        scanf("%f", &data[i][0]);
        printf("y%d = ", i + 1);
        scanf("%f", &data[i][1]);
    }
}
int fact(int n)
{
    if (n == 0 || n == 0)
        return 1;
    else
    {
        int temp = 1;
        for (int i = n; i > 0; i--)
        {
            temp *= i;
        }
        return temp;
    }
}
float prod(float s, int r)
{
    float t = 1;
    for (int i = 0; i < r; i++)
    {
        t *= (s - i);
    }
    t = t / fact(r);
    return t;
}
float del(int order, int subscript, float data[noe][2])
{
    if (order == 0)
        return data[subscript][1];
    else
        return del(order - 1, subscript + 1, data) - del(order - 1, subscript, data);
}
float phi(float x, float data[noe][2])
{
    float s, h, temp = 0;
    h = data[1][0] - data[0][0];
    s = ((x - data[0][0]) / h);
    for (int r = 0; r < noe; r++)
    {
        temp += prod(s, r) * del(r, 0, data);
    }
    return temp;
}
void diffTable(float data[noe][2])
{
    printf("Difference table is:-\n\tx\ty\t^1y\t^2y\t^3y\n");
    for (unsigned i = 0; i < noe; i++)
    {
        printf("\t%.4f\t%.4f", data[i][0], data[i][1]);
        for (unsigned j = 0; j < noe - 1 - i; j++)
        {
            printf("\t%.4f", del(j + 1, i, data));
        }
        printf("\n");
    }
}
void main()
{
    printf("Enter the number of data points: ");
    scanf("%d", &noe);
    printf("Enter the data\n");
    float data[noe][2];
    float x;
    takeInput(data);
    diffTable(data);
    printf("Enter the value x for function f(x): ");
    scanf("%f", &x);
    printf("The value of function at x = %f is %f", x, phi(x, data));
}