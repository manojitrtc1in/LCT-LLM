#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 5001

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

void pushBack(Vector *vec, int value) {
    vec->data[vec->size++] = value;
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

Vector primes(int n) {
    Vector res = createVector(n);
    for (int i = 0; i < n; i++) {
        if (isPrime(i)) {
            pushBack(&res, i);
        }
    }
    return res;
}

Vector id7(int n) {
    Vector res = createVector(n);
    fillVector(&res, 0);
    if (n > 1) {
        res.data[1] = 1;
    }
    for (int i = 2; i < n; i++) {
        if (res.data[i] == 0) {
            res.data[i] = i;
            for (int j = i * i; j < n; j += i) {
                res.data[j] = i;
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

typedef struct {
    int *data;
    int size;
} Array;

Array createArray(int size) {
    Array arr;
    arr.data = (int *)malloc(size * sizeof(int));
    arr.size = size;
    return arr;
}

void freeArray(Array *arr) {
    free(arr->data);
}

void solve() {
    int n;
    scanf("%d", &n);
    
    Vector k = createVector(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k.data[i]);
    }

    Vector p = primes(MAX_SIZE);
    Vector d = id7(MAX_SIZE);
    Array id0[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        id0[i] = createArray(0);
    }

    for (int i = 2; i < MAX_SIZE; i++) {
        if (d.data[i] == i) {
            id0[i].size = 1;
            id0[i].data = (int *)malloc(sizeof(int));
            id0[i].data[0] = 1;
        } else {
            id0[i].size = 0;
            id0[i].data = (int *)malloc(sizeof(int));
            for (int q = i; q > 1; q /= d.data[q]) {
                id0[i].data[id0[i].size++] = d.data[q];
            }
        }
    }

    long long answer = 0;
    Vector q = getQty(k.data, k.data + n, MAX_SIZE);
    int lost = 0;
    bool still[MAX_SIZE];
    fillVector(&(Vector){.data = still, .size = MAX_SIZE}, true);
    Array cur = createArray(p.size);

    while (true) {
        fillVector(&cur, 0);
        for (int i = 0; i < MAX_SIZE; i++) {
            if (still[i] && id0[i].size > 0) {
                cur.data[id0[i].size - 1] += q.data[i];
            }
        }

        int pos = 0;
        for (int i = 1; i < cur.size; i++) {
            if (cur.data[i] > cur.data[pos]) {
                pos = i;
            }
        }

        if (cur.data[pos] <= n / 2) {
            pos = -2;
        }

        int step = INT_MAX;
        for (int i = 0; i < MAX_SIZE; i++) {
            if (still[i] && id0[i].size - 1 != pos) {
                answer += q.data[i] * (id0[i].size);
                lost += q.data[i];
                still[i] = false;
            } else if (still[i]) {
                if (id0[i].data[id0[i].size - 1] < step) {
                    step = id0[i].data[id0[i].size - 1];
                }
            }
        }

        if (pos == -2) {
            break;
        }

        answer += (long long)step * lost;
        for (int i = 0; i < MAX_SIZE; i++) {
            if (still[i]) {
                id0[i].data[id0[i].size - 1] -= step;
                if (id0[i].data[id0[i].size - 1] == 0) {
                    id0[i].size--;
                }
            }
        }
    }

    printf("%lld\n", answer);

    for (int i = 0; i < MAX_SIZE; i++) {
        freeArray(&id0[i]);
    }
    freeVector(&k);
    freeVector(&p);
    freeVector(&d);
    freeArray(&cur);
}

int main() {
    solve();
    return 0;
}
