#include <stdio.h>
int revnum(int num)
{
    int rev = 0;
    while (num != 0)
    {
        rev = rev * 10 + (num % 10);
        num = num / 10;
    }
    return rev;
}
void main()
{
    int num;
    printf("Enter your number: ");
    scanf("%d", &num);
    printf("Number is %d\nReversed number is %d",num, revnum(num) );
}