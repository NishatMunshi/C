#include <stdio.h>
#include <math.h>
int main()
{
    int accuracy;
    double number, temp;
    printf("Enter the number you want natural log of: ");
    scanf("%lf", &number);
    if (number > 0 && number < 2)
    {
        printf("Enter number of terms of accuracy: ");
        scanf("%d", &accuracy);
        temp = number - 1;
        for (int i = 2; i <= accuracy; i++)
        {
            temp = temp + pow(-1, i + 1) * pow(number - 1, i) / i;
        }
        printf("ln(%.2lf) = %lf", number, temp);
    }
    else
    {
        printf("Can't compute natural log of number outside (0, 2)");
    }
    return 0;
}