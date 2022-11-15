#include <iostream>

template<typename Array1D>
auto insertion_sort(Array1D *arr, const size_t &size) -> void {

  for(size_t i = 1; i <= n - 1; i++) {
    size_t curr = arr[i];
    size_t prev = i - 1;

    while(prev >= 0 && arr[prev] > curr) {
      arr[prev + 1] = arr[prev];
      prev = prev - 1;
    }

    arr[prev + 1] = curr;
  } 

}

auto main() -> int {

  

}