// stoll example
#include <iostream>   // std::cout
#include <string>     // std::string, std::stoll

int main ()
{
  std::string str = "8246821";

  std::string::size_type sz = 0;   // alias of size_t

//   while (!str.empty()) {
    long long ll = std::stoll (str);
    std::cout << " interpreted as " << ll << '\n';
    std::cout <<" sizeof long long as " << sizeof(long) << '\n';
    // str = str.substr(sz);
//   }
    std::string perfect = std::to_string(ll) + " is a perfect number";
    std::cout <<" ll to str " << perfect << '\n';
  return 0;
}