#include <iostream>

auto main() -> int {

  constexpr int size = 5;
  int array[size] = { 100, 200, 300, 400, 500 };

  // for(size_t i = 0; i < size; ++i) {
  //   std::cout << array[i] << "\n";
  // }

  for(size_t i = 0; i < size; ++i) {
    std::cout << "Array index " << i << " memory address is " << &array[i] << "\n";
  }

}