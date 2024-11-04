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
    int size;
    int cap;
    int *data;
} IntegerList;

IntegerList new_IntegerList(int cap) {
    IntegerList list;
    list.size = 0;
    list.cap = cap;
    if (cap == 0) {
        list.data = NULL;
    } else {
        list.data = (int *)malloc(cap * sizeof(int));
    }
    return list;
}

void remove(IntegerList *list, int l, int r) {
    if (l > r) {
        return;
    }
    if (r == list->size - 1) {
        list->size = l;
        return;
    } else {
        for (int i = r + 1; i < list->size; i++) {
            list->data[l + i - r - 1] = list->data[i];
        }
        list->size -= (r - l + 1);
    }
}

void ensureSpace(IntegerList *list, int req) {
    if (req > list->cap) {
        while (list->cap < req) {
            list->cap = list->cap + 10 > 2 * list->cap ? list->cap + 10 : 2 * list->cap;
        }
        list->data = (int *)realloc(list->data, list->cap * sizeof(int));
    }
}

int get(IntegerList *list, int i) {
    return list->data[i];
}

void add(IntegerList *list, int x) {
    ensureSpace(list, list->size + 1);
    list->data[list->size++] = x;
}

void addAll(IntegerList *list, int *x, int offset, int len) {
    ensureSpace(list, list->size + len);
    for (int i = 0; i < len; i++) {
        list->data[list->size++] = x[offset + i];
    }
}

void addAll_IntegerList(IntegerList *list, IntegerList *other) {
    addAll(list, other->data, 0, other->size);
}

void expandWith(IntegerList *list, int x, int len) {
    ensureSpace(list, list->size + len);
    while (list->size < len) {
        list->data[list->size++] = x;
    }
}

void set(IntegerList *list, int i, int x) {
    list->data[i] = x;
}

int size(IntegerList *list) {
    return list->size;
}

int *toArray(IntegerList *list) {
    int *arr = (int *)malloc(list->size * sizeof(int));
    for (int i = 0; i < list->size; i++) {
        arr[i] = list->data[i];
    }
    return arr;
}

void clear(IntegerList *list) {
    list->size = 0;
}

typedef struct {
    int m;
    int *inv;
} InverseNumber;

InverseNumber new_InverseNumber(int limit, Modular modular) {
    InverseNumber in;
    in.m = modular.m;
    in.inv = (int *)malloc((limit + 1) * sizeof(int));
    in.inv[1] = 1;
    int p = modular.m;
    for (int i = 2; i <= limit; i++) {
        int k = p / i;
        int r = p % i;
        in.inv[i] = mul(modular, -k, in.inv[r]);
    }
    return in;
}

typedef struct {
    int *fact;
    int *inv;
    Modular modular;
} Factorial;

Factorial new_Factorial(int limit, Modular modular) {
    Factorial factorial;
    factorial.fact = (int *)malloc((limit + 1) * sizeof(int));
    factorial.inv = (int *)malloc((limit + 1) * sizeof(int));
    factorial.modular = modular;
    factorial.fact[0] = factorial.inv[0] = 1;
    for (int i = 1; i <= limit; i++) {
        factorial.fact[i] = mul(modular, factorial.fact[i - 1], i);
        factorial.inv[i] = mul(modular, factorial.inv[i - 1], new_InverseNumber(limit, modular).inv[i]);
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
    int *realLevels[30];
    int *imgLevels[30];
} FastFourierTransform;

void prepareLevel(FastFourierTransform *fft, int i) {
    if (fft->realLevels[i] == NULL) {
        fft->realLevels[i] = (int *)malloc((1 << i) * sizeof(int));
        fft->imgLevels[i] = (int *)malloc((1 << i) * sizeof(int));
        for (int j = 0, s = 1 << i; j < s; j++) {
            fft->realLevels[i][j] = cos(M_PI / s * j);
            fft->imgLevels[i][j] = sin(M_PI / s * j);
        }
    }
}

void dft(FastFourierTransform *fft, int **p, int m) {
    int n = 1 << m;

    int shift = 32 - __builtin_ctz(n);
    for (int i = 1; i < n; i++) {
        int j = __builtin_bswap32(i << shift);
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
                int realA = (*p)[a] & ((1 << 15) - 1);
                int imgA = (*p)[a] >> 15;
                int realB = (*p)[b] & ((1 << 15) - 1);
                int imgB = (*p)[b] >> 15;

                int realLevel = fft->realLevels[d][j];
                int imgLevel = fft->imgLevels[d][j];

                int realMul = mul(fft->modular, realLevel, realB) - mul(fft->modular, imgLevel, imgB);
                int imgMul = mul(fft->modular, realLevel, imgB) + mul(fft->modular, imgLevel, realB);

                t[0] = (*p)[a] + realMul;
                t[1] = imgA + imgMul;
                (*p)[b] = (*p)[a] - realMul;
                (*p)[a] = imgA - imgMul;
            }
        }
    }
}

