#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

const int MOD = 998244353;

typedef struct {
    int x;
} mint;

mint new_mint(int x) {
    mint m;
    m.x = x;
    return m;
}

mint add(mint a, mint b) {
    return new_mint((a.x + b.x) % MOD);
}

mint sub(mint a, mint b) {
    return new_mint((a.x - b.x + MOD) % MOD);
}

mint mul(mint a, mint b) {
    return new_mint((ll)a.x * b.x % MOD);
}

mint pow(mint a, ll n) {
    mint res = new_mint(1);
    while (n > 0) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

mint inv(mint a) {
    return pow(a, MOD - 2);
}

mint div(mint a, mint b) {
    return mul(a, inv(b));
}

mint sqrt(mint a) {
    if (a.x <= 1) {
        return a;
    }
    int v = (MOD - 1) / 2;
    mint z;
    do {
        z = new_mint(rand() % MOD);
    } while (pow(z, v).x != MOD - 1);
    mint c = pow(z, (MOD - 1) / 2);
    mint t = pow(a, (MOD + 1) / 2);
    mint r = pow(a, MOD - 1);
    int m = 0;
    while (r.x != 1) {
        r = mul(r, r);
        m++;
    }
    for (int i = 0; i < m - 1; i++) {
        if (pow(t, 1 << (m - 2 - i)).x != 1) {
            r = mul(r, c);
            t = mul(t, mul(c, c));
        }
        c = mul(c, c);
    }
    return r;
}

typedef struct {
    int size;
    mint *coeff;
} FPS;

FPS new_FPS(int size) {
    FPS f;
    f.size = size;
    f.coeff = (mint *)malloc(size * sizeof(mint));
    return f;
}

void delete_FPS(FPS f) {
    free(f.coeff);
}

FPS add_FPS(FPS a, FPS b) {
    FPS res = new_FPS(a.size);
    for (int i = 0; i < a.size; i++) {
        res.coeff[i] = add(a.coeff[i], b.coeff[i]);
    }
    return res;
}

FPS sub_FPS(FPS a, FPS b) {
    FPS res = new_FPS(a.size);
    for (int i = 0; i < a.size; i++) {
        res.coeff[i] = sub(a.coeff[i], b.coeff[i]);
    }
    return res;
}

FPS mul_FPS(FPS a, FPS b) {
    FPS res = new_FPS(a.size + b.size - 1);
    for (int i = 0; i < a.size; i++) {
        for (int j = 0; j < b.size; j++) {
            res.coeff[i + j] = add(res.coeff[i + j], mul(a.coeff[i], b.coeff[j]));
        }
    }
    return res;
}

FPS pow_FPS(FPS a, ll n) {
    FPS res = new_FPS(a.size);
    res.coeff[0] = new_mint(1);
    while (n > 0) {
        if (n & 1) {
            res = mul_FPS(res, a);
        }
        a = mul_FPS(a, a);
        n >>= 1;
    }
    return res;
}

FPS inv_FPS(FPS a) {
    FPS res = new_FPS(a.size);
    res.coeff[0] = inv(a.coeff[0]);
    for (int i = 1; i < a.size; i <<= 1) {
        FPS f(2 * i);
        for (int j = 0; j < i; j++) {
            f.coeff[j] = a.coeff[j];
        }
        FPS g(2 * i);
        for (int j = 0; j < i; j++) {
            g.coeff[j] = res.coeff[j];
        }
        f.coeff = fft(f.coeff);
        g.coeff = fft(g.coeff);
        for (int j = 0; j < 2 * i; j++) {
            f.coeff[j] = mul(f.coeff[j], g.coeff[j]);
        }
        f.coeff = ifft(f.coeff);
        for (int j = 0; j < i; j++) {
            f.coeff[j] = new_mint(0);
            f.coeff[j + i] = sub(f.coeff[j + i], f.coeff[j + i]);
        }
        f.coeff = fft(f.coeff);
        for (int j = 0; j < 2 * i; j++) {
            f.coeff[j] = mul(f.coeff[j], g.coeff[j]);
        }
        f.coeff = ifft(f.coeff);
        for (int j = 0; j < i; j++) {
            f.coeff[j] = res.coeff[j];
        }
        res = f;
    }
    return res;
}

FPS sqrt_FPS(FPS a) {
    if (a.coeff[0].x == 0) {
        for (int i = 1; i < a.size; i++) {
            if (a.coeff[i].x != 0) {
                if (i & 1) {
                    return new_FPS(0);
                }
                FPS res = sqrt_FPS(new_FPS(a.size - i));
                if (res.size == 0) {
                    return res;
                }
                for (int j = 0; j < res.size; j++) {
                    res.coeff[j] = mul(res.coeff[j], pow(a.coeff[i], j));
                }
                res.coeff = mul_FPS(res.coeff, pow_FPS(new_FPS(a.size), i / 2));
                if (res.size < a.size) {
                    res.coeff = realloc(res.coeff, a.size * sizeof(mint));
                    for (int j = res.size; j < a.size; j++) {
                        res.coeff[j] = new_mint(0);
                    }
                }
                return res;
            }
        }
        return new_FPS(a.size);
    }
    mint sqr = sqrt(a.coeff[0]);
    if (mul(sqr, sqr).x != a.coeff[0].x) {
        return new_FPS(0);
    }
    FPS res = new_FPS(a.size);
    res.coeff[0] = sqr;
    mint inv2 = inv(new_mint(2));
    for (int i = 1; i < a.size; i <<= 1) {
        res = mul_FPS(add_FPS(res, mul_FPS(a.pre(i << 1), inv_FPS(res.pre(i << 1)))), inv2);
    }
    return res.pre(a.size);
}

mint eval_FPS(FPS f, mint x) {
    mint r = new_mint(0), w = new_mint(1);
    for (int i = 0; i < f.size; i++) {
        r = add(r, mul(w, f.coeff[i]));
        w = mul(w, x);
    }
    return r;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int *h = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    h[n] = h[0];

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (h[i] == h[i + 1]) {
            cnt++;
        }
    }
    int d = n - cnt;

    mint res = pow(new_mint(k), cnt), sum = new_mint(0);

    FPS f = new_FPS(2 * d + 1);
    f.coeff[0] = new_mint(1), f.coeff[1] = sub(new_mint(k), new_mint(2)), f.coeff[2] = new_mint(1);
    f = pow_FPS(f, d);
    for (int i = d + 1; i < 2 * d + 1; i++) {
        sum = add(sum, f.coeff[i]);
    }

    printf("%lld\n", mul(res, sum).x);

    free(h);
    delete_FPS(f);

    return 0;
}
