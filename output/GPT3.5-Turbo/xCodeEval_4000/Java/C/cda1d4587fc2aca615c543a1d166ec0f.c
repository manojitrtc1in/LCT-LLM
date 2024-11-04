#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

Modular getModularForPowerComputation(Modular mod) {
    return new_Modular(mod.m - 1);
}

typedef struct {
    int m;
    int *data;
} IntegerList;

IntegerList new_IntegerList(int cap) {
    IntegerList list;
    list.m = cap;
    list.data = (int *)malloc(sizeof(int) * cap);
    return list;
}

void remove(IntegerList *list, int l, int r) {
    if (l > r) {
        return;
    }
    if (r == list->m - 1) {
        list->m = l;
        return;
    } else {
        for (int i = r + 1; i < list->m; i++) {
            list->data[l + i - r - 1] = list->data[i];
        }
        list->m -= (r - l + 1);
    }
}

int get(IntegerList *list, int i) {
    if (i < 0 || i >= list->m) {
        printf("index %d out of range\n", i);
        exit(1);
    }
    return list->data[i];
}

void add(IntegerList *list, int x) {
    if (list->m == 0) {
        list->data = (int *)malloc(sizeof(int));
    } else {
        list->data = (int *)realloc(list->data, sizeof(int) * (list->m + 1));
    }
    list->data[list->m++] = x;
}

void addAll(IntegerList *list, int *x, int offset, int len) {
    if (list->m == 0) {
        list->data = (int *)malloc(sizeof(int) * len);
    } else {
        list->data = (int *)realloc(list->data, sizeof(int) * (list->m + len));
    }
    for (int i = 0; i < len; i++) {
        list->data[list->m + i] = x[offset + i];
    }
    list->m += len;
}

void addAll_IntegerList(IntegerList *list, IntegerList *other) {
    addAll(list, other->data, 0, other->m);
}

void expandWith(IntegerList *list, int x, int len) {
    if (list->m == 0) {
        list->data = (int *)malloc(sizeof(int) * len);
    } else {
        list->data = (int *)realloc(list->data, sizeof(int) * (list->m + len));
    }
    for (int i = 0; i < len; i++) {
        list->data[list->m + i] = x;
    }
    list->m += len;
}

void set(IntegerList *list, int i, int x) {
    if (i < 0 || i >= list->m) {
        printf("index %d out of range\n", i);
        exit(1);
    }
    list->data[i] = x;
}

int size(IntegerList *list) {
    return list->m;
}

int *toArray(IntegerList *list) {
    int *arr = (int *)malloc(sizeof(int) * list->m);
    for (int i = 0; i < list->m; i++) {
        arr[i] = list->data[i];
    }
    return arr;
}

void clear(IntegerList *list) {
    list->m = 0;
}

typedef struct {
    int *realLevels[30];
    int *imgLevels[30];
} FastFourierTransform;

FastFourierTransform new_FastFourierTransform() {
    FastFourierTransform fft;
    for (int i = 0; i < 30; i++) {
        fft.realLevels[i] = NULL;
        fft.imgLevels[i] = NULL;
    }
    return fft;
}

void prepareLevel(FastFourierTransform *fft, int i) {
    if (fft->realLevels[i] == NULL) {
        int s = 1 << i;
        fft->realLevels[i] = (int *)malloc(sizeof(int) * s);
        fft->imgLevels[i] = (int *)malloc(sizeof(int) * s);
        for (int j = 0; j < s; j++) {
            fft->realLevels[i][j] = cos(M_PI / s * j);
            fft->imgLevels[i][j] = sin(M_PI / s * j);
        }
    }
}

void dft(FastFourierTransform *fft, int **p, int m) {
    int n = 1 << m;

    int shift = 32 - __builtin_ctz(n);
    for (int i = 1; i < n; i++) {
        int j = __builtin_bitreverse32(i << shift);
        if (i < j) {
            int tmp = (*p)[i];
            (*p)[i] = (*p)[j];
            (*p)[j] = tmp;
        }
    }

    int t[2];
    for (int d = 0; d < m; d++) {
        int s = 1 << d;
        int s2 = s << 1;
        prepareLevel(fft, d);
        for (int i = 0; i < n; i += s2) {
            for (int j = 0; j < s; j++) {
                int a = i + j;
                int b = a + s;
                int r1 = (*p)[b];
                int i1 = (*p)[b + 1];
                int r2 = fft->realLevels[d][j];
                int i2 = fft->imgLevels[d][j];

                t[0] = (*p)[a];
                t[1] = (*p)[a + 1];
                (*p)[a] = plus(*fft, t[0], mul(*fft, r1, r2) - mul(*fft, i1, i2));
                (*p)[a + 1] = plus(*fft, t[1], mul(*fft, r1, i2) + mul(*fft, i1, r2));
            }
        }
    }
}

