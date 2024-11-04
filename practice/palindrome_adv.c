#include <stdio.h>
#include <math.h>
int reverseNumber(int number) // This function reverses a given integer
{
    int reversed = 0;
    while (number != 0)
    {
        reversed = (reversed * 10 + number % 10);
        number = (number / 10);
    }
    printf("The reversed number is %d\n", reversed);
    return reversed;
}
int isPalindrome(int number) // given binary true false as return value
{
    if (reverseNumber(number) == number)
    {
        return 1;
    }
    return 0; // you dont need to write "else" because if the code enters if statement it returns 1 and closes the function
}
void main()
{
    int number;
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