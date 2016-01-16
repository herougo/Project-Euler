// Eulerproject Question 6
// find square of sum of first 10 numbers minus first 10 squares
// this is essentially 2 times a summation (over all (i,j) pairs where i < j) of ij
// fastest solution: O(1)
// tricks: algebraiic simplification

#include <iostream>
using namespace std;

// sum 1, 2, ... n
// O(1)
int sumOneToN(int n) {
    return n * (n + 1) / 2;
}


// sum 1^2, 2^2, ... n^2
// O(1)
int sumSquaresOneToN(int n) {
    return n * (n + 1) * (2*n + 1) / 6;
}

// sum 1^3, 2^3, ... n^3
// O(1)
int sumCubesOneToN(int n) {
    return (n * (n + 1) * n * (n + 1)) / 4;
}

// brute force
// O(n^2)
int question6Soln1(int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            result += i*j;
        }
    }
    return 2 * result;
}

// algebra simplification of brute force
// - inner loop can be simplified to i * (sum of numbers from i+1 to n)
//   which is i × (sum from 1 to n) - i * (sum from 1 to i)
// note that one can reduce the number of operations, but this is more intuitive
// O(1)
int question6Soln2(int n) {
    return 2 * (sumOneToN(n) * sumOneToN(n - 1)) - sumSquaresOneToN(n - 1) - sumCubesOneToN(n - 1);
}


template <typename T>
void assert(T t1, T t2) {
	if (t1 != t2) { 
		std::cerr << "Failed " << t1 << " " << t2 << std::endl;
	}
}

int main() {
	// Tests
	int n = 0;
	for (n = 0; n <= 100; n++) {
		assert<int>(question6Soln1(n), question6Soln2(n));
	}
	assert<int>(question6Soln1(1), 0);
	assert<int>(question6Soln1(2), 4);
	assert<int>(question6Soln1(3), 22);
	assert<int>(question6Soln1(4), 70);
	assert<int>(question6Soln1(5), 170);

	cout << question6Soln1(100) << endl; // Answer is 25164150
}