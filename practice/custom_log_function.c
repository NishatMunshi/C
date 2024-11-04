#include <stdio.h>
#define EXP_PRECISION 13 // TRIED AND TESTED, FACT CAN GIVE CORRECT VALUE UNTIL FACT(12)
#define STEP_SIZE 0.000001
#define LOG_PRECISION 10000 // number of terms of taylor series of ln
#define MAX_ALLOWED_ERROR 0.000001
unsigned fact(const unsigned num) // CHECKED AND FOUND CORRECT
{
    if (num == 0)
        return 1;
    unsigned temp = num;
    for (unsigned i = 1; i < num; i++)
        temp = temp * (num - i);
    return temp;
}
double intPower(const double x, const int exponent) // CHECKED AND FOUND CORRECT
{
    if (exponent < 0)
        return 1 / intPower(x, -exponent);
    if (x == 0)
    {
        if (exponent == 0)
            printf("ERROR!\n");
        else
            return 0;
    }
    else if (x == 1)
        return 1;
    else
    {
        double temp = 1.0;
        for (unsigned i = 0; i < exponent; i++)
            temp *= x;
        return temp;
    }
}
double expo(const double x) // CHECKED AND FOUND CORRECT
{
    if (x == 0)
        return 1;
    else
    {
        double temp = 0.0;
        for (unsigned index = 0; index < EXP_PRECISION; index++)
            temp += (intPower(x, index) / fact(index));
        return temp;
    }
}
double fetch_ln_of_integer(const double a) // checked and found correct
{
    FILE *src = fopen("ln_of_integers.txt", "r");
    unsigned temp;
    for (unsigned line = 0; line < a - 1; line++) // SKIP a-1 LINES
    {
        while (1)
        {
            temp = fgetc(src);
            if (temp == '\n')
                break;
        }
    }
    temp = fgetc(src);
    double lnx = 0.0;
    while (temp != '.')
    {
        lnx = lnx * 10 + temp - 48;
        temp = fgetc(src);
    }
    temp = fgetc(src);
    for (unsigned i = 1; i <= 6; i++) // there are 6 digits after decimal point
    {
        lnx += ((double)(temp - 48) / intPower(10.0, i));
        temp = fgetc(src);
    }
    fclose(src);
    return lnx;
}
double trial_and_error_ln(const double x, const unsigned number_of_points) // CHECKED AND FOUND CORRECT
{
    if (x <= 0)
        printf("ERROR IN THE ARGUMENT OF LOG");
    else if (x < 1 && x > 0)
        return -trial_and_error_ln(1 / x, number_of_points);
    else
    {
        for (unsigned i = (int)(fetch_ln_of_integer(x - number_of_points) / STEP_SIZE); i < (int)((x / 2.5) / STEP_SIZE); i++)
        {
            // printf("testing the %dth input\n", i); // DEBUGGING
            if (x - expo(i * STEP_SIZE) < MAX_ALLOWED_ERROR)
                return i * STEP_SIZE;
        }
    }
}
double iterative_ln(const double x, const double a) // CHECKED AND FOUND CORRECT
{
    FILE *src = fopen("ln_of_integers.txt", "r");
    if (x <= 0)
        printf("ERROR IN THE ARGUMENT OF LOG");
    else if (x < 1 && x > 0)
    {
        double t = 0.0;
        for (unsigned i = 1; i <= LOG_PRECISION; i++)
            t -= intPower((-(x - 1) / 1), i) / i;
        return t;
    }
    else if (x == (double)((int)x)) // if x is an integer we just read it from file. it saves the loop time
        return fetch_ln_of_integer(x);
    else
    {
        double temp = 0.0;
        for (unsigned i = 1; i <= LOG_PRECISION; i++)
            temp -= intPower((-(x - a) / a), i) / i;
        return fetch_ln_of_integer(a) + temp;
    }
    fclose(src);
}
void use() // actually using the programme
{
    double x = 1;
    while (1)
    {
    repeat1:
        printf("\nx = ");
        scanf("%lf", &x);
        if (x == 0)
        {
            printf("You entered x = 0 which broke the loop.");
            break;
        }
        else if (x < 0)
        {
            printf("Logarithm of negative numbers is not defined.");
            goto repeat1;
        }
        printf("\nln(%lf) = %lf\n", x, iterative_ln(x, (double)((int)x)));
    }
}
void add_to_file(const unsigned first_number, const unsigned last_number) // used only for saving data for future calculations.
{
    const unsigned number_of_points = last_number - first_number + 1;
    FILE *dst = fopen("ln_of_integers.txt", "a");
    for (unsigned i = first_number; i <= last_number; i++)
    {
        // printf("\nfilling data for ln(%u)\n", i); // DEBUGGING
        fprintf(dst, "%lf\n", trial_and_error_ln(i, number_of_points));
        printf("ln(%u) = %lf\n", i, trial_and_error_ln(i, number_of_points));
    }
    printf("\nDone.");
    fclose(dst);
}
void make_graph_data(const unsigned limit, const double step_size){
    FILE* fp = fopen("graph_data.csv", "w");
    for(unsigned i = 1; i <= (int)(limit/step_size); i++)
    {
        printf("writing entry number: %u\n", i);
        fprintf(fp, "%lf,%lf\n", i*step_size, expo(i*step_size));
    }
    fclose(fp);
}
int main()
{
    // add_to_file(76, 100);  //speed is proportional to how many numbers you give.
    // use();
    make_graph_data(10, 0.01);

    return 0;
}