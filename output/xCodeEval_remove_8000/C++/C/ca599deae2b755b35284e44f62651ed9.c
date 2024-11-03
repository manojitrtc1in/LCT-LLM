#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

int c132() {
    char str[MAX_SIZE];
    int n;
    scanf("%s %d", str, &n);

    int soln[2][n+1];
    int id12[2][n+1];

    if (str[strlen(str)-1] == 'F') {
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
        memcpy(id12, soln, sizeof(soln));
        if (str[i] == 'F') {
            soln[0][0] = 1 + id12[0][0];
            soln[1][0] = 1 + id12[1][0];

            for (int j = 1; j < n + 1; j++) {
                soln[0][j] = (1 + id12[0][j]) > (-id12[1][j - 1]) ? (1 + id12[0][j]) : (-id12[1][j - 1]);
                soln[1][j] = (1 + id12[1][j]) < (-id12[0][j - 1]) ? (1 + id12[1][j]) : (-id12[0][j - 1]);
            }
        } else {
            soln[0][0] = -id12[1][0];
            soln[1][0] = -id12[0][0];

            for (int j = 1; j < n + 1; j++) {
                soln[0][j] = (-id12[1][j]) > (1 + id12[0][j - 1]) ? (-id12[1][j]) : (1 + id12[0][j - 1]);
                soln[1][j] = (-id12[0][j]) < (1 + id12[1][j - 1]) ? (-id12[0][j]) : (1 + id12[1][j - 1]);
            }
        }
    }

    return soln[0][n] > -soln[1][n] ? soln[0][n] : -soln[1][n];
}

size_t sched(size_t i,
        const size_t *m,
        const size_t *const *rev,
        size_t *deps,
        size_t **load) {
    size_t val = 0;
    size_t *unload = malloc(sizeof(size_t) * MAX_SIZE);

    for (size_t n = m[i], j = 0; n > 0; i = (i + 1) % 3, ++val) {
        while (load[i][0] != -1) {
            --n;

            size_t *p = load[i];
            size_t *q = unload;
            while (*p != -1) {
                *q++ = *p++;
            }
            *q = -1;

            for (size_t *p = unload; *p != -1; ++p) {
                for (const size_t *q = rev[*p]; *q != -1; ++q) {
                    --deps[*q];
                    if (deps[*q] == 0) {
                        load[m[*q]][0] = *q;
                        ++load[m[*q]];
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
    for (size_t i = 0; i < n; ++i) {
        size_t x;
        scanf("%zu", &x);
        deps[i] = x;

        for (size_t j = 0; j < x; ++j) {
            size_t y;
            scanf("%zu", &y);
            rev[y - 1][i] = 1;
        }
    }

    size_t *load[3];
    for (size_t i = 0; i < 3; ++i) {
        load[i] = malloc(sizeof(size_t) * (n + 1));
        load[i][0] = -1;
    }

    for (size_t i = 0; i < n; ++i) {
        if (deps[i] == 0) {
            load[m[i]][0] = i;
            ++load[m[i]];
        }
    }

    size_t result = sched(0, m, rev, deps, load);
    result = result < sched(1, m, rev, deps, load) ? result : sched(1, m, rev, deps, load);
    result = result < sched(2, m, rev, deps, load) ? result : sched(2, m, rev, deps, load);

    for (size_t i = 0; i < 3; ++i) {
        free(load[i]);
    }

    return result + n;
}

int main() {
    printf("%zu\n", a213());
    return 0;
}
