#include <stdio.h>
#include <math.h>
int binToDec(int bin)
{
    int t, dec = 0, i = 0;
    if(bin==0)
    return 0;
    while (bin != 0)
    {
        t = bin % 10;
        if ((t != 0 && t != 1)||bin <0)
        {
            printf("Invalid binary number.");
            dec = 0;
            break;
        }
        bin = bin / 10;
        dec += t * pow(2, i);
        i++;
    }
    return dec;
}
int decToBin(int dec)
{
    int bin = 0, rem, i=0;
    if (dec==0)
    return 0;
    if (dec<0)
    {
        printf("Invalid decimal number.\n");
        return 0;
    }
    while (dec != 0)
    {
        rem = dec % 2;
        dec = dec / 2;
        bin += rem*pow(10, i);
        i++;
    }
    return bin;
}
int octToDec(int oct)
{
    int t, dec = 0, i = 0;
    if (oct == 0)
        return 0;
    while (oct != 0)
    {
        t = oct % 10;
        if (oct <0||(t<0)||(t>7))
        {
            printf("Invalid Octal number.");
            dec = 0;
            break;
        }
        oct = oct / 10;
        dec += t * pow(8, i);
        i++;
    }
    return dec;
}
int decToOct(int dec)
{
    int oct = 0, rem, i=0;
    if (dec ==0 )
    return 0;
    if (dec<0)
    {
        printf("Invalid decimal number.\n");
        return 0;
    }
    while (dec != 0)
    {
        rem = dec % 8;
        dec = dec / 8;
        oct += rem*pow(10, i);
        i++;
    }
    return oct;
}
void main()
{
    while (1)
    {
        int num, ch;

        printf("Press 0 to quit.\nPress 1 for binary to decimal\nPress 2 for decimal to binary\nPress 3 for octal to decimal\nPress 4 for decimal to octal\nPress 5 for binary to octal\nPress 6 for octal to binary\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter binary number: ");
            scanf("%d", &num);
            if (num == 0)
                break;
            printf("Decimal Equivalent is: %d\n\n", binToDec(num));
            break;

        case 2:
            printf("Enter decimal number: ");
            scanf("%d", &num);
            if (num == 0)
                break;
            printf("Binary Equivalent is: %d\n\n", decToBin(num));
            break;

        case 3:
            printf("Enter octal number: ");
            scanf("%d", &num);
            if (num == 0)
                break;
            printf("Decimal Equivalent is: %d\n\n", octToDec(num));
            break;

        case 4:
            printf("Enter decimal number: ");
            scanf("%d", &num);
            if (num == 0)
                break;
            printf("Octal Equivalent is: %d\n\n", decToOct(num));
            break;

        case 5:
            printf("Enter binary number: ");
            scanf("%d", &num);
            if (num == 0)
                break;
            printf("Octal Equivalent is: %d\n\n", decToOct(binToDec(num)));
            break;  

        case 6:
            printf("Enter octal number: ");
            scanf("%d", &num);
            if (num == 0)
                break;
            printf("Binary Equivalent is: %d\n\n", decToBin(octToDec(num)));
            break;
        case 0:
            goto end;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    end:
}