void idft(FastFourierTransform *fft, int **p, int m) {
    dft(fft, p, m);

    int n = 1 << m;
    int inv = p[0][0];
    for (int i = 0; i < n; i++) {
        p[0][i] = mul(*fft, p[0][i], inv);
        p[1][i] = mul(*fft, p[1][i], inv);
    }
}

void add(int *r1, int *i1, int r2, int i2, int **r, int **i, int idx) {
    (*r)[idx] = plus(*modular, r1, r2);
    (*i)[idx] = plus(*modular, i1, i2);
}

void sub(int *r1, int *i1, int r2, int i2, int **r, int **i, int idx) {
    (*r)[idx] = plus(*modular, r1, -r2);
    (*i)[idx] = plus(*modular, i1, -i2);
}

void mul(int *r1, int *i1, int r2, int i2, int **r, int **i, int idx) {
    (*r)[idx] = plus(*modular, mul(*modular, r1, r2), -mul(*modular, i1, i2));
    (*i)[idx] = plus(*modular, mul(*modular, r1, i2), mul(*modular, i1, r2));
}

void div(int *r1, int *i1, int r2, int **r, int **i, int idx) {
    (*r)[idx] = mul(*modular, r1, r2);
    (*i)[idx] = mul(*modular, i1, r2);
}

int *multiplyMod(int *a, int aLen, int *b, int bLen, int m) {
    int need = aLen + bLen - 1;
    int n = 1 << (int)ceil(log2(need));

    int *aReal = (int *)malloc(sizeof(int) * n);
    int *aImag = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < aLen; i++) {
        int x = (a[i] % m + m) % m;
        aReal[i] = x & ((1 << 15) - 1);
        aImag[i] = x >> 15;
    }
    dft(&fft, &aReal, &aImag, (int)log2(n));

    int *bReal = (int *)malloc(sizeof(int) * n);
    int *bImag = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < bLen; i++) {
        int x = (b[i] % m + m) % m;
        bReal[i] = x & ((1 << 15) - 1);
        bImag[i] = x >> 15;
    }
    dft(&fft, &bReal, &bImag, (int)log2(n));

    int *faReal = (int *)malloc(sizeof(int) * n);
    int *faImag = (int *)malloc(sizeof(int) * n);
    int *fbReal = (int *)malloc(sizeof(int) * n);
    int *fbImag = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        int j = (n - i) & (n - 1);

        int a1r = (aReal[i] + aReal[j]) / 2;
        int a1i = (aImag[i] - aImag[j]) / 2;
        int a2r = (aImag[i] + aImag[j]) / 2;
        int a2i = (aReal[j] - aReal[i]) / 2;

        int b1r = (bReal[i] + bReal[j]) / 2;
        int b1i = (bImag[i] - bImag[j]) / 2;
        int b2r = (bImag[i] + bImag[j]) / 2;
        int b2i = (bReal[j] - bReal[i]) / 2;

        faReal[i] = a1r * b1r - a1i * b1i - a2r * b2i - a2i * b2r;
        faImag[i] = a1r * b1i + a1i * b1r + a2r * b2r - a2i * b2i;

        fbReal[i] = a1r * b2r - a1i * b2i + a2r * b1r - a2i * b1i;
        fbImag[i] = a1r * b2i + a1i * b2r + a2r * b1i + a2i * b1r;
    }

    idft(&fft, &faReal, &faImag, (int)log2(n));
    idft(&fft, &fbReal, &fbImag, (int)log2(n));
    int *res = (int *)malloc(sizeof(int) * need);
    for (int i = 0; i < need; i++) {
        long long aa = (long long)(faReal[i] + 0.5);
        long long bb = (long long)(fbReal[i] + 0.5);
        long long cc = (long long)(faImag[i] + 0.5);
        res[i] = (int)((aa % m + (bb % m << 15) + (cc % m << 30)) % m);
    }
    return res;
}

typedef struct {
    int *fact;
    int *inv;
    Modular modular;
} Factorial;

Factorial new_Factorial(int limit, Modular modular) {
    Factorial factorial;
    factorial.fact = (int *)malloc(sizeof(int) * (limit + 1));
    factorial.inv = (int *)malloc(sizeof(int) * (limit + 1));
    factorial.modular = modular;
    factorial.fact[0] = factorial.inv[0] = 1;
    for (int i = 1; i <= limit; i++) {
        factorial.fact[i] = mul(modular, factorial.fact[i - 1], i);
        factorial.inv[i] = mul(modular, factorial.inv[i - 1], modular.m - modular.m / i);
    }
    return factorial;
}

