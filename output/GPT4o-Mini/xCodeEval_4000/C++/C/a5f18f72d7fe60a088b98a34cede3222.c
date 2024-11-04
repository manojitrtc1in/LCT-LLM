#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MAX_N 5001

typedef long long ll;

typedef struct {
    int *data;
    int size;
} Vector;

Vector createVector(int size) {
    Vector vec;
    vec.data = (int *)malloc(size * sizeof(int));
    vec.size = size;
    return vec;
}

void freeVector(Vector *vec) {
    free(vec->data);
}

void fillVector(Vector *vec, int value) {
    for (int i = 0; i < vec->size; i++) {
        vec->data[i] = value;
    }
}

Vector primes(int n) {
    bool *isPrime = (bool *)malloc(n * sizeof(bool));
    Vector result = createVector(0);
    for (int i = 0; i < n; i++) {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (isPrime[i]) {
            result.size++;
            result.data = (int *)realloc(result.data, result.size * sizeof(int));
            result.data[result.size - 1] = i;
        }
    }

    free(isPrime);
    return result;
}

Vector divisorTable(int n) {
    Vector res = createVector(n);
    fillVector(&res, 0);
    for (int i = 2; i < n; i++) {
        if (res.data[i] == 0) {
            res.data[i] = i;
            for (int j = i * i; j < n; j += i) {
                if (res.data[j] == 0) {
                    res.data[j] = i;
                }
            }
        }
    }
    return res;
}

Vector getQty(int *begin, int *end, int length) {
    Vector res = createVector(length);
    fillVector(&res, 0);
    for (int *it = begin; it != end; it++) {
        res.data[*it]++;
    }
    return res;
}

void solve() {
    int n;
    scanf("%d", &n);
    int *k = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &k[i]);
    }

    Vector p = primes(5000);
    Vector d = divisorTable(5001);
    Vector *divisors = (Vector *)malloc(5001 * sizeof(Vector));
    for (int i = 0; i < 5001; i++) {
        divisors[i] = createVector(0);
    }
    for (int i = 2; i < 5001; i++) {
        divisors[i] = divisors[i - 1];
        if (d.data[i] == i) {
            divisors[i].size++;
            divisors[i].data = (int *)realloc(divisors[i].data, divisors[i].size * sizeof(int));
            divisors[i].data[divisors[i].size - 1] = 1;
        } else {
            for (int q = i; q > 1; q /= d.data[q]) {
                divisors[i].data[lower_bound(p.data, p.data + p.size, d.data[q]) - p.data]++;
            }
        }
    }

    ll answer = 0;
    Vector q = getQty(k, k + n, 5001);
    int lost = 0;
    bool still[5001];
    fillVector((Vector *)&(Vector){.data = (int *)still, .size = 5001}, true);
    int *cur = (int *)malloc(p.size * sizeof(int));

    while (true) {
        fillVector((Vector *)&(Vector){.data = cur, .size = p.size}, 0);
        for (int i = 0; i < 5001; i++) {
            if (still[i] && divisors[i].size > 0) {
                cur[divisors[i].size - 1] += q.data[i];
            }
        }
        int pos = 0;
        for (int i = 1; i < p.size; i++) {
            if (cur[i] > cur[pos]) {
                pos = i;
            }
        }
        if (cur[pos] <= n / 2) {
            pos = -2;
        }
        int step = INT_MAX;
        for (int i = 0; i < 5001; i++) {
            if (still[i] && divisors[i].size - 1 != pos) {
                answer += q.data[i] * accumulate(divisors[i].data, divisors[i].data + divisors[i].size, 0LL);
                lost += q.data[i];
                still[i] = false;
            } else if (still[i]) {
                step = (divisors[i].data[divisors[i].size - 1] < step) ? divisors[i].data[divisors[i].size - 1] : step;
            }
        }
        if (pos == -2) {
            break;
        }
        answer += (ll)step * lost;
        for (int i = 0; i < 5001; i++) {
            if (still[i]) {
                divisors[i].data[divisors[i].size - 1] -= step;
                if (divisors[i].data[divisors[i].size - 1] == 0) {
                    divisors[i].size--;
                }
            }
        }
    }
    printf("%lld\n", answer);

    free(k);
    free(q.data);
    for (int i = 0; i < 5001; i++) {
        freeVector(&divisors[i]);
    }
    free(divisors);
    free(p.data);
    free(d.data);
    free(cur);
}

int main() {
    solve();
    return 0;
}
