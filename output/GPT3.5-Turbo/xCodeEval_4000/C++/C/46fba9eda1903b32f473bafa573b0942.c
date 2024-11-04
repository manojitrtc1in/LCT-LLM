#include <stdio.h>

typedef long long ll;

#define MOD 1000000007
#define INF 1000000000000000000

void yes() {
    printf("Yes\n");
}

void no() {
    printf("No\n");
}

int main() {
    ll a;
    scanf("%lld", &a);
    ll n = 100000000000000000;
    n *= 18;
    n %= a;
    ll k = n;
    for (int i = 0; i < 44; i++) {
        n = (n + k) % a;
    }
    if (n < 0) {
        n += a;
    }
    ll c = a - n;
    ll d = c + 1000000000000000000 - 1;
    printf("%lld %lld", c, d);
    return 0;
}
