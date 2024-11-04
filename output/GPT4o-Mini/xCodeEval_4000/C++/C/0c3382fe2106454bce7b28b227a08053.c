#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXN 3005
#define INT_INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f

typedef struct {
    long long first;
    long long second;
} pill;

int T, N, M, B[MAXN], W[MAXN];
pill dp[MAXN][MAXN], merged[MAXN];
int adj[MAXN][MAXN];
int adj_size[MAXN];

int dfs(int v, int prev) {
    int SZV = 1;
    dp[v][0] = (pill){0, W[v] - B[v]};
    for (int i = 0; i < adj_size[v]; i++) {
        int w = adj[v][i];
        if (w != prev) {
            int SZW = dfs(w, v);
            for (int j = SZW; j >= 1; j--) {
                if (dp[w][j - 1].second > 0) {
                    dp[w][j] = (pill){dp[w][j - 1].first + 1, 0};
                } else {
                    dp[w][j] = (pill){dp[w][j - 1].first, 0};
                }
            }
            memset(merged, -INT_INF, sizeof(merged));
            for (int j = 0; j < SZV; j++) {
                for (int k = 0; k <= SZW; k++) {
                    merged[j + k] = (pill){
                        fmax(merged[j + k].first, dp[v][j].first + dp[w][k].first),
                        merged[j + k].second + dp[v][j].second + dp[w][k].second
                    };
                }
            }
            memcpy(dp[v], merged, sizeof(pill) * (SZV + SZW));
            SZV += SZW;
        }
    }
    return SZV;
}

void read(int *x) {
    scanf("%d", x);
}

void writeln(long long x) {
    printf("%lld\n", x);
}

int main() {
    read(&T);
    for (int ti = 0; ti < T; ti++) {
        read(&N);
        read(&M);
        for (int i = 0; i < N; i++) {
            read(&B[i]);
        }
        for (int i = 0; i < N; i++) {
            read(&W[i]);
        }
        for (int i = 0; i < N - 1; i++) {
            int a, b;
            read(&a);
            read(&b);
            a--; b--;
            adj[a][adj_size[a]++] = b;
            adj[b][adj_size[b]++] = a;
        }
        for (int i = 0; i < N; i++) {
            memset(dp[i], -INT_INF, sizeof(dp[i]));
        }
        dfs(0, -1);
        writeln(dp[0][M - 1].first + (dp[0][M - 1].second > 0));
        for (int i = 0; i < N; i++) {
            adj_size[i] = 0;
        }
    }
    return 0;
}
