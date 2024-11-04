// This program removes tags and empty spaces from basic html lines
/*
input:
<h1>This is a heading</h1>

output:
This is a heading
*/
#include <stdio.h>
#include <string.h>
char output[10000];
// function for counting characters in input string (copied from a previous program I wrote)
int NumberOfCharacters(char string[])
{
    int num = 0;
    while (string[num] != '\0')
    {
        num++;
    }
    return num;
}
// function for counting size of opening tag
int OpeningTagSize(char string[])
{
    int index_first = 0;
    while (string[index_first] != '>')
    {
        index_first++;
    }
    return index_first + 1;
}
// function for counting size of closing tag. cant use opening size + 1 because of ending white spaces if there are any.
int ClosingTagSize(char string[])
{
    int index_last = NumberOfCharacters(string) - 1;
    while (string[index_last] != '<')
    {
        index_last--;
    }
    return NumberOfCharacters(string) - index_last;
}
// function for counting white spaces after opening tag
int OpeningWhiteSpaces(char string[])
{
    int count = 0;
    while (string[OpeningTagSize(string) + count] == ' ')
    {
        count++;
    }
    return count;
}
// function for counting white spaces before closing tag
int ClosingWhiteSpaces(char string[])
{
    int count = 0;
    while (string[NumberOfCharacters(string) - ClosingTagSize(string) - count - 1] == ' ')
    {
        count++;
    }
    return count;
}
// function for removing tags and spaces.
void parser(char string[])
{
    // using some smaller variables.
    int noc = NumberOfCharacters(string);
    int ots = OpeningTagSize(string);
    int cts = ClosingTagSize(string);
    int ows = OpeningWhiteSpaces(string);
    int cws = ClosingWhiteSpaces(string);

    for (int i = 0; i < noc - ots - cts - ows - cws; i++)
    {
        output[i] = string[ots + ows + i];
    }
    output[noc - cts - cws] = '\0';
}
void main()
{
    char str[100000];
    printf("Enter the HTML tagline here: ");
    gets(str);
    parser(str);
    puts(output);
}