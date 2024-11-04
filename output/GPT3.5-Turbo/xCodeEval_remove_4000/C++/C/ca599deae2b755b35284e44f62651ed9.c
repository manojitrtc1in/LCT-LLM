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
        for (int j = 0; j < n + 1; ++j) {
            soln[0][j] = j & 1 ? 0 : 1;
        }
    } else {
        for (int j = 0; j < n + 1; ++j) {
            soln[0][j] = j & 1 ? 1 : 0;
        }
    }

    memcpy(soln[1], soln[0], sizeof(soln[0]));

    for (int i = strlen(str) - 2; i >= 0; --i) {
        memcpy(id12, soln, sizeof(soln));
        if (str[i] == 'F') {
            soln[0][0] = 1 + id12[0][0];
            soln[1][0] = 1 + id12[1][0];

            for (int j = 1; j < n + 1; ++j) {
                soln[0][j] = (1 + id12[0][j]) > (-id12[1][j - 1]) ? (1 + id12[0][j]) : (-id12[1][j - 1]);
                soln[1][j] = (1 + id12[1][j]) < (-id12[0][j - 1]) ? (1 + id12[1][j]) : (-id12[0][j - 1]);
            }
        } else {
            soln[0][0] = -id12[1][0];
            soln[1][0] = -id12[0][0];

            for (int j = 1; j < n + 1; ++j) {
                soln[0][j] = (-id12[1][j]) > (1 + id12[0][j - 1]) ? (-id12[1][j]) : (1 + id12[0][j - 1]);
                soln[1][j] = (-id12[0][j]) < (1 + id12[1][j - 1]) ? (-id12[0][j]) : (1 + id12[1][j - 1]);
            }
        }
    }

    return soln[0][n] > -soln[1][n] ? soln[0][n] : -soln[1][n];
}

size_t sched(size_t i,
        const size_t m[],
        const size_t rev[][MAX_SIZE],
        size_t deps[],
        size_t load[][MAX_SIZE]) {
    size_t val = 0;
    size_t unload[MAX_SIZE];

    size_t n = sizeof(m) / sizeof(m[0]);
    for (; n > 0; i = (i + 1) % 3, ++val) {
        while (load[i][0] != 0) {
            n -= sizeof(load[i]) / sizeof(load[i][0]);

            memcpy(unload, load[i], sizeof(load[i]));

            for (size_t j = 0; j < sizeof(unload) / sizeof(unload[0]); ++j) {
                for (size_t k = 0; k < sizeof(rev[unload[j]]) / sizeof(rev[unload[j]][0]); ++k) {
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
    size_t m[MAX_SIZE];
    size_t n;
    scanf("%zu", &n);

    for (size_t i = 0; i < n; ++i) {
        scanf("%zu", &m[i]);
    }

    size_t rev[MAX_SIZE][MAX_SIZE];
    size_t deps[MAX_SIZE];
    for (size_t j = 0; j < n; ++j) {
        size_t xs[MAX_SIZE];
        size_t xs_size;
        scanf("%zu", &xs_size);

        deps[j] = xs_size;

        for (size_t i = 0; i < xs_size; ++i) {
            scanf("%zu", &xs[i]);
            rev[xs[i] - 1][j] = 1;
        }
    }

    size_t load[3][MAX_SIZE];
    for (size_t j = 0; j < n; ++j) {
        if (deps[j] == 0) {
            load[m[j]][0] = j;
        }
    }

    return sched(0, m, rev, deps, load) + n;
}

int main() {
    printf("%zu\n", a213());

    return EXIT_SUCCESS;
}
