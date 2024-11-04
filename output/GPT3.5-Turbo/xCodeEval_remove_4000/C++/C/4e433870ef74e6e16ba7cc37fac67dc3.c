#include <stdio.h>
#include <stdlib.h>

typedef long long int i64;

i64 max(i64 a, i64 b) {
    return (a > b) ? a : b;
}

i64 min(i64 a, i64 b) {
    return (a < b) ? a : b;
}

i64 ceil_div(i64 x, i64 y) {
    if (y < 0) {
        x = -x;
        y = -y;
    }
    return (x < 0) ? (x - y + 1) / y : x / y;
}

void main() {
    i64 n, k;
    scanf("%lld %lld", &n, &k);
    i64* c = (i64*)malloc(n * sizeof(i64));
    i64* pf = (i64*)malloc(n * sizeof(i64));
    i64 c_size = 0, pf_size = 0;
    for (i64 i = 0; i < n; ++i) {
        i64 v;
        scanf("%lld", &v);
        if (v < 0) {
            c[c_size++] = -v;
        } else {
            pf[pf_size++] = v;
        }
    }

    for (i64 i = 0; i < pf_size; ++i) {
        for (i64 j = i + 1; j < pf_size; ++j) {
            if (pf[i] < pf[j]) {
                i64 temp = pf[i];
                pf[i] = pf[j];
                pf[j] = temp;
            }
        }
    }

    i64 ini = 0;
    i64 base = 0;
    for (i64 i = 0; i < pf_size; ++i) {
        base += ini;
        ini += pf[i];
    }

    for (i64 i = 0; i < c_size; ++i) {
        for (i64 j = i + 1; j < c_size; ++j) {
            if (c[i] < c[j]) {
                i64 temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }

    if (k == 0) {
        for (i64 i = c_size - 1; i >= 0; --i) {
            base += ini;
            ini -= c[i];
        }
        printf("%lld\n", base);
        return;
    }

    i64* cs = (i64*)malloc((c_size + 1) * sizeof(i64));
    cs[0] = 0;
    for (i64 i = 0; i < c_size; ++i) {
        cs[i + 1] = cs[i] + (i / (k + 1) * c[i]);
    }

    i64* sf = (i64*)malloc((c_size + 1) * sizeof(i64));
    i64* sf2 = (i64*)malloc((c_size + 1) * sizeof(i64));
    sf[c_size] = 0;
    sf2[c_size] = 0;
    for (i64 i = c_size - 1; i >= 0; --i) {
        sf[i] = sf[i + 1] + c[i];
        sf2[i] = sf2[i + 1] + c[i] * i;
    }

    i64 ans = -1000000000000000000;
    for (i64 j = 0; j <= c_size; ++j) {
        if (j * (k + 1) < c_size) continue;
        i64 cd = ceil_div(c_size - j, k);
        i64 tp = j - cd;
        i64 now = ini * j;
        now -= sf2[c_size - tp] + sf[tp] * (cd - (c_size - tp));
        now -= cs[c_size - tp];
        ans = max(ans, now);
    }

    ans += base;
    printf("%lld\n", ans);

    free(c);
    free(pf);
    free(cs);
    free(sf);
    free(sf2);
}
