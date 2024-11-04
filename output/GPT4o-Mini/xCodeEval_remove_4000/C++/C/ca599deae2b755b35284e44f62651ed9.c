#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

typedef long long int int64;
typedef unsigned long long int uint64;

#define MAX_SIZE 1000

size_t mini(size_t n, ...) {
    va_list vl;
    va_start(vl, n);
    size_t res = va_arg(vl, size_t);
    for (size_t i = 1; i < n; ++i) {
        size_t val = va_arg(vl, size_t);
        res = val < res ? val : res;
    }
    va_end(vl);
    return res;
}

size_t sched(size_t i, const size_t *m, const size_t rev[MAX_SIZE][MAX_SIZE], size_t *deps, size_t load[MAX_SIZE][3]) {
    size_t val = 0;
    size_t unload[MAX_SIZE];
    
    for (size_t n = 0; n < MAX_SIZE; n++) {
        if (n > 0) {
            i = (i + 1) % 3;
            ++val;
        }
        while (load[i][0] > 0) {
            n -= load[i][0];
            memcpy(unload, load[i], sizeof(size_t) * load[i][0]);
            load[i][0] = 0;

            for (size_t j = 0; j < load[i][0]; ++j) {
                for (size_t k = 0; k < deps[j]; ++k) {
                    --deps[k];
                    if (deps[k] == 0) {
                        load[m[k]][load[m[k]][0]++] = k;
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
    for (size_t j = 0; j < n; ++j) {
        scanf("%zu", &m[j]);
        m[j]--;
    }

    size_t rev[MAX_SIZE][MAX_SIZE] = {0};
    size_t deps[MAX_SIZE] = {0};
    for (size_t j = 0; j < n; ++j) {
        size_t xs[MAX_SIZE];
        scanf("%zu", &deps[j]);
        for (size_t k = 0; k < deps[j]; ++k) {
            scanf("%zu", &xs[k]);
            rev[xs[k] - 1][j] = 1;
        }
    }

    size_t load[3][MAX_SIZE] = {0};
    for (size_t j = 0; j < n; ++j) {
        if (deps[j] == 0) {
            load[m[j]][load[m[j]][0]++] = j;
        }
    }

    return mini(3, sched(0, m, rev, deps, load), sched(1, m, rev, deps, load), sched(2, m, rev, deps, load)) + n;
}

int main() {
    printf("%zu\n", a213());
    return EXIT_SUCCESS;
}
