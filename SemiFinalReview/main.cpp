#include <iostream>

class Algorithms {

  private:

    template<typename ARRAY_TYPE>
    constexpr auto partition(
      ARRAY_TYPE *array,
      ARRAY_TYPE start,
      ARRAY_TYPE end
    ) -> ARRAY_TYPE {

      ARRAY_TYPE pivot{array[end]};
      ARRAY_TYPE pivot_index{start};

      for(auto i{start}; i < end; ++i) {
        if(array[i] <= pivot) {
          std::swap(array[i], array[pivot_index]);
          ++pivot_index;
        }
      }

      std::swap(array[end], array[pivot_index]);

      return pivot_index; 

    }

    template<typename ARRAY_TYPE>
    auto quick_sort(
      ARRAY_TYPE *array,
      ARRAY_TYPE start,
      ARRAY_TYPE end
    ) -> void {
      
      if(start < end) {
        ARRAY_TYPE partition_index{partition(array, start, end)};

        quick_sort(array, start, (partition_index - 1));
        quick_sort(array, (partition_index + 1), end);
      }
      
    }

    template<typename ARRAY_TYPE, typename ARRAY_VAL>
    constexpr auto binary_search(
      ARRAY_TYPE *array, 
      ARRAY_TYPE left, 
      ARRAY_TYPE right, 
      ARRAY_VAL  val_to_search
    ) -> ARRAY_TYPE {

      while(left <= right) {
        ARRAY_TYPE mid{left + (right - left) / 2};

        if(array[mid] == val_to_search) {
          return mid;
        }
        if(array[mid] < val_to_search) {
          left = mid + 1;
        }
        if(array[mid] > val_to_search) {
          right = mid - 1;
        }
      }

      return -1;

    } 

  public:

    Algorithms() = default;

    template<typename ARRAY_TYPE>
    auto sort_items(ARRAY_TYPE *array, ARRAY_TYPE size) -> void {
      quick_sort(array, 0, (size - 1));
    }

    template<typename ARRAY_TYPE, typename ARRAY_VAL>
    constexpr auto search_an_item(
      ARRAY_TYPE *array, ARRAY_TYPE size, ARRAY_VAL  val_to_search
    ) -> ARRAY_TYPE {
      return binary_search(array, 0, (size - 1), val_to_search);
    }

    ~Algorithms() {}; 

};

template<typename ARRAY_TYPE>
auto display_all_item_val(
  const char       *msg,
  ARRAY_TYPE       *array,
  const ARRAY_TYPE size
) -> void {
  std::cout << "\n" << msg << "\n";
  for(size_t i{}; i != static_cast<size_t>(size); ++i) {
    std::cout << "Item Value in Array[" << i << "]: " << array[i] << "\n";
  }
}

auto main(int argc, char **argv) -> decltype(argc) {

  std::atexit([]() -> void {
    std::cout << "\nExit\n";
  });

  Algorithms *algorithms{new Algorithms{}};

  unsigned int array_size{};
  std::cout << "\nEnter your desire Size for Array: ";
  std::cin >> array_size;

  int *array{
    new(std::nothrow) int[static_cast<int>(array_size)]{}
  };
  if(array == nullptr) {
    std::cerr << "\nInvalid Format! We can't create an array like that.\n";
    std::exit(0);
  }

  std::cout << "\n";
  for(size_t i{}; i != static_cast<size_t>(array_size); ++i) {
    std::cout << "Enter Item Value for Array[" << i << "]: ";
    std::cin >> array[static_cast<int>(i)];
  }

  display_all_item_val("Before Sort: ", array, static_cast<int>(array_size));
  
  algorithms->sort_items(array, static_cast<int>(array_size));
  display_all_item_val("After Sort : ", array, static_cast<int>(array_size));

  int find_item_val{};
  std::cout << "\nEnter an Item Value to Search: ";
  std::cin >> find_item_val;

  int item_val_location{
    algorithms->search_an_item(array, static_cast<int>(array_size), find_item_val)
  };

  if(item_val_location == -1) {
    std::cout << "\nItem(" << find_item_val << ") is not Found in Array\n";
  }
  if(item_val_location != -1) {
    std::cout << "\nItem(" << find_item_val << ") is Found in Array[" << item_val_location << "]\n";
  }

  delete algorithms;
  algorithms = nullptr;

  delete array;
  array = nullptr;

  std::exit(0);

}