#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    int i;
    char s[]="C";
    float a0=27.5, bb0=29.14, b0=30.87, c1=32.70, db1=34.65, d1=36.71, eb1=38.89, e1=41.2, f1=43.65, gb1=46.25, g1=49.00, ab1=51.91, a1=55; 
    printf("Please enter the note's name (in standard notation): ");
    scanf("%s", &s);
    if (strcmp(s, "A")==0)
    {
        printf("Here is the frequency list for all %s notes.\n", s);
        for ( i = 0; i < 11; i++)
        {
            printf("%s%d --> %.2f Hz\n", s, i, a0*pow(2, i));
        }    
    }
    else if (strcmp(s, "A#")==0||strcmp(s, "Bb")==0)
    {
        printf("Here is the frequency list for all %s notes.\n", s);
        for ( i = 0; i < 11; i++)
        {
            printf("%s%d --> %.2f Hz\n", s, i, bb0*pow(2, i));
        }    
    }
    else if (strcmp(s, "B")==0)
    {
        printf("Here is the frequency list for all %s notes.\n", s);
        for ( i = 0; i < 11; i++)
        {
            printf("%s%d --> %.2f Hz\n", s, i, b0*pow(2, i));
        }    
    }
    else if (strcmp(s, "C")==0)
    {
        printf("Here is the frequency list for all %s notes.\n", s);
        for ( i = 0; i < 11; i++)
        {
            printf("%s%d --> %.2f Hz\n", s, i, c1*pow(2, i-1));
        }    
    }
    else if (strcmp(s, "C#")==0||strcmp(s, "Db")==0)
    {
        printf("Here is the frequency list for all %s notes.\n", s);
        for ( i = 0; i < 11; i++)
        {
            printf("%s%d --> %.2f Hz\n", s, i, db1*pow(2, i-1));
        }    
    }
    else if (strcmp(s, "D")==0)
    {
        printf("Here is the frequency list for all %s notes.\n", s);
        for ( i = 0; i < 11; i++)
        {
            printf("%s%d --> %.2f Hz\n", s, i, d1*pow(2, i-1));
        }    
    }
    else if (strcmp(s, "D#")==0||strcmp(s, "Eb")==0)
    {
        printf("Here is the frequency list for all %s notes.\n", s);
        for ( i = 0; i < 11; i++)
        {
            printf("%s%d --> %.2f Hz\n", s, i, eb1*pow(2, i-1));
        }    
    }
    else if (strcmp(s, "E")==0)
    {
        printf("Here is the frequency list for all %s notes.\n", s);
        for ( i = 0; i < 11; i++)
        {
            printf("%s%d --> %.2f Hz\n", s, i, e1*pow(2, i-1));
        }    
    }
    else if (strcmp(s, "F")==0)
    {
        printf("Here is the frequency list for all %s notes.\n", s);
        for ( i = 0; i < 11; i++)
        {
            printf("%s%d --> %.2f Hz\n", s, i, f1*pow(2, i-1));
        }    
    }
    else if (strcmp(s, "F#")==0||strcmp(s, "Gb")==0)
    {
        printf("Here is the frequency list for all %s notes.\n", s);
        for ( i = 0; i < 11; i++)
        {
            printf("%s%d --> %.2f Hz\n", s, i, gb1*pow(2, i-1));
        }    
    }
    else if (strcmp(s, "G")==0)
    {
        printf("Here is the frequency list for all %s notes.\n", s);
        for ( i = 0; i < 11; i++)
        {
            printf("%s%d --> %.2f Hz\n", s, i, g1*pow(2, i-1));
        }    
    }
    else if (strcmp(s, "G#")==0||strcmp(s, "Ab")==0)
    {
        printf("Here is the frequency list for all %s notes.\n", s);
        for ( i = 0; i < 11; i++)
        {
            printf("%s%d --> %.2f Hz\n", s, i, ab1*pow(2, i-1));
        }    
    }
    else
    {
        printf("No such note exists");
    } 
    return 0;   
}