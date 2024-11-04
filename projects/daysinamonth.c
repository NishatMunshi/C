#include <stdio.h>
int main()
{
    int no, l, y;
    printf("Please enter the year : ");
    scanf("%d", &y);
    printf("Please enter the month serial number(1 till 12) : ");
    scanf("%d", &no);

    if (y % 4 == 0)
    {
        if (y % 100 == 0)
        {

            if (y % 400 == 0)
            {
                printf("The year %d is a leap year.\n", y);
                l = 1;
            }
            else
            {
                printf("The year %d is not a leap year.\n", y);
                l = 0;
            }
        }
        else
        {
            printf("The year %d is a leap year.\n");
            l = 1;
        }
    }

    else
    {
        printf("The year %d is not a leap year.\n", y);
        l = 0;
    }
    if (no == 1)
    {
        printf("The month you chose is January.\nThere are 31 days in January.");
    }

    else if (no == 2)
    {
        if (l == 1)
        {
            printf("The month you chose is February.\nThere are 29 days in February [Since it's a leap year.] .");
        }
        else
        {
            printf("The month you entered is Februaury.\nThere are 28 days in February [Since it's not a leap year.]");
        }
    }
    else if (no == 3)
    {
        printf("The month you chose is March.\nThere are 31 days in March.");
    }

    else if (no == 4)
    {
        printf("The month you chose is April.\nThere are 30 days in April.");
    }

    else if (no == 5)
    {
        printf("The month you chose is May.\nThere are 31 days in May.");
    }

    else if (no == 6)
    {
        printf("The month you chose is June.\nThere are 30 days in June.");
    }

    else if (no == 7)
    {
        printf("The month you chose is July.\nThere are 31 days in July.");
    }

    else if (no == 8)
    {
        printf("The month you chose is August.\nThere are 31 days in August.");
    }

    else if (no == 9)
    {
        printf("The month you chose is September.\nThere are 30 days in September.");
    }

    else if (no == 10)
    {
        printf("The month you chose is October.\nThere are 31 days in October.");
    }

    else if (no == 11)
    {
        printf("The month you chose is November.\nThere are 30 days in November.");
    }

    else if (no == 12)
    {
        printf("The month you chose is December.\nThere are 31 days in December.");
    }

    else
    {
        printf("This number is not valid.");
    }

    return 0;
}