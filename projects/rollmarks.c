#include <stdio.h>
int main()
{
    int RollMarks[2][10]; // a 2x10 matrix whose first row is the roll numbers of students and the second row is their corresponding marks.
    for (int j = 0; j < 10; j++)
    {
        RollMarks[0][j] = j + 1;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("Marks of student %d = ", i + 1);
        scanf("%d", &RollMarks[1][i]);
    }
    for (int k = 0; k < 10; k++)
    {
        printf("%d  ", RollMarks[0][k]);
    }
    printf("\n");
    for (int l = 0; l < 10; l++)
    {
        printf("%d  ", RollMarks[1][l]);
    }
    return 0;
}