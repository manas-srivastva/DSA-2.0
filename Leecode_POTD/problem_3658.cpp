#include <iostream>
#include <numeric> // Required for std::gcd

// The standalone function with the class wrapper removed
int gcdOfOddEvenSums(int n) {
    int sumOdd = n * n;
    int sumEven = (n * n) + n;
    
    // std::gcd is the standard C++ way to calculate GCD
    int gcD = std::gcd(sumOdd, sumEven);
    return gcD;
}

int main() {
    // Example test case
    int n;
    std::cout << "Enter a value for n: ";
    std::cin >> n;

    int result = gcdOfOddEvenSums(n);
    
    std::cout << "The GCD of odd and even sums is: " << result << std::endl;

    return 0;
}