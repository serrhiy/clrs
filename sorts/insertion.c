#include <stdio.h>
#include <stdlib.h>

const int array_size = 10;

void printArray(const int* numbers, const int size) {
  for (int index = 0; index < size; index++) {
    printf("%d ", numbers[index]);
  }
  printf("\n");
}

void insertionSort(int* array, const int size) {
  for (int i = 1; i < size; i++) {
    int key = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
  }
}

int main(const int argc, const char* argv[]) {
  int* numbers = malloc(sizeof(int) * array_size);
  for (int index = 0; index < array_size; index++) {
    numbers[index] = array_size - index;
  }

  printf("Before:\t");
  printArray(numbers, array_size);
  insertionSort(numbers, array_size);
  printf("After:\t");
  printArray(numbers, array_size);

  free(numbers);
  return 0;
}
