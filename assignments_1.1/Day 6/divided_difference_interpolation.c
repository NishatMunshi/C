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
    printf("Enter the number of entries you have: ");
    scanf("%d", &noe);
    float data[noe][2];
    float x;
    for (int i = 0; i < noe; i++)
    {
        printf("Enter x%d: ", i);
        scanf("%f", &data[i][0]);
        printf("Enter f(x%d): ", i);
        scanf("%f", &data[i][1]);
    }
    printf("Enter the x value where to calculate: ");
    scanf("%f", &x);
    printf("%.2f", phi(data, x));
}