#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MX 5000

typedef struct {
    int *data;
    size_t size;
} vector_int;

typedef struct {
    long long *data;
    size_t size;
} vector_ll;

typedef struct {
    int **data;
    size_t rows;
    size_t cols;
} vector2_int;

typedef struct {
    long long **data;
    size_t rows;
    size_t cols;
} vector2_ll;

void vector_int_init(vector_int *v, size_t size) {
    v->data = (int *)malloc(size * sizeof(int));
    v->size = size;
}

void vector_ll_init(vector_ll *v, size_t size) {
    v->data = (long long *)malloc(size * sizeof(long long));
    v->size = size;
}

void vector2_int_init(vector2_int *v, size_t rows, size_t cols) {
    v->data = (int **)malloc(rows * sizeof(int *));
    for (size_t i = 0; i < rows; i++) {
        v->data[i] = (int *)calloc(cols, sizeof(int));
    }
    v->rows = rows;
    v->cols = cols;
}

void vector2_ll_init(vector2_ll *v, size_t rows, size_t cols) {
    v->data = (long long **)malloc(rows * sizeof(long long *));
    for (size_t i = 0; i < rows; i++) {
        v->data[i] = (long long *)calloc(cols, sizeof(long long));
    }
    v->rows = rows;
    v->cols = cols;
}

void vector_int_free(vector_int *v) {
    free(v->data);
}

void vector2_int_free(vector2_int *v) {
    for (size_t i = 0; i < v->rows; i++) {
        free(v->data[i]);
    }
    free(v->data);
}

void vector2_ll_free(vector2_ll *v) {
    for (size_t i = 0; i < v->rows; i++) {
        free(v->data[i]);
    }
    free(v->data);
}

void sieve(int n, bool *is_prime, vector_int *primes) {
    for (int i = 0; i <= n; i++) {
        is_prime[i] = true;
    }
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    primes->size = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes->data[primes->size++] = i;
        }
    }
}

void solve() {
    int N;
    scanf("%d", &N);
    
    vector_int K;
    vector_int_init(&K, N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &K.data[i]);
    }
    
    qsort(K.data, N, sizeof(int), (__compar_fn_t)compare);
    
    int C[MX + 1] = {0};
    for (int i = 0; i < N; i++) {
        C[K.data[i]]++;
    }

    bool is_prime[MX + 1];
    vector_int primes;
    vector_int_init(&primes, MX);
    sieve(MX, is_prime, &primes);

    vector2_int D;
    vector2_int_init(&D, MX + 1, primes.size);
    
    for (size_t i = 0; i < primes.size; i++) {
        int p = primes.data[i];
        for (int j = p; j <= MX; j *= p) {
            for (int k = 0; k <= MX; k++) {
                D.data[k][i] += k / j;
            }
        }
    }
    
    for (int i = 0; i <= MX; i++) {
        for (size_t j = 0; j < primes.size / 2; j++) {
            int temp = D.data[i][j];
            D.data[i][j] = D.data[i][primes.size - j - 1];
            D.data[i][primes.size - j - 1] = temp;
        }
    }

    vector2_ll Pref;
    vector2_ll_init(&Pref, MX + 1, primes.size + 1);
    
    for (int i = 0; i <= MX; i++) {
        for (size_t j = 0; j < primes.size; j++) {
            Pref.data[i][j + 1] = Pref.data[i][j] + D.data[i][j];
        }
    }

    int CountPref[MX + 2] = {0};
    long long tot = 0;
    for (int i = 0; i <= MX; i++) {
        CountPref[i + 1] = CountPref[i] + C[i];
        tot += C[i] * Pref.data[i][primes.size];
    }

    int use = K.data[N / 2];
    vector_ll W;
    vector_ll_init(&W, MX + 1);
    long long base = 0;

    for (int i = 0; i <= MX; i++) {
        if (C[i] == 0) continue;

        int x = 0;
        long long len = 0;
        while (x < primes.size && D.data[i][x] == D.data[use][x]) {
            len += D.data[i][x];
            x++;
        }
        if (x < primes.size) {
            len += (D.data[i][x] < D.data[use][x]) ? D.data[i][x] : D.data[use][x];
        }
        W.data[i] = len;
        base += (Pref.data[i][primes.size] - len) * C[i];
    }

    long long ans = 1e18;
    for (int i = 0; i <= MX; i++) {
        long long cur = 0;
        for (int j = 0; j <= MX; j++) {
            cur += abs(W.data[j] - W.data[i]) * C[j];
        }
        ans = (ans < base + cur) ? ans : (base + cur);
    }
    
    printf("%lld\n", ans);

    vector_int_free(&K);
    vector_int_free(&primes);
    vector2_int_free(&D);
    vector2_ll_free(&Pref);
    vector_ll_free(&W);
}

int main() {
    solve();
    return 0;
}
