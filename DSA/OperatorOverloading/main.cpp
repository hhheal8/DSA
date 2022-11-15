#include <iostream>
#include <string>

struct attributes {

  double val1 = 0;
  double val2 = 0;

  attributes(double val1, double val2) : val1(val1), val2(val2){}

  //Add function
  attributes sum(const attributes &r_other_val) const {
    return attributes(
      val1 + r_other_val.val1, val2 + r_other_val.val2
    );
  }

  attributes operator+(const attributes &r_other_val) const {
    return sum(r_other_val);
  }

  //Multiply function
  attributes multiply(const attributes &r_other_val) const {
    return attributes(
      val1 * r_other_val.val1, val2 * r_other_val.val2
    );
  }

  attributes operator*(const attributes &r_other_val) const {
    return multiply(r_other_val);
  }

  ~attributes(){}

};

std::ostream &operator<<(std::ostream &r_stream, const attributes &r_other_val) {
  r_stream << r_other_val.val1 << ", " << r_other_val.val2;
  return r_stream;
}

auto main() -> int {

  attributes position(4.0, 4.0);
  attributes speed(0.5, 1.5);
  attributes power_up(1.1, 1.1);

  // attributes result = position.add(speed.multiply(power_up)); //without operator overloading
  attributes result = position + speed * power_up;

  std::cout << result << "\n";

}