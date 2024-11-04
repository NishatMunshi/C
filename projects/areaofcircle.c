#include<stdio.h>
#include<math.h>
int main()
{   
    double x1, x2, y1, y2, r, a, d;
    char cont;

    printf(" \nThis programme shows the area and radius of a cicle after taking inputs about the endpoints of its diameter.\nPlease enter one endpoint of the diameter (x1,y1) :\nx1=");
    scanf("%lf", &x1);
    printf("y1=");
    scanf("%lf", &y1);
    printf("Please enter the other endpoint of the diameter (x2,y2) :\nx2=");
    scanf("%lf", &x2);
    printf("y2=");
    scanf("%lf", &y2);

    printf("Just make sure these are true :\n(x1,y1)=(%lf,%lf)\n(x2,y2)=(%lf,%lf)", x1, y1, x2, y2);

    printf("Enter 'y' to continue or 'n' to close the programme. Then you can rerun it.\n");
    scanf(" %c", &cont);

    d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    r=(d/2);
    a=M_PI*r*r;

    if (cont=='y')
    {
        printf("The endpoints the diameter are (%lf,%lf) and (%lf,%lf)\nThe radius of the circle is %.2lf units.\nThe area of the circle is %.2lf sq units", x1, y1, x2, y2, r, a);
    }
    else
    {
        printf("The programme is ended.");
    }
return 0;    
}