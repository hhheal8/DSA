#include <iostream>

template<typename Array1D>
auto bubble_sort(Array1D *arr, const size_t &size) -> void {

  for(size_t t = 1; t <= size - 1; t++) {
    for(size_t i = 0; i <= size - t - 1; i++) {
      if(arr[i] > arr[i + 1]) {
        std::swap(arr[i], arr[i + 1]);
      }
    }
  }

}

auto main() -> int {
  
  int arr[] = { -2, 3, 4, -1, 5, -12, 6, 1, 3 };

  size_t size = sizeof(arr) / sizeof(int);

  bubble_sort<int>(arr, size);

  for(auto elements : arr) {
    std::cout << elements << ", ";
  }

}