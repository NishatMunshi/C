#include <stdio.h>
void swap(int *a, int *b, int *c, int *d)
{
    printf("Value before swapping:\na = %d\nb = %d\nc = %d\nd = %d", *a, *b, *c, *d);
    int t = *d;
    *d = *c;
    *c = *b;
    *b = *a;
    *a = t;
    printf("\n\nValue after swapping:\na = %d\nb = %d\nc = %d\nd = %d", *a, *b, *c, *d);
}
void main()
{
    int a, b, c, d, ch;
    printf("Enter a, b, c and d respectively: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    while (1)
    {
        swap(&a,&b,&c,&d);
        printf("\n\nPress 1 to cyclic swap.\nPress 2 to quit.\n");
        scanf("%d", &ch);
        if (ch == 2)
        {
            break;
        }
    }
}