#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1000000

int mod = (int) (pow(10, 9)+7);
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dx9[] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 }, dy9[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

double eps = 1e-10;
int primeNumbers[MAX];
int primeCount = 0;

void primeSieve(int n) {
    bool isPrime[MAX];
    memset(isPrime, true, sizeof(isPrime));

    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            primeNumbers[primeCount++] = p;
        }
    }
}

int gcd(int a, int b) {
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

long long power(long long x, long long y) {
    long long res = 1;
    while (y > 0) {
        if ((y & 1) != 0) {
            res = (res * x) % mod;
        }

        x = (x * x) % mod;
        y = y >> 1;
    }
    return res % mod;
}

int main() {
    int mod = (int) (pow(10, 9) + 7);
    int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
    int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    int dx9[] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 }, dy9[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

    double eps = 1e-10;
    int primeNumbers[MAX];
    int primeCount = 0;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        primeNumbers[primeCount++] = num;
    }

    return 0;
}
