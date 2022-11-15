#include <iostream>

struct temperature {
  
  double celsius = 0.00;
  double fahrenheit = 0.00;

  double to_fahrenheit = 0.00;
  double to_celsius = 0.00;

  ~temperature(){}

};

auto calculate_fahrenheit(temperature degree) -> double {
  return degree.to_fahrenheit = (degree.celsius * 9 / 5) + 32;
}

auto calculate_celsius(temperature degree) -> double {
  return degree.to_celsius = (degree.fahrenheit - 32) * 5 / 9;
}

auto main() -> int {

  temperature degree;

  double celsius_to_f = 0.00;
  double fahrenheit_to_c = 0.00;

  std::cout << "\nEnter value for Celsius: ";
  std::cin >> degree.celsius;

  std::cout << "Enter value for Fahrenheit: ";
  std::cin >> degree.fahrenheit;

  celsius_to_f = calculate_fahrenheit(degree);
  fahrenheit_to_c = calculate_celsius(degree);

  std::cout << "\n" << degree.celsius << " Celsius to Fahrenheit is " << celsius_to_f << "\n";
  std::cout << degree.fahrenheit << " Fahrenheit to Celsius is " << fahrenheit_to_c;

}