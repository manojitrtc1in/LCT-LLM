#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

typedef struct {
    int m;
} Modular;

Modular new_Modular(int m) {
    Modular mod;
    mod.m = m;
    return mod;
}

int valueOf(Modular mod, int x) {
    x %= mod.m;
    if (x < 0) {
        x += mod.m;
    }
    return x;
}

int mul(Modular mod, int x, int y) {
    return valueOf(mod, (long long)x * y);
}

int plus(Modular mod, int x, int y) {
    return valueOf(mod, x + y);
}

typedef struct {
    int size;
    int cap;
    int *data;
} IntList;

IntList new_IntList(int cap) {
    IntList list;
    list.size = 0;
    list.cap = cap;
    list.data = (int *)malloc(sizeof(int) * cap);
    return list;
}

void ensureSpace(IntList *list, int req) {
    if (req > list->cap) {
        while (list->cap < req) {
            list->cap = list->cap + 10 > 2 * list->cap ? list->cap + 10 : 2 * list->cap;
        }
        list->data = (int *)realloc(list->data, sizeof(int) * list->cap);
    }
}

void addAll(IntList *list, int *x, int offset, int len) {
    ensureSpace(list, list->size + len);
    for (int i = 0; i < len; i++) {
        list->data[list->size++] = x[offset + i];
    }
}

void addAll_IntList(IntList *list, IntList *other) {
    addAll(list, other->data, 0, other->size);
}

void expandWith(IntList *list, int x, int len) {
    ensureSpace(list, list->size + len);
    while (list->size < len) {
        list->data[list->size++] = x;
    }
}

void retain(IntList *list, int n) {
    if (n < 0) {
        exit(1);
    }
    if (n >= list->size) {
        return;
    }
    list->size = n;
}

int size(IntList *list) {
    return list->size;
}

int get(IntList *list, int i) {
    if (i < 0 || i >= list->size) {
        exit(1);
    }
    return list->data[i];
}

void clear(IntList *list) {
    list->size = 0;
}

IntList clone(IntList *list) {
    IntList ans;
    ans.size = list->size;
    ans.cap = list->cap;
    ans.data = (int *)malloc(sizeof(int) * ans.cap);
    for (int i = 0; i < ans.size; i++) {
        ans.data[i] = list->data[i];
    }
    return ans;
}

typedef struct {
    Modular mod;
    int g;
    int wCache[30];
    int invCache[30];
} NumberTheoryTransform;

NumberTheoryTransform new_NumberTheoryTransform(Modular mod, int g) {
    NumberTheoryTransform ntt;
    ntt.mod = mod;
    ntt.g = g;
    for (int i = 0; i < 30; i++) {
        int s = 1 << i;
        ntt.wCache[i] = pow_mod(ntt.g, (ntt.mod.m - 1) / 2 / s, ntt.mod.m);
        ntt.invCache[i] = inverse(s, ntt.mod.m);
    }
    return ntt;
}

void dotMul(NumberTheoryTransform *ntt, int *a, int *b, int *c, int m) {
    for (int i = 0, n = 1 << m; i < n; i++) {
        c[i] = mul(ntt->mod, a[i], b[i]);
    }
}

void dft(NumberTheoryTransform *ntt, int *p, int m) {
    int n = 1 << m;

    int shift = 32 - __builtin_clz(n - 1);
    for (int i = 1; i < n; i++) {
        int j = __builtin_bswap32(i << shift);
        if (i < j) {
            int temp = p[i];
            p[i] = p[j];
            p[j] = temp;
        }
    }

    int w = 0;
    int t = 0;
    for (int d = 0; d < m; d++) {
        int w1 = ntt->wCache[d];
        int s = 1 << d;
        int s2 = s << 1;
        for (int i = 0; i < n; i += s2) {
            w = 1;
            for (int j = 0; j < s; j++) {
                int a = i + j;
                int b = a + s;
                t = mul(ntt->mod, w, p[b]);
                p[b] = plus(ntt->mod, p[a], -t);
                p[a] = plus(ntt->mod, p[a], t);
                w = mul(ntt->mod, w, w1);
            }
        }
    }
}

