#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define eol '\n'

typedef int64_t i64;

void main();
unsigned case_number();

unsigned caseid;

void iterate_main() {
    for (unsigned total = case_number(), counter = 1; counter <= total; ++counter) {
        caseid = counter;
        main();
    }
}

unsigned case_number() {
    return 1;
}

void main() {
    i64 n, k;
    scanf("%lld %lld", &n, &k);
    
    i64 *c = (i64 *)malloc(n * sizeof(i64));
    i64 *pf = (i64 *)malloc(n * sizeof(i64));
    size_t c_size = 0, pf_size = 0;

    for (i64 i = 0; i < n; ++i) {
        i64 v;
        scanf("%lld", &v);
        if (v < 0) {
            c[c_size++] = -v;
        } else {
            pf[pf_size++] = v;
        }
    }

    // Sort pf in descending order
    qsort(pf, pf_size, sizeof(i64), (int (*)(const void *, const void *))compare_desc);
    
    i64 ini = 0;
    i64 base = 0;
    for (size_t i = 0; i < pf_size; ++i) {
        base += ini;
        ini += pf[i];
    }

    // Sort c in descending order
    qsort(c, c_size, sizeof(i64), (int (*)(const void *, const void *))compare_desc);

    if (k == 0) {
        for (size_t i = c_size; i > 0; --i) {
            base += ini;
            ini -= c[i - 1];
        }
        printf("%lld%c", base, eol);
        free(c);
        free(pf);
        return;
    }

    i64 *cs = (i64 *)calloc(c_size + 1, sizeof(i64));
    for (size_t i = 0; i < c_size; ++i) {
        cs[i + 1] = cs[i] + (i / (k + 1)) * c[i];
    }

    i64 *sf = (i64 *)calloc(c_size + 1, sizeof(i64));
    i64 *sf2 = (i64 *)calloc(c_size + 1, sizeof(i64));
    for (size_t i = c_size; i-- > 0;) {
        sf[i] = sf[i + 1] + c[i];
        sf2[i] = sf2[i + 1] + c[i] * i;
    }

    i64 ans = -1e18;
    for (size_t j = 0; j <= c_size; ++j) {
        if (j * (k + 1) < c_size) continue;
        i64 cd = ceil_div(c_size - j, k);
        i64 tp = j - cd;
        i64 now = ini * j;
        now -= sf2[c_size - tp] + sf[tp] * (cd - (c_size - tp));
        now -= cs[c_size - tp];
        if (now > ans) ans = now;
    }

    ans += base;
    printf("%lld%c", ans, eol);

    free(c);
    free(pf);
    free(cs);
    free(sf);
    free(sf2);
}

int compare_desc(const void *a, const void *b) {
    return (*(i64 *)b - *(i64 *)a);
}

i64 ceil_div(i64 x, i64 y) {
    return (x + y - 1) / y;
}
