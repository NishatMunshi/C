#include<stdio.h>
#include<math.h>
#include<string.h>
#define pi 3.14
#define e 2.71

int main()
{
    double num;
    int i=1;
    printf("\nYOU NEED TO ENTER THE PASSWORD (4 digit number) THAT OPENS THIS PROGRAMME\n");

    do
    {
        printf("\nPassword: ");
        scanf("%lf", &num);
        i++;
        if (num==1234)
        {
            printf("Correct Password! The programme will launch soon.\n\n");
            double a, b, c, d, sumr, sumi, subr, subi, mulr, muli, divr, divi, AM, GM, HM, mod, lnr, lni, sinr, sini, cosr, cosi, tanr, tani,sinhr, sinhi, coshr, coshi, tanhr, tanhi, powr, powi;

    //taking inputs from user
    char ch='n';
    printf(" \nThis programme is the updated version of the calculator I made earlier.\n\n");
    printf("This version uses two numbers given by the user to do addition, subtraction, multiplication, division or it can also calculate their AM, GM or HM (if they are real) and all other kinds of stuff including modulus, power, natural log.\n\n");
    do
    {
    printf("Please enter the first number in complex plane in the form a+ib: \n\na=");
    scanf("%lf", &a);
    printf("b=");
    scanf("%lf", &b);
    printf("\nPLease make sure this is the complex number you want to use: (%.2lf+(%.2lf)i)\n", a, b);
    printf("\nEnter anything EXCEPT 'n' to continue or enter 'n' to re-input the values of a and b.\nChoice: ");
    scanf(" %c", &ch);
    }
    while(ch=='n');

    //asking user what operation to perform
    char str[]="s";
    char cho='n';
    do
    {
    printf("\nChoose what operation to perform.\noptions: sum, sub, mul, div, mod, arg, ln, power, sin, cos, tan, sinh, cosh, tanh\n");
    printf("Remember AM, GM, HM only work for pure real numbers.\n\n");
    scanf("%s", &str);
    printf("\nOption chosen: %s\n\n", str);
    printf("Enter anything EXCEPT 'n' to continue or enter 'n' to choose another option.\nChoice: ");
    scanf(" %c", &cho);
    } while (cho=='n');
    
    //predefining some terms
        mod=sqrt(a*a+b*b);
        lnr=log(mod);
        
        sinr=sin(a)*cosh(b);
        sini=cos(a)*sinh(b);
        cosr=cos(a)*cosh(b);
        cosi=sin(a)*sinh(b);
        tanr=(tan(a)-tan(a)*tanh(b)*tanh(b))/(1+tan(a)*tan(a)*tanh(b)*tanh(b));
        tani=(tanh(b)+tan(a)*tan(a)*tanh(b))/(1+tan(a)*tan(a)*tanh(b)*tanh(b));
        sinhr=sinh(a)*cos(b);
        sinhi=cosh(a)*sin(b);
        coshr=cosh(a)*cos(b);
        coshi=sinh(a)*sin(b);
        tanhr=(tanh(a)+tanh(a)*tan(b)*tan(b))/(1+tanh(a)*tanh(a)*tan(b)*tan(b));
        tanhi=(tan(b)-tanh(a)*tanh(a)*tan(b))/(1+tanh(a)*tanh(a)*tan(b)*tan(b));

    double theta;
    if (a>0)
        {
            theta=atan(b/a);
        }
    else if (a<0&&b>0)
        {
            theta=pi-atan(b/(-a));
        }
    else if (a<0&&b<0)
        {
            theta=-pi+atan(b/a);
        }
    else if (a==0&&b>0)
    {
        theta=pi/2;
    }
    else if (a==0&&b<0)
    {
        theta=-pi/2;
    }
    else if (a>0&&b==0)
    {
        theta=0;
    }
    else if (a<0&&b==0)
    {
        theta=pi;
    }
    else if (a==0&&b==0)
    {
        printf("The complex number is zero.");
    }
    else

        {
            printf("The complex number is invalid.");
        }
    lni=theta;
       
        

    //performing the calculations    
    if (strcmp(str, "sum")==0)
    { 
        printf("\nEnter the second complex number in the form c+id: \n\nc=");
        scanf("%lf", &c);
        printf("d=");
        scanf("%lf", &d);
        sumr=a+c;
        sumi=b+d;
        printf("The result is (%.2lf+(%.2lf)i)", sumr, sumi);
    }
    else if (strcmp(str, "sub")==0)
    {
        printf("\nEnter the second complex number in the form c+id: \n\nc=");
        scanf("%lf", &c);
        printf("d=");
        scanf("%lf", &d);
        subr=a-c;
        subi=b-d;
        printf("The result is (%.2lf+(%.2lf)i)", subr, subi);
    }
    else if (strcmp(str, "mul")==0)
    {
        printf("\nEnter the second complex number in the form c+id: \n\nc=");
        scanf("%lf", &c);
        printf("d=");
        scanf("%lf", &d);
        mulr=a*c-b*d;
        muli=a*d+b*c;
        printf("The result is (%.2lf+(%.2lf)i)", mulr, muli);
    }
    else if (strcmp(str, "div")==0)
    {        
        printf("\nEnter the second complex number in the form c+id: \n\nc=");
        scanf("%lf", &c);
        printf("d=");
        scanf("%lf", &d);
        divr=(a*c+b*d)/(c*c+d*d);
        divi=(b*c-a*d)/(c*c+d*d);
        printf("The result is (%.2lf+(%.2lf)i)", divr, divi);
    }
    
    else if (strcmp(str, "mod")==0)
    {
        printf("\nThe modulus of the complex number is %.2lf", mod);
    }
    else if (strcmp(str, "arg")==0)
    {
        printf("\nThe argument of the complex number is %.2lf", theta);
    }
    else if (strcmp(str, "ln")==0)
    {
        printf("\nThe principal branch of the complex natural logarithm of the complex number is (%.2lf+(%.2lf)i)", lnr, lni);
    }
    else if (strcmp(str, "power")==0)
    {       
        printf("\nEnter the second complex number in the form c+id: \n\nc=");
        scanf("%lf", &c);
        printf("d=");
        scanf("%lf", &d);
        powr=pow(mod, c)*pow(e, (-d*theta))*cos(c*theta+d*lnr);
        powi=pow(mod, c)*pow(e, (-d*theta))*sin(c*theta+d*lnr);
        printf("The result is: (%.2lf)+(%.2lf)i", powr, powi);
    }   

    else if (strcmp(str, "sin")==0)
    {
        printf("\nThe Sine of the complex number is (%.2lf+(%.2lf)i)", sinr, sini);
    }
    else if (strcmp(str, "cos")==0)
    {
        printf("\nThe Cosine of the complex number is (%.2lf-(%.2lf)i)", cosr, cosi);
    }
    else if (strcmp(str, "tan")==0)
    {
        printf("\nThe Tangent of the complex number is (%.2lf+(%.2lf)i)", tanr, tani);
    }
    else if (strcmp(str, "sinh")==0)
    {
        printf("\nThe Hyperbloic Sine of the complex number is (%.2lf+(%.2lf)i)", sinhr, sinhi);
    }
    else if (strcmp(str, "cosh")==0)
    {
        printf("\nThe Hyperbloic Cosine of the complex number is (%.2lf+(%.2lf)i)", coshr, coshi);
    }
    else if (strcmp(str, "tanh")==0)
    {
        printf("\nThe Hyperbloic Tangent of the complex number is (%.2lf+(%.2lf)i)", tanhr, tanhi);
    }
    
    else if (strcmp(str, "AM")==0)
    {
        if (b==0)
        {
        printf("\nEnter the second complex number in the form c+0i: \n\nc=");
        scanf("%lf", &c);
        printf("The AM of the two real numbers %.2lf and %.2lf is %.2lf", a, c, (a+c)/2);
        }
        else
        {
            printf("Cannot compute the AM when both numbers are not purely real.");
        }
    }
    else if (strcmp(str, "GM")==0)
    {
        if (b==0)
        {
        printf("\nEnter the second complex number in the form c+0i: \n\nc=");
        scanf("%lf", &c);
        printf("The GM of the two real numbers %.2lf and %.2lf is %.2lf", a, c, sqrt(a*b));
        }
        else
        {
            printf("Cannot compute the GM when both numbers are not purely real.");
        }
    }
    else if (strcmp(str, "HM")==0)
    {
        if (b==0)
        {
        printf("\nEnter the second complex number in the form c+0i: \n\nc=");
        scanf("%lf", &c);
        printf("The HM of the two real numbers %.2lf and %.2lf is %.2lf", a, c, 2*a*c/(a+c));
        }
        else
        {
            printf("Cannot compute the HM when both numbers are not purely real.");
        }
    }        
    else
    {
        printf("\n'%s' is not a valid option", str );

    }       
        }
        else
        {
            printf("Wrong password. you have %d chances left.", 4-i);
        }    
    } while (num!=1234&&i<=3);
    
return 0;   
}