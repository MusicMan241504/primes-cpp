// List all prime numbers <= n using Sieve of Eratosthenes
// Create array of length n-1
// With indexes 2..n but physically 0..n-2 so any int n has index n-2
// let p = 2, smallest prime number
// enumerate nultiples of p

#include <iostream>
#include <vector>




template <typename T>
void printLoop(const T& a) {
	for (const auto& i : a) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

void printPrimes(const std::vector<bool>& nums, const size_t maxN) {
	for (size_t i{2}; i < maxN; i++) {
		if (nums[i-2]) {
			std::cout << i << ' ';
		}
	}
	std::cout << '\n';
}

int main() {
	size_t maxN {1000000000};
	std::vector<bool> nums(maxN,true); // if true can be prime
					   // if false definetely isn't prime
	for (size_t p{2}; p < maxN; p++) { // iterate through 2...maxN
		if (nums[p-2]) { // if not crossed out
			for (size_t i{p}; i*p <=maxN; i++) {
				nums[i*p-2] = false;
			}
		}
	}

	//printLoop(nums);
	printPrimes(nums,maxN);


	return 0;

}
