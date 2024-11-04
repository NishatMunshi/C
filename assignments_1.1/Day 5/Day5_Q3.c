#include <stdio.h>
#include <stdlib.h>
typedef struct Date
{
    int d;
    int m;
    int y;
} Date;
int validDate(Date *);
int compareDates(Date *, Date *);
char *toString(Date *);
int main()
{
    int n;
    while (1)
    {
        printf("Press 1 to compare dates\n2 to quit\n");
        scanf("%d", &n);
        if (n == 2)
            break;
        if (n != 1)
        {
            printf("WRONG CHOICE!\n");
            continue;
        }
        Date d1, d2;
        printf("Enter date 1: ");
        scanf("%d/%d/%d", &d1.d, &d1.m, &d1.y);
        if (!validDate(&d1))
        {
            printf("You have entered invalid date\n");
            continue;
        }
        printf("Enter date 2: ");
        scanf("%d/%d/%d", &d2.d, &d2.m, &d2.y);
        if (!validDate(&d2))
        {
            printf("You have entered invalid date\n");
            continue;
        }
        int comp = compareDates(&d1, &d2);
        if (comp == 0)
        {
            printf("Dates are equal\n");
        }
        else if (comp < 0)
        {
            printf("%s comes before %s\n", toString(&d1), toString(&d2));
        }
        else
        {
            printf("%s comes after %s\n", toString(&d1), toString(&d2));
        }
    }
    return 0;
}

int validDate(Date *date)
{
    if (date->y < 1000 || date->y > 9999)
    {
        return 0;
    }
    if (date->m < 1 || date->m > 12)
    {
        return 0;
    }
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((date->y % 4) == 0)
    {
        if (date->y % 100)
        {
            days[2] = 29;
        }
        else
        {
            if ((date->y % 400) == 0)
            {
                days[2] = 29;
            }
        }
    }
    if (date->d <= 0 || date->d > days[date->m])
    {
        return 0;
    }
    return 1;
}
int compareDates(Date *d1, Date *d2)
{
    if (d1->y < d2->y)
        return -1;
    if (d1->y > d2->y)
        return 1;
    if (d1->m < d2->m)
        return -1;
    if (d1->m > d2->m)
        return 1;
    if (d1->d < d2->d)
        return -1;
    if (d1->d > d2->d)
        return 1;
    return 0;
}
char *toString(Date *date)
{
    char *s = (char *)malloc(sizeof(char) * 11);
    s[10] = '\0';
    s[0] = date->d / 10 + 48;
    s[1] = date->d % 10 + 48;
    s[2] = '/';
    s[3] = date->m / 10 + 48;
    s[4] = date->m % 10 + 48;
    s[5] = '/';
    s[6] = date->y / 1000 + 48;
    s[7] = (date->y % 1000) / 100 + 48;
    s[8] = (date->y % 100) / 10 + 48;
    s[9] = (date->y % 10) + 48;
    return s;
}
