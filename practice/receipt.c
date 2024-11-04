#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *replaceWord(const char *str, const char *oldWord, const char *newWord)
{
    char *resultString;
    int oldWordLength = strlen(oldWord); // we need these in order to know how much memory resultString needs
    int newWordLength = strlen(newWord);
    int count = 0; // this variable stores the number of times oldWord appears in str

    for (int i = 0; str[i] != '\0'; i++) // traverse the whole string to find oldWord and increment count
    {
        if (strstr(&str[i], oldWord) == &str[i]) // this condition checks if we are at the address of oldWord
        {
            count++;                // we found an occurance of oldWord so increment count
            i += oldWordLength - 1; // we skip some iterations to skip the oldWord. '-1' bc loop itself increases i by 1
        }
    } // at this point we know how many times oldWord appears in str.

    resultString = (char *)malloc(strlen(str) + count * (newWordLength - oldWordLength) + 1); // dynamically allocates memory required for resultString. "+1" accounts for the memory for null char

    int i = 0;
    int j = 0;
    while (str[i] != '\0') // this loop replaces all occurances of oldword with newword
    {
        if (strstr(&str[i], oldWord) == &str[i]) // this condition checks if we are at the address of oldWord
        {
            strcpy(&resultString[j], newWord); // we copy new word in the address of resultstrig[i]
            i += oldWordLength;                // in str we skip oldword
            j += newWordLength;                // in resultstring we skip a few addresses for insering newword
        }
        else // if we're not at the address of oldword we simply copy the content of str to resultString
        {
            resultString[j] = str[i];
            i++;
            j++;
        }
    }
    resultString[j]='\0'; //at the end of loop we haev to close it by null char
    return resultString;
}

void main(int argc, char const *argv[]) // argv[1] is the name of customer, argv[2] is the item
{
    FILE *ptr = NULL;
    FILE *ptr2 = NULL;
    ptr = fopen("bill.txt", "r");
    ptr2 = fopen("generatedBill.txt", "w");
    char str[165];
    fgets(str, 165, ptr);
    // printf("THE CONTENT OF bill.txt IS: %s\n", str);

    char *newStr = str;
    // We call our funtion here
    newStr = replaceWord(str, "{{name}}", argv[1]);
    newStr = replaceWord(newStr, "{{item}}", argv[2]);
    newStr = replaceWord(newStr, "{{outlet}}", "Tematha Outlet");

    printf("\nTHE NEWLY GENERATED BILL IS:\n\n %s\n\n", newStr);
    printf("This new content is copied to generatedBill.txt");
    fputs(newStr, ptr2);
    fclose(ptr);
    fclose(ptr2);
}