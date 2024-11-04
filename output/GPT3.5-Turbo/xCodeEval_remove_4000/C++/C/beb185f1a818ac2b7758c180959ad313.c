#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

#define INF (1LL << 61)

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ll id1(ll a, ll b, ll* x, ll* y) {
    if (a < b) {
        return id1(b, a, y, x);
    }

    if (b > 0) {
        int g = id1(b, a % b, y, x);
        *y -= (a / b) * (*x);
        return g;
    } else {
        *x = 1, *y = 0;
        return a;
    }
}

int main() {
    ll m;
    scanf("%lld", &m);
    ll h1, a1, x1, y1;
    scanf("%lld %lld %lld %lld", &h1, &a1, &x1, &y1);
    ll t[1000000];
    int used[1000000] = {0};
    used[h1] = 1;
    int t_size = 1;
    t[0] = h1;
    while (1) {
        ll tmp = (t[t_size - 1] * x1 + y1) % m;
        t[t_size] = tmp;
        if (used[tmp]) {
            break;
        }
        used[tmp] = 1;
        t_size++;
    }
    int used2[1000000] = {0};
    ll h2, a2, x2, y2;
    scanf("%lld %lld %lld %lld", &h2, &a2, &x2, &y2);
    used2[h2] = 1;
    ll s[1000000];
    int s_size = 1;
    s[0] = h2;
    while (1) {
        ll tmp = (s[s_size - 1] * x2 + y2) % m;
        s[s_size] = tmp;
        if (used2[tmp]) {
            break;
        }
        used2[tmp] = 1;
        s_size++;
    }

    ll l1 = -1, l2 = -1;
    ll mn1 = INF, mn2 = INF;
    int now = 0;
    while (1) {
        if (t[t_size - 1] == t[now]) {
            l1 = t_size - now - 1;
        }
        if (t[now] == a1) {
            mn1 = now;
            break;
        }
        now++;
        if (now == t_size) {
            break;
        }
    }
    now = 0;
    while (1) {
        if (s[s_size - 1] == s[now]) {
            l2 = s_size - now - 1;
        }
        if (s[now] == a2) {
            mn2 = now;
            break;
        }
        now++;
        if (now == s_size) {
            break;
        }
    }

    ll calc() {
        if (mn1 != INF && mn2 != INF) {
            if (mn1 == mn2) {
                return mn1;
            }
            if (mn1 > mn2 && l2 == -1) {
                return -1;
            }
            if (mn1 < mn2 && l1 == -1) {
                return -1;
            }
            if (l1 == -1) {
                if ((mn1 - mn2) % l2 == 0) {
                    return mn1;
                } else {
                    return -1;
                }
            }
            if (l2 == -1) {
                if ((mn2 - mn1) % l1 == 0) {
                    return mn2;
                } else {
                    return -1;
                }
            }
            if (l1 == l2) {
                if (abs(mn1 - mn2) % l1 == 0) {
                    return mn1 > mn2 ? mn1 : mn2;
                } else {
                    return -1;
                }
            }
            if (mn2 > mn1 && (mn2 - mn1) % l1 == 0) {
                return mn2;
            }
            if (mn1 > mn2 && (mn1 - mn2) % l2 == 0) {
                return mn1;
            }

            if (abs(mn2 - mn1) % abs(gcd(l1, l2)) != 0) {
                return -1;
            }
            ll x, y;
            ll g = id1(l1, l2, &x, &y);
            x *= (mn2 - mn1) / g;
            y *= (mn2 - mn1) / g;
            ll mn = INF;
            while (x * l1 + mn1 < (mn1 > mn2 ? mn1 : mn2)) {
                x += l2 / g;
            }
            mn = x * l1 + mn1;
            while (1) {
                x -= l2 / g;
                if (x * l1 + mn1 >= (mn1 > mn2 ? mn1 : mn2)) {
                    if (mn > x * l1 + mn1) {
                        mn = x * l1 + mn1;
                    }
                } else {
                    break;
                }
            }
            return mn;
        } else {
            return -1;
        }
    }

    printf("%lld\n", calc());

    return 0;
}
