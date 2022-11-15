#include <iostream>

struct Celsius {
  virtual auto to_fahrenheit() const -> double = 0;
  virtual ~Celsius() {}
};

struct Fahrenheit {
  virtual auto to_celsius() const -> double = 0;
  virtual ~Fahrenheit() {}
};

class Temperature : public Celsius, public Fahrenheit {

  private:
    double *val{nullptr}; 
  
  public:
    Temperature() = default;

    Temperature(double assign_val): val{new double{assign_val}} {}

    auto to_celsius() const -> double final {
      return ((*val) - 32) * 5 / 9;
    }

    auto to_fahrenheit() const -> double final {
      return ((*val) * 9 / 5) + 32;
    }

    ~Temperature() {
      delete val;
      val = nullptr;
    }

};

template<typename ...ENTITIES>
constexpr auto delete_all(ENTITIES &...entities) -> void {
  ((delete entities), ...);
  ((entities = nullptr), ...);
}

auto main() -> int {

  double c_val{27.4};
  double f_val{93.1};

  Celsius *celsius = new Temperature{c_val};
  Fahrenheit *fahrenheit = new Temperature{f_val};

  //Result: 27.4 Celsius to Fahrenheit -> 81.32 Fahrenheit
  std::cout << "\n" << c_val << " Celsius to Fahrenheit is: " << celsius->to_fahrenheit();

  //Result: 93.1 Fahrenheit to Celsius -> 33.94 Celsius
  std::cout << "\n" << f_val << " Fahrenheit to Celsius is: " << fahrenheit->to_celsius();
  
  delete_all(celsius, fahrenheit);

  //Hard Way: Written by Gil Rovero

}