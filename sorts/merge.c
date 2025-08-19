#include <stdio.h>
#include <stdlib.h>

const int array_size = 10;

void printArray(const int* numbers, const int size) {
  for (int index = 0; index < size; index++) {
    printf("%d ", numbers[index]);
  }
  printf("\n");
}

void merge(int* array, int left, int middle, int right) {
  const int left_part_size = middle - left;
  const int right_part_size = right - middle;

  int* left_part = malloc(sizeof(int) * left_part_size);
  int* right_part = malloc(sizeof(int) * right_part_size);

  for (int i = 0; i < left_part_size; i++) {
    left_part[i] = array[left + i];
  }
  for (int i = 0; i < right_part_size; i++) {
    right_part[i] = array[middle + i];
  }

  int i = 0, j = 0, k = left;
  while (i < left_part_size && j < right_part_size) {
    if (left_part[i] <= right_part[j]) {
      array[k++] = left_part[i];
      i++;
    }
    else {
      array[k++] = right_part[j];
      j++;
    }
  }

  while (i < left_part_size) {
    array[k++] = left_part[i];
    i++;
  }

  while (j < right_part_size) {
    array[k++] = right_part[j];
    j++;
  }

  free(left_part);
  free(right_part);
}

void mergeSort(int* array, int left, int right) {
  if (right - left <= 1) return;
  int middle = (left + right) / 2;
  mergeSort(array, left, middle);
  mergeSort(array, middle, right);
  merge(array, left, middle, right);
}

int main(const int argc, const char* argv[]) {
  int* numbers = malloc(sizeof(int) * array_size);
  for (int index = 0; index < array_size; index++) {
    numbers[index] = array_size - index;
  }
  
  printf("Before:\t");
  printArray(numbers, array_size);
  mergeSort(numbers, 0, array_size);
  printf("After:\t");
  printArray(numbers, array_size);

  free(numbers);
  return 0;
}
