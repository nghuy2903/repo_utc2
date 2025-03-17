#include <iostream>

using namespace std;

long long powerMod(long long base, long long exponent, long long modulus) {
    long long result = 1;
    base %= modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

int main() {
    long long n, m;

    cin >> n >> m;

    long long result = powerMod(n, m, 10);

    cout <<  result ;

    return 0;
}
