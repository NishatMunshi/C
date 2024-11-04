//this app is even more ADVANCED than the other apps.
#include<stdio.h>
#include<string.h>
int main()
{
    int i;
    char s[]="variable for storing input password from user.";
    const char p[]="password here";   //only to be used by the programmer    
    printf(" \nYou need to enter a password to be able to use the programme\n\n");
for (i = 0; i < 3; i++)
{
    switch (i)
    {
    case 0:
    printf("This is your 1st attempt. You have 2 more attempts left.\nPassword: ");
    scanf("%s", &s);
        break;
    case 1:
    printf("This is your 2nd attempt. You have 1 more attempt left.\nPassword: ");
    scanf("%s", &s);
        break;
    case 2:
    printf("This is your 3rd attempt. You will have no more attempts left after this one.\nPassword: ");
    scanf("%s", &s);
        break;
    }
    
    if (strcmp(s, p)==0)
    {
        printf("Correct password, the programme will launch soon.\n\n");
        //start coding here
        //printf("Hello World!");
        break;
    }
    else
    {
        printf("\noops wrong password !\n\n");
    }
}

return 0;
}