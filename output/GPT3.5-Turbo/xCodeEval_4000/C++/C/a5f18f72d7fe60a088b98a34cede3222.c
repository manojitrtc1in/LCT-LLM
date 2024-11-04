#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;

typedef struct {
    int* data;
    int size;
} vi;

typedef struct {
    bool* data;
    int size;
} vec;

typedef struct {
    int* data;
    int size;
} arri;

typedef struct {
    vec* data;
    int size;
} arr;

typedef struct {
    arr* data;
    int size;
} arr2d;

typedef struct {
    arr2d* data;
    int size;
} arr3d;

typedef struct {
    arr3d* data;
    int size;
} arr4d;

vec primalityTable(int n) {
    vec res;
    res.size = n;
    res.data = (bool*)malloc(n * sizeof(bool));
    if (n > 0) {
        res.data[0] = false;
    }
    if (n > 1) {
        res.data[1] = false;
    }
    for (int i = 2; i * i < n; i++) {
        if (res.data[i]) {
            for (int j = i * i; j < n; j += i) {
                res.data[j] = false;
            }
        }
    }
    return res;
}

arri divisorTable(int n) {
    arri res;
    res.size = n;
    res.data = (int*)malloc(n * sizeof(int));
    if (n > 1) {
        res.data[1] = 1;
    }
    for (int i = 2; i < n; i++) {
        if (res.data[i] == 0) {
            res.data[i] = i;
            if ((ll)i * i < n) {
                for (int j = i * i; j < n; j += i) {
                    res.data[j] = i;
                }
            }
        }
    }
    return res;
}

vi primes(int n) {
    vec isPrime = primalityTable(n);
    vi res;
    for (int i = 0; i < n; ++i) {
        if (isPrime.data[i]) {
            res.data[res.size++] = i;
        }
    }
    return res;
}

bool isPrime(long n) {
    if (n < 2) {
        return false;
    }
    for (long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

ll nextPrime(ll n) {
    if (n <= 2) {
        return 2;
    }
    n += 1 - (n & 1);
    while (!isPrime(n)) {
        n += 2;
    }
    return n;
}

void unique(vec* v) {
    int i, j;
    for (i = 0; i < v->size; i++) {
        for (j = i + 1; j < v->size; j++) {
            if (v->data[i] == v->data[j]) {
                v->data[j] = v->data[--v->size];
                j--;
            }
        }
    }
}

arri createOrder(int n) {
    arri order;
    order.size = n;
    order.data = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        order.data[i] = i;
    }
    return order;
}

arri inverse(const arri* p) {
    arri res;
    res.size = p->size;
    res.data = (int*)malloc(p->size * sizeof(int));
    for (int i = 0; i < p->size; i++) {
        res.data[p->data[i]] = i;
    }
    return res;
}

arri getQty(const int* begin, const int* end, int length) {
    arri res;
    res.size = length;
    res.data = (int*)calloc(length, sizeof(int));
    for (const int* it = begin; it != end; it++) {
        res.data[*it]++;
    }
    return res;
}

arri getQty(const int* begin, const int* end) {
    int length = *max_element(begin, end) + 1;
    return getQty(begin, end, length);
}

void collect(vec* v) {}

void collect(vec* all, vec* a, ...) {
    for (int i = 0; i < a->size; i++) {
        all->data[all->size++] = a->data[i];
    }
    collect(all, ...);
}

void replace(const vi* all) {}

void replace(const vi* all, vi* a, ...) {
    for (int i = 0; i < a->size; i++) {
        int* pos = (int*)bsearch(&a->data[i], all->data, all->size, sizeof(int), compare);
        a->data[i] = pos - all->data;
    }
    replace(all, ...);
}

void replace(const vi* all, arri* a, ...) {
    for (int i = 0; i < a->size; i++) {
        int* pos = (int*)bsearch(&a->data[i], all->data, all->size, sizeof(int), compare);
        a->data[i] = pos - all->data;
    }
    replace(all, ...);
}

vi compress(vi* a, ...) {
    vec vals;
    collect(&vals, a, ...);
    qsort(vals.data, vals.size, sizeof(int), compare);
    unique(&vals);
    replace(&vals, a, ...);
    return vals;
}

void DKhaotichnayaV_solve() {
    int n;
    scanf("%d", &n);
    int* k = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &k[i]);
    }

    vi p = primes(5000);
    arri d = divisorTable(5001);
    arr divisors;
    divisors.size = 5001;
    divisors.data = (vi*)malloc(5001 * sizeof(vi));
    divisors.data[0].size = 0;
    divisors.data[0].data = NULL;
    divisors.data[1].size = 0;
    divisors.data[1].data = NULL;
    for (int i = 2; i < 5001; i++) {
        divisors.data[i].size = divisors.data[i - 1].size;
        divisors.data[i].data = (int*)malloc(divisors.data[i].size * sizeof(int));
        for (int j = 0; j < divisors.data[i].size; j++) {
            divisors.data[i].data[j] = divisors.data[i - 1].data[j];
        }
        if (d.data[i] == i) {
            divisors.data[i].data[divisors.data[i].size++] = 1;
        } else {
            for (int q = i; q > 1; q /= d.data[q]) {
                int* pos = (int*)bsearch(&d.data[q], p.data, p.size, sizeof(int), compare);
                divisors.data[i].data[pos - p.data]++;
            }
        }
    }
    ll answer = 0;
    arri q = getQty(k, k + n, 5001);
    int lost = 0;
    arr still;
    still.size = 5001;
    still.data = (bool*)malloc(5001 * sizeof(bool));
    for (int i = 0; i < 5001; i++) {
        still.data[i] = true;
    }
    arri cur;
    cur.size = p.size;
    cur.data = (int*)malloc(p.size * sizeof(int));
    while (1) {
        for (int i = 0; i < p.size; i++) {
            cur.data[i] = 0;
        }
        for (int i = 0; i < 5001; i++) {
            if (still.data[i] && divisors.data[i].size > 0) {
                cur.data[divisors.data[i].size - 1] += q.data[i];
            }
        }
        int pos = 0;
        for (int i = 0; i < p.size; i++) {
            if (cur.data[i] > cur.data[pos]) {
                pos = i;
            }
        }
        if (cur.data[pos] <= n / 2) {
            pos = -2;
        }
        int step = INT_MAX;
        for (int i = 0; i < 5001; i++) {
            if (still.data[i] && divisors.data[i].size - 1 != pos) {
                answer += (ll)q.data[i] * accumulate(divisors.data[i].data, divisors.data[i].data + divisors.data[i].size, 0);
                lost += q.data[i];
                still.data[i] = false;
            } else if (still.data[i]) {
                step = min(step, divisors.data[i].data[divisors.data[i].size - 1]);
            }
        }
        if (pos == -2) {
            break;
        }
        answer += (ll)step * lost;
        for (int i = 0; i < 5001; i++) {
            if (still.data[i]) {
                divisors.data[i].data[divisors.data[i].size - 1] -= step;
                if (divisors.data[i].data[divisors.data[i].size - 1] == 0) {
                    divisors.data[i].size--;
                }
            }
        }
    }
    printf("%lld\n", answer);
}

int main() {
    DKhaotichnayaV_solve();
    return 0;
}
