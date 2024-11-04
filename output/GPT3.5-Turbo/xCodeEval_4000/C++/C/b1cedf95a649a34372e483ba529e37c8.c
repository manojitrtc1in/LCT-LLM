#include <stdio.h>
#include <stdbool.h>

#define MAX_N 400001
#define MAX_M 200001

int K[MAX_N];
int vv[4 * MAX_M][MAX_N];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &K[i]);
    }
    for (int i = 0; i < M; i++) {
        int D, T;
        scanf("%d %d", &D, &T);
        vv[D - 1][T - 1] = 1;
    }
    int ok = 2 * sum(K), ng = sum(K) - 1;
    while (ok - ng > 1) {
        int k = (ok + ng) >> 1;
        int v[MAX_N] = {0};
        bool b[MAX_N] = {false};
        for (int i = k - 1; i >= 0; i--) {
            for (int j = 0; j < N; j++) {
                if (!b[j] && vv[i][j]) {
                    b[j] = true;
                    v[i] += K[j];
                }
            }
        }
        int t = 0;
        int s = sum(K);
        for (int i = 0; i < k; i++) {
            t++;
            int m = (t < v[i]) ? t : v[i];
            t -= m;
            s -= m;
        }
        if (t >= s * 2) {
            ok = k;
        } else {
            ng = k;
        }
    }
    printf("%d\n", ok);
    return 0;
}
