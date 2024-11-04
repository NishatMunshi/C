#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
    char name[50];
    int roll;
    int m[5];
} st;
float avg(int m[5])
{
    return (float)(m[0] + m[1] + m[2] + m[3] + m[4]) / 5;
}
int main()
{
    int n;
    printf("How many students? ");
    scanf("%d", &n);
    st *s = (st *)malloc(n * sizeof(st));
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("Enter name of student %d: ", i + 1);
        gets(s[i].name);
        printf("Enter roll number of student %d: ", i + 1);
        scanf("%d", &s[i].roll);
        printf("Enter marks in 5 subjects of student %d: ", i + 1);
        scanf("%d %d %d %d %d", &s[i].m[0], &s[i].m[1], &s[i].m[2], &s[i].m[3], &s[i].m[4]);
        for (int j = 0; j < 5; j++)
        {
            if (s[i].m[j] > 100 || s[i].m[j] < 0)
            {
                printf("Marks is not valid.");
                i--;
            }
        }
    }
    printf("Name\tAverage\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t%f\n", s[i].name, avg(s[i].m));
    }
    return 0;
}