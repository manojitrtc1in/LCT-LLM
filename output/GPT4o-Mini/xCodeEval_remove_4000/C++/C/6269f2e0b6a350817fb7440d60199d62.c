#include <stdio.h>

typedef long long ll;

typedef struct {
    unsigned int _v;
} mint;

mint modint1000000007(ll v) {
    mint x;
    x._v = (unsigned int)(v % 1000000007);
    return x;
}

unsigned int val(mint x) {
    return x._v;
}

int main() {
    ll q;
    scanf("%lld", &q);
    while (q--) {
        ll n;
        scanf("%lld", &n);
        ll M = n / 4 + 1;
        mint m = modint1000000007(M);
        if (n % 4 <= 1) {
            printf("%u\n", val(m) * val(m) % 1000000007);
        } else {
            printf("%u\n", val(m) * (val(m) + 1) % 1000000007);
        }
    }
    return 0;
}
