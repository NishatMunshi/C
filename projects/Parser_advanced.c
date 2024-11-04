// This program removes tags and empty spaces from basic html lines
/*
input:
<h1>This is a heading</h1>

output:
This is a heading
*/
#include <stdio.h>
#include <string.h>
void parser(char str[])
{
    int in = 0;    // variable to keep track of whether we are inside a tag or not.if in=0(we are outside of any tag) we collect data
    int index = 0; // variable for index of string when we start collecting data.
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '<') /*these lines show us if we're inside a tag or not*/
        {
            in = 1;
            continue;
        }
        else if (str[i] == '>')
        {
            in = 0;
            continue;
        }
        if (in == 0) // now we start collecting data and storing it inside the same string
        {
            str[index] = str[i];
            index++;
        }
    }
    str[index] = '\0';

    // now we need to remove trailing white spaces.
    while (str[0] == ' ')
    {
        // shift string to the left
        int j = 0;
        for (int i = 0; i < strlen(str); i++)
        {
            str[i] = str[i + 1];
        }
    }
    strrev(str);          // reversing the string so we can trim from the beginning again
    while (str[0] == ' ') // same block of code again
    {
        // shift string to the left
        int j = 0;
        for (int i = 0; i < strlen(str); i++)
        {
            str[i] = str[i + 1];
        }
    }
    strrev(str); // reversing it again to restore the earlier reverse
}
void main()
{
    char str[] = "<h1>  This is a heading      </h1>";
    parser(str);
    printf("~~%s~~", str);
}