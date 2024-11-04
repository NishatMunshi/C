#include <stdio.h>
int count(char string[])
{
    int num = 0;
    while (string[num] != '\0')
    {
        num++;
    }
    return num;
}
void StrCombine(char str1[], char str2[], char combined[])
{
    for (int i = 0; i < count(str1); i++)
    {
        combined[i] = str1[i];
    }
    for (int j = 0; j < count(str2); j++)
    {
        combined[j+count(str1)] = str2[j];
    }
    combined[count(str1) + count(str2) + 1] = '\0';
}
int main()
{
    char str1[] = "test";
    char str2[] = "string";
    char combined[50];
    StrCombine(str1, str2, combined);
    puts(combined);
    printf("%d", count(combined));
    return 0;
}