#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    unsigned roll;
    char name[50];
    char dept[50];
    unsigned year;
} s;

void getNameByYear(s *stu, const unsigned size)
{
    unsigned year;
    printf("\nEnter the year: ");
    scanf("%u", &year);
    for (unsigned i = 0; i < size; i++)
    {
        if (year == stu[i].year)
        {
            puts(stu[i].name);
            return;
        }
    }
    printf("There is no such year in the database.\n");
}

void getNameByRoll(s *stu, const unsigned size)
{
    unsigned roll;
    printf("\nEnter the roll no: ");
    scanf("%u", &roll);
    for (unsigned i = 0; i < size; i++)
    {
        if (roll == stu[i].roll)
        {
            puts(stu[i].name);
            return;
        }
    }
    printf("There is no such roll in the database.\n");
}

int main()
{
    unsigned choice, size;
    printf("Enter the size of database: ");
    scanf("%u", &size);
    s *stu = (s *)malloc(size * sizeof(s));
    for (unsigned i = 0; i < size; i++)
    {
        printf("\nEnter the roll of student %u: ", i + 1);
        scanf("%u", &stu[i].roll);
        getchar();
        printf("Enter the name: ");
        gets(stu[i].name);
        printf("Enter the dept: ");
        gets(stu[i].dept);
        printf("Enter the year: ");
        scanf("%u", &stu[i].year);
        getchar();
    }

    printf("\nPress 1 to get name by year\nPress 2 to get name by Roll No");
    printf("\nEnter the choice: ");
    scanf("%u", &choice);
    if (choice == 1)
    {
        getNameByYear(stu, size);
    }
    else if (choice == 2)
    {
        getNameByRoll(stu, size);
    }

    return 0;
}
