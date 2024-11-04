#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

long giveAns(long x) {
    int numOfDigits = (int)log10(x) + 1;
    long ans = 0L;
    for (int i = 2; i < numOfDigits; i++)
        ans += 9L * (long)pow(10, i - 2);
    if (numOfDigits > 1)
        ans += 9;
    if (numOfDigits == 1)
        ans += x;
    else {
        int firstDigit = (int)(x / pow(10, numOfDigits - 1));
        int lastDigit = (int)(x % 10);
        ans += (firstDigit - 1) * (long)pow(10, numOfDigits - 2);
        char s[20];
        sprintf(s, "%ld", x);
        for (int j = 1; j < numOfDigits - 1; j++) {
            long val = 1L;
            int digit = s[j] - '0';
            val *= (1L * digit * (long)pow(10, numOfDigits - j - 2));
            ans += val;
        }
        if (firstDigit <= lastDigit)
            ans++;
    }
    return ans;
}

int* createDSU(int n) {
    int* parent = (int*)malloc(n * sizeof(int));
    int* size = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }
    return parent;
}

int findSet(int* parent, int v) {
    if (v == parent[v]) return v;
    return parent[v] = findSet(parent, parent[v]);
}

void unionSets(int* parent, int* size, int a, int b) {
    a = findSet(parent, a);
    b = findSet(parent, b);
    if (a != b) {
        if (size[a] < size[b]) {
            int temp = a;
            a = b;
            b = temp;
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

void fft(double* a, double* b, int count, bool invert) {
    for (int i = 1, j = 0; i < count; i++) {
        int bit = count >> 1;
        for (; j >= bit; bit >>= 1)
            j -= bit;
        j += bit;
        if (i < j) {
            double temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            temp = b[i];
            b[i] = b[j];
            b[j] = temp;
        }
    }
    for (int len = 2; len <= count; len <<= 1) {
        int halfLen = len >> 1;
        double angle = 2 * M_PI / len;
        if (invert)
            angle = -angle;
        double wLenA = cos(angle);
        double wLenB = sin(angle);
        for (int i = 0; i < count; i += len) {
            double wA = 1;
            double wB = 0;
            for (int j = 0; j < halfLen; j++) {
                double uA = a[i + j];
                double uB = b[i + j];
                double vA = a[i + j + halfLen] * wA - b[i + j + halfLen] * wB;
                double vB = a[i + j + halfLen] * wB + b[i + j + halfLen] * wA;
                a[i + j] = uA + vA;
                b[i + j] = uB + vB;
                a[i + j + halfLen] = uA - vA;
                b[i + j + halfLen] = uB - vB;
                double nextWA = wA * wLenA - wB * wLenB;
                wB = wA * wLenB + wB * wLenA;
                wA = nextWA;
            }
        }
    }
    if (invert) {
        for (int i = 0; i < count; i++) {
            a[i] /= count;
            b[i] /= count;
        }
    }
}

long* multiply(long* a, long* b, int aSize, int bSize) {
    int resultSize = 1 << (int)(ceil(log2(fmax(aSize, bSize))) + 2);
    double* aReal = (double*)calloc(resultSize, sizeof(double));
    double* aImaginary = (double*)calloc(resultSize, sizeof(double));
    double* bReal = (double*)calloc(resultSize, sizeof(double));
    double* bImaginary = (double*)calloc(resultSize, sizeof(double));
    for (int i = 0; i < aSize; i++)
        aReal[i] = a[i];
    for (int i = 0; i < bSize; i++)
        bReal[i] = b[i];
    fft(aReal, aImaginary, resultSize, false);
    fft(bReal, bImaginary, resultSize, false);
    for (int i = 0; i < resultSize; i++) {
        double real = aReal[i] * bReal[i] - aImaginary[i] * bImaginary[i];
        aImaginary[i] = aImaginary[i] * bReal[i] + bImaginary[i] * aReal[i];
        aReal[i] = real;
    }
    fft(aReal, aImaginary, resultSize, true);
    long* result = (long*)malloc(resultSize * sizeof(long));
    for (int i = 0; i < resultSize; i++)
        result[i] = (long)round(aReal[i]);
    free(aReal);
    free(aImaginary);
    free(bReal);
    free(bImaginary);
    return result;
}

bool isPrime(long n) {
    if (n < 2)
        return false;
    for (long x = 2; x * x <= n; x++) {
        if (n % x == 0)
            return false;
    }
    return true;
}

long* primeFactorisation(long n, int* size) {
    long* f = (long*)malloc(sizeof(long) * 100); // Arbitrary size
    *size = 0;
    for (long x = 2; x * x <= n; x++) {
        while (n % x == 0) {
            f[(*size)++] = x;
            n /= x;
        }
    }
    if (n > 1)
        f[(*size)++] = n;
    return f;
}

int* sieveOfEratosthenes(int n) {
    int* sieve = (int*)calloc(n + 1, sizeof(int));
    for (int x = 2; x * x <= n; x++) {
        if (sieve[x] != 0)
            continue;
        for (int u = x * x; u <= n; u += x) {
            if (sieve[u] == 0) {
                sieve[u] = x;
            }
        }
    }
    return sieve;
}

long gcd(long a, long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long phi(long n) {
    double result = n;
    for (long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result *= (1.0 - (1.0 / (double)p));
        }
    }
    if (n > 1)
        result *= (1.0 - (1.0 / (double)n));
    return (long)result;
}

typedef struct {
    long d;
    long x;
    long y;
} Name;

Name extendedEuclid(long a, long b) {
    if (b == 0)
        return (Name){a, 1, 0};
    Name n1 = extendedEuclid(b, a % b);
    return (Name){n1.d, n1.y, n1.x - (long)floor((double)a / b) * n1.y};
}

long modularExponentiation(long a, long b, long n) {
    long d = 1L;
    while (b > 0) {
        d = (d * d) % n;
        if (b % 2 == 1)
            d = (d * a) % n;
        b /= 2;
    }
    return d;
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void sort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        sort(arr, l, m);
        sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    // Example usage
    long l, r;
    scanf("%ld %ld", &l, &r);
    printf("%ld\n", giveAns(r) - giveAns(l - 1));
    return 0;
}
