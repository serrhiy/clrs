#include <iostream>

void insertionSort(int* array, int size) {
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
  const int size = 10;
  int* array = new int[size]{ 4, 2, 6, 7, 1, 4, 7, 8, 2, 5 };
  insertionSort(array, size);
  for (int index = 0; index < size; index++) {
    std::cout << array[index] << '\t';
  }
  std::cout << '\n';
  return 0;
}
