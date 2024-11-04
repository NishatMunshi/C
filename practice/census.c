#include <stdio.h>
void main()
{
    int m, l, lm, p, M, F, Lm, Lf, iLm, iLf, L;
repeat:
    printf("Enter percentage of men: ");
    scanf("%d", &m);
    printf("Enter percentage of total literacy: ");
    scanf("%d", &l);
    printf("Enter percentage of literate men: ");
    scanf("%d", &lm);
    printf("Enter total population: ");
    scanf("%d", &p);
    if (m > 100 || l > 100 || lm > 100)
    {
        printf("Inavlid data. Input data again.\n");
        goto repeat;
    }
    M = p * m / 100;
    F = p - M;
    L = p * l / 100;
    Lm = M * lm / 100;
    iLm = M - Lm;
    Lf = L - Lm;
    iLf = F - Lf;
    printf("Total number of illiterate men: %d\n", iLm);
    printf("Total number of illeterate women: %d", iLf);
}