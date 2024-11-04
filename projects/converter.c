/*
km to miles
inches to feet
cm to inches
pound to kg
inches to meter
seconds to minutes
*/
#include <stdio.h>
float f1(float km) // km to mile function
{
    return 0.621371 * km;
}
float f2(float inch) // inch to feet function
{
    return inch / 12;
}
float f3(float cm) // cm to inches function
{
    return cm / 2.54;
}
float f4(float pound) // pound to kg funtion
{
    return 0.453592 * pound;
}
float f5(float inch) // inch to meter function
{
    return 0.0254 * inch;
}
float f6(float sec) // second to minute function
{
    return sec / 60;
}
int main()
{

    int a;
    float b, c;
    char d = '0';
    do
    {
        printf("Enter the option number for the operation you would like to perform\n");
        printf("1. km to miles\n2. inches to feet\n3. cm to inches\n4. pound to kg\n5. inches to meter\n6. seconds to minutes\n");
        scanf("%d", &a);
        printf("Enter the number represented in the first unit\n");
        scanf("%f", &b);
        switch (a)
        {
        case 1:
            c = f1(b);
            break;
        case 2:
            c = f2(b);
            break;
        case 3:
            c = f3(b);
            break;
        case 4:
            c = f4(b);
            break;
        case 5:
            c = f5(b);
            break;
        case 6:
            c = f6(b);
            break;

        default:
            printf("That's not a valid option.");
            break;
        }
        printf("The value in second unit is %f\n", c);
        printf("would you like to reuse the programme? Enter 'y' for yes and 'n' for no.\n");
        scanf(" %c", &d);
    } while (d == 'y');
    return 0;
}