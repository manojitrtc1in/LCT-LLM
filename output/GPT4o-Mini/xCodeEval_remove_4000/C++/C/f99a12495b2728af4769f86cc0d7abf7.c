#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAXN 200000
#define MOD 998244353

typedef long long ll;
typedef struct {
    int *data;
    int size;
} V;

typedef struct {
    V *data;
    int size;
} VV;

V create_vector(int size) {
    V vec;
    vec.data = (int *)malloc(size * sizeof(int));
    vec.size = size;
    return vec;
}

void free_vector(V *vec) {
    free(vec->data);
}

void input_vector(V *vec) {
    for (int i = 0; i < vec->size; i++) {
        scanf("%d", &vec->data[i]);
    }
}

ll pow_mod(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

typedef struct {
    int x;
} ModInt;

ModInt create_modint(int value) {
    ModInt mi;
    mi.x = (value % MOD + MOD) % MOD;
    return mi;
}

ModInt modint_add(ModInt a, ModInt b) {
    return create_modint(a.x + b.x);
}

ModInt modint_mul(ModInt a, ModInt b) {
    return create_modint((1LL * a.x * b.x) % MOD);
}

ModInt modint_pow(ModInt a, ll exp) {
    return create_modint(pow_mod(a.x, exp, MOD));
}

typedef struct {
    ModInt *data;
    int size;
} FPS;

FPS create_fps(int size) {
    FPS fps;
    fps.data = (ModInt *)malloc(size * sizeof(ModInt));
    fps.size = size;
    return fps;
}

void free_fps(FPS *fps) {
    free(fps->data);
}

FPS fps_pow(FPS f, int exp) {
    FPS result = create_fps(f.size);
    result.data[0] = create_modint(1);
    for (int i = 1; i < f.size; i++) {
        result.data[i] = create_modint(0);
    }
    for (int i = 0; i < exp; i++) {
        FPS temp = create_fps(result.size);
        for (int j = 0; j < result.size; j++) {
            for (int k = 0; k < f.size; k++) {
                if (j + k < temp.size) {
                    temp.data[j + k] = modint_add(temp.data[j + k], modint_mul(result.data[j], f.data[k]));
                }
            }
        }
        free_fps(&result);
        result = temp;
    }
    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    V h = create_vector(n + 1);
    input_vector(&h);
    h.data[n] = h.data[0];

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (h.data[i] == h.data[i + 1]) cnt++;
    }
    int d = n - cnt;

    ModInt res = modint_pow(create_modint(k), cnt);
    ModInt sum = create_modint(0);

    FPS f = create_fps(2 * d + 1);
    f.data[0] = create_modint(1);
    f.data[1] = create_modint(k - 2);
    f.data[2] = create_modint(1);
    
    FPS f_pow = fps_pow(f, d);
    
    for (int i = d + 1; i <= 2 * d; i++) {
        sum = modint_add(sum, f_pow.data[i]);
    }

    printf("%d\n", (res.x * sum.x) % MOD);

    free_vector(&h);
    free_fps(&f);
    free_fps(&f_pow);
    return 0;
}
