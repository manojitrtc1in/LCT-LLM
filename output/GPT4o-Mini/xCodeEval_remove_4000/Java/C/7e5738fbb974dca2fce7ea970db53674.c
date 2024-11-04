#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void process_input() {
    char s[100001];
    int n, k;
    scanf("%d %d\n", &n, &k);
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0; // Remove newline character

    if (k == 0) {
        printf("%s\n", s);
        return;
    }

    char result[100001];
    int count = 0;
    if (s[0] != '1') {
        result[0] = '1';
        count++;
    } else {
        result[0] = '1';
    }

    for (int i = 1; i < n; i++) {
        if (count >= k) {
            strcat(result, s + i);
            break;
        } else {
            if (s[i] == '0') {
                result[i] = '0';
                continue;
            } else {
                result[i] = '0';
                count++;
            }
        }
    }
    printf("%s\n", result);
}

typedef struct {
    int *parent;
    int *size;
} DSU;

DSU* create_dsu(int n) {
    DSU *dsu = (DSU *)malloc(sizeof(DSU));
    dsu->parent = (int *)malloc(n * sizeof(int));
    dsu->size = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        dsu->parent[i] = -1;
    }
    return dsu;
}

void make_set(DSU *dsu, int v) {
    dsu->parent[v] = v;
    dsu->size[v] = 1;
}

int find_set(DSU *dsu, int v) {
    if (v == dsu->parent[v]) return v;
    return dsu->parent[v] = find_set(dsu, dsu->parent[v]);
}

void union_sets(DSU *dsu, int a, int b) {
    a = find_set(dsu, a);
    b = find_set(dsu, b);
    if (a != b) {
        if (dsu->size[a] < dsu->size[b]) {
            int temp = a;
            a = b;
            b = temp;
        }
        dsu->parent[b] = a;
        dsu->size[a] += dsu->size[b];
    }
}

void fft(double *a, double *b, int count, int invert) {
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

long* multiply(long *a, long *b, int a_len, int b_len, int *result_size) {
    int resultSize = 1 << (int)(ceil(log2(a_len + b_len - 1)));
    double *aReal = (double *)calloc(resultSize, sizeof(double));
    double *bReal = (double *)calloc(resultSize, sizeof(double));
    for (int i = 0; i < a_len; i++)
        aReal[i] = a[i];
    for (int i = 0; i < b_len; i++)
        bReal[i] = b[i];
    fft(aReal, (double *)calloc(resultSize, sizeof(double)), resultSize, 0);
    fft(bReal, (double *)calloc(resultSize, sizeof(double)), resultSize, 0);
    for (int i = 0; i < resultSize; i++) {
        double real = aReal[i] * bReal[i];
        aReal[i] = real;
    }
    fft(aReal, (double *)calloc(resultSize, sizeof(double)), resultSize, 1);
    long *result = (long *)malloc(resultSize * sizeof(long));
    for (int i = 0; i < resultSize; i++)
        result[i] = (long)(round(aReal[i]));
    *result_size = resultSize;
    free(aReal);
    free(bReal);
    return result;
}

int is_prime(long n) {
    if (n < 2)
        return 0;
    for (long x = 2; x * x <= n; x++) {
        if (n % x == 0)
            return 0;
    }
    return 1;
}

long* factorize(long n, int *size) {
    long *factors = (long *)malloc(sizeof(long) * 100);
    *size = 0;
    for (long x = 2; x * x <= n; x++) {
        while (n % x == 0) {
            factors[(*size)++] = x;
            n /= x;
        }
    }
    if (n > 1)
        factors[(*size)++] = n;
    return factors;
}

int* sieve(int n) {
    int *sieve = (int *)malloc((n + 1) * sizeof(int));
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

Name extended_gcd(long a, long b) {
    if (b == 0)
        return (Name){a, 1, 0};
    Name n1 = extended_gcd(b, a % b);
    return (Name){n1.d, n1.y, n1.x - (long)floor((double)a / b) * n1.y};
}

long mod_exp(long a, long b, long n) {
    long d = 1L;
    while (b > 0) {
        d = (d * d) % n;
        if (b & 1)
            d = (d * a) % n;
        b >>= 1;
    }
    return d;
}

int main() {
    process_input();
    // Other functionalities can be called here as needed.
    return 0;
}
