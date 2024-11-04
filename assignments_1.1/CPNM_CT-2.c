#include <stdio.h>
unsigned countWords(const char *s)
{
    unsigned i = 0, count = 0;
    while (s[i] != '\0')
    {
        if (s[i] == ' ' && s[i + 1] != ' ' && s[i + 2] != ' ')
            count++;
        i++;
    }
    return count + 1;
}
int main(unsigned argc, char const *argv[])
{
    printf("Number of words = %u", countWords(argv[1]));
    return 0;
}
