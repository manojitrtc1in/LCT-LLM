#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MOD7 1000000007
#define MOD9 1000000009
#define MODF 998244353

typedef long long ll;

int mod = MOD7;

typedef struct {
    int n;
} modint;

modint modint_create(int n) {
    modint m;
    m.n = n;
    return m;
}

modint modint_add(modint a, modint b) {
    return modint_create((a.n + b.n) % mod);
}

modint modint_sub(modint a, modint b) {
    return modint_create((a.n - b.n + mod) % mod);
}

modint modint_mul(modint a, modint b) {
    return modint_create((ll)(a.n) * b.n % mod);
}

modint modint_div(modint a, modint b) {
    if (b.n == 0) {
        printf("Division by zero\n");
        exit(1);
    }
    return modint_mul(a, modint_inverse(b));
}

modint modint_neg(modint a) {
    return modint_create(mod - a.n);
}

modint modint_inverse(modint a) {
    ll x, y;
    ll g = gcd(a.n, mod, &x, &y);

    if (g != 1) {
        printf("not inversable\n");
        exit(1);
    }

    return modint_create(x);
}

int modint_log(modint alpha, modint a) {
    // Not implemented
    return 0;
}

int gcd(int a, int b, int* x, int* y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int d = gcd(b % a, a, y, x);
    *x -= (b / a) * (*y);
    return d;
}

typedef struct {
    int type;
    int at;
    int dx;
    int v;
} Event;

bool event_compare(Event a, Event b) {
    return (ll)(a.dx) * b.v < (ll)(b.dx) * a.v;
}

typedef struct {
    int* data;
    int size;
} arr;

arr arr_create(int size) {
    arr a;
    a.data = (int*)malloc(size * sizeof(int));
    a.size = size;
    return a;
}

void arr_free(arr a) {
    free(a.data);
}

void arr_copy(arr src, arr dest) {
    for (int i = 0; i < src.size; i++) {
        dest.data[i] = src.data[i];
    }
}

typedef struct {
    bool* data;
    int dim1;
    int dim2;
} id2;

id2 id2_create(int dim1, int dim2) {
    id2 a;
    a.data = (bool*)malloc(dim1 * dim2 * sizeof(bool));
    a.dim1 = dim1;
    a.dim2 = dim2;
    return a;
}

void id2_free(id2 a) {
    free(a.data);
}

void id2_copy(id2 src, id2 dest) {
    for (int i = 0; i < src.dim1; i++) {
        for (int j = 0; j < src.dim2; j++) {
            dest.data[i * src.dim2 + j] = src.data[i * src.dim2 + j];
        }
    }
}

void join(arr left, arr right, arr result, int at) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    if (allowed(at, 2 * j + k)) {
                        result.data[i * 2 + l] = modint_add(result.data[i * 2 + l], modint_mul(left.data[i * 2 + j], right.data[k * 2 + l]));
                    }
                }
            }
        }
    }
}

bool query(int root, int left, int right, int from, int to, arr pp, arr tmp, id2 allowed) {
    if (left >= to || right <= from) {
        return false;
    }
    if (left >= from && right <= to) {
        arr_copy(pp, tmp);
        return true;
    }
    int mid = (left + right) / 2;
    bool lRes = query(2 * root + 1, left, mid, from, to, pp, tmp, allowed);
    bool rRes = query(2 * root + 2, mid, right, from, to, pp, tmp, allowed);
    if (!lRes) {
        arr_copy(tmp, pp);
        return true;
    }
    if (!rRes) {
        arr_copy(tmp, pp);
        return true;
    }
    join(tmp, tmp, pp, mid);
    return true;
}

void recalc(int root, int left, int right, int at, arr pp) {
    if (left >= at || right <= at) {
        return;
    }
    int mid = (left + right) / 2;
    recalc(2 * root + 1, left, mid, at, pp);
    recalc(2 * root + 2, mid, right, at, pp);
    join(pp[2 * root + 1], pp[2 * root + 2], pp[root], mid);
}

void solve() {
    int n;
    scanf("%d", &n);

    arr x = arr_create(n);
    arr v = arr_create(n);
    arr p = arr_create(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x.data[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &v.data[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &p.data[i]);
    }

    arr pp = arr_create(4 * n);
    arr tmp = arr_create(4 * n);
    id2 allowed = id2_create(n, 4);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            allowed.data[i * 4 + j] = true;
        }
    }

    Event* events = (Event*)malloc(2 * n * sizeof(Event));
    int eventCount = 0;
    for (int i = 1; i < n; i++) {
        events[eventCount++] = (Event){2, i, x.data[i] - x.data[i - 1], v.data[i] + v.data[i - 1]};
        if (v.data[i] > v.data[i - 1]) {
            events[eventCount++] = (Event){0, i, x.data[i] - x.data[i - 1], v.data[i] - v.data[i - 1]};
        } else if (v.data[i] < v.data[i - 1]) {
            events[eventCount++] = (Event){3, i, x.data[i] - x.data[i - 1], v.data[i - 1] - v.data[i]};
        }
    }
    qsort(events, eventCount, sizeof(Event), event_compare);

    modint answer = modint_create(0);
    for (int i = 0; i < eventCount; i++) {
        query(0, 0, n, 0, events[i].at, pp, tmp, allowed);
        modint left = modint_add(tmp.data[events[i].type / 2], tmp.data[2 + events[i].type / 2]);
        query(0, 0, n, events[i].at, n, pp, tmp, allowed);
        modint right = modint_add(tmp.data[events[i].type % 2 * 2], tmp.data[events[i].type % 2 * 2 + 1]);
        answer = modint_add(answer, modint_mul(modint_div(modint_create(events[i].dx), modint_create(events[i].v)), modint_mul(left, right)));
        allowed.data[events[i].at * 4 + events[i].type] = false;
        recalc(0, 0, n, events[i].at, pp);
    }

    printf("%d\n", answer.n);

    arr_free(x);
    arr_free(v);
    arr_free(p);
    arr_free(pp);
    arr_free(tmp);
    id2_free(allowed);
    free(events);
}

int main() {
    solve();
    return 0;
}
