#include<stdio.h>
#include<math.h>
int main()
{
    double x1, x2, x3, y1, y2, y3, a, b, c, P, A, s, cosA, cosB, cosC, sinA, sinB, sinC, tanA, tanB, tanC, R, x, y, h, k, p, q, f, g;

    //taking inputs from user

    printf(" \nThis programme gives the properties of a tringle given by the verteces entered by the user.\nPlease enter the coordinates of the first vertex A.\nx1=");
    scanf("%lf", &x1);
    printf("y1=");
    scanf("%lf", &y1);
    printf("Please enter the coordinates of the second vertex B.\nx2=");
    scanf("%lf", &x2);
    printf("y2=");
    scanf("%lf", &y2);
    printf("Please enter the coordinates of the third vertex C.\nx3=");
    scanf("%lf", &x3);
    printf("y3=");
    scanf("%lf", &y3);
    
    //defining side lengths 

    c=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    a=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
    b=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));

    //defining perimeter, area, half-perimeter, and radius of circumcircle 

    P=a+b+c;
    s=P/2;
    A=sqrt(s*(s-a)*(s-b)*(s-c));
    R=(a*b*c)/(4*A);

    //defining trigonometric quantities

    cosA=(b*b+c*c-a*a)/(2*b*c);
    cosB=(c*c+a*a-b*b)/(2*c*a);
    cosC=(a*a+b*b-c*c)/(2*a*b);
    sinA=sqrt(1-cosA*cosA);
    sinB=sqrt(1-cosB*cosB);
    sinC=sqrt(1-cosC*cosC);
    tanA=sinA/cosA;
    tanB=sinB/cosB;
    tanC=sinC/cosC;

    //defining coordiantes of G, I, O and C
    //G=x,y
    //C=h,k
    //I=p,q
    //O=f,g

    x=(x1+x2+x3)/3;
    y=(y1+y2+y3)/3;
    h=(x1*sinA*cosA+x2*sinB*cosB+x3*sinC*cosC)/(sinA*cosA+sinB*cosB+sinC*cosC);
    k=(y1*sinA*cosA+y2*sinB*cosB+y3*sinC*cosC)/(sinA*cosA+sinB*cosB+sinC*cosC);
    p=(a*x1+b*x2+c*x3)/(a+b+c);
    q=(a*y1+b*y2+c*y3)/(a+b+c);
    f=(x1*tanA+x2*tanB+x3*tanC)/(tanA+tanB+tanC);
    g=(y1*tanA+y2*tanB+y3*tanC)/(tanA+tanB+tanC);

    //asking user what info they want to know

    char choice;
    printf("What property do you want to know about the traingle? Choose one of the following options.\n");
    printf("'a' for BC side length, 'b' for AC side length, and 'c' for AB side length.\n");
    printf("'P' for perimeter.\n'A' for area.\n'R' for radius of circumcircle.\n");
    printf("'G' for the centre of gravity.\n'C' for the circumcentre.\n");
    printf("'I' for the incentre.\n'O' for the orthocentre.\nchoice :");
    scanf(" %c", &choice);

    //last step: printing results.

    if (choice=='a')
    {
        printf("Length of the side BC is: %.2lf units.", a);
    }
    else if (choice=='b')
    {
        printf("Length of the side AC is: %.2lf units.", b);
    }
    else if (choice=='c')
    {
        printf("Length of the side AB is: %.2lf units.", c);
    }
    else if (choice=='P')
    {
        printf("The perimeter of the triangle is: %.2lf units.", P);   
    }
    else if (choice=='A')
    {
        printf("The area of the triange is: %.2lf sq units.", A);
    }
    else if (choice=='R')
    {
        printf("The radius of the circumcircle of ABC is %.2lf units.", R);
    }
    else if (choice=='G')
    {
        printf("The centre of gravity is located at G(%.2lf,%.2lf).", x, y);   
    }
    else if (choice=='C')
    {
        printf("The circumcentre is located at C(%.2lf,%.2lf).", h, k);   
    }
    else if (choice=='I')
    {
        printf("The incentre is located at I(%.2lf,%.2lf).", p, q);   
    }
    else if (choice=='O')
    {
        printf("The orthocentre is located at O(%.2lf,%.2lf).", f, g);   
    }

    else
    {
        printf("The choice does not exist.");
    }   
return 0;
}