#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD (int)(1e9 + 7)
#define MAX_N 50
#define MAX_M 20

typedef long long LL;
typedef double DB;

char S[MAX_N][MAX_M + 1];
LL f[1 << MAX_M], ok[MAX_M + 1];
int n, m;

inline int count_bits(int x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

inline LL _1(int i) {
    return 1LL << i;
}

int main() {
    FILE *input = fopen("in.txt", "r");
    fscanf(input, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(input, "%s", S[i]);
    }
    fclose(input);
    
    m = strlen(S[0]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int s = 0;
                for (int k = 0; k < m; k++) {
                    if (S[i][k] == S[j][k]) {
                        s |= _1(k);
                    }
                }
                f[s] |= _1(i);
            }
        }
    }

    for (int s = (1 << m) - 1; s >= 0; s--) {
        for (int i = 0; i < m; i++) {
            if (s & _1(i)) {
                f[s ^ _1(i)] |= f[s];
            }
        }
    }

    DB ans = 0;
    for (int s = 0; s < (1 << m); s++) {
        int step = count_bits(s) + 1;
        for (int i = 0; i < m; i++) {
            if (!(s & _1(i))) {
                LL d = f[s | _1(i)] ^ f[s];
                ok[step] += count_bits(d);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (ok[i]) {
            DB t = ok[i] * i;
            for (int j = 1; j < i; j++) {
                t *= j;
            }
            for (int j = i + 1; j <= m; j++) {
                t /= j;
            }
            ans += t;
        }
    }

    ans /= n;
    printf("%.15f\n", ans);
    return 0;
}
