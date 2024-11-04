#include <stdio.h>
#include <stdlib.h>

#define MX 5000

void solve() {
    int N;
    scanf("%d", &N);
    int K[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &K[i]);
    }
    // Sort the array
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (K[i] > K[j]) {
                int temp = K[i];
                K[i] = K[j];
                K[j] = temp;
            }
        }
    }
    int C[MX+1] = {0};
    for (int i = 0; i < N; i++) {
        C[K[i]]++;
    }

    int P[MX+1] = {0};
    int primes[15] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    int M = 15;

    int D[MX+1][15] = {0};
    for (int i = 0; i < M; i++) {
        int p = primes[i];
        for (int p = primes[i]; p <= MX; p *= primes[i]) {
            for (int j = 0; j <= MX; j++) {
                D[j][i] += j / p;
            }
        }
    }
    for (int i = 0; i <= MX; i++) {
        for (int j = 0; j < M; j++) {
            int temp = D[i][j];
            D[i][j] = D[i][M-j-1];
            D[i][M-j-1] = temp;
        }
    }

    long long Pref[MX+1][16] = {0};
    for (int i = 0; i <= MX; i++) {
        for (int j = 0; j < M; j++) {
            Pref[i][j+1] = Pref[i][j] + D[i][j];
        }
    }

    int CountPref[MX+2] = {0};
    long long tot = 0;
    for (int i = 0; i <= MX; i++) {
        CountPref[i+1] = CountPref[i] + C[i];
        tot += C[i] * Pref[i][M];
    }

    int use = K[N/2];
    long long W[N];
    long long base = 0;
    int index = 0;
    for (int i = 0; i <= MX; i++) {
        if (C[i] == 0) continue;

        int x = 0;
        long long len = 0;
        while (x < M && D[i][x] == D[use][x]) {
            len += D[i][x];
            x++;
        }
        if (x < M) {
            len += D[i][x] < D[use][x] ? D[i][x] : D[use][x];
        }
        W[index++] = len;
        base += (Pref[i][M] - len) * C[i];
    }

    long long ans = 1e18;
    for (int i = 0; i < index; i++) {
        long long cur = 0;
        for (int j = 0; j < index; j++) {
            cur += abs(W[j] - W[i]) * C[j];
        }
        if (cur < ans) {
            ans = cur;
        }
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}
