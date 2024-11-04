#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

typedef long long ll;
typedef unsigned long long ull;

void doReplace() {
}

void doReplaceSingle(int* t, const int u) {
    *t = u;
}

void doReplaceMultiple(int* t, const int u, ...) {
    *t = u;
    va_list args;
    va_start(args, u);
    int* next;
    while ((next = va_arg(args, int*)) != NULL) {
        *next = u;
    }
    va_end(args);
}

int minim(int* was, const int cand, ...) {
    if (*was > cand) {
        *was = cand;
        doReplaceSingle(was, cand);
    }
    return *was;
}

int maxim(int* was, const int cand, ...) {
    if (*was < cand) {
        *was = cand;
        doReplaceSingle(was, cand);
    }
    return *was;
}

double dPower(double base, ll exponent) {
    if (exponent < 0) {
        return dPower(1 / base, -exponent);
    }
    if (exponent == 0) {
        return 1;
    }
    if (exponent % 2 == 1) {
        return dPower(base, exponent - 1) * base;
    } else {
        double res = dPower(base, exponent / 2);
        return res * res;
    }
}

typedef struct {
    int v;
} NumberIterator;

NumberIterator createNumberIterator(int v) {
    NumberIterator it;
    it.v = v;
    return it;
}

typedef struct {
    int first;
    int second;
} Range;

Range createRange(int begin, int end) {
    Range r;
    r.first = begin;
    r.second = (begin > end) ? begin : end;
    return r;
}

typedef struct {
    int* b;
    int n;
} arr;

void allocate(arr* a, int sz) {
    if (sz < 0) {
        fprintf(stderr, "bad alloc\n");
        exit(1);
    }
    a->n = sz;
    if (sz > 0) {
        a->b = (int*)malloc(sz * sizeof(int));
    } else {
        a->b = NULL;
    }
}

arr createArr(int n) {
    arr a;
    allocate(&a, n);
    return a;
}

void freeArr(arr* a) {
    free(a->b);
}

int size(arr* a) {
    return a->n;
}

int* begin(arr* a) {
    return a->b;
}

int* end(arr* a) {
    return a->b + a->n;
}

int& operatorArr(arr* a, int at) {
    if (at < 0 || at >= a->n) {
        fprintf(stderr, "Out of bounds\n");
        exit(1);
    }
    return a->b[at];
}

bool operatorEqual(arr* a, arr* other) {
    if (a->n != other->n) {
        return false;
    }
    for (int i = 0; i < a->n; i++) {
        if (a->b[i] != other->b[i]) {
            return false;
        }
    }
    return true;
}

typedef struct {
    int id0;
    int bufSize;
    char* buf;
    int bufRead;
    int bufAt;
} Input;

void initInput(Input* in) {
    in->id0 = 0;
    in->bufSize = 4096;
    in->buf = (char*)malloc(in->bufSize);
    in->bufRead = 0;
    in->bufAt = 0;
}

void freeInput(Input* in) {
    free(in->buf);
}

int get(Input* in) {
    if (in->id0) {
        fprintf(stderr, "Input id0\n");
        return EOF;
    }
    if (in->bufRead == in->bufAt) {
        in->bufRead = fread(in->buf, sizeof(char), in->bufSize, stdin);
        in->bufAt = 0;
    }
    if (in->bufRead == in->bufAt) {
        in->id0 = 1;
        return EOF;
    }
    return in->buf[in->bufAt++];
}

int skipWhitespace(Input* in) {
    int c;
    while (isspace(c = get(in)) && c != EOF);
    return c;
}

int readInt(Input* in) {
    int c = skipWhitespace(in);
    int sgn = 1;
    if (c == '-') {
        sgn = -1;
        c = get(in);
    }
    int res = 0;
    do {
        if (!isdigit(c)) {
            fprintf(stderr, "Number format error\n");
            exit(1);
        }
        res = res * 10 + (c - '0');
        c = get(in);
    } while (!isspace(c));
    return res * sgn;
}

arr readIntArray(Input* in, int size) {
    arr res = createArr(size);
    for (int i = 0; i < size; i++) {
        operatorArr(&res, i) = readInt(in);
    }
    return res;
}

void printArr(arr* a) {
    for (int i = 0; i < a->n; i++) {
        printf("%d", operatorArr(a, i));
        if (i + 1 != a->n) {
            printf(" ");
        }
    }
}

void solve() {
    Input in;
    initInput(&in);
    int n = readInt(&in);
    arr a = readIntArray(&in, n);

    // Sort array a
    qsort(a.b, a.n, sizeof(int), (int (*)(const void*, const void*))compare);

    arr d = createArr(n);
    for (int i = 0; i < n; i++) {
        ll c = a.b[i];
        int count = 0;
        for (ll j = 2; j * j <= c; j++) {
            while (c % j == 0) {
                count++;
                c /= j;
            }
        }
        if (c != 1) {
            count++;
        }
        operatorArr(&d, i) = count;
    }

    int infty = INT_MAX / 2;
    arr reachable = createArr(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        operatorArr(&reachable, i) = infty;
    }
    operatorArr(&reachable, 0) = 0;

    for (int i = 0; i < n; i++) {
        for (unsigned j = 0; j < (1 << i); j++) {
            ll rem = a.b[i];
            bool good = true;
            for (int k = 0; k < i; k++) {
                if (isSet(j, k)) {
                    if (rem % a.b[k] != 0) {
                        good = false;
                        break;
                    }
                    rem /= a.b[k];
                }
            }
            int qty = 0;
            for (ll c = 2; c * c <= rem; c++) {
                while (rem % c == 0) {
                    qty++;
                    rem /= c;
                }
            }
            if (rem != 1) {
                qty++;
            }
            int lim = (i == 0) ? 0 : (1 << (i - 1));
            if (good) {
                for (unsigned k = 0; k < (1 << i); k++) {
                    if ((j & k) == 0 && operatorArr(&reachable, j + k) != infty && j + k >= lim) {
                        minim(&operatorArr(&reachable, (1 << i) + k), operatorArr(&reachable, j + k) + qty + (d.b[i] == 1 ? 0 : 1));
                    }
                }
            }
        }
    }

    int answer = infty;
    for (unsigned i = (1 << (n - 1)); i < (1 << n); i++) {
        if (!operatorArr(&reachable, i)) {
            continue;
        }
        minim(&answer, operatorArr(&reachable, i) + (bitCount(i) == 1 ? 0 : 1));
    }
    printf("%d\n", answer);
}

int main() {
    solve();
    return 0;
}