int fact(Factorial *factorial, int n) {
    return factorial->fact[n];
}

int invFact(Factorial *factorial, int n) {
    return factorial->inv[n];
}

typedef struct {
    Factorial factorial;
    Modular modular;
} Composite;

Composite new_Composite(int limit, Modular modular) {
    Composite composite;
    composite.factorial = new_Factorial(limit, modular);
    composite.modular = modular;
    return composite;
}

int composite(Composite *composite, int m, int n) {
    if (n > m) {
        return 0;
    }
    return mul(composite->modular, mul(composite->modular, fact(&composite->factorial, m), invFact(&composite->factorial, n)), invFact(&composite->factorial, m - n));
}

typedef struct {
    int *first;
    int *second;
    Modular mod;
    Modular powMod;
} CachedPow;

CachedPow new_CachedPow(int x, Modular mod) {
    CachedPow cachedPow;
    cachedPow.mod = mod;
    cachedPow.powMod = getModularForPowerComputation(mod);
    int k = fmax(1, round(sqrt(cachedPow.powMod.m)));
    cachedPow.first = (int *)malloc(sizeof(int) * k);
    cachedPow.second = (int *)malloc(sizeof(int) * (cachedPow.powMod.m / k + 1));
    cachedPow.first[0] = 1;
    for (int i = 1; i < k; i++) {
        cachedPow.first[i] = mul(mod, x, cachedPow.first[i - 1]);
    }
    cachedPow.second[0] = 1;
    int step = mul(mod, x, cachedPow.first[k - 1]);
    for (int i = 1; i < cachedPow.powMod.m / k + 1; i++) {
        cachedPow.second[i] = mul(mod, cachedPow.second[i - 1], step);
    }
    return cachedPow;
}

int pow(CachedPow *cachedPow, int exp) {
    return mul(cachedPow->mod, cachedPow->first[exp % (cachedPow->powMod.m / sizeof(int))], cachedPow->second[exp / (cachedPow->powMod.m / sizeof(int))]);
}

int inverse(CachedPow *cachedPow, int exp) {
    return pow(cachedPow, powMod(cachedPow->mod, -exp));
}

typedef struct {
    int m;
    Modular mod;
    IntegerList composites;
} BinomialComposite;

BinomialComposite new_BinomialComposite(long n, int m, Modular mod) {
    BinomialComposite binomialComposite;
    binomialComposite.m = m;
    binomialComposite.mod = mod;
    binomialComposite.composites = pow(n);
    expandWith(&binomialComposite.composites, 0, m + 1);
    return binomialComposite;
}

int get(BinomialComposite *binomialComposite, int i) {
    return get(&binomialComposite->composites, i);
}

void mul(IntegerList *a, IntegerList *b, IntegerList *c, Modular mod) {
    int rA = rankOf(a);
    int rB = rankOf(b);
    clear(c);
    expandWith(c, 0, rA + rB + 1);
    if (rA >= 64 && rB >= 64) {
        int *ans = multiplyMod(a->data, rA + 1, b->data, rB + 1, mod.m);
        clear(c);
        addAll(c, ans, 0, rA + rB + 1);
        return;
    }
    for (int i = 0; i <= rA; i++) {
        for (int j = 0; j <= rB; j++) {
            c->data[i + j] = plus(mod, c->data[i + j], mul(mod, a->data[i], b->data[j]));
        }
    }
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    CachedPow pm = new_CachedPow(m, new_Modular(MOD));
    int *xk = (int *)malloc(sizeof(int) * (k + 1));
    for (int i = 0; i <= k; i++) {
        xk[i] = pow(&pm, i, k);
    }

    int ans = 0;
    BinomialComposite bc = new_BinomialComposite(n, k, new_Modular(MOD));
    for (int t = 0; t <= k; t++) {
        int p1 = get(&bc, t);
        int p2 = 0;
        for (int i = 0; i <= t; i++) {
            int contrib = composite(&bc, t, i);
            contrib = mul(mod, contrib, xk[t - i]);
            if (i % 2 == 1) {
                contrib = valueOf(mod, -contrib);
            }
            p2 = plus(mod, p2, contrib);
        }
        int p3 = inverse(&pm, t);

        int contrib = mul(mod, p1, p2);
        contrib = mul(mod, contrib, p3);
        ans = plus(mod, ans, contrib);
    }

    printf("%d\n", ans);

    return 0;
}
