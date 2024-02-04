#include <iostream>
int main() {
	size_t n {100};

	for (size_t i {1}; i < n; i+=2*3) {
			for (size_t k {0}; k < 6; k+=4) {

			std::cout << i+k << ' ';
			}
	}
	


	return 0;
}
