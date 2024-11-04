#include <stdio.h>
#include <math.h>
float euclidianDistance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
float area(int x1, int y1, int x2, int y2, float (*ptr)(int, int, int, int))
{
    float rad = (*ptr)(x1, y1, x2, y2);
    return M_PI * rad * rad;
}
void main()
{
    int x1,y1,x2,y2;
    float (*ptr)(int, int, int, int);
    ptr = &euclidianDistance;
    printf("enter x1: ");
    scanf("%d", &x1);
    printf("enter y1: ");
    scanf("%d", &y1);
    printf("enter x2: ");
    scanf("%d", &x2);
    printf("enter y2: ");
    scanf("%d", &y2);
    printf("The area of the circle is %f", area(x1,y1,x2,y2,ptr));
}
