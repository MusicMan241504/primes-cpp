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

int sieve() {
	size_t maxN {1000000000};
	std::vector<bool> nums(maxN,true); // if true can be prime
					   // if false definetely isn't prime
	for (size_t i{2}; i*i < maxN; i++) { // iterate through 2...maxN
					   // largest factor of maxN is sqrt(maxN) so p^2 < maxN
		if (nums[i-2]) { // if not crossed out

			for (size_t j{i}; i*i+i*j <=maxN; j++) { // iterates to calculate multiples of i
								 // only need to check n > i^2 as any nums below that will already be crossed out so check for i^2 + j, i^2 + 2j, i^2 + 3j. Which is i^2 + i*j
				nums[i*i+i*j-2] = false;
			}
		}
	}

	//printLoop(nums);
	//printPrimes(nums,maxN);
	



	return 0;

}

int main() {
	sieve();
	return 0;
}
