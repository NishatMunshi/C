#include <stdio.h>
int array[7] = {1, 2, 3, 4, 5, 6, 7};
void PrintArr(int array[], int size) // prints elements of an integer array given the number of elements.
{
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
}
void swap(int a, int b) // swaps elements at index a and b.
{
    int temp;
    temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}
void ArrayRev(int array[]) // reverses the given array and stores it in that given array.
{
    for (int j = 0; j < 7 / 2; j++) // we go only to size/2 because otherwise reversing will be done 2 times having no net effect.
    {
        swap(j, 6 - j);
    }
}
void main()
{
    printf("Before reversing:\n");
    PrintArr(array, 7);
    ArrayRev(array);
    printf("\nAfter reversing:\n");
    PrintArr(array, 7);
}