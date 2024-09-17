#include <stdio.h>

long long fastExponentiation(int a, int k) {
    if (k < 0) {
        return -1;  // Handle negative exponents
    } else if (k == 0) {
        return 1;  // Base case: a^0 = 1
    } else {
        long long res = 1;

        while (k > 0) {
            if (k % 2 == 1) {
                res *= a;
            }
            a *= a;
            k /= 2;  // Integer division to prevent overflow
        }

        return res;
    }
}

int main() {
    int base = 2;
    int exponent = 12;

    printf("%lld\n", fastExponentiation(base, exponent));

    return 0;
}