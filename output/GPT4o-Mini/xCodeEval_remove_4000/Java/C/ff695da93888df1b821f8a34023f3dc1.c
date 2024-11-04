#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long giveAns(long x) {
    int id23 = (int)log10(x) + 1;
    long ans = 0L;
    for (int i = 2; i < id23; i++)
        ans += 9L * (long)pow(10, i - 2);
    if (id23 > 1)
        ans += 9;
    if (id23 == 1)
        ans += x;
    else {
        int firstDigit = (int)(x / pow(10, id23 - 1));
        int lastDigit = (int)(x % 10);
        ans += (firstDigit - 1) * (long)pow(10, id23 - 2);
        char s[20];
        sprintf(s, "%ld", x);
        for (int j = 1; j < id23 - 1; j++) {
            long val = 1L;
            int digit = s[j] - '0';
            val *= (1L * digit * (long)pow(10, id23 - j - 2));
            ans += val;
        }
        if (firstDigit <= lastDigit)
            ans++;
    }
    return ans;
}

int* parent;
int* size;

void makeSet(int v) {
    parent[v] = v;
    size[v] = 1;
}

int findSet(int v) {
    if (v == parent[v]) return v;
    return parent[v] = findSet(parent[v]);
}

void unionSets(int a, int b) {
    a = findSet(a);
    b = findSet(b);
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

void fft(double* a, double* b, int count, int invert) {
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
        double id17 = cos(angle);
        double id2 = sin(angle);
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
                double nextWA = wA * id17 - wB * id2;
                wB = wA * id2 + wB * id17;
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
    int resultSize = 1 << (int)(log2(fmax(aSize, bSize)) + 2);
    resultSize = fmax(resultSize, 1);
    double* aReal = (double*)calloc(resultSize, sizeof(double));
    double* id10 = (double*)calloc(resultSize, sizeof(double));
    double* bReal = (double*)calloc(resultSize, sizeof(double));
    double* id30 = (double*)calloc(resultSize, sizeof(double));
    for (int i = 0; i < aSize; i++)
        aReal[i] = a[i];
    for (int i = 0; i < bSize; i++)
        bReal[i] = b[i];
    fft(aReal, id10, resultSize, 0);
    fft(bReal, id30, resultSize, 0);
    for (int i = 0; i < resultSize; i++) {
        double real = aReal[i] * bReal[i] - id10[i] * id30[i];
        id10[i] = id10[i] * bReal[i] + id30[i] * aReal[i];
        aReal[i] = real;
    }
    fft(aReal, id10, resultSize, 1);
    long* result = (long*)malloc(resultSize * sizeof(long));
    for (int i = 0; i < resultSize; i++)
        result[i] = (long)round(aReal[i]);
    free(aReal);
    free(id10);
    free(bReal);
    free(id30);
    return result;
}

int isPrime(long n) {
    if (n < 2)
        return 0;
    for (long x = 2; x * x <= n; x++) {
        if (n % x == 0)
            return 0;
    }
    return 1;
}

long* id27(long n, int* size) {
    long* f = (long*)malloc(sizeof(long) * 100); // Arbitrary size, should be dynamic
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

int* id19(int n) {
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

Name id21(long a, long b) {
    if (b == 0)
        return (Name){a, 1, 0};
    Name n1 = id21(b, a % b);
    return (Name){n1.d, n1.y, n1.x - (long)floor((double)a / b) * n1.y};
}

long id22(long a, long b, long n) {
    long d = 1L;
    char bString[65];
    itoa(b, bString, 2);
    for (int i = 0; bString[i] != '\0'; i++) {
        d = (d * d) % n;
        if (bString[i] == '1')
            d = (d * a) % n;
    }
    return d;
}

int main() {
    long l, r;
    scanf("%ld %ld", &l, &r);
    printf("%ld\n", giveAns(r) - giveAns(l - 1));
    return 0;
}
