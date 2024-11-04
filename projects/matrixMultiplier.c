#include <stdio.h>
void multiplier(int r1, int c1, int r2, int c2, int A[r1][c1], int B[r2][c2])
{
    if (c1 == r2)
    {
        // initializing AB as a nullmatrix
        int AB[r1][c2];
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                AB[i][j] = 0;
            }
        }

        // filling AB correctly
        for (int k = 0; k < c2; k++)
        {
            for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j < c1; j++)
                {
                    AB[i][k] = AB[i][k] + A[i][j] * B[j][k];
                }
            }
        }

        // printing AB
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                printf("%d      ", AB[i][j]);
            }
            if (i != r1 - 1)
            {
                printf("\n\t");
            }
            else
            {
                printf("\n");
            }
        }
    }
    else
    {
        printf("This product is not defined.");
    }
}
void main()
{
    int r1, c1, r2, c2;
    // filling up matrix A
    printf("How many rows does matrix A have? ");
    scanf("%d", &r1);
    printf("How many columns does matrix A have? ");
    scanf("%d", &c1);
    int A[r1][c1];
    printf("Please fill matrix A(%dX%d)\n\n", r1, c1);
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("a%d%d = ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\n");

    // filling up matrix B
    printf("How many rows does matrix B have? ");
    scanf("%d", &r2);
    printf("How many columns does matrix B have? ");
    scanf("%d", &c2);
    int B[r2][c2];
    printf("Please fill matrix B(%dX%d)\n\n", r2, c2);
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("b%d%d = ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }
    printf("\n\n");
    
repeat:
    printf("Which operation would you like to perform?\n1. AB\n2. BA\n3. Both\nChoose any option: ");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("The product AB is: \n\t");
        multiplier(r1, c1, r2, c2, A, B);
        break;
    case 2:
        printf("The product BA is: \n\t");
        multiplier(r2, c2, r1, c1, B, A);
        break;
    case 3:
        printf("The product AB is: \n\t");
        multiplier(r1, c1, r2, c2, A, B);
        printf("The product BA is: \n\t");
        multiplier(r2, c2, r1, c1, B, A);
        break;
    default:
        printf("Wrong input.");
        goto repeat;
        break;
    }
}