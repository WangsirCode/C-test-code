#include <iostream>
 
constexpr size_t scale(size_t cnt) {
	return 2 * cnt;
}
 
int main () {
	constexpr size_t sz = 3;
	constexpr size_t s = 3;
    int test = 2;
    size_t a = scale(test);			
	std::cout << sz << std::endl;
	return 0;
}