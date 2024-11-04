#include<stdio.h>
#include<math.h>
int main()
{
    double a, b, c, Sa, Sg, Tna, Tng, r, d;
    double n;
    // taking inputs

    printf("This programme lets you find nth term and sum upto n terms of AP or GP,\n");
    printf("All you have to do is input the first three terms of the sequence and the programme will automatically identify it as AP or GP.\n");
    printf("Please enter the first term :");
    scanf("%lf", &a);
    printf("Please enter the second term :");
    scanf("%lf", &b);
    printf("Please enter the third term :");
    scanf("%lf", &c);

    //identifying as AP or GP

    if (2*b==(a+c))
    {
        char ch;
        d=b-a;
        printf("Your sequence is an AP with common difference %.3lf\n", d);
        printf("Choose one of the options below\n");
        printf("'s' for sum upto n terms, 't' for showing the nth term.\nchoice :");
        scanf(" %c", &ch);
        
        if (ch=='s')
        {
            printf("Enter the number of terms you want the sum of.\nn=");
            scanf("%lf", &n);
            
            if (floor(n)==n&&n>0)
            {
            Sa=n*a+n*(n-1)*d/2;
            printf("The resultant sum is S=%.3lf", Sa);
            }
            else
            {
                printf("The input for 'n' is invalid.");
            }
        }
        else if (ch=='t')
        {
            printf("Enter the value for n for which you want to know the nth term.\nn=");
            scanf("%lf", &n);

            if (floor(n)==n&&n>0)
            {
                Tna=a+(n-1)*d;
                printf("The %.0lfth term of the AP is T%.0lf=%.3lf", n, n, Tna);
            }
            else
            {
                printf("The input for n is not valid.");
            }            
        }
        else
        {
            printf("Invalid option chosen.");
        }   
    }

    else if (b*b==a*c)
    {
        char ch;
        r=b/a;
        printf("Your sequence is a GP with common ratio %.3lf\n", r);
        printf("Choose one of the options below\n");
        printf("'s' for sum upto n terms, 't' for showing the nth term.\nchoice :");
        scanf(" %c", &ch);
        
        if (ch=='s')
        {
            printf("Enter the number of terms you want the sum of.\nn=");
            scanf("%lf", &n);
            
            if (floor(n)==n&&n>0)
            {
            Sg=a*(pow(r, n)-1)/(r-1);
            printf("The resultant sum is S=%.3lf", Sg);
            }
            else
            {
                printf("The input for 'n' is invalid.");
            }
        }
        else if (ch=='t')
        {
            printf("Enter the value for n for which you want to know the nth term.\nn=");
            scanf("%lf", &n);

            if (floor(n)==n&&n>0)
            {
                Tng=a*pow(r, (n-1));
                printf("The %.0lfth term of the GP is T%.0lf=%.3lf", n, n, Tng);
            }
            else
            {
                printf("The input for n is not valid.");
            }            
        }
        else
        {
            printf("Invalid option chosen.");
        }   
    }
    else
    {
        printf("The given sequence is neither an AP nor a GP.");
    }
return 0;
}