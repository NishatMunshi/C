#include <stdio.h>
#include <math.h>
typedef unsigned int ui;
int isPalindrome(ui number)
{
    int digits = 10;
    while ((number / (int)pow(10, digits - 1)) % 10 == 0) // This loop calculates the number of digits of the given number.
    {
        digits -= 1;
    }
    ui list[digits];
    for (int i = 0; i < digits; i++) // This loop puts only the digits of the number into the list array
    {
        list[i] = (number / (int)pow(10, i)) % 10; // (number / (int)pow(10, i)) % 10 this expression is the 10^ith place digit
    }
    int bin = 1; // the binary return value of this function
    for (int i = 0; i < digits / 2; i++)
    {
        if (list[i] != list[digits - i - 1])
        {
            bin = 0;
            break; // breaks the loop upon first encounter with a non matching set of digits
        }
    }
    return bin;
}
void main()
{
    ui number;
    printf("Enter a number to check whether it is a palindrome or not: ");
    scanf("%u", &number);
    if (isPalindrome(number))
    {
        printf("This number is a palindrome\n");
    }
    else
    {
        printf("This number is not a palindrome\n");
    }
}