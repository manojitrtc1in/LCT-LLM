#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define e5 100000
#define e9 1000000000
#define MD 1000000007

typedef long long ll;
typedef struct {
    int *data;
    int size;
} vi;

void init_vi(vi *v, int size) {
    v->data = (int *)malloc(size * sizeof(int));
    v->size = size;
}

void free_vi(vi *v) {
    free(v->data);
}

ll sum(vi a) {
    ll s = 0;
    for (int i = 0; i < a.size; i++) {
        s += a.data[i];
    }
    return s;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    vi K;
    init_vi(&K, N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &K.data[i]);
    }
    
    vi *vv = (vi *)malloc((4 * e5 + 1) * sizeof(vi));
    for (int i = 0; i < 4 * e5 + 1; i++) {
        init_vi(&vv[i], 0);
    }

    for (int _ = 0; _ < M; _++) {
        int D, T;
        scanf("%d %d", &D, &T);
        D--;
        T--;
        vv[D].data = (int *)realloc(vv[D].data, (vv[D].size + 1) * sizeof(int));
        vv[D].data[vv[D].size++] = T;
    }

    int ok = 2 * sum(K), ng = sum(K) - 1;
    while (ok - ng > 1) {
        int k = (ok + ng) >> 1;
        vi v;
        init_vi(&v, k);
        bool *b = (bool *)calloc(N, sizeof(bool));
        
        for (int i = k - 1; i >= 0; i--) {
            for (int j = 0; j < vv[i].size; j++) {
                if (!b[vv[i].data[j]]) {
                    b[vv[i].data[j]] = true;
                    v.data[i] += K.data[vv[i].data[j]];
                }
            }
        }

        int t = 0;
        int s = sum(K);
        for (int i = 0; i < k; i++) {
            t++;
            int m = (t < v.data[i]) ? t : v.data[i];
            t -= m;
            s -= m;
        }

        (t >= s * 2 ? ok : ng) = k;

        free(b);
        free_vi(&v);
    }

    printf("%d\n", ok);

    for (int i = 0; i < 4 * e5 + 1; i++) {
        free_vi(&vv[i]);
    }
    free(vv);
    free_vi(&K);
    
    return 0;
}
