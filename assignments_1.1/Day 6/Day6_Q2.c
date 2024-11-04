#include <stdio.h>
int noe; // noe= number of entries of data we have
float divided_difference_recursive(const float table[noe][2], const unsigned order, const unsigned subs0)
{
    if (order == 0)
    {
        return table[subs0][1];
    }
    else
    {
        return (divided_difference_recursive(table, order - 1, subs0) - divided_difference_recursive(table, order - 1, subs0 + 1)) / (table[subs0][0] - table[subs0 + order][0]);
    }
}
float a(int order, float data[noe][2])
{
    float temp = 0, term;
    for (int i = 0; i < order + 1; i++)
    {
        term = data[i][1];
        for (int j = 0; j < order + 1; j++)
        {
            if (i == j)
                continue;
            else
                term *= 1 / (data[i][0] - data[j][0]);
        }
        temp += term;
    }
    return temp;
}
float phi(float data[noe][2], float x)
{
    float temp = 0, term;
    for (int i = 0; i < noe; i++)
    {
        term = a(i, data);
        for (int j = 0; j < i + 1; j++)
        {
            if (i == j)
                continue;
            else
                term *= (x - data[j][0]);
        }
        temp += term;
    }
    return temp;
}
void main()
{
    printf("Enter the number of observations: \n");
    scanf("%d", &noe);
    float data[noe][2];
    float x;
    printf("\nEnter the different values of x:\n");
    scanf("%f %f %f %f %f", &data[0][0], &data[1][0], &data[2][0], &data[3][0], &data[4][0]);
    printf("\nThe corresponding values of y are:\n");
    scanf("%f %f %f %f %f", &data[0][1], &data[1][1], &data[2][1], &data[3][1], &data[4][1]);
    printf("\nEnter the value of 'k' in f(k) you want to evaluate:\n");
    scanf("%f", &x);
    printf("\nf(%.0f) = %.2f",x, phi(data, x));
}