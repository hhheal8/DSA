#include <iostream>
#include <string>

#include "algorithms.hpp"

template<typename ARRAY_TYPE>
auto display_all_item_val(
  const char       *msg, 
  ARRAY_TYPE       *array, 
  const ARRAY_TYPE size
) -> void {
  std::cout << std::endl << msg << std::endl;
  for(size_t i{}; i != static_cast<size_t>(size); ++i) {
    std::cout << "Item value in Collection[" << i << "]: " << array[i] << std::endl;
  }
}

auto main(int argc, char **argv) -> decltype(argc) {

  std::atexit([]() -> void { 
    std::cout << "\nExit\n"; 
  });

  Algorithms *algorithms = new Algorithms{};

  int size{};

  std::cout << "\nEnter Size of the Collection: ";
  std::cin >> size;

  int *array{
    new(std::nothrow) int[size]{}
  };
  if(array == nullptr) {
    std::cerr << "\nInvalid Format! We can't create an array like that.\n";
    std::exit(0);
  }

  for(size_t i{}; i != static_cast<size_t>(size); ++i) {
    std::cout << "Enter Item for Collection[" << i << "]: ";
    std::cin >> array[i];
  }

  display_all_item_val("Before sort:", array, size);

  algorithms->sort_items(array, size);

  display_all_item_val("After sort :", array, size);
  
  int find_item_val{};
  std::cout << "\nEnter an Item value to search: ";
  std::cin >> find_item_val;

  int item_val_location{
    algorithms->search_an_item(array, size, find_item_val)
  };

  if(item_val_location == -1) {
    std::cout << "\nItem(" << find_item_val << ") is not found in the Collection\n";
  }
  if(item_val_location != -1) {
    std::cout << "\nItem(" << find_item_val << ") is found in Collection[" << item_val_location << "]\n";
  }

  delete algorithms;
  algorithms = nullptr;

  delete[] array;
  array = nullptr;

  std::exit(0);

}
