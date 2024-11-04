#include <stdio.h>
float integral_simpson(const float a, const float b, const int n, const float data[][4], const int order)
{
    float temp = 0;
    for (int i = 0; i < n / 2; i++)
    {
        temp += 4 * data[2 * i + 1][order];
    }
    for (int i = 1; i <= (n - 2) / 2; i++)
    {
        temp += 2 * data[2 * i][order];
    }
    temp += data[0][order] + data[n][order];
    temp *= (b - a) / (3 * (n));
    return temp;
}
float integral_trapezoidal(const float a, const float b, const int n, float data[][4], const int order)
{
    float h = (b - a) / n, temp = 0;
    for (int i = 0; i < n + 1; i++)
    {
        temp += data[i][order];
    }
    for (int i = 1; i < n; i++)
    {
        temp += data[i][order];
    }
    temp *= (h / 2);
    return temp;
}
void fillVelocitiesTrapezoidal(float data[9][4])
{
    data[0][2] = 0;
    for (unsigned point = 1; point < 9; point++)
    {
        data[point][2] = integral_trapezoidal(data[0][0], data[point][0], point, data, 1);
        // printf("%f\n", data[point][2]);
    }
}
void fillVelocitiesSimpson(float data[9][4])
{
    data[0][2] = 0;
    for (unsigned point = 1; point < 9; point++)
    {
        data[point][2] = integral_simpson(data[0][0], data[point][0], point, data, 1);
        // printf("%f\n", data[point][2]);
    }
}
void fillPositionsTrapezoidal(float data[9][4])
{
    data[0][3] = 0;
    for (unsigned point = 1; point < 9; point++)
    {
        data[point][3] = integral_trapezoidal(data[0][0], data[point][0], point, data, 2);
        // printf("%f\n", data[point][3]);
    }
}
void fillPositionsSimpson(float data[9][4])
{
    data[0][3] = 0;
    for (unsigned point = 1; point < 9; point++)
    {
        data[point][3] = integral_simpson(data[0][0], data[point][0], point, data, 2);
        // printf("%f\n", data[point][3]);
    }
}

void main()
{
    float data[9][4]; // 9 points in time 0s to 40s and 4 columns indicate time, accln, velocity, and position respectively
    printf("Enter the data:\n");
    for (unsigned point = 0; point < 9; point++)
    {
        printf("t%d = ", point + 1);
        scanf("%f", &data[point][0]);
    }
    for (unsigned point = 0; point < 9; point++)
    {
        printf("accln%d = ", point + 1);
        scanf("%f", &data[point][1]);
    }
    fillVelocitiesSimpson(data);
    fillPositionsSimpson(data);
    printf("\nSimpson Method:\nVelocity at t = 40s: %.2f\nPosition at t = 40s: %.2f", data[8][2], data[8][3]);

    fillVelocitiesTrapezoidal(data);
    fillPositionsTrapezoidal(data);
    printf("\nTrapezoidal Method:\nVelocity at t = 40s: %.2f\nPosition at t = 40s: %.2f", data[8][2], data[8][3]);
}