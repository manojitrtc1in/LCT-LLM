#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN 200005
#define MOD 1000000007

typedef struct {
    long long first;
    long long second;
} pii;

pii adj[MAXN][MAXN];
long long vis[MAXN];
long long n, m, t, c = 0;
long long q[MAXN];
int q_size = 0;

void push(long long value) {
    if (q_size < t) {
        q[q_size++] = value;
        if (q_size == t) {
            // Sort the queue to maintain the smallest t elements
            for (int i = 0; i < q_size; i++) {
                for (int j = i + 1; j < q_size; j++) {
                    if (q[i] > q[j]) {
                        long long temp = q[i];
                        q[i] = q[j];
                        q[j] = temp;
                    }
                }
            }
        }
    } else if (value < q[q_size - 1]) {
        q[q_size - 1] = value;
        // Sort the queue again
        for (int i = 0; i < q_size; i++) {
            for (int j = i + 1; j < q_size; j++) {
                if (q[i] > q[j]) {
                    long long temp = q[i];
                    q[i] = q[j];
                    q[j] = temp;
                }
            }
        }
    }
}

void solve(long long ind) {
    if (ind == n) {
        push(c);
        return;
    }
    solve(ind + 1);
    for (long long i = 0; i < adj[ind][0].first; i++) {
        if (vis[adj[ind][i].first] == 0) {
            vis[adj[ind][i].first] = 1;
            c += adj[ind][i].second;
            if (q_size < t || c < q[q_size - 1]) solve(ind + 1);
            c -= adj[ind][i].second;
            vis[adj[ind][i].first] = 0;
        }
    }
}

int main() {
    long long r, s = 0, x, i, j, k, l;
    scanf("%lld %lld %lld", &n, &m, &t);
    for (long long i = 0; i < m; i++) {
        long long x, y, w;
        scanf("%lld %lld %lld", &x, &y, &w);
        x--, y--;
        adj[x][0].first++;
        adj[x][adj[x][0].first].first = y;
        adj[x][adj[x][0].first].second = w;
    }
    solve(0);
    printf("%lld\n", q[q_size - 1]);
    return 0;
}
