#include <stdio.h>
#include <math.h>
int det(int order, int mat[order][order]) // order is the order of det.
{
    if (order == 1)
    {
        return mat[0][0];
    }
    else if (order == 2)
    {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }
    else
    {
        int temp = 0;
        for (int i = 0; i < order; i++)
        {
            int minor[order - 1][order - 1];
            int list[order - 1];
            for (int a = 1; a <= order - 1; a++)
            {
                list[a - 1] = a; // predefining the list. we may choose to overwrite this everytime i changes
            }
            int index = 0;    // this block of code is tried and tested
            while (index < i) // this block of code helps choose the column for minor from mat
            {
                list[index] = index;
                index++;
            }

            for (int j = 0; j < order - 1; j++)
            {
                for (int k = 0; k < order - 1; k++)
                {
                    minor[j][k] = mat[j + 1][list[k]];
                }
            }
            temp += mat[0][i] * pow(-1, i) * det(order - 1, minor);
        }
        return temp;
    }
}
void main()
{
    // filling matrix A
    int order; // order of square matrix.
    printf("\nWhat is the order of matrix A? (only square matrices can have determinants.)");
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
    printf("\ndet(A) = %d", det(order, A));
}