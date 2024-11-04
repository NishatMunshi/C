#include <stdio.h>
#include <math.h>
float avg(float arr[10])
{
    float sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += arr[i];
    }
    return sum / 10;
}
float sd(float arr[10])
{
    float sd = 0;
    for (int i = 0; i < 10; i++)
    {
        sd += (arr[i] - avg(arr)) * (arr[i] - avg(arr));
    }
    sd = sd / 9;
    sd = sqrt(sd);
    return sd;
}
void main()
{
    float x[10];
    printf("Enter the numbers\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%f", &x[i]);
    }
    printf("\nAverage is: %f", avg(x));
    printf("\nstandard deviation is: %f", sd(x));
}