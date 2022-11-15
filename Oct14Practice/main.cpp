#include <array>
#include <iostream>
#include <utility>

static constexpr size_t max_index_64bit_val{93};

//Calculate the nth Fibonacci Number
static constexpr auto get_fibonacci_number(size_t index) -> size_t {
  size_t f1{0}, f2{1};
  while(index--) {
    size_t f3{f2 + f1};
    f1 = f2;
    f2 = f3;
  }
  return f2;
}

template<size_t ...INDICES>
static constexpr auto generate_array_helper(std::integer_sequence<size_t, INDICES...>) noexcept {
  return std::array<size_t, sizeof...(INDICES)> {
    {get_fibonacci_number(INDICES)...}
  };
}

static constexpr auto generate_array() noexcept {
  return generate_array_helper(
    std::make_integer_sequence<size_t, max_index_64bit_val>()
  );
}

static constexpr auto fibonacci_series = generate_array();

auto main() -> int {

  for(size_t i{}; i < max_index_64bit_val; ++i) {
    std::cout << i << "\t->\t" << fibonacci_series[i] << "\n";
  }

}