void idft(FastFourierTransform *fft, int **p, int m) {
    dft(fft, p, m);

    int n = 1 << m;
    int invN = new_Modular(n).m - 1;
    int invN2 = mul(new_Modular(n).m - 1, invN, invN);
    int invN3 = mul(new_Modular(n).m - 1, invN2, invN);

    (*p)[0] = mul(new_Modular(n), (*p)[0], invN);
    (*p)[n / 2] = mul(new_Modular(n), (*p)[n / 2], invN);

    for (int i = 1, until = n / 2; i < until; i++) {
        int a = (*p)[n - i];
        int b = (*p)[i];
        (*p)[i] = mul(new_Modular(n), a, invN);
        (*p)[n - i] = mul(new_Modular(n), b, invN);
    }
}

int *multiplyMod(int *a, int aLen, int *b, int bLen, int m) {
    int need = aLen + bLen - 1;
    int n = 1 << (int)ceil(log2(need));

    int *aReal = (int *)malloc(n * sizeof(int));
    int *aImag = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < aLen; i++) {
        int x = a[i] % m;
        aReal[i] = x & ((1 << 15) - 1);
        aImag[i] = x >> 15;
    }
    dft(new FastFourierTransform(), &aReal, (int)floor(log2(n)));

    int *bReal = (int *)malloc(n * sizeof(int));
    int *bImag = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < bLen; i++) {
        int x = b[i] % m;
        bReal[i] = x & ((1 << 15) - 1);
        bImag[i] = x >> 15;
    }
    dft(new FastFourierTransform(), &bReal, (int)floor(log2(n)));

    int *faReal = (int *)malloc(n * sizeof(int));
    int *faImag = (int *)malloc(n * sizeof(int));
    int *fbReal = (int *)malloc(n * sizeof(int));
    int *fbImag = (int *)malloc(n * sizeof(int));

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

    idft(new FastFourierTransform(), &faReal, (int)floor(log2(n)));
    idft(new FastFourierTransform(), &fbReal, (int)floor(log2(n)));
    int *res = (int *)malloc(need * sizeof(int));
    for (int i = 0; i < need; i++) {
        long long aa = (long long)(faReal[i] + 0.5);
        long long bb = (long long)(fbReal[i] + 0.5);
        long long cc = (long long)(faImag[i] + 0.5);
        res[i] = ((aa % m + ((bb % m) << 15) + ((cc % m) << 30)) % m + m) % m;
    }
    return res;
}

typedef struct {
    int *data;
    int pos;
} Loop;

Loop new_Loop(int *data) {
    Loop loop;
    loop.data = data;
    loop.pos = 0;
    return loop;
}

int turn(Loop *loop, int i) {
    loop->pos += i;
    return loop->data[0];
}

int get(Loop *loop, int i) {
    return loop->data[(loop->pos + i) % 2];
}

int get_(Loop *loop) {
    return get(loop, 0);
}

typedef struct {
    int m;
    int *inv;
} CachedPow;

CachedPow new_CachedPow(int x, Modular mod) {
    CachedPow cp;
    cp.m = mod.m;
    cp.inv = (int *)malloc((x + 1) * sizeof(int));
    cp.inv[1] = 1;
    int p = mod.m;
    for (int i = 2; i <= x; i++) {
        int k = p / i;
        int r = p % i;
        cp.inv[i] = mul(mod, -k, cp.inv[r]);
    }
    return cp;
}

int pow(CachedPow *cp, int exp) {
    return cp->inv[exp];
}

int inverse(CachedPow *cp, int exp) {
    return pow(cp, -exp);
}

typedef struct {
    int *realLevels[30];
    int *imgLevels[30];
} FastFourierTransform;

void prepareLevel(FastFourierTransform *fft, int i) {
    if (fft->realLevels[i] == NULL) {
        fft->realLevels[i] = (int *)malloc((1 << i) * sizeof(int));
        fft->imgLevels[i] = (int *)malloc((1 << i) * sizeof(int));
        for (int j = 0, s = 1 << i; j < s; j++) {
            fft->realLevels[i][j] = cos(M_PI / s * j);
            fft->imgLevels[i][j] = sin(M_PI / s * j);
        }
    }
}

