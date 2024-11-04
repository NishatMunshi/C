#include<stdio.h>

int main()

{
    int a,b,c,d,e;
    printf("This programme is basically a small calculator thats only meant for small integers \n");
    printf("Enter your first number here :");
    scanf("%d", &a);

    printf("What is the operation that you would like to perform?\n");
    printf("Choose among these symbols: + for addition, - for subtraction, * for multiplication, and / for division\n");
    char sym;
    scanf(" %c", &sym);

    if (sym=='+')
    {
    printf("%d+", a);
    scanf("%d", &b);
    printf("The result is : %d", a+b);
    }

    
   else if (sym=='-')
    {
    printf("%d-", a);
    scanf("%d", &c);
    printf("The result is : %d", a-c);
    }

    else if (sym=='*')
    {
    printf("%d*", a);
    scanf("%d", &d);
    printf("The result is : %d", a*d);
    }
    else if (sym=='/')
    {
    printf("%d/", a);
    scanf("%d", &e);
    printf("The result is : %d", a/e);
    }

   else
   {
    printf("Error: wrong symbol chosen");
   }
return 0;
}
