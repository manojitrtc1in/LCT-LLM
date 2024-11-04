#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 100000
#define MAX_M 400000
#define MAX_K 400000

long long sum(long long *a, int size) {
    long long s = 0;
    for (int i = 0; i < size; i++) {
        s += a[i];
    }
    return s;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    long long K[MAX_N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &K[i]);
    }

    int vv[MAX_K][MAX_N];
    int vv_size[MAX_K] = {0}; // To keep track of the size of each list

    for (int _ = 0; _ < M; _++) {
        int D, T;
        scanf("%d %d", &D, &T);
        vv[D - 1][vv_size[D - 1]++] = T - 1;
    }

    long long ok = 2 * sum(K, N);
    long long ng = sum(K, N) - 1;

    while (ok - ng > 1) {
        long long k = (ok + ng) >> 1;
        long long v[MAX_K] = {0};
        bool b[MAX_N] = {false};

        for (int i = k - 1; i >= 0; i--) {
            for (int j = 0; j < vv_size[i]; j++) {
                int idx = vv[i][j];
                if (!b[idx]) {
                    b[idx] = true;
                    v[i] += K[idx];
                }
            }
        }

        int t = 0;
        long long s = sum(K, N);
        for (int i = 0; i < k; i++) {
            t++;
            long long m = (t < v[i]) ? t : v[i];
            t -= m;
            s -= m;
        }

        if (t >= s * 2) {
            ok = k;
        } else {
            ng = k;
        }
    }

    printf("%lld\n", ok);
    return 0;
}
