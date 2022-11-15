#include <iostream>

struct math {

  int m_val{};

  math() = default;

  math(int val): m_val(val){}

  auto factorize(math val, const int div = 2) const -> void {
    if(m_val % div == 0) {
      std::cout << div << " * ";
      factorize((m_val / div), div);
    }
    else if(div <= m_val) {
      factorize(m_val, div + 1);
    }
  }
  
  auto fib_series(math &val) const -> int {
    if(m_val <= 1) {
      return m_val;
    }
    return fib_series(m_val - 1) + fib_series(m_val - 2);
  }

  // ~math(){}

};

std::ostream &operator<<(std::ostream &stream, const math &s_entity) {
  stream << s_entity.m_val;
  return stream;
}

auto main() -> int {



}