#include <iostream>

void merge(int* array, int left, int middle, int right) {
  int leftLength = middle - left;
  int rightLength = right - middle;
  int* leftCopy = new int[leftLength];
  int* rightCopy = new int[rightLength];

  for (int index = 0; index < leftLength; index++) {
    leftCopy[index] = array[left + index];
  }
  for (int index = 0; index < rightLength; index++) {
    rightCopy[index] = array[middle + index];
  }

  int i = 0, j = 0, k = left;
  while (i < leftLength && j < rightLength) {
    if (leftCopy[i] < rightCopy[j]) {
      array[k] = leftCopy[i];
      i++;
    } else {
      array[k] = rightCopy[j];
      j++;
    }
    k++;
  }

  while (i < leftLength) {
    array[k] = leftCopy[i];
    i++;
    k++;
  }

  while (j < rightLength) {
    array[k] = rightCopy[j];
    j++;
    k++;
  }

  delete[] leftCopy;
  delete[] rightCopy;
}

void mergeSort(int* array, int left, int right) {
  if (right - left <= 1) return;
  int middle = (left + right) / 2;
  mergeSort(array, left, middle);
  mergeSort(array, middle, right);
  merge(array, left, middle, right);
}

int main(const int argc, const char* argv[]) {
  const int size = 10;
  int* array = new int[size]{ 4, 2, 6, 7, 1, 4, 7, 8, 2, 5 };
  mergeSort(array, 0, size);
  for (int index = 0; index < size; index++) {
    std::cout << array[index] << '\t';
  }
  std::cout << '\n';
  return 0;
}
