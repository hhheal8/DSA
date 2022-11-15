#include <iostream>

/*
  REVIEW: 
  Function to iterate from beginning until the end of an array

  @param beginning first index of an array
  @param end size of an array
  @param fun function to print the values of the array
*/
template<typename Collections, typename UnaryFunction>
constexpr auto iterate_through(
  Collections   beginning, 
  Collections   end, 
  UnaryFunction fun
) -> UnaryFunction {

  while(beginning != end) {
    fun(*beginning);
    ++beginning;
  }

  return fun;

}

auto main() -> int {

  int size{};

  std::cout << "Enter size of integer collection: ";
  std::cin >> size;

  int *collection{new(std::nothrow) int[size]{}};

  for(size_t i{}; i != size; ++i) {
    std::cout << "\nEnter Item for Collection[" << i << "]: ";
    std::cin >> collection[i];
  }

  for(size_t i{}; i != size; ++i) {
    std::cout << collection[i];
  }

  delete[] collection;
  collection = nullptr;

}