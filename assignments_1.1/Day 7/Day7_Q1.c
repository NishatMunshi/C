#include <stdio.h>
#include <math.h>
float mean(const int arr[], const unsigned n)
{
    float t = 0;
    for (unsigned i = 0; i < n; i++)
    {
        t += arr[i];
    }
    return t / n;
}
float standardDeviation(const int arr[], const unsigned n)
{
    float t = 0;
    for (unsigned i = 0; i < n; i++)
    {
        t += (arr[i] - mean(arr, n)) * (arr[i] - mean(arr, n));
    }
    t = t / n;
    return sqrt(t);
}

void main()
{
    unsigned arr[30];
    FILE *in = fopen("input.txt", "r");
    unsigned t = 0, a;
    for (unsigned i = 0; i < 30; i++)
    {
        while (t != ':')
        {
            t = fgetc(in);
        }
        t = fgetc(in); // takes in the blank space
        t = 0;
        a = fgetc(in); // the first digit of the number
        do
        {
            t = t * 10 + a - 48;
            a = fgetc(in);
        } while (a != '\n');
        arr[i] = t;
    }
    fclose(in);
    FILE *out = fopen("output.txt", "w");
    fprintf(out, "Mean = %f\nStandard Deviation = %f", mean(arr, 30), standardDeviation(arr, 30));
    fclose(out);
}