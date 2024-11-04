#include <stdio.h>
int noe;
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
        t *= (s + i);
    }
    t = t / fact(r);
    return t;
}
float del(int order, int subscript, float data[noe][2])
{
    if (order == 0)
        return data[subscript][1];
    else
        return del(order - 1, subscript, data) - del(order - 1, subscript - 1, data);
}
float phi(float data[noe][2], float x, int n)
{
    float s, h, temp = 0;
    h = data[1][0] - data[0][0];
    s = ((x - data[n][0]) / h);
    for (int i = 0; i < n + 1; i++)
    {
        temp += (prod(s, i) * del(i, n, data));
    }
    return temp;
}
void diffTable(float data[noe][2])
{
    printf("Difference table is:-\n\tx\t\ty\t^1y\t^2y\t^3y\t^4y\n");
    for(unsigned i = 0; i < noe; i++)
    {
        printf("\t%.4f  %.4f", data[i][0], data[i][1]);
        for(unsigned j = 0; j < i; j++)
        {
            printf("   %.4f", del(j+1, i, data));
        }
        printf("\n");
    }
}
void main()
{
    printf("Enter the number of data points: ");
    scanf("%d", &noe);
    float data[noe][2], x;
    int n = noe - 1;
    printf("Enter the data:\n");
    for (int i = 0; i < noe; i++)
    {
        printf("x%d = ", i+1);
        scanf("%f", &data[i][0]);
        printf("y%d = ", i+1);
        scanf("%f", &data[i][1]);
    }
    diffTable(data);
    printf("Enter the value of x for f(x): ");
    scanf("%f", &x);
    printf("The value of f(x) at x = %f is %f", x, phi(data, x, n));
}