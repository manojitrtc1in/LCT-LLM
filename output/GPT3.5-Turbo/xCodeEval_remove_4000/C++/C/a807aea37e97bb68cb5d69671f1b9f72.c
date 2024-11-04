#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MX 5000

typedef long long ll;

void solve() {
    int N;
    scanf("%d", &N);
    int K[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &K[i]);
    }
    // Sort the array K in ascending order
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-i-1; j++) {
            if (K[j] > K[j+1]) {
                int temp = K[j];
                K[j] = K[j+1];
                K[j+1] = temp;
            }
        }
    }
    int C[MX+1] = {0};
    for (int i = 0; i < N; i++) {
        C[K[i]]++;
    }

    int P[MX+1] = {0};
    int p = 2;
    int idx = 0;
    while (p <= MX) {
        if (P[p] == 0) {
            for (int i = p; i <= MX; i += p) {
                P[i] = p;
            }
        }
        p++;
    }

    int M = 0;
    for (int i = 2; i <= MX; i++) {
        if (P[i] == i) {
            M++;
        }
    }

    int D[MX+1][M];
    for (int i = 0; i <= MX; i++) {
        for (int j = 0; j < M; j++) {
            D[i][j] = 0;
        }
    }
    for (int i = 0; i < M; i++) {
        int p = P[i+2];
        for (int j = 0; j <= MX; j++) {
            int x = j;
            while (x % p == 0) {
                D[j][i]++;
                x /= p;
            }
        }
    }
    for (int i = 0; i <= MX; i++) {
        for (int j = 0; j < M; j++) {
            D[i][j] = D[i][M-1-j];
        }
    }

    ll Pref[MX+1][M+1];
    for (int i = 0; i <= MX; i++) {
        for (int j = 0; j <= M; j++) {
            Pref[i][j] = 0;
        }
    }
    for (int i = 0; i <= MX; i++) {
        for (int j = 0; j < M; j++) {
            Pref[i][j+1] = Pref[i][j] + D[i][j];
        }
    }

    int CountPref[MX+2] = {0};
    ll tot = 0;
    for (int i = 0; i <= MX; i++) {
        CountPref[i+1] = CountPref[i] + C[i];
        tot += C[i] * Pref[i][M];
    }

    int use = K[N/2];
    ll W[N];
    ll base = 0;
    int idxW = 0;
    for (int i = 0; i <= MX; i++) {
        if (C[i] == 0) continue;

        int x = 0;
        ll len = 0;
        while (x < M && D[i][x] == D[use][x]) {
            len += D[i][x];
            x++;
        }
        if (x < M) {
            len += fmin(D[i][x], D[use][x]);
        }
        W[idxW++] = len;
        base += (Pref[i][M] - len) * C[i];
    }

    for (int i = 0; i < idxW-1; i++) {
        for (int j = 0; j < idxW-i-1; j++) {
            if (W[j] > W[j+1]) {
                ll temp = W[j];
                W[j] = W[j+1];
                W[j+1] = temp;
            }
        }
    }

    ll ans = 1e18;
    for (int i = 0; i < idxW; i++) {
        ll cur = 0;
        for (int j = 0; j < idxW; j++) {
            cur += abs(W[j] - W[i]) * C[j];
        }
        ans = fmin(ans, base + cur);
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}
