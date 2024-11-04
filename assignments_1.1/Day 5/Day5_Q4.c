#include <stdio.h>
#include <stdlib.h>
int main()
{
    int **arr1, **arr2, **arr3;
    int row1, col1, row2, col2;
    int i, j, k;
    printf("\nEnter number of rows and columns for first matrix: ");
    scanf("%d %d", &row1, &col1);

    printf("\nEnter number of rows and column for second matrix: ");
    scanf("%d %d", &row2, &col2);

    if (col1 != row2)
    {
        printf("\nCannot multiply the two matrices.");
        return (0);
    }
    arr1 = (int **)malloc(sizeof(int *) * row1);
    arr2 = (int **)malloc(sizeof(int *) * row2);
    arr3 = (int **)malloc(sizeof(int *) * row1);
    for (i = 0; i < row1; i++)
        arr1[i] = (int *)malloc(sizeof(int) * col1);
    for (i = 0; i < row2; i++)
        arr2[i] = (int *)malloc(sizeof(int) * col2);
    for (i = 0; i < row1; i++)
        arr3[i] = (int *)malloc(sizeof(int) * col2);
    printf("\nEnter elements of first matrix:\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {

            scanf("%d", &arr1[i][j]);
        }
    }
    printf("\nEnter elements of second matrix:\n");
    for (i = 0; i < row2; i++)
    {
        for (j = 0; j < col2; j++)
        {

            scanf("%d", &arr2[i][j]);
        }
    }
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
        {
            arr3[i][j] = 0;
            for (k = 0; k < col1; k++)
                arr3[i][j] = arr3[i][j] + arr1[i][k] * arr2[k][j];
        }
    }
    printf("\n\nProduct:");
    for (i = 0; i < row1; i++)
    {
        printf("\n");
        for (j = 0; j < col2; j++)
            printf("%d\t", arr3[i][j]);
    }
    return 0;
}