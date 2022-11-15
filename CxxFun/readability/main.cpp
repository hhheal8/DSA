#include <algorithm> //for std::remove_if
#include <iostream>   
#include <set>       //for std::set
#include <string>    //for std::string
#include <vector>    //for std::vector

auto main() -> int { 

  //1. Too long!
  std::vector<std::pair<std::string, std::string>> name_id{};
  std::vector<std::pair<std::string, std::string>> email_password{};

  
  //Using `using` keyword for aliasing types 

  //`pair_of` - equivalent to std::vector<std::pair<std::string, std::string>>
  using pair_of = std::vector<std::pair<std::string, std::string>>;
  //std::vector<std::pair<std::string, std::string>> now has an alias named - `pair_of`

  
  pair_of name_id{};
  pair_of email_password{};

}