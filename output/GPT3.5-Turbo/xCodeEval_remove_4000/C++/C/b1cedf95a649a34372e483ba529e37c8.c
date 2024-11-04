#include <stdio.h>
#include <stdbool.h>

#define MAX_N 200000
#define MAX_M 200000

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    int K[MAX_N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &K[i]);
    }
    
    int vv[4 * MAX_M + 1][MAX_N];
    for (int i = 0; i < M; i++) {
        int D, T;
        scanf("%d %d", &D, &T);
        vv[D - 1][T - 1] = 1;
    }
    
    int ok = 2 * sum(K, N), ng = sum(K, N) - 1;
    while (ok - ng > 1) {
        int k = (ok + ng) >> 1;
        int v[MAX_M] = {0};
        bool b[MAX_N] = {false};
        
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < N; j++) {
                if (!b[j] && vv[i][j]) {
                    b[j] = true;
                    v[i] += K[j];
                }
            }
        }
        
        int t = 0;
        int s = sum(K, N);
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

int sum(int arr[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += arr[i];
    }
    return s;
}
