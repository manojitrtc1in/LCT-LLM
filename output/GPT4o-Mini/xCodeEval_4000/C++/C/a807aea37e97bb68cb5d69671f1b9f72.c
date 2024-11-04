#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MX 5000
#define MAX_PRIMES 1000

typedef struct {
    int *data;
    size_t size;
} Vector;

typedef struct {
    int *data;
    size_t size;
} Pair;

typedef struct {
    int *data;
    size_t size;
} IntVector;

typedef struct {
    bool *data;
    size_t size;
} Sieve;

void init_vector(Vector *v, size_t size) {
    v->data = (int *)malloc(size * sizeof(int));
    v->size = size;
}

void free_vector(Vector *v) {
    free(v->data);
}

void init_int_vector(IntVector *v, size_t size) {
    v->data = (int *)malloc(size * sizeof(int));
    v->size = size;
}

void free_int_vector(IntVector *v) {
    free(v->data);
}

void init_sieve(Sieve *s, size_t n) {
    s->data = (bool *)malloc((n + 1) * sizeof(bool));
    s->size = n + 1;
    for (size_t i = 0; i <= n; i++) {
        s->data[i] = true;
    }
    s->data[0] = false;
    if (n != 0) s->data[1] = false;
    for (size_t i = 2; i * i <= n; i++) {
        if (s->data[i]) {
            for (size_t j = i * i; j <= n; j += i) {
                s->data[j] = false;
            }
        }
    }
}

void free_sieve(Sieve *s) {
    free(s->data);
}

void get_primes(Sieve *s, IntVector *primes) {
    init_int_vector(primes, 0);
    for (int i = 2; i <= s->size; i++) {
        if (s->data[i]) {
            primes->data[primes->size++] = i;
        }
    }
}

void solve(int N, int *K) {
    int C[MX + 1] = {0};
    for (int i = 0; i < N; i++) {
        C[K[i]]++;
    }

    Sieve sieve;
    init_sieve(&sieve, MX);
    IntVector primes;
    get_primes(&sieve, &primes);

    int M = primes.size;
    Vector D[MX + 1];
    for (int i = 0; i <= MX; i++) {
        init_vector(&D[i], M);
        for (int j = 0; j < M; j++) {
            D[i].data[j] = 0;
        }
    }

    for (int i = 0; i < M; i++) {
        int p = primes.data[i];
        for (int j = p; j <= MX; j *= p) {
            for (int k = 0; k <= MX; k++) {
                D[k].data[i] += k / j;
            }
        }
    }

    for (int i = 0; i <= MX; i++) {
        for (int j = 0; j < M / 2; j++) {
            int temp = D[i].data[j];
            D[i].data[j] = D[i].data[M - 1 - j];
            D[i].data[M - 1 - j] = temp;
        }
    }

    Vector Pref[MX + 1];
    for (int i = 0; i <= MX; i++) {
        init_vector(&Pref[i], M + 1);
        Pref[i].data[0] = 0;
        for (int j = 0; j < M; j++) {
            Pref[i].data[j + 1] = Pref[i].data[j] + D[i].data[j];
        }
    }

    int CountPref[MX + 2] = {0};
    long long tot = 0;
    for (int i = 0; i <= MX; i++) {
        CountPref[i + 1] = CountPref[i] + C[i];
        tot += C[i] * Pref[i].data[M];
    }

    int use = K[N / 2];
    Pair W[MX + 1];
    int W_size = 0;
    long long base = 0;

    for (int i = 0; i <= MX; i++) {
        if (C[i] == 0) continue;

        int x = 0;
        long long len = 0;
        while (x < M && D[i].data[x] == D[use].data[x]) {
            len += D[i].data[x];
            x++;
        }
        if (x < M) {
            len += (D[i].data[x] < D[use].data[x]) ? D[i].data[x] : D[use].data[x];
        }
        W[W_size++] = (Pair){len, C[i]};
        base += (Pref[i].data[M] - len) * C[i];
    }

    long long ans = 1e18;
    for (int i = 0; i < W_size; i++) {
        long long cur = 0;
        for (int j = 0; j < W_size; j++) {
            cur += abs(W[j].data - W[i].data) * W[j].size;
        }
        ans = (ans < base + cur) ? ans : (base + cur);
    }
    printf("%lld\n", ans);

    for (int i = 0; i <= MX; i++) {
        free_vector(&D[i]);
        free_vector(&Pref[i]);
    }
    free_sieve(&sieve);
    free_int_vector(&primes);
}

int main() {
    int N;
    scanf("%d", &N);
    int *K = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &K[i]);
    }
    qsort(K, N, sizeof(int), (int (*)(const void *, const void *))strcmp);
    solve(N, K);
    free(K);
    return 0;
}
