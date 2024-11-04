#include <stdio.h>
int main()

{
    int y;
    printf("THIS PROGRAMME IS FOR IDENTIFYING A GIVEN YEAR AS A LEAP YEAR OR NOT.\n");
    printf("Please input the year you would like to identify :");
    scanf("%d", &y);

    printf("The year you entered is %d\n", y);
    if (y % 4 == 0)
    {
        if (y % 100 == 0)
        {

            if (y % 400 == 0)
            {
                printf("The year %d is a leap year.\n", y);
            }
            else
            {
                printf("The year %d is not a leap year.\n", y);
            }
        }
        else
        {
            printf("The year %d is a leap year");
        }
    }
    else
    {
        printf("The year %d is not a leap year.\n", y);
    }

    return 0;
}