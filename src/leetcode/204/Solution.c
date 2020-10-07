#include "Solution.h"

int countPrimes(const int n)
{
    if (n == 0) {
        return 0;
    }
    bool isPrime[n];
    for (int i = 2; i < n; i++) {
        isPrime[i] = true;
    }
    int cnt = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            cnt++;
            for (int j = 2; i * j < n; j++) {
                isPrime[i * j] = false;
            }
        }
    }
    return cnt;
}