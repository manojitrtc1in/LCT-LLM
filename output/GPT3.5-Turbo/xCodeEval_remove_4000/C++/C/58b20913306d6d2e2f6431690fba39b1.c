#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200000

typedef long long ll;

ll gcd(ll a, ll b) {
    ll temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll modpow(ll a, ll n, ll temp) {
    ll res = 1, y = a;
    while (n > 0) {
        if (n & 1) {
            res = (res * y) % temp;
        }
        y = (y * y) % temp;
        n /= 2;
    }
    return res % temp;
}

ll ison(ll mask, ll pos) {
    return (mask & (1 << pos));
}

typedef struct {
    ll first;
    ll second;
} pii;

ll xo(ll i) {
    if ((i & 3) == 0) {
        return i;
    }
    if ((i & 3) == 1) {
        return 1;
    }
    if ((i & 3) == 2) {
        return i + 1;
    }
    return 0;
}

int main() {
    ll i, j, k, l, m, n;
    scanf("%lld", &n);
    ll tot = 0;
    ll data[MAX_SIZE][MAX_SIZE];
    for (i = 1; i <= n; i++) {
        ll k, a, x, y, m;
        scanf("%lld %lld %lld %lld %lld", &k, &a, &x, &y, &m);
        tot += k;
        ll tmp[MAX_SIZE];
        tmp[0] = a;
        for (j = 2; j <= k; j++) {
            tmp[j - 1] = (tmp[j - 2] * x + y) % m;
        }
        for (j = 0; j < k; j++) {
            data[i - 1][j] = tmp[j];
        }
    }
    ll q[MAX_SIZE][3];
    ll q_size = 0;
    for (i = 0; i < n; i++) {
        q[q_size][0] = data[i][0];
        q[q_size][1] = i;
        q[q_size][2] = 0;
        q_size++;
    }
    ll ans[MAX_SIZE];
    pii sol[MAX_SIZE];
    ll p = 0;
    ll ans_size = 0;
    while (ans_size < tot) {
        ll min_val = 1e18;
        ll min_idx = -1;
        ll min_j = -1;
        for (i = 0; i < q_size; i++) {
            if (q[i][0] < min_val) {
                min_val = q[i][0];
                min_idx = q[i][1];
                min_j = q[i][2];
            }
        }
        p = min_val;
        ans[ans_size] = p;
        sol[ans_size].first = p;
        sol[ans_size].second = min_idx + 1;
        ans_size++;
        for (i = 0; i < q_size; i++) {
            if (q[i][1] == min_idx && q[i][2] == min_j) {
                for (j = i; j < q_size - 1; j++) {
                    q[j][0] = q[j + 1][0];
                    q[j][1] = q[j + 1][1];
                    q[j][2] = q[j + 1][2];
                }
                q_size--;
                break;
            }
        }
        if (min_j + 1 < k) {
            q[q_size][0] = data[min_idx][min_j + 1];
            q[q_size][1] = min_idx;
            q[q_size][2] = min_j + 1;
            q_size++;
        }
    }
    ll bad = 0;
    for (i = 1; i < ans_size; i++) {
        if (ans[i - 1] > ans[i]) {
            bad++;
        }
    }
    printf("%lld\n", bad);
    if (tot <= 200000) {
        for (i = 0; i < ans_size; i++) {
            printf("%lld %lld\n", sol[i].first, sol[i].second);
        }
    }
    return 0;
}
