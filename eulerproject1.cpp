// Eulerproject Question 1
// sum of all multiples of 3 and 5 strictly below 1000
// fastest solution: O(1)
// tricks: algebraic simplification

#include <iostream>
using namespace std;

// sum 1, 2, ... n
// O(1)
int sumOneToN(int n) {
    return n * (n + 1) / 2;
}

// return multiples of multiple below n
// O(1)
int sumMultiples(int multiple, int n) {
	n = n > 0 ? n - 1 : 0;
    return multiple * sumOneToN(n / multiple);
}

// return multiples of p and q below n
// O(n)
int question1Soln1(int p, int q, int n) {
    int result = 0;
    for (int i = 1; i < n; i++) {
        if (i % p == 0 || i % q == 0) {
            result += i;
        }
    }
    return result;
}

// return multiples of p and q below n assuming that gcd(p, q) = 1
// O(1)
int question1Soln2(int p, int q, int n) {
    return sumMultiples(p, n) + sumMultiples(q, n) - sumMultiples(p * q, n);
}

template <typename T>
void assert(T t1, T t2) {
	if (t1 != t2) { 
		std::cerr << "Failed " << t1 << " " << t2 << std::endl;
	}
}

int main() {
	// Tests
	int p = 3;
	int q = 5;
	int n = 0;
	for (n = 0; n < 1001; n++) {
		assert<int>(question1Soln1(p, q, n), question1Soln2(p, q, n));
	}
	assert<int>(question1Soln2(3, 5, 3), 0);
	assert<int>(question1Soln2(3, 5, 5), 3);
	assert<int>(question1Soln2(3, 5, 6), 8);
	assert<int>(question1Soln2(3, 5, 9), 14);
	assert<int>(question1Soln2(3, 5, 10), 23);

	std::cout << question1Soln1(3, 5, 1000) << std::endl; // Answer is 233168
	cin >> n;
}

