#include <stdio.h>
int order;
void power(int A[order][order], int exponent)
{

    // define temp 3D matrix and initialize it as null
    int temp[exponent][order][order];
    for (int k = 0; k < exponent; k++)
    {
        for (int i = 0; i < order; i++)
        {
            for (int j = 0; j < order; j++)
            {
                temp[k][i][j] = 0;
            }
        }
    }
    // initializing temp[0]= A^1
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            temp[0][i][j] = A[i][j];
        }
    }

    for (int l = 0; l < exponent - 1; l++) // here we're using space in temp[n-1] to store A^n
    {                                      // thus temp[n-1] = A^n
        for (int k = 0; k < order; k++)    // and also using the fact that A^n = A * A^(n-1)
        {                                  // all this is subject to initial condition temp[0] = A^1
            for (int i = 0; i < order; i++)
            {
                for (int j = 0; j < order; j++)
                {
                    temp[l + 1][i][k] = temp[l + 1][i][k] + (A[i][j] * temp[l][j][k]);
                }
            }
        }
    }

    // printing temp matrix at temp[exponent-1] (aka A^n)
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            printf("%d\t", temp[exponent - 1][i][j]);
        }
        printf("\n\t");
    }
    printf("\n all powers together:\n\n");
    for (int k = 0; k < exponent; k++) // this loop shows all powers from 1 to exponent
    {
        printf("A^%d is:\n\t", k + 1);
        for (int i = 0; i < order; i++)
        {
            for (int j = 0; j < order; j++)
            {
                printf("%d\t", temp[k][i][j]);
            }
            printf("\n\t");
        }
        printf("\n");
    }
}
void main()
{
    // filling matrix A
    printf("\nWhat is the order of matrix A? (only square matrices can be multiplied to themslves) ");
    scanf("%d", &order);
    int A[order][order];
    printf("\nPlease fill matrix A(%dX%d)\n\n", order, order);
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            printf("a%d%d = ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }
    int exponent;
    printf("\nWhich power of A would you like to see?: ");
    scanf("%d", &exponent);
    printf("\n A^%d is:\n\t", exponent);
    power(A, exponent);
}