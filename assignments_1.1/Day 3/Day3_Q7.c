#include <stdio.h>
#include <math.h>
float dist(float x1, float y1, float x2, float y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
float area(float x1, float y1, float x2, float y2, float x3, float y3)
{
    float a = dist(x1, y1, x2, y2);
    float b = dist(x2, y2, x3, y3);
    float c = dist(x3, y3, x1, y1);
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int checkInside(float x1, float y1, float x2, float y2, float x3, float y3, float x, float y)
{
        printf("%f", area(x1, y1, x2, y2, x, y) + area(x1, y1, x, y, x3, y3) + area(x, y, x2, y2, x3, y3));
    if (area(x1, y1, x2, y2, x, y) + area(x1, y1, x, y, x3, y3) + area(x, y, x2, y2, x3, y3) > area(x1, y1, x2, y2, x3, y3)+0.000005){
        return 0;
    }
    else
        return 1;
}
void main()
{
    float x1, y1, x2, y2, x3, y3, x, y;
    printf("Enter the x coordinates:\n");
    scanf("%f%f%f", &x1, &x2, &x3);
    printf("Enter the y coordinates:\n");
    scanf("%f%f%f", &y1, &y2, &y3);
    printf("Enter (x,y) :\n");
    scanf("%f%f", &x, &y);
    if (checkInside(x1, y1, x2, y2, x3, y3, x, y))
        printf("\nInside");
    else
        printf("\nOutside");
}