#include <stdio.h>
void main()
{
    char str[1000];
    printf("Enter the string: \n");
    gets(str);
    int counts[256], j = 0;
    for (int i = 0; i < 256; i++)
    {
        counts[i] = 0;
    }
    for (int i = 0; i < 256; i++)
    {
        j = 0;
        while (str[j] != '\0')
        {
            if ((int)(str[j]) == i)
                counts[i]++;
            j++;
        }
    }
    for (int i = 0; i < 256; i++)
    {
        if (counts[i] != 0)
            printf("%c has %d occurences.\n", i, counts[i]);
    }
}