void dft(FastFourierTransform *fft, int *p, int m) {
    int n = 1 << m;

    int shift = 32 - __builtin_ctz(n);
    for (int i = 1; i < n; i++) {
        int j = __builtin_bswap32(i << shift);
        if (i < j) {
            int tmp = p[i];
            p[i] = p[j];
            p[j] = tmp;
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
                int realA = p[a] & ((1 << 15) - 1);
                int imgA = p[a] >> 15;
                int realB = p[b] & ((1 << 15) - 1);
                int imgB = p[b] >> 15;

                int realLevel = fft->realLevels[d][j];
                int imgLevel = fft->imgLevels[d][j];

                int realMul = mul(new_Modular(998244353), realLevel, realB) - mul(new_Modular(998244353), imgLevel, imgB);
                int imgMul = mul(new_Modular(998244353), realLevel, imgB) + mul(new_Modular(998244353), imgLevel, realB);

                t[0] = p[a] + realMul;
                t[1] = imgA + imgMul;
                p[b] = p[a] - realMul;
                p[a] = imgA - imgMul;
            }
        }
    }
}

void idft(FastFourierTransform *fft, int *p, int m) {
    dft(fft, p, m);

    int n = 1 << m;
    int invN = new_Modular(n).m - 1;
    int invN2 = mul(new_Modular(n).m - 1, invN, invN);
    int invN3 = mul(new_Modular(n).m - 1, invN2, invN);

    p[0] = mul(new_Modular(n), p[0], invN);
    p[n / 2] = mul(new_Modular(n), p[n / 2], invN);

    for (int i = 1, until = n / 2; i < until; i++) {
        int a = p[n - i];
        int b = p[i];
        p[i] = mul(new_Modular(n), a, invN);
        p[n - i] = mul(new_Modular(n), b, invN);
    }
}

int *multiplyMod(int *a, int aLen, int *b, int bLen, int m) {
    int need = aLen + bLen - 1;
    int n = 1 << (int)ceil(log2(need));

    int *aReal = (int *)malloc(n * sizeof(int));
    int *aImag = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < aLen; i++) {
        int x = a[i] % m;
        aReal[i] = x & ((1 << 15) - 1);
        aImag[i] = x >> 15;
    }
    dft(new FastFourierTransform(), aReal, (int)floor(log2(n)));

    int *bReal = (int *)malloc(n * sizeof(int));
    int *bImag = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < bLen; i++) {
        int x = b[i] % m;
        bReal[i] = x & ((1 << 15) - 1);
        bImag[i] = x >> 15;
    }
    dft(new FastFourierTransform(), bReal, (int)floor(log2(n)));

    int *faReal = (int *)malloc(n * sizeof(int));
    int *faImag = (int *)malloc(n * sizeof(int));
    int *fbReal = (int *)malloc(n * sizeof(int));
    int *fbImag = (int *)malloc(n * sizeof(int));

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

    idft(new FastFourierTransform(), faReal, (int)floor(log2(n)));
    idft(new FastFourierTransform(), fbReal, (int)floor(log2(n)));
    int *res = (int *)malloc(need * sizeof(int));
    for (int i = 0; i < need; i++) {
        long long aa = (long long)(faReal[i] + 0.5);
        long long bb = (long long)(fbReal[i] + 0.5);
        long long cc = (long long)(faImag[i] + 0.5);
        res[i] = ((aa % m + ((bb % m) << 15) + ((cc % m) << 30)) % m + m) % m;
    }
    return res;
}

typedef struct {
    int *data;
    int pos;
} Loop;

Loop new_Loop(int *data) {
    Loop loop;
    loop.data = data;
    loop.pos = 0;
    return loop;
}

int turn(Loop *loop, int i) {
    loop->pos += i;
    return loop->data[0];
}

int get(Loop *loop, int i) {
    return loop->data[(loop->pos + i) % 2];
}

int get_(Loop *loop) {
    return get(loop, 0);
}

typedef struct {
    int m;
    int *inv;
} CachedPow;

CachedPow new_CachedPow(int x, Modular mod) {
    CachedPow cp;
    cp.m = mod.m;
    cp.inv = (int *)malloc((x + 1) * sizeof(int));
    cp.inv[1] = 1;
    int p = mod.m;
    for (int i = 2; i <= x; i++) {
        int k = p / i;
        int r = p % i;
        cp.inv[i] = mul(mod, -k, cp.inv[r]);
    }
    return cp;
}

int pow(CachedPow *cp, int exp) {
    return cp->inv[exp];
}

int inverse(CachedPow *cp, int exp) {
    return pow(cp, -exp);
}

typedef struct {
    int *realLevels[30];
    int *imgLevels[30];
} FastFourierTransform;

void prepareLevel(FastFourierTransform *fft, int i) {
    if (fft->realLevels[i] == NULL) {
        fft->realLevels[i] = (int *)malloc((1 << i) * sizeof(int));
        fft->imgLevels[i] = (int *)malloc((1 << i) * sizeof(int));
        for (int j = 0, s = 1 << i; j < s; j++) {
            fft->realLevels[i][j] = cos(M_PI / s * j);
            fft->imgLevels[i][j] = sin(M_PI / s * j);
        }
    }
}

