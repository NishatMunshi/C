#include <stdio.h>
#include <stdlib.h>
float f_v(int NOE, float table[0][NOE], float v) // NOE is number of entries
{
    float l_x, result = 0; // temp variable to return f_v // l_x is temp variable to store li(x). we initialize it by 1 in each iteration
    for (int i = 0; i < NOE; i++)
    {
        l_x = 1;
        for (int j = 0; j < NOE; j++)
        {
            if (i == j)
                continue;
            else
                l_x *= (v - table[0][j]) / (table[0][i] - table[0][j]);
        }
        result += table[1][i] * l_x;
    }
    return result;
}
void main()
{
    int NOE;
    float v, fv = 0;                 // variable to use finally is v, fv is the approximation of f at x=v
    printf("Enter the value of n: ");
    scanf("%d", &NOE);
    printf("Enter the value to be found: ");
    scanf("%f", &v);
    float table[2][NOE]; // given table of values
    printf("Enter the values of xi's and fi's:\n");
    for(unsigned i = 0; i < NOE; i++)
        scanf("%f %f", &table[0][i], &table[1][i]);
    fv = f_v(NOE, table, v);
    printf("x = %f\nf(x) = %f", v, fv);
}