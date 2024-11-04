#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define INF 1LL << 61

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

ll calc(ll m, ll h1, ll a1, ll x1, ll y1, ll h2, ll a2, ll x2, ll y2) {
    ll* t = (ll*)malloc(sizeof(ll) * m);
    ll* s = (ll*)malloc(sizeof(ll) * m);
    ll* used = (ll*)calloc(m, sizeof(ll));

    t[0] = h1;
    used[h1] = 1;
    int t_size = 1;
    while (1) {
        ll tmp = (t[t_size - 1] * x1 + y1) % m;
        t[t_size] = tmp;
        if (used[tmp]) {
            break;
        }
        used[tmp] = 1;
        t_size++;
    }

    used = (ll*)calloc(m, sizeof(ll));
    s[0] = h2;
    used[h2] = 1;
    int s_size = 1;
    while (1) {
        ll tmp = (s[s_size - 1] * x2 + y2) % m;
        s[s_size] = tmp;
        if (used[tmp]) {
            break;
        }
        used[tmp] = 1;
        s_size++;
    }

    ll l1 = -1, l2 = -1;
    ll mn1 = INF, mn2 = INF;
    ll now = 0;
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

    ll result = -1;
    if (mn1 != INF && mn2 != INF) {
        if (mn1 == mn2) {
            result = mn1;
        } else if (mn1 > mn2 && l2 == -1) {
            result = -1;
        } else if (mn1 < mn2 && l1 == -1) {
            result = -1;
        } else if (l1 == -1) {
            if ((mn1 - mn2) % l2 == 0) {
                result = mn1;
            } else {
                result = -1;
            }
        } else if (l2 == -1) {
            if ((mn2 - mn1) % l1 == 0) {
                result = mn2;
            } else {
                result = -1;
            }
        } else if (l1 == l2) {
            if (abs(mn1 - mn2) % l1 == 0) {
                result = mn1 > mn2 ? mn1 : mn2;
            } else {
                result = -1;
            }
        } else {
            if (mn2 > mn1 && (mn2 - mn1) % l1 == 0) {
                result = mn2;
            } else if (mn1 > mn2 && (mn1 - mn2) % l2 == 0) {
                result = mn1;
            } else if (abs(mn2 - mn1) % abs(gcd(l1, l2)) != 0) {
                result = -1;
            } else {
                ll x, y;
                ll g = id1(l1, l2, &x, &y);
                x *= (mn2 - mn1) / g;
                y *= (mn2 - mn1) / g;
                if (x * l1 + mn1 < (mn1 > mn2 ? mn1 : mn2)) {
                    x += (((mn1 > mn2 ? mn1 : mn2) - x * l1 + mn1 + l1 - 1) / l1 + l2 / g - 1) / (l2 / g) * (l2 / g);
                }
                if (x * l1 + mn1 >= (mn1 > mn2 ? mn1 : mn2)) {
                    x -= (x * l1 + mn1 - (mn1 > mn2 ? mn1 : mn2)) / l1 / (l2 / g) * (l2 / g);
                }
                result = x * l1 + mn1;
            }
        }
    }

    free(t);
    free(s);
    free(used);

    return result;
}

int main() {
    ll m;
    scanf("%lld", &m);
    ll h1, a1, x1, y1;
    scanf("%lld %lld %lld %lld", &h1, &a1, &x1, &y1);
    ll h2, a2, x2, y2;
    scanf("%lld %lld %lld %lld", &h2, &a2, &x2, &y2);

    ll result = calc(m, h1, a1, x1, y1, h2, a2, x2, y2);
    printf("%lld\n", result);

    return 0;
}
