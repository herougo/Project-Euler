// Eulerproject Question 2
// find sum of even fibonacci numbers <= 4 million
// fastest solution: O(n)
// tricks: sum of first n fibonacci numbers is equal to f_(n+2) - 1, from the first 3n fibonacci numbers, the sum of the even numbers is equal to the sum of the odd ones
// - can be proven by induction or derived with the explicit formula
// - applies to sequence starting with 1, 1, 2, ...

// for this problem, we use f_(n+2) - 2 as the general sum
// sum of even numbers (from first 3n + 2 terms) is (general sum + 1) / 2


const int fib_1 = 1;
const int fib_2 = 2;

// brute force
// O(n)
int question2Soln1(int n) {
    int prev = fib_1;
    int current = fib_2;
    int temp = 0;
    int result = 0;
    
    if (prev % 2 == 0) {
        result += prev;
    }
    
    while (current <= n) {
        if (current % 2 == 0) {
            result += current;
        }
        temp = prev;
        prev = current;
        current += temp;
    }
    return result;
}

// fibonacci property optimization
// assumption that fibonacci sequence with initial terms follow odd odd even pattern
// O(n)
int question2Soln2(int n) {
    int prev = fib_1;
    int current = fib_2;
    int temp = 0;
    int count = 0;
    
    if (prev % 2 == 0) {
        count += prev;
    }
    
    // less calculations in main loop
    while (current <= n) {
        temp = prev;
        prev = current;
        current += temp;
    }
    
    // now use temp for next for loop boundary
    // fibonacci has odd odd even pattern
    if (current % 2 == 0) {
        temp = 2;
    } else if (prev % 2 == 0) {
        temp = 1;
    } else {
        temp = 0;
    }
    
    // go to k+2 fibonacci number where k is the last even fibonacci number
    for (int j = 0; j < ) {
        temp = prev;
        prev = current;
        current += temp;
    }
    
    return (current - 1) / 2;
}