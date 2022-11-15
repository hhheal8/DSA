#include <iostream>
#include <string>

auto main() -> int {

  std::string programming_languages[5] = {
    "C++", "Rust", "JavaScript", "Java", "Dart"
  };

  std::string frameworks[5] = {
    "Open CV", "YEW WebAssembly", "ReactJS", "Java Spring", "Flutter"
  };

  std::string *p_programming_languages = programming_languages;
  std::string *p_frameworks = frameworks;

  std::cout << "Programming Languages Before Swapping:\n";
  for(size_t i = 0; i < std::size(programming_languages); ++i) {
    std::cout << *(p_programming_languages + i) << ' ';
  }

  std::cout << "Frameworks Before Swapping:\n";
  for(size_t i = 0; i < std::size(frameworks); ++i) {
    std::cout << *(p_frameworks + i) << ' ';
  }

  std::cout << "\n";

  //Swapping array elements using pointers

  std::string *p_temp = nullptr;

  p_temp = p_frameworks;
  p_frameworks = p_programming_languages;
  p_programming_languages = p_temp;

  std::cout << "Programming Languages After Swapping:\n";
  for(size_t i = 0; i < std::size(programming_languages); ++i) {
    std::cout << *(p_programming_languages + i) << ' ';
  }

  std::cout << "Frameworks After Swapping:\n";
  for(size_t i = 0; i < std::size(frameworks); ++i) {
    std::cout << *(p_frameworks + i) << ' ';
  }

}