#include <stdio.h>
#include <stdlib.h>

#define MAXN 3005

typedef long long ll;
typedef struct {
    int first;
    ll second;
} pill;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int T, N, M, B[MAXN], W[MAXN];
pill dp[MAXN][MAXN], merged[MAXN];
int adj[MAXN][MAXN];

int dfs(int v, int prev) {
    int SZV = 1;
    dp[v][0].first = 0;
    dp[v][0].second = W[v] - B[v];
    for (int i = 0; i < N; i++) {
        if (adj[v][i] && i != prev) {
            int w = i;
            int SZW = dfs(w, v);
            for (int i = SZW; i >= 1; i--) {
                if (dp[w][i - 1].second > 0) {
                    dp[w][i].first = dp[w][i - 1].first + 1;
                } else {
                    dp[w][i].first = dp[w][i - 1].first;
                }
                dp[w][i].second = 0;
            }
            for (int i = 0; i < SZV + SZW; i++) {
                merged[i].first = -INT_MAX;
                merged[i].second = -LLONG_MAX;
            }
            for (int i = 0; i < SZV; i++) {
                for (int j = 0; j <= SZW; j++) {
                    if (dp[v][i].first + dp[w][j].first > merged[i + j].first) {
                        merged[i + j].first = dp[v][i].first + dp[w][j].first;
                        merged[i + j].second = dp[v][i].second + dp[w][j].second;
                    }
                }
            }
            for (int i = 0; i < SZV + SZW; i++) {
                dp[v][i].first = merged[i].first;
                dp[v][i].second = merged[i].second;
            }
            SZV += SZW;
        }
    }
    return SZV;
}

int main() {
    scanf("%d", &T);
    for (int ti = 0; ti < T; ti++) {
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++) {
            scanf("%d", &B[i]);
        }
        for (int i = 0; i < N; i++) {
            scanf("%d", &W[i]);
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                adj[i][j] = 0;
            }
        }
        for (int i = 0; i < N - 1; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a - 1][b - 1] = 1;
            adj[b - 1][a - 1] = 1;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= N; j++) {
                dp[i][j].first = -INT_MAX;
                dp[i][j].second = -LLONG_MAX;
            }
        }
        dfs(0, -1);
        printf("%d\n", dp[0][M - 1].first + (dp[0][M - 1].second > 0 ? 1 : 0));
    }
    return 0;
}
