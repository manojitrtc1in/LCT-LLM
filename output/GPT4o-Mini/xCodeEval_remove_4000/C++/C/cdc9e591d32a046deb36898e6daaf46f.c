#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <ctype.h>

typedef long long int int64;
typedef unsigned long long int uint64;

#define MAX_N 1000
#define MAX_M 1000

int64 gcd(int64 a, int64 b) {
    return b == 0 ? a : gcd(b, a % b);
}

void b303() {
    int64 n, m, x, y, a, b;
    scanf("%lld %lld %lld %lld %lld %lld", &n, &m, &x, &y, &a, &b);

    int64 g = gcd(a, b);
    a /= g;
    b /= g;

    int64 k = fmin(m / b, n / a);
    int64 width = k * a;
    int64 height = k * b;

    int64 x1 = fmax(x - (width + 1) / 2, 0LL);
    int64 x2 = fmin(x1 + width, n);
    x1 = x2 - width;

    int64 y1 = fmax(y - (height + 1) / 2, 0LL);
    int64 y2 = fmin(y1 + height, m);
    y1 = y2 - height;

    printf("%lld %lld %lld %lld\n", x1, y1, x2, y2);
}

bool xsolve(size_t w, size_t j, size_t t, size_t jump_size, char wall[2][MAX_N], bool cache[MAX_N][MAX_N][MAX_N]) {
    size_t n = strlen(wall[0]);
    if (!(j < n)) return true;
    else if (j < t || wall[w][j] != '-') return false;
    else {
        if (cache[w][j][t]) return false;

        cache[w][j][t] = true;

        if (xsolve(1 - w, j + jump_size, t + 1, jump_size, wall, cache) ||
            xsolve(w, j + 1, t + 1, jump_size, wall, cache) ||
            (j > 0 && xsolve(w, j - 1, t + 1, jump_size, wall, cache))) {
            return true;
        }

        return false;
    }
}

const char* b198() {
    size_t n, k;
    scanf("%zu %zu", &n, &k);
    char wall[2][MAX_N];
    scanf("%s %s", wall[0], wall[1]);

    bool cache[MAX_N][MAX_N][MAX_N] = { false };

    const size_t INF = SIZE_MAX;

    cache[0][0][INF] = true;
    cache[1][n][INF] = true;

    bool flag = xsolve(1, k, 1, k, wall, cache) || xsolve(0, 1, 1, k, wall, cache);

    return flag ? "YES" : "NO";
}

size_t a442() {
    char xs[MAX_N][3];
    size_t count = 0;
    while (scanf("%s", xs[count]) != EOF) count++;

    char char_map[256][256] = { 0 }, digit_map[256][256] = { 0 };

    for (size_t i = 0; i < count; i++) {
        char_map[xs[i][0]][xs[i][1]] = 1;
        digit_map[xs[i][1]][xs[i][0]] = 1;
    }

    size_t id17 = 0;
    for (size_t i = 0; i < 256; i++) {
        bool valid = true;
        for (size_t j = 0; j < 256; j++) {
            if (char_map[i][j] && digit_map[j][i] != 1) {
                valid = false;
                break;
            }
        }
        if (valid) id17++;
    }

    size_t id19 = 0;
    for (size_t i = 0; i < 256; i++) {
        bool valid = true;
        for (size_t j = 0; j < 256; j++) {
            if (digit_map[i][j] && char_map[j][i] != 1) {
                valid = false;
                break;
            }
        }
        if (valid) id19++;
    }

    return fmin(digit_map[0][0] - 1 + (id17 < count ? count - id17 - 1 : 0),
                count - 1 + (id19 < count ? count - id19 - 1 : 0));
}

uint64 a163() {
    char subj[MAX_N], targ[MAX_N];
    scanf("%s %s", subj, targ);

    uint64 pos[256][MAX_N] = { 0 };
    for (size_t j = 0; j < strlen(targ); j++)
        pos[targ[j]][j] = 1;

    uint64 val = 0;
    uint64 soln[MAX_N + 1] = { 0 }, id12[MAX_N + 1] = { 0 };
    const uint64 m = 1000000007ULL;

    for (size_t i = 0; i < strlen(subj); i++) {
        memcpy(id12, soln, sizeof(soln));
        memset(soln, 0, sizeof(soln));

        for (size_t j = 0; j < strlen(targ); j++) {
            if (pos[subj[i]][j]) {
                soln[j + 1] = (1 + id12[j]) % m;
            }
        }

        for (size_t j = 1; j <= strlen(targ); j++) {
            soln[j] = (soln[j] + soln[j - 1]) % m;
        }
        val = (val + soln[strlen(targ)]) % m;
    }
    return val;
}

int main() {
    printf("%llu\n", a163());
    return EXIT_SUCCESS;
}
