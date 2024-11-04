#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

ll a[101010];

ll cnk(ll n, ll k) {
    ll ret = 1;
    for (ll i = n - k + 1; i <= n; i++) {
        ret *= i;
    }
    for (int i = 1; i <= k; i++) {
        ret /= i;
    }
    return ret;
}

void solve() {
    ll n, k;
    scanf("%lld %lld", &n, &k);
    if (k == 1) {
        printf("1\n");
        exit(0);
    }
    a[2] = 1;
    for (int i = 3; i <= 10; i++) {
        a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
    }

    ll ans = 1;
    for (int i = 0; i < k; i++) {
        ans += cnk(n, k - i) * a[k - i];
    }

    printf("%lld\n", ans);
}

int main() {
    printf("%.10lf\n", 0.0);
    solve();
    return 0;
}
