#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN 200005
#define MOD 1000000007

typedef long long ll;
typedef struct {
    ll first;
    ll second;
} pii;

typedef struct {
    ll first;
    pii second;
} ver;

pii adj[MAXN];
ll vis[MAXN];
ll n, m, t, c = 0;
ll q[MAXN];
int q_size = 0;

void push(ll value) {
    if (q_size < t) {
        q[q_size++] = value;
        if (q_size == t) {
            for (int i = q_size / 2 - 1; i >= 0; i--) {
                // Heapify
                for (int j = 2 * i + 1; j < q_size; j = 2 * j + 1) {
                    if (j + 1 < q_size && q[j] < q[j + 1]) j++;
                    if (q[i] < q[j]) {
                        ll temp = q[i];
                        q[i] = q[j];
                        q[j] = temp;
                        i = j - 1;
                    } else {
                        break;
                    }
                }
            }
        }
    } else if (value < q[0]) {
        q[0] = value;
        // Heapify
        for (int i = 0; i < q_size; ) {
            int j = 2 * i + 1;
            if (j >= q_size) break;
            if (j + 1 < q_size && q[j] < q[j + 1]) j++;
            if (q[i] < q[j]) {
                ll temp = q[i];
                q[i] = q[j];
                q[j] = temp;
                i = j;
            } else {
                break;
            }
        }
    }
}

void solve(ll ind) {
    if (ind == n) {
        push(c);
        return;
    }
    solve(ind + 1);
    for (ll i = 0; i < adj[ind].first; i++) {
        if (vis[adj[ind].first] == 0) {
            vis[adj[ind].first] = 1;
            c += adj[ind].second;
            if (q_size < t || c < q[0]) solve(ind + 1);
            c -= adj[ind].second;
            vis[adj[ind].first] = 0;
        }
    }
}

int main() {
    scanf("%lld %lld %lld", &n, &m, &t);
    for (ll i = 0; i < m; i++) {
        ll x, y, w;
        scanf("%lld %lld %lld", &x, &y, &w);
        x--, y--;
        adj[x].first++;
        adj[x].second = (pii){y, w};
    }
    solve(0);
    printf("%lld\n", q[0]);
    return 0;
}
