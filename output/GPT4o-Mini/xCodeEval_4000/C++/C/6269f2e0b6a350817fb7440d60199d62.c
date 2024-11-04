#include <stdio.h>

typedef long long ll;

typedef struct {
    unsigned int _v;
} mint;

unsigned int mod = 1000000007;

mint raw(int v) {
    mint x;
    x._v = v % mod;
    return x;
}

unsigned int val(mint x) {
    return x._v;
}

mint add(mint a, mint b) {
    mint result;
    result._v = (a._v + b._v) % mod;
    return result;
}

