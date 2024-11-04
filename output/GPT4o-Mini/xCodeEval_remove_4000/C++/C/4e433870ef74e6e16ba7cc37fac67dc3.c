#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define EOL '\n'

typedef int32_t i32;
typedef int64_t i64;

void sort_desc(i64 *arr, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                i64 temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

i64 ceil_div(i64 x, i64 y) {
    return (x + y - 1) / y;
}

int main() {
    i64 n, k;
    scanf("%lld %lld", &n, &k);
    
    i64 *c = malloc(n * sizeof(i64));
    i64 *pf = malloc(n * sizeof(i64));
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

    sort_desc(pf, pf_size);
    i64 ini = 0;
    i64 base = 0;
    for (size_t i = 0; i < pf_size; ++i) {
        base += ini;
        ini += pf[i];
    }

    sort_desc(c, c_size);

    if (k == 0) {
        for (size_t i = 0; i < c_size; ++i) {
            base += ini;
            ini -= c[i];
        }
        printf("%lld%c", base, EOL);
        free(c);
        free(pf);
        return 0;
    }

    i64 *cs = calloc(c_size + 1, sizeof(i64));
    for (size_t i = 0; i < c_size; ++i) {
        cs[i + 1] = cs[i] + (i / (k + 1)) * c[i];
    }

    i64 *sf = calloc(c_size + 1, sizeof(i64));
    i64 *sf2 = calloc(c_size + 1, sizeof(i64));
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
    printf("%lld%c", ans, EOL);

    free(c);
    free(pf);
    free(cs);
    free(sf);
    free(sf2);

    return 0;
}
