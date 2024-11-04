#include <stdio.h>
int main()
{
    double f1, c1, t;
    char u, ans;
    do
    {
        printf("This programme can show a temp in celcius or ferhenheight scale\nEnter the value of the temperature: ");
        scanf("%lf", &t);
        printf("Enter C for celcius and F for ferhenheight.\n");
        scanf(" %c", &u);
        if (u == 'C' || u == 'F')
        {
            printf("The temperature entered is %.2lf degrees %c\nWould you like to continue (y/n)? \n", t, u);
            scanf(" %c", &ans);
            if (ans == 'y' || ans == 'n')
            {
                if (ans == 'y')
                {
                    if (u == 'C')
                    {
                        f1 = 32 + 9 * t / 5;
                        printf("The temperature in ferhenheight scale would be %.2lf degrees F", f1);
                    }
                    else if (u == 'F')
                    {
                        c1 = 5 * (t - 32) / 9;
                        printf("The temperature in celcius scale would be %.2lf degrees C", c1);
                    }
                }
            }
            else
            {
                printf("Invalid option chosen!");
            }
        }
        else
        {
            printf("Invalid option chosen!");
        }
    } while (ans == 'n');
    return 0;
}