void idft(NumberTheoryTransform *ntt, int *p, int m) {
    dft(ntt, p, m);

    int n = 1 << m;
    int invN = ntt->invCache[m];

    p[0] = mul(ntt->mod, p[0], invN);
    p[n / 2] = mul(ntt->mod, p[n / 2], invN);
    for (int i = 1, until = n / 2; i < until; i++) {
        int a = p[n - i];
        p[n - i] = mul(ntt->mod, p[i], invN);
        p[i] = mul(ntt->mod, a, invN);
    }
}

void mulByPQ(NumberTheoryTransform *ntt, IntList *lists, IntList *ans) {
    int n = size(lists);
    IntList *pqs = (IntList *)malloc(sizeof(IntList) * n);
    for (int i = 0; i < n; i++) {
        pqs[i] = clone(&lists[i]);
    }
    while (n > 1) {
        IntList *a = &pqs[n - 2];
        IntList *b = &pqs[n - 1];
        multiplyAndStoreAnswerIntoA(ntt, a, b);
        clear(b);
        n--;
    }

    IntList *last = &pqs[0];
    clear(ans);
    addAll_IntList(ans, last);
    free(last);
    free(pqs);
}

void pow2(NumberTheoryTransform *ntt, int *a, int m) {
    int rankAns = (size(a) - 1) * 2;
    int proper = 32 - __builtin_clz(rankAns + 1);
    expandWith(a, 0, 1 << proper);
    dft(ntt, a, proper);
    dotMul(ntt, a, a, a, proper);
    idft(ntt, a, proper);
    retain(a, rankOf(a) + 1);
}

void multiplyAndStoreAnswerIntoA(NumberTheoryTransform *ntt, IntList *a, IntList *b) {
    int rankAns = size(a) - 1 + size(b) - 1;
    int proper = 32 - __builtin_clz(rankAns + 1);
    expandWith(a, 0, 1 << proper);
    expandWith(b, 0, 1 << proper);
    dft(ntt, a, proper);
    dft(ntt, b, proper);
    dotMul(ntt, a, b, a, proper);
    idft(ntt, a, proper);
    retain(a, rankOf(a) + 1);
}

int pow_mod(int x, int n, int m) {
    if (n == 0) {
        return 1;
    }
    long long r = pow_mod(x, n >> 1, m);
    r = r * r % m;
    if (n & 1) {
        r = r * x % m;
    }
    return r;
}

int inverse(int x, int m) {
    return pow_mod(x, m - 2, m);
}

int gcd(int a, int b) {
    return a >= b ? gcd0(a, b) : gcd0(b, a);
}

int gcd0(int a, int b) {
    return b == 0 ? a : gcd0(b, a % b);
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int *allow = (int *)malloc(sizeof(int) * 10);
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        allow[x] = 1;
    }
    IntList p = new_IntList(10);
    addAll(&p, allow, 0, 10);

    int m = n / 2;
    IntList last = clone(&p);
    NumberTheoryTransform ntt = new_NumberTheoryTransform(new_Modular(MOD), 3);
    IntList *lists = (IntList *)malloc(sizeof(IntList) * 30);
    int listsSize = 0;
    while (m > 1) {
        if (m % 2 == 1) {
            lists[listsSize++] = clone(&last);
        }
        pow2(&ntt, last.data, size(&last));
        retain(&last, size(&last) / 2);
        m /= 2;
    }
    lists[listsSize++] = clone(&last);

    IntList prod = new_IntList(1 << 20);
    mulByPQ(&ntt, lists, &prod);

    int ans = 0;
    for (int i = 0; i < size(&prod); i++) {
        int plus = prod.data[i];
        ans = plus(&ntt.mod, ans, mul(&ntt.mod, plus, plus));
    }

    printf("%d\n", ans);
    return 0;
}
