#include <stdio.h>
void multiplier(int A[3][3], int B[3][3])
{
    
        // initializing AB as a nullmatrix
        int AB[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                AB[i][j] = 0;
            }
        }

        // filling AB correctly
        for (int k = 0; k < 3; k++)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    AB[i][k] = AB[i][k] + A[i][j] * B[j][k];
                }
          }
        }

        // printing AB
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d      ", AB[i][j]);
            }
            if (i != 3 - 1)
            {
                printf("\n\t");
            }
            else
            {
                printf("\n");
            }
        }
}
void adder(int A[3][3], int B[3][3])
{
        int AsumB[3][3];
        // filling AsumB correctly
            for (int i = 0; i < 3; i++){
              for (int j = 0; j < 3; j++)
                {
                    AsumB[i][j] =A[i][j] + B[i][j];
                
          }
            }

        // printing A+B
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d      ", AsumB[i][j]);
            }
            if (i != 3 - 1)
            {
                printf("\n\t");
            }
            else
            {
                printf("\n");
            }
        }
}
void subtracter(int A[3][3], int B[3][3])
{
        int AsubB[3][3];
        // filling AsubB correctly
        
        
            for (int i = 0; i < 3; i++){
              for (int j = 0; j < 3; j++)
                {
                    AsubB[i][j] =A[i][j] - B[i][j];
                
          }
            }

        // printing A-B
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d      ", AsubB[i][j]);
            }
            if (i != 3 - 1)
            {
                printf("\n\t");
            }
            else
            {
                printf("\n");
            }
        }
}
void main()
{
    // filling up matrix A
    
    int A[3][3];
    printf("Please fill matrix A(%dX%d)\n\n", 3, 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("a%d%d = ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\n");

    // filling up matrix B
    
    int B[3][3];
    printf("Please fill matrix B(%dX%d)\n\n", 3, 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("b%d%d = ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }
    printf("\n");
        printf("The product AB is: \n\t");
        multiplier( A, B);
        printf("The sum A+B is: \n\t");
        adder(A,B);
        printf("The difference A-B is: \n\t");
        subtracter(A,B);
}