#include <stdio.h>
void star(int lines)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
void reverse_star(int lines)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < lines-i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
int main()
{
    int pref, lines;
    printf("Choose 0 for triangular star pattern and 1 for reversed triangular star pattern\n");
    scanf("%d", &pref);
    printf("How many lines of stars do you want to see?\n");
    scanf("%d", &lines);
    switch (pref)
    {
    case 0:        
        star(lines);
        break;
    case 1:
        reverse_star(lines);
        break;
    default:
        break;
    }    
    return 0;
}


