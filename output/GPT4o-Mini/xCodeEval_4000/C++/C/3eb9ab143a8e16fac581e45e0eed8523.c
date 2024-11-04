#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int v;
} mint;

static int mod;

void set_mod(int m) {
    mod = m;
}

mint raw(int value) {
    mint x;
    x.v = value % mod;
    if (x.v < 0) x.v += mod;
    return x;
}

unsigned int val(mint x) {
    return x.v;
}

mint add(mint a, mint b) {
    mint result;
    result.v = (a.v + b.v) % mod;
    return result;
}

mint subtract(mint a, mint b) {
    mint result;
    result.v = (a.v + mod - b.v) % mod;
    return result;
}

mint multiply(mint a, mint b) {
    mint result;
    result.v = (unsigned long long)a.v * b.v % mod;
    return result;
}

mint power(mint base, long long exp) {
    mint result = raw(1);
    while (exp) {
        if (exp & 1) result = multiply(result, base);
        base = multiply(base, base);
        exp >>= 1;
    }
    return result;
}

void solve(int n, int m) {
    set_mod(m);
    mint* ways = (mint*)malloc((n + 1) * sizeof(mint));
    mint* extras = (mint*)malloc((n + 1) * sizeof(mint));
    for (int i = 0; i <= n; ++i) {
        ways[i] = raw(0);
        extras[i] = raw(0);
    }
    ways[1] = raw(1);
    mint sum = raw(0);
    mint extra = raw(0);
    
    for (int i = 1; i <= n; ++i) {
        ways[i] = add(ways[i], sum);
        extra = add(extra, extras[i]);
        ways[i] = add(ways[i], extra);
        
        for (int j = 2; i * j <= n; ++j) {
            extras[i * j] = add(extras[i * j], ways[i]);
            if ((i + 1) * j <= n)
                extras[(i + 1) * j] = subtract(extras[(i + 1) * j], ways[i]);
        }
        sum = add(sum, ways[i]);
    }
    
    printf("%u\n", val(ways[n]));
    
    free(ways);
    free(extras);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    solve(n, m);
    return 0;
}
