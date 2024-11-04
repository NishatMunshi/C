#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *const _a, int *const _b) {
  int temp = *_a;
  *_a = *_b;
  *_b = temp;
}
void displayArray(int *array, int length) {
  printf("\nArray:\n");
  for (unsigned i = 0; i < length; i++)
    printf("%d ", array[i]);
  printf("\n");
}

void bubble_sort(int *const _array, unsigned const _length) {
  unsigned numberOfComparisons = 0;

  for (unsigned i = 0; i < _length - 1; ++i) {
    for (unsigned j = 0; j < _length - 1 - i; ++j) {
      numberOfComparisons++;
      if (_array[j] > _array[j + 1]) {
        swap(_array + j, _array + j + 1);
      }
    }
  }
  printf("\nBubble sort done after %d comparisons\n", numberOfComparisons);
}

void quick_sort(int *const _array, int const _left, int const _right,
                unsigned *const _numberOfComparisons) {
  if (_left > _right)
    return; // safety
  // partitioning
  int pivot = _array[_left], down = _left, up = _right;
  while (down < up) {
    (*_numberOfComparisons)++;
    while (_array[down] <= pivot && down < _right) {
      down++;
      (*_numberOfComparisons)++;
    }
    (*_numberOfComparisons)++;
    while (_array[up] > pivot && up > _left) {
      up--;
      (*_numberOfComparisons)++;
    }
    if (down < up)
      swap(_array + down, _array + up);
  }
  _array[_left] = _array[up];
  _array[up] = pivot;

  // recursion
  quick_sort(_array, _left, up - 1, _numberOfComparisons);
  quick_sort(_array, up + 1, _right, _numberOfComparisons);
}
int main() {
  printf("Enter array length: ");
  int length;
  scanf("%d", &length);
  int *array = (int *)malloc(length * sizeof(int));
  int *array2 = (int *)malloc(length * sizeof(int));

  for (unsigned index = 0; index < length; index++) {
    printf("Enter array element %d: ", index);
    int data;
    scanf("%d", &data);
    array[index] = data;
    array2[index] = data;
  }
  displayArray(array, length);

  clock_t bubbleBegin = clock();
  bubble_sort(array, length);
  clock_t bubbleEnd = clock();

  displayArray(array, length);

  int numberOfComparisons = 0;
  clock_t quickBegin = clock();
  quick_sort(array2, 0, length - 1, &numberOfComparisons);
  clock_t quickEnd = clock();

  printf("\nQuick sort done after %d comparisons\n", numberOfComparisons);
  displayArray(array2, length);

  double bubbleTime = (double)(bubbleEnd - bubbleBegin);
  double quickTime = (double)(quickEnd - quickBegin);
  printf("\nTime for Bubble Sort = %f miliseconds\n", bubbleTime);
  printf("Time for Quick Sort = %f miliseconds\n", quickTime);

  free(array);
  free(array2);
  return 0;
}