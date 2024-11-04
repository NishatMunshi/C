#include <stdio.h>
int charCount(char s[100])
{
    int i = 0, count = 0;
    while (s[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}
int wordCounter(char s[100])
{
    int i = 0, count = 0;
    while (s[i] != '\0')
    {
        if (s[i] == ' ' && s[i + 1] != ' ')
        {
            count++;
        }
        i++;
    }
    return count + 1;
}
void rev(char s[100])
{
    for (int i = charCount(s) - 1; i >= 0; i--)
    {

        printf("%c", s[i]);
    }
    printf("\n");
}
int main()
{
    char s[100];
    printf("Enter string:\n");
    gets(s);
    printf("characters: %d\n", charCount(s));
    printf("words: %d\n", wordCounter(s));
    printf("reversed: ");
    rev(s);
}