void dft(FastFourierTransform *fft, int *p, int m) {
    int n = 1 << m;

    int shift = 32 - __builtin_ctz(n);
    for (int i = 1; i < n; i++) {
        int j = __builtin_bswap32(i << shift);
        if (i < j) {
            int tmp = p[i];
            p[i] = p[j];
            p[j] = tmp;
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
                int realA = p[a] & ((1 << 15) - 1);
                int imgA = p[a] >> 15;
                int realB = p[b] & ((1 << 15) - 1);
                int imgB = p[b] >> 15;

                int realLevel = fft->realLevels[d][j];
                int imgLevel = fft->imgLevels[d][j];

                int realMul = mul(new_Modular(998244353), realLevel, realB) - mul(new_Modular(998244353), imgLevel, imgB);
                int imgMul = mul(new_Modular(998244353), realLevel, imgB) + mul(new_Modular(998244353), imgLevel, realB);

                t[0] = p[a] + realMul;
                t[1] = imgA + imgMul;
                p[b] = p[a] - realMul;
                p[a] = imgA - imgMul;
            }
        }
    }
}

void idft(FastFourierTransform *fft, int *p, int m) {
    dft(fft, p, m);

    int n = 1 << m;
    int invN = new_Modular(n).m - 1;
    int invN2 = mul(new_Modular(n).m - 1, invN, invN);
    int invN3 = mul(new_Modular(n).m - 1, invN2, invN);

    p[0] = mul(new_Modular(n), p[0], invN);
    p[n / 2] = mul(new_Modular(n), p[n / 2], invN);

    for (int i = 1, until = n / 2; i < until; i++) {
        int a = p[n - i];
        int b = p[i];
        p[i] = mul(new_Modular(n), a, invN);
        p[n - i] = mul(new_Modular(n), b, invN);
    }
}

int *multiplyMod(int *a, int aLen, int *b, int bLen, int m) {
    int need = aLen + bLen - 1;
    int n = 1 << (int)ceil(log2(need));

    int *aReal = (int *)malloc(n * sizeof(int));
    int *aImag = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < aLen; i++) {
        int x = a[i] % m;
        aReal[i] = x & ((1 << 15) - 1);
        aImag[i] = x >> 15;
    }
    dft(new FastFourierTransform(), aReal, (int)floor(log2(n)));

    int *bReal = (int *)malloc(n * sizeof(int));
    int *bImag = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < bLen; i++) {
        int x = b[i] % m;
        bReal[i] = x & ((1 << 15) - 1);
        bImag[i] = x >> 15;
    }
    dft(new FastFourierTransform(), bReal, (int)floor(log2(n)));

    int *faReal = (int *)malloc(n * sizeof(int));
    int *faImag = (int *)malloc(n * sizeof(int));
    int *fbReal = (int *)malloc(n * sizeof(int));
    int *fbImag = (int *)malloc(n * sizeof(int));

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

    idft(new FastFourierTransform(), faReal, (int)floor(log2(n)));
    idft(new FastFourierTransform(), fbReal, (int)floor(log2(n)));
    int *res = (int *)malloc(need * sizeof(int));
    for (int i = 0; i < need; i++) {
        long long aa = (long long)(faReal[i] + 0.5);
        long long bb = (long long)(fbReal[i] + 0.5);
        long long cc = (long long)(faImag[i] + 0.5);
        res[i] = ((aa % m + ((bb % m) << 15) + ((cc % m) << 30)) % m + m) % m;
    }
    return res;
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    Modular mod = new_Modular(MOD);
    int *xk = (int *)malloc((k + 1) * sizeof(int));
    for (int i = 0; i <= k; i++) {
        xk[i] = pow(new_CachedPow(m, mod), i);
    }

    int ans = 0;
    int *bc = multiplyMod(new_IntegerList(n), new_IntegerList(k), mod.m);
    for (int t = 0; t <= k; t++) {
        int p1 = bc[t];
        int p2 = 0;
        for (int i = 0; i <= t; i++) {
            int contrib = mul(mod, t, i);
            contrib = mul(mod, contrib, xk[t - i]);
            if (i % 2 == 1) {
                contrib = valueOf(mod, -contrib);
            }
            p2 = plus(mod, p2, contrib);
        }
        int p3 = inverse(new_CachedPow(t, mod), t);

        int contrib = mul(mod, p1, p2);
        contrib = mul(mod, contrib, p3);
        ans = plus(mod, ans, contrib);
    }

    printf("%d\n", ans);

    return 0;
}
