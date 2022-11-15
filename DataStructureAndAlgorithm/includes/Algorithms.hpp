#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <string>

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

        //NOTE - Left partition
        quick_sort(array, start, (partition_index - 1));

        //NOTE - Right partition
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

    ~Algorithms() = default; 

};

#endif // ALGORITHMS_H