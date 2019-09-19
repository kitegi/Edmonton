#include <iostream>
#include <map>

using namespace std;

// Returns the length of the chain generated by the Collatz sequence. Uses memoization to increase speed.
unsigned int collatz(unsigned int n) {
	// Check if this number is now equal to 1. If so just return 1.
	if(n == 1) {
		return 1;
	}
	static map<unsigned int, unsigned int> cache;
	// Check to see if we have already covered this number before.
	// If it has been used, we can simply return that number.
	auto it = cache.find(n);
	if(it != cache.end()) {
		return (*it).second;
	}
	// Check if number is even or not, perform based on that.
	unsigned int chain_length = 0;
	if(n % 2 == 0) {
		chain_length = collatz(n / 2) + 1;
	} else {
		chain_length = collatz((3 * n) + 1) + 1;
	}
	cache.emplace(n, chain_length);
	return chain_length;
}

int main(int argc, char *argv[]) {
	unsigned int longest_producer = 1, longest_chain = 0;
	for(unsigned int i = 1; i < 1'000'000; i++) {
		unsigned int chain_length = collatz(i);
		if(chain_length > longest_chain) {
			longest_chain = chain_length;
			longest_producer = i;
		}
	}
	cout << longest_producer << endl;
	return 0;
}