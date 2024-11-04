#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int modularAddition(int a, int b, int MOD) {
    return (a % MOD + b % MOD) % MOD;
}

long modularAddition(long a, long b, long MOD) {
    return (a % MOD + b % MOD) % MOD;
}

int modularMultiplication(int a, int b, int MOD) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

long modularMultiplication(long a, long b, long MOD) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

int modularSubtraction(int a, int b, int MOD) {
    return (a % MOD - b % MOD + MOD) % MOD;
}

long modularSubtraction(long a, long b, long MOD) {
    return (a % MOD - b % MOD + MOD) % MOD;
}

int binaryExponentiation(int x, int n) {
    if (n == 0) return 1;
    else if (n % 2 == 0) return binaryExponentiation(x * x, n / 2);
    else return x * binaryExponentiation(x * x, (n - 1) / 2);
}

long binaryExponentiation(long x, long n) {
    long result = 1;
    while (n > 0) {
        if (n % 2 == 1) result *= x;
        x = x * x;
        n /= 2;
    }
    return result;
}

int modularExponentiation(int x, int n, int MOD) {
    if (n == 0) return 1 % MOD;
    else if (n % 2 == 0) return modularExponentiation(modularMultiplication(x, x, MOD), n / 2, MOD);
    else return modularMultiplication(x, modularExponentiation(modularMultiplication(x, x, MOD), (n - 1) / 2, MOD), MOD);
}

long modularExponentiation(long x, long n, long MOD) {
    long result = 1;
    while (n > 0) {
        if (n % 2 == 1) result = modularMultiplication(result, x, MOD);
        x = modularMultiplication(x, x, MOD);
        n /= 2;
    }
    return result;
}

long factorials(long n) {
    if (n == 0) return 1;
    return n * factorials(n - 1);
}

void distinctPrimeFactors(int n, int *factorials, int *size) {
    int limit = (int) sqrt(n);
    if (n % 2 == 0) {
        factorials[*size] = 2;
        (*size)++;
        while (n % 2 == 0) n /= 2;
    }
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) {
            factorials[*size] = i;
            (*size)++;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 2) {
        factorials[*size] = n;
        (*size)++;
    }
}

void primeFactors(int n, int *factorials, int *size) {
    int limit = (int) sqrt(n);
    if (n % 2 == 0) {
        factorials[*size] = 2;
        (*size)++;
        while (n % 2 == 0) n /= 2;
    }
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) {
            factorials[*size] = i;
            (*size)++;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 2) {
        factorials[*size] = n;
        (*size)++;
    }
}

int binomialCoefficientRecursive(int n, int k) {
    if (k == 0 || k == n) return 1;
    return binomialCoefficientRecursive(n - 1, k - 1) + binomialCoefficientRecursive(n - 1, k);
}

long binomialCoefficientIterative(int n, int k) {
    long C[n + 1][k + 1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= fmin(n, k); ++j) {
            if (j == 0 || j == i) C[i][j] = 1;
            else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}

long nCr(int n, int r) {
    int C[r + 1];
    C[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = fmin(i, r); j > 0; --j) {
            C[j] = C[j] + C[j - 1];
        }
    }
    return C[r];
}

long catlanNumber(int n) {
    long catlan[n + 1];
    catlan[0] = catlan[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            catlan[i] += catlan[j] * catlan[i - 1 - j];
        }
    }
    return catlan[n];
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long lcm(long a, long b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int test = 1;

    while (test-- > 0) {
        int n;
        scanf("%d", &n);
        int ar[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &ar[i][j]);
            }
        }

        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ar[i][i];
        }

        for (int i = 0; i < n; i++) {
            sum += ar[n - i - 1][i];
        }

        for (int i = 0; i < n; i++) {
            sum += ar[(int) (n - 1) / 2][i];
        }

        for (int i = 0; i < n; i++) {
            sum += ar[i][(int) (n - 1) / 2];
        }
        printf("%ld\n", sum - ar[(int) (n - 1) / 2][(int) (n - 1) / 2] * 3);
    }

    return 0;
}
