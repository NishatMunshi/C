#include <stdio.h>
#include <math.h>
float area(float *a, float *b, float *c)
{
    float s = (*a + *b + *c) / 2;
    return sqrt(s * (s - *a) * (s - *b) * (s - *c));
}
int main()
{
    float a, b, c;
    printf("Enter length of side 1:\t");
    scanf("%f", &a);
    printf("Enter length of side 2:\t");
    scanf("%f", &b);
    printf("Enter length of side 3:\t");
    scanf("%f", &c);
    printf("The area is:\t%f", area(&a, &b, &c));
}
