#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

typedef long long ll;
typedef unsigned long long ull;

void doReplace() {
}

void minim(int *was, const int cand) {
    if (*was > cand) {
        *was = cand;
    }
}

void maxim(int *was, const int cand) {
    if (*was < cand) {
        *was = cand;
    }
}

ll dPower(double base, ll exponent) {
    if (exponent < 0) {
        return dPower(1.0 / base, -exponent);
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
    int *data;
    int size;
} arr;

arr createArr(int n) {
    arr a;
    a.size = n;
    a.data = (int *)malloc(n * sizeof(int));
    return a;
}

void freeArr(arr *a) {
    free(a->data);
}

void decreaseByOne(arr *array) {
    for (int i = 0; i < array->size; i++) {
        array->data[i]--;
    }
}

arr readIntArray(int size) {
    arr result = createArr(size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &result.data[i]);
    }
    return result;
}

void sortArr(arr *a) {
    for (int i = 0; i < a->size - 1; i++) {
        for (int j = 0; j < a->size - i - 1; j++) {
            if (a->data[j] > a->data[j + 1]) {
                int temp = a->data[j];
                a->data[j] = a->data[j + 1];
                a->data[j + 1] = temp;
            }
        }
    }
}

int bitCount(unsigned x) {
    return __builtin_popcount(x);
}

int isSet(unsigned mask, int bit) {
    return (mask >> bit) & 1;
}

int main() {
    int n;
    scanf("%d", &n);
    arr a = readIntArray(n);
    
    sortArr(&a);
    arr d = createArr(n);
    for (int i = 0; i < n; i++) {
        ll c = a.data[i];
        d.data[i] = 0;
        for (ll j = 2; j * j <= c; j++) {
            while (c % j == 0) {
                d.data[i]++;
                c /= j;
            }
        }
        if (c != 1) {
            d.data[i]++;
        }
    }
    
    int infty = INT_MAX / 2;
    arr reachable = createArr(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        reachable.data[i] = infty;
    }
    reachable.data[0] = 0;

    for (int i = 0; i < n; i++) {
        for (unsigned j = 0; j < (1 << i); j++) {
            ll rem = a.data[i];
            int good = 1;
            for (int k = 0; k < i; k++) {
                if (isSet(j, k)) {
                    if (rem % a.data[k] != 0) {
                        good = 0;
                        break;
                    }
                    rem /= a.data[k];
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
                    if ((j & k) == 0 && reachable.data[j + k] != infty && j + k >= lim) {
                        minim(&reachable.data[(1 << i) + k], reachable.data[j + k] + qty + (d.data[i] == 1 ? 0 : 1));
                    }
                }
            }
        }
    }

    int answer = infty;
    for (unsigned i = (1 << (n - 1)); i < (1 << n); i++) {
        if (!reachable.data[i]) {
            continue;
        }
        minim(&answer, reachable.data[i] + (bitCount(i) == 1 ? 0 : 1));
    }
    
    printf("%d\n", answer);
    
    freeArr(&a);
    freeArr(&d);
    freeArr(&reachable);
    
    return 0;
}
