#include <stdio.h>
#include <stdlib.h>
typedef struct driver
{
    char name[25];
    int ln;
    char route[25];
    int km;
} dri;
dri *ptr;
int n;
void input(int dNo) //dNo = driver number
{
    printf("Driver %d Please Enter your details below:\n\n", dNo + 1);
    printf("Name: ");
    scanf("%s", &ptr[dNo].name);
    printf("Driving License Number: ");
    scanf("%d", &ptr[dNo].ln);
    printf("Route: ");
    scanf("%s", &ptr[dNo].route);
    printf("Kilometers you have travelled: ");
    scanf("%d", &ptr[dNo].km);
    printf("\n");
}
void result(int dNo)
{
    printf("Details of driver %d:\n", dNo + 1);
    printf("Name: %s\n", ptr[dNo].name);
    printf("Driving License Number: %d\n", ptr[dNo].ln);
    printf("Route: %s\n", ptr[dNo].route);
    printf("kilometers travelled: %d\n", ptr[dNo].km);
    printf("\n");
}

void main()
{
    printf("Enter the number of drivers: ");
    scanf("%d", &n);
    ptr = (dri *)calloc(n, sizeof(dri));
    for (int i = 0; i < n; i++)
    {
        input(i);
    }
    printf("\nThe result is as below:\n\n");
    for (int j = 0; j < n; j++)
    {
        result(j);
    }
    free(ptr);
}