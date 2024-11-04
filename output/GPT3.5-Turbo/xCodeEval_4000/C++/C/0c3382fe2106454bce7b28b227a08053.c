#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAXN 3005

typedef struct {
    int first;
    long long second;
} pair;

pair make_pair(int first, long long second) {
    pair p;
    p.first = first;
    p.second = second;
    return p;
}

void MAX(pair* a, pair b) {
    if (b.first > a->first || (b.first == a->first && b.second > a->second)) {
        *a = b;
    }
}

void fill(pair* arr, int size, pair value) {
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
}

pair dp[MAXN][MAXN], merged[MAXN];
int T, N, M, B[MAXN], W[MAXN];
int adj[MAXN][MAXN];

int dfs(int v, int prev) {
    int SZV = 1;
    dp[v][0] = make_pair(0, W[v] - B[v]);
    for (int i = 0; i < N; i++) {
        int w = adj[v][i];
        if (w != prev) {
            int SZW = dfs(w, v);
            for (int j = SZW; j >= 1; j--) {
                MAX(&dp[w][j], make_pair(dp[w][j - 1].first + (dp[w][j - 1].second > 0), 0LL));
            }
            fill(merged, SZV + SZW, make_pair(-INT_MAX, -LLONG_MAX));
            for (int i = 0; i < SZV; i++) {
                for (int j = 0; j <= SZW; j++) {
                    MAX(&merged[i + j], make_pair(dp[v][i].first + dp[w][j].first, dp[v][i].second + dp[w][j].second));
                }
            }
            for (int i = 0; i < SZV + SZW; i++) {
                dp[v][i] = merged[i];
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
        for (int i = 0; i < N - 1; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[--a][--b] = 1;
            adj[b][a] = 1;
        }
        for (int i = 0; i < N; i++) {
            fill(dp[i], N + 1, make_pair(-INT_MAX, -LLONG_MAX));
        }
        dfs(0, -1);
        printf("%d\n", dp[0][M - 1].first + (dp[0][M - 1].second > 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                adj[i][j] = 0;
            }
        }
    }
    return 0;
}
