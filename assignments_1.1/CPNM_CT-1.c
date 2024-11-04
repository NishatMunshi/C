#include <stdio.h>
#include <string.h>
struct student
{
    char name[50];
    unsigned roll;
} s[72];
void main()
{
    // Taking the input from user
    for (int i = 0; i < 72; i++)
    {
        printf("\nEnter student %d's name: ", i + 1);
        gets(s[i].name);
        printf("Enter roll number: ", i + 1);
        scanf("%u", &s[i].roll);
        getchar();
    }

    // capitalizing properly
    int j = 0;
    for (int i = 0; i < 72; i++)
    {
        j = 0;
        if (s[i].name[0] > 90)
        {
            s[i].name[0] -= 32;
        }
        while (s[i].name[j] != ' ')
        {
            j++;
        }
        j++;
        if (s[i].name[j] > 90)
        {
            s[i].name[j] -= 32;
        }
    }

    // alphabetical descending order(for ascending order use < symbol in if's condition)
    char temp[50]; // temporary storage for swapping positions of two strings.
    unsigned t;    // temporary storage for swapping of roll numbers.
    for (int i = 0; i < 72; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (strcmp(s[i].name, s[j].name) > 0)
            {
                strcpy(temp, s[i].name);
                strcpy(s[i].name, s[j].name);
                strcpy(s[j].name, temp);
                t = s[i].roll;
                s[i].roll = s[j].roll;
                s[j].roll = t;
            }
        }
    }

    // Printing the result
    printf("\nPeople with even roll number:\n");
    for (int i = 0; i < 72; i++)
    {
        if (s[i].roll % 2 == 0)
        {
            printf("Name: ");
            puts(s[i].name);
            printf("Roll: %u\n", s[i].roll);
        }
    }
    printf("\nPeople with odd roll number:\n");
    for (int i = 0; i < 72; i++)
    {
        if (s[i].roll % 2 != 0)
        {
            printf("Name: ");
            puts(s[i].name);
            printf("Roll: %u\n", s[i].roll);
        }
    }
}
