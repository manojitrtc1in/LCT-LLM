#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

int c132() {
    char str[MAX_SIZE];
    int n;
    scanf("%s %d", str, &n);

    int soln[2][n + 1];
    int xsoln[2][n + 1];

    if (str[strlen(str) - 1] == 'F') {
        for (int j = 0; j < n + 1; j++) {
            soln[0][j] = j & 1 ? 0 : 1;
        }
    } else {
        for (int j = 0; j < n + 1; j++) {
            soln[0][j] = j & 1 ? 1 : 0;
        }
    }

    memcpy(soln[1], soln[0], sizeof(soln[0]));

    for (int i = strlen(str) - 2; i >= 0; i--) {
        memcpy(xsoln, soln, sizeof(soln));
        if (str[i] == 'F') {
            soln[0][0] = 1 + xsoln[0][0];
            soln[1][0] = 1 + xsoln[1][0];

            for (int j = 1; j < n + 1; j++) {
                soln[0][j] = (1 + xsoln[0][j]) > (-xsoln[1][j - 1]) ? (1 + xsoln[0][j]) : (-xsoln[1][j - 1]);
                soln[1][j] = (1 + xsoln[1][j]) < (-xsoln[0][j - 1]) ? (1 + xsoln[1][j]) : (-xsoln[0][j - 1]);
            }
        } else {
            soln[0][0] = -xsoln[1][0];
            soln[1][0] = -xsoln[0][0];

            for (int j = 1; j < n + 1; j++) {
                soln[0][j] = (-xsoln[1][j]) > (1 + xsoln[0][j - 1]) ? (-xsoln[1][j]) : (1 + xsoln[0][j - 1]);
                soln[1][j] = (-xsoln[0][j]) < (1 + xsoln[1][j - 1]) ? (-xsoln[0][j]) : (1 + xsoln[1][j - 1]);
            }
        }
    }

    return soln[0][n] > -soln[1][n] ? soln[0][n] : -soln[1][n];
}

size_t sched(size_t i, const size_t *m, const size_t *const *rev, size_t *deps, size_t **load) {
    size_t val = 0;
    size_t *unload = malloc(sizeof(size_t) * MAX_SIZE);

    for (size_t n = m[0], j = 0; n > 0; i = (i + 1) % 3, ++val) {
        while (load[i][0] != 0) {
            n -= load[i][0];

            memcpy(unload, load[i], sizeof(size_t) * MAX_SIZE);
            memset(load[i], 0, sizeof(size_t) * MAX_SIZE);

            for (size_t k = 0; k < MAX_SIZE; ++k) {
                const size_t j = unload[k];
                if (j == 0) {
                    break;
                }
                for (size_t l = 0; l < MAX_SIZE; ++l) {
                    const size_t k = rev[j][l];
                    if (k == 0) {
                        break;
                    }
                    --deps[k];
                    if (deps[k] == 0) {
                        load[m[k]][0]++;
                        load[m[k]][load[m[k]][0]] = k;
                    }
                }
            }
        }
    }

    free(unload);
    return val - 1;
}

size_t a213() {
    size_t m[MAX_SIZE];
    size_t n;
    scanf("%zu", &n);
    for (size_t i = 0; i < n; ++i) {
        scanf("%zu", &m[i]);
    }

    for (size_t i = 0; i < n; ++i) {
        --m[i];
    }

    size_t rev[MAX_SIZE][MAX_SIZE];
    size_t deps[MAX_SIZE];
    memset(rev, 0, sizeof(rev));
    memset(deps, 0, sizeof(deps));

    for (size_t i = 0; i < n; ++i) {
        size_t k;
        scanf("%zu", &k);
        for (size_t j = 0; j < k; ++j) {
            size_t x;
            scanf("%zu", &x);
            rev[x - 1][deps[x - 1]++] = i;
        }
    }

    size_t load[3][MAX_SIZE];
    memset(load, 0, sizeof(load));
    for (size_t i = 0; i < n; ++i) {
        if (deps[i] == 0) {
            load[m[i]][0]++;
            load[m[i]][load[m[i]][0]] = i;
        }
    }

    return sched(0, m, rev, deps, load) < sched(1, m, rev, deps, load)
               ? sched(0, m, rev, deps, load)
               : sched(1, m, rev, deps, load);
}

int main() {
    printf("%zu\n", a213());
    return 0;
}
