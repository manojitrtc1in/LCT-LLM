#include <stdio.h>

typedef long long ll;

ll max(ll a, ll b) {
    if (a < b) return b;
    else return a;
}

ll min(ll a, ll b) {
    if (a > b) return b;
    else return a;
}

int main() {
    ll q;
    scanf("%lld", &q);
    while (q--) {
        ll n;
        scanf("%lld", &n);
        ll M = n / 4 + 1;
        if (n % 4 <= 1) printf("%lld\n", M * M);
        else printf("%lld\n", M * (M + 1));
    }
    return 0;
}
