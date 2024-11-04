#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

typedef long long int int64;
typedef unsigned long long int uint64;

#define MAX_N 1000

int soln[2][MAX_N + 1];
int xsoln[2][MAX_N + 1];

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int c132() {
    char str[MAX_N];
    size_t n;
    scanf("%s %zu", str, &n);

    if (str[strlen(str) - 1] == 'F') {
        for (size_t j = 0; j < n + 1; ++j)
            soln[0][j] = j & 1 ? 0 : 1;
    } else {
        for (size_t j = 0; j < n + 1; ++j)
            soln[0][j] = j & 1 ? 1 : 0;
    }

    memcpy(soln[1], soln[0], sizeof(soln[0]));

    for (int iter = strlen(str) - 2; iter >= 0; --iter) {
        memcpy(xsoln, soln, sizeof(soln));
        if (str[iter] == 'F') {
            soln[0][0] = 1 + xsoln[0][0];
            soln[1][0] = 1 + xsoln[1][0];

            for (size_t j = 1; j < n + 1; ++j) {
                soln[0][j] = max(1 + xsoln[0][j], -xsoln[1][j - 1]);
                soln[1][j] = min(1 + xsoln[1][j], -xsoln[0][j - 1]);
            }
        } else {
            soln[0][0] = -xsoln[1][0];
            soln[1][0] = -xsoln[0][0];

            for (size_t j = 1; j < n + 1; ++j) {
                soln[0][j] = max(-xsoln[1][j], 1 + xsoln[0][j - 1]);
                soln[1][j] = min(-xsoln[0][j], 1 + xsoln[1][j - 1]);
            }
        }
    }

    return max(soln[0][n], -soln[1][n]);
}

size_t sched(size_t i, const size_t *m, const size_t rev[MAX_N][MAX_N], size_t *deps, size_t load[MAX_N][3]) {
    size_t val = 0;
    size_t unload[MAX_N];
    size_t n;

    for (n = 0; n < 3; i = (i + 1) % 3, ++val) {
        while (load[i][0] != 0) {
            n -= load[i][0];

            memcpy(unload, load[i], sizeof(load[i]));
            load[i][0] = 0;

            for (size_t j = 0; j < unload[0]; ++j) {
                for (size_t k = 0; k < rev[unload[j]][0]; ++k) {
                    --deps[rev[unload[j]][k]];
                    if (deps[rev[unload[j]][k]] == 0) {
                        load[m[rev[unload[j]][k]]][0] = rev[unload[j]][k];
                    }
                }
            }
        }
    }

    return val - 1;
}

size_t a213() {
    size_t m[MAX_N];
    size_t n;
    scanf("%zu", &n);

    for (size_t j = 0; j < n; ++j) {
        scanf("%zu", &m[j]);
        m[j]--;
    }

    size_t rev[MAX_N][MAX_N] = {0};
    size_t deps[MAX_N] = {0};
    for (size_t j = 0; j < n; ++j) {
        size_t xs[MAX_N];
        scanf("%zu", &xs[0]);
        deps[j] = xs[0];

        for (size_t k = 1; k <= xs[0]; ++k) {
            scanf("%zu", &xs[k]);
            rev[xs[k] - 1][0]++;
            rev[xs[k] - 1][rev[xs[k] - 1][0]] = j;
        }
    }

    size_t load[3][MAX_N] = {0};
    for (size_t j = 0; j < n; ++j) {
        if (deps[j] == 0) {
            load[m[j]][0] = j;
        }
    }

    return min(sched(0, m, rev, deps, load), min(sched(1, m, rev, deps, load), sched(2, m, rev, deps, load))) + n;
}

int main() {
    printf("%zu\n", a213());
    return EXIT_SUCCESS;
}
