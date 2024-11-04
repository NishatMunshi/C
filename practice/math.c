#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // atoi(string) converts string into integer
int main(int argc, char const *argv[])
{
    int num1=atoi(argv[2]);
    int num2=atoi(argv[3]);
    if (strcmp(argv[1], "sum")==0)
    {
        printf("sum = %d", num1+num2);
    }
    else if (strcmp(argv[1], "sub")==0)
    {
        printf("difference = %d", num1-num2);
    }
    else if (strcmp(argv[1], "mul")==0)
    {
        printf("product = %d", num1*num2);
    }
    else if (strcmp(argv[1], "div")==0)
    {
        printf("quotient = %d", num1/num2);
    }
}
