#include <bitset>
#define MAX 10000000 // Adjust as needed for your max 'n'

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        std::bitset<MAX> isPrime;
        isPrime.set(); // Set all bits to true initially
        isPrime[0] = isPrime[1] = 0;

        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = 0;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) count++;
        }

        return count;
    }
};
