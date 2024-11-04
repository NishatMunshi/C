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
    int number, temp;
    while (1)
    {
        printf("Enter a number to check whether it is a palindrome or not: ");
        scanf("%u", &number);
        temp = number;
        if (number == 0)
        {
            break;
        }
        else if (number  < 0)
        {
            printf("Number cannot be negative.");
            continue;
        }
        while (number != 0)
        {
            if (number % 10 == 0)
                printf("Number cannot contain 0");
            number = number / 10;
        }
        if (isPalindrome(temp))
        {
            printf("This number is a palindrome\n");
        }
        else
        {
            printf("This number is not a palindrome\n");
        }
    }
}