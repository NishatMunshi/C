#include <stdio.h>
int max(int a, int b)
{
    return a>b?a:b ;
}
int MaxElement(int A[], int n)
{
    if (n == 1)
        return A[0];
    return max(A[n-1], MaxElement(A, n-1));
}
void main()
{
    int arr[10];
    printf("Enter 10 numbers: \n");
    for (int i = 0; i < 10; i++) {
     scanf("%d", &arr[i]);
    }
    printf("\nLargest in given array is %d", MaxElement(arr, 10));
}