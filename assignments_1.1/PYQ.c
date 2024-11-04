#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
unsigned sumOfSquares(unsigned n)
{
    unsigned a = 0;
    while (n != 0)
    {
        a += (n % 10) * (n % 10);
        n = n / 10;
    }
    return a;
}
int isHappy(int n)
{
    int temp1 = n, temp2, i = 0;
    while (i < 100)
    {
        temp2 = sumOfSquares(temp1);
        temp1 = temp2;
        if (temp1 == 1)
        {
            return 1;
        }
        i++;
    }
    return 0;
}
unsigned len(char const *str)
{
    unsigned i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
char *revString(char *str)
{
    char temp;
    const unsigned l = len(str);
    for (int i = 0; i < l / 2; i++)
    {
        temp = str[i];
        str[i] = str[l - i - 1];
        str[l - 1 - i] = temp;
    }
    return str;
}
unsigned numberOfDigits(const unsigned n)
{
    return n == 0 ? 1 : (unsigned)log10(n) + 1;
}
unsigned highestMinusLowest(unsigned n)
{
    const unsigned d = numberOfDigits(n);
    unsigned max = 0, min = 9, arr[d];
    for (unsigned i = 0; i < d; i++)
    {
        arr[i] = n % 10;
        n = n / 10;
    }
    for (unsigned i = 0; i < d; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    return max - min;
}
unsigned max(const unsigned l1, const unsigned l2)
{
    return l1 > l2 ? l1 : l2;
}
unsigned min(const unsigned l1, const unsigned l2)
{
    return l1 < l2 ? l1 : l2;
}
char *specialStrcat(char *s1, char *s2)

{
    const int l1 = strlen(s1), l2 = strlen(s2);
    const unsigned a = max(l1, l2);
    const unsigned b = min(l1, l2);
    char t[l1 + 1];
    strcpy(t, s1);
    for (unsigned i = 0; i < b; i++)
    {
        // printf("loop");
        s1[2 * i] = t[i];
        s1[2 * i + 1] = s2[i];
    }
    if (l1 < l2)
    {
        for (unsigned i = l1; i < l2; i++)
        {
            s1[l1 + i] = s2[i];
        }
    }
    else if (l2 < l1)
    {
        for (unsigned i = l2; i < l1; i++)
        {
            s1[l2 + i] = t[i];
        }
    }
    s1[l1 + l2] = '\0';
    return s1;
}
unsigned noOfAlphabeticCharacters(char const *filename)
{
    FILE *f = fopen(filename, "r");
    char a;
    unsigned count = 0;
    while (a != EOF)
    {
        a = fgetc(f);
        if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
            count++;
    }
    fclose(f);
    return count;
}
unsigned noOfNumericCharacters(char const *filename)
{
    FILE *f = fopen(filename, "r");
    char a;
    unsigned count = 0;
    while (a != EOF)
    {
        a = fgetc(f);
        if ((a >= 48 && a <= 57))
            count++;
    }
    fclose(f);
    return count;
}

void pattern1(const unsigned n)
{
    for (unsigned i = 1; i <= n; i++)
    {
        for (unsigned j = 0; j < (n - i); j++)
        {
            printf("  ");
        }
        for (unsigned j = 1; j <= i; j++)
        {
            printf("%u ", j);
        }
        printf("\n");
    }
}

unsigned search(char const *s, char const *Filename)
{
    FILE *f = fopen(Filename, "r");

    // getting size of buffer needed
    char temp = fgetc(f);
    unsigned size = 0;
    while (temp != EOF)
    {
        size++;
        temp = fgetc(f);
    }

    // allocating memory for buffer and filling it
    char *buffer = (char *)malloc((size + 1) * sizeof(char));
    rewind(f);
    unsigned i = 0;
    temp = fgetc(f);
    while (temp != EOF)
    {
        buffer[i] = temp;
        i++;
        temp = fgetc(f);
    }
    buffer[i] = '\0';
    fclose(f);

    // search process which returns the number of occurances of s in buffer
    i = 0;
    unsigned count = 0;
    while (buffer[i] != '\0')
    {
        if (strstr(buffer + i, s) == buffer + i)
        {
            // at this line i is the index of buffer where s is situated in buffer
            printf("Found at index %d\n", i);
            count++;
        }
        i++;
    }
    return count;
}

double X(const unsigned i)
{
    if (i == 0)
        return 2.0;
    else
    {
        return 2 + 1 / X(i - 1);
    }
}

char *concatenate(char *s1, char const *s2)
{
    int i = 0, j = 0;
    while (s1[i] != '\0')
    {
        i++;
    }
    s1[i] = ' ';
    i++;
    while (s1[j] != '\0')
    {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
    return s1;
}
unsigned fact(const unsigned n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

unsigned comb(const unsigned n, const unsigned r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
void pattern2(const unsigned n)
{
    for (unsigned i = 0; i <= n; i++)
    {
        for (unsigned j = 0; j < n - i; j++)
        {
            printf(" ");
        }
        for (unsigned j = 0; j < i + 1; j++)
        {
            printf("%u ", comb(i, j));
        }
        printf("\n");
    }
}
void count(char const *Filename)
{
    FILE *f = fopen(Filename, "r");
    unsigned i = 0, words = 0;

    // counting characters;
    char temp = fgetc(f);
    while (temp != EOF)
    {
        i++;
        temp = fgetc(f);
    }
    printf("Number of characters = %u\n", i);

    // filling buffer string
    char *buffer = (char *)malloc((i + 1) * sizeof(char));
    i = 0;
    rewind(f);
    temp = fgetc(f);
    while (temp != EOF)
    {
        buffer[i] = temp;
        i++;
        temp = fgetc(f);
    }
    buffer[i] = '\0';
    fclose(f);

    // counting words
    i = 0;
    while (buffer[i] != '\0')
    {
        if ((buffer[i] == ' ' || buffer[i] == '\n') && buffer[i + 1] != ' ' && buffer[i + 1] != '\n' && buffer[i + 1] != EOF)
            words++;
        i++;
    }
    free(buffer);
    words++;
    printf("Number of words = %u\n", words);
}
unsigned bin(const unsigned n)
{
    unsigned temp = n, b = 0, i = 0;

    while (temp != 0)
    {
        b = b + (temp % 2) * pow(10, i);
        temp /= 2;
        i++;
    }
    return b;
}
unsigned flipIthBit(const unsigned n, const unsigned i)
{
    unsigned b = bin(n);
    unsigned d = numberOfDigits(b);
    int *arr = (int *)malloc(d * sizeof(int));
    for (unsigned j = 0; j < d; j++)
    {
        arr[j] = (b / (unsigned)pow(10, d - j - 1)) % 10;
    }
    arr[i - 1] = !arr[i - 1];
    unsigned result = 0;
    for (unsigned j = 0; j < d; j++)
    {
        result += pow(2, d - j - 1) * arr[j];
    }
    return result;
}

struct student
{
    char name[50];
    int roll;
    int marks[6];
    int total;
} s[3];

void swap(int sortedIndices[3], const int i, const int j)
{
    int temp;
    temp = sortedIndices[i];
    sortedIndices[i] = sortedIndices[j];
    sortedIndices[j] = temp;
}
void decreasing(struct student s[3])
{
    int sortedIndices[3] = {0, 1, 2};
    for (unsigned i = 0; i < 3; i++)
    {
        for (unsigned j = 2; j > i; j--)
        {
            if (s[i].total < s[j].total)
                swap(sortedIndices, i, j);
        }
    }
    printf("\nPrinting Merit list:\n");
    for (unsigned i = 0; i < 3; i++)
    {
        printf("name: %s\troll: %d\ttotal: %d\n", s[sortedIndices[i]].name, s[sortedIndices[i]].roll, s[sortedIndices[i]].total);
    }
}

double series(const double x, const unsigned n)
{
    double temp = 0;
    for (unsigned i = 0; 2 * i + 1 <= n; i++)
    {
        temp += pow(-1, i) * pow(x, 2 * i + 1);
    }
    return temp;
}
unsigned sumOfDigits(const unsigned n)
{
    unsigned t = n, s = 0;
    while (t != 0)
    {
        s += t % 10;
        t /= 10;
    }
    return s;
}
unsigned isHarshad(const unsigned n)
{
    unsigned s = sumOfDigits(n);
    if (n % s == 0)
        return 1;
    else
        return 0;
}

void hourMinuteSecond(const unsigned seconds)
{
    unsigned s = seconds, m, h;
    m = s / 60;
    s = s % 60;
    h = m / 60;
    m = m % 60;
    printf("%u hours %u minutes %u seconds.", h, m, s);
}

unsigned revNumber(const unsigned number)
{
    unsigned t = number, s = 0;
    while (t != 0)
    {
        s = s * 10 + t % 10;
        t /= 10;
    }
    return s;
}

unsigned term(const unsigned r)
{
    unsigned temp = 1;
    for (unsigned i = 0; i < r - 1; i++)
    {
        temp = temp * 10 + 1;
    }
    return temp;
}

unsigned sum1(const unsigned n)
{
    unsigned temp = 0;
    for (unsigned i = 1; i <= n; i++)
    {
        temp += term(i);
    }
    return temp;
}

unsigned sum2(const unsigned n, const int arr[n])
{
    int temp = 0;
    for (unsigned i = 0; i < n - 1; i++)
    {
        temp += arr[i] * arr[i + 1];
    }
    return temp;
}

void pattern3(const unsigned n)
{
    for (unsigned i = 1; i <= n; i++)
    {
        for (unsigned j = 0; j < n - i; j++)
        {
            printf(" ");
        }
        for (unsigned j = 0; j < i; j++)
        {
            printf("%d ", j + 1);
        }
        printf("\n");
    }
}

unsigned len2(char const *s)
{
    if (s[0] == '\0')
        return 0;
    else
        return 1 + len2(s + 1);
}

void Union(const unsigned n, const unsigned m, int *a, const int b[m])
{
    int k = n, flag = 0;
    for (unsigned ib = 0; ib < m; ib++)
    {
        flag = 0;
        for (unsigned ia = 0; ia < k; ia++)
        {
            if (b[ib] == a[ia])
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            a[k] = b[ib];
            k++;
        }
    }

    // printing the union
    for (unsigned i = 0; i < k; i++)
    {
        printf("%d ", a[i]);
    }
}

int isBalanced(char const *Filename)
{
    FILE *f = fopen(Filename, "r");
    unsigned numberOfOpeningParanthesis = 0, numberOfClosingParanthesis = 0, sumOfIndices1 = 0, sumOfIndices2 = 0, i = 0;
    char temp = fgetc(f);
    while (temp != EOF)
    {
        if (temp == '(')
        {
            printf("Found opening paranthesis at index %d\n", i);
            numberOfOpeningParanthesis++;
            sumOfIndices1 += i;
        }
        else if (temp == ')')
        {
            printf("Found closing paranthesis at index %d\n", i);
            numberOfClosingParanthesis++;
            sumOfIndices2 += i;
        }
        i++;
        temp = fgetc(f);
    }
    printf("\nNumber of opening paranthesis = %d\n", numberOfOpeningParanthesis);
    printf("\nNumber of closing paranthesis = %d\n", numberOfClosingParanthesis);
    fclose(f);
    if ((numberOfOpeningParanthesis == numberOfClosingParanthesis) && (sumOfIndices1 < sumOfIndices2))
        return 1;
    else
        return 0;
}
void printItself()
{
    FILE *f = fopen("PYQ.c", "r");
    char temp = fgetc(f);
    while (temp != EOF)
    {
        printf("%c", temp);
        temp = fgetc(f);
    }
    fclose(f);
}
int main()
{
    printItself();
}