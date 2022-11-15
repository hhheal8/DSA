#include <iostream>

template<typename Array1D>
auto selection_sort(Array1D *arr, const size_t &size) -> void {

  for(size_t pos = 0; pos <= size - 2; pos++) {

    size_t current = arr[pos];

    size_t min_position = pos;

    for(size_t i = pos; i < size; i++) {
      if(arr[i] < arr[min_position]) { 
        min_position = i;
      }
    }

    std::swap(arr[min_position], arr[pos]);

  }

}

auto main() -> int {

  int array[] = { -2, 3, 4, -1, 5, -12, 6, 1, 3 };

  int size = sizeof(array) / sizeof(int);

  selection_sort<int>(array, size);

  for(auto elements : array) {
    std::cout << elements << ", ";
  }

}