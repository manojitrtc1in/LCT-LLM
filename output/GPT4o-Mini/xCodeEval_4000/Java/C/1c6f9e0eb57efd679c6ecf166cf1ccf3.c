#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MOD 998244353
#define BIG (8LL * MOD * MOD)

typedef struct {
    int *data;
    int size;
} IntArray;

IntArray pow(int **A, IntArray v, long e);
IntArray mul(int **A, IntArray v);
int **p2(int **A, int n);
int lowerBound(int *a, int l, int r, int v);
int ni();
long nl();
char *ns();
void solve();
void run();

int main() {
    run();
    return 0;
}

void solve() {
    int n = ni(), m = ni();
    char **oss = malloc(n * sizeof(char *));
    int *offset = malloc((n + 1) * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        oss[i] = ns();
    }
    
    offset[0] = 1;
    for (int i = 0; i < n; i++) {
        offset[i + 1] = offset[i] + strlen(oss[i]) - 1;
    }
    
    int U = offset[n] - 1;
    const int D = 5;
    int **M = malloc((U + 1) * D * sizeof(int *));
    for (int i = 0; i < (U + 1) * D; i++) {
        M[i] = calloc((U + 1) * D, sizeof(int));
    }

    for (int i = 0; i <= U; i++) {
        int lb, of;
        if (i == 0) {
            lb = 0;
            of = 0;
        } else {
            lb = lowerBound(offset, i + 1, n + 1, 0) - 1;
            of = i - offset[lb] + 1;
        }

        if (i == 0) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (k != j && strncmp(oss[k], oss[j], strlen(oss[j])) == 0) {
                        M[offset[k] + strlen(oss[j]) - 1][0 + (U + 1) * (strlen(oss[j]) - 1)] = 1;
                    }
                }
                M[0][0 + (U + 1) * (strlen(oss[j]) - 1)] += 1;
            }
        } else {
            if (strncmp(oss[lb] + of, oss[j], strlen(oss[j])) == 0) {
                M[0][i + (U + 1) * (strlen(oss[j]) - 1)] += 2;
            } else if (strncmp(oss[lb] + of, oss[j], strlen(oss[j])) == 0) {
                M[i + strlen(oss[j])][i + (U + 1) * (strlen(oss[j]) - 1)] += 1;
            }

            char *suf = oss[lb] + of;
            for (int j = 0; j < n; j++) {
                if (strncmp(oss[j], suf, strlen(suf)) == 0 && strcmp(oss[j], suf) != 0) {
                    M[offset[j] + strlen(suf) - 1][i + (U + 1) * (strlen(suf) - 1)] += 1;
                }
            }
        }
    }

    for (int i = 0; i <= U; i++) {
        for (int j = 0; j < D - 1; j++) {
            M[i + (U + 1) * (j + 1)][i + (U + 1) * j] = 1;
        }
    }

    IntArray v;
    v.size = (U + 1) * D;
    v.data = calloc(v.size, sizeof(int));
    v.data[0] = 1;
    v = pow(M, v, m);

    printf("%d\n", v.data[0]);

    for (int i = 0; i < (U + 1) * D; i++) {
        free(M[i]);
    }
    free(M);
    free(oss);
    free(offset);
    free(v.data);
}

IntArray pow(int **A, IntArray v, long e) {
    for (int i = 0; i < v.size; i++) {
        if (v.data[i] >= MOD) v.data[i] %= MOD;
    }
    int **MUL = A;
    for (; e > 0; e >>= 1) {
        if ((e & 1) == 1) v = mul(MUL, v);
        MUL = p2(MUL, v.size);
    }
    return v;
}

IntArray mul(int **A, IntArray v) {
    int m = sizeof(A) / sizeof(A[0]);
    int n = v.size;
    IntArray w;
    w.size = m;
    w.data = calloc(m, sizeof(int));
    
    for (int i = 0; i < m; i++) {
        long sum = 0;
        for (int k = 0; k < n; k++) {
            sum += (long)A[i][k] * v.data[k];
            if (sum >= BIG) sum -= BIG;
        }
        w.data[i] = (int)(sum % MOD);
    }
    return w;
}

int **p2(int **A, int n) {
    int **C = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        C[i] = calloc(n, sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        long *sum = calloc(n, sizeof(long));
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                sum[j] += (long)A[i][k] * A[k][j];
                if (sum[j] >= BIG) sum[j] -= BIG;
            }
        }
        for (int j = 0; j < n; j++) {
            C[i][j] = (int)(sum[j] % MOD);
        }
        free(sum);
    }
    return C;
}

int lowerBound(int *a, int l, int r, int v) {
    if (l > r || l < 0 || r > sizeof(a) / sizeof(a[0])) {
        fprintf(stderr, "Invalid arguments for lowerBound\n");
        exit(EXIT_FAILURE);
    }
    int low = l - 1, high = r;
    while (high - low > 1) {
        int h = (high + low) >> 1;
        if (a[h] >= v) {
            high = h;
        } else {
            low = h;
        }
    }
    return high;
}

int ni() {
    int num;
    scanf("%d", &num);
    return num;
}

long nl() {
    long num;
    scanf("%ld", &num);
    return num;
}

char *ns() {
    char *buffer = malloc(1000 * sizeof(char));
    scanf("%s", buffer);
    return buffer;
}

void run() {
    solve();
}
