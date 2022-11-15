#include <iostream>

struct temperature {

  double val = 0.00;

  temperature() = default; 

  temperature(double val): val(val){}

  auto to_celsius() const -> temperature {
    return (val - 32) * 5 / 9;
  }

  auto to_fahrenheit() const -> temperature {
    return (val * 9 / 5) + 32;
  }

  ~temperature(){}

};

std::ostream &operator<<(std::ostream &stream, const temperature &s_entity) {
  stream << s_entity.val;
  return stream;
}

template<typename ...ALL_VNARGS>
auto dealloc_all(ALL_VNARGS &...s_entity) -> void {
  ((delete s_entity), ...);
  ((s_entity = nullptr), ...);
}

auto main() -> int {

  temperature *celsius = new temperature();
  temperature *fahrenheit = new temperature();

  std::cout << "\nEnter value for Celsius: ";
  std::cin >> celsius->val;

  std::cout << "Enter value for Fahrenheit: ";
  std::cin >> fahrenheit->val;

  std::cout << "\n" << celsius->val << " Celsius to Fahrenheit is " << celsius->to_fahrenheit() << "\n";
  std::cout << fahrenheit->val << " Fahrenheit to Celsius is " << fahrenheit->to_celsius();

  dealloc_all(celsius, fahrenheit);

}