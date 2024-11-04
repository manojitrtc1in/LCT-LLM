#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 102
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FLC(A, x) memset(A, x, sizeof(A))

typedef struct {
    int fi, se;
} PII;

char a[N], c[N];
int t[N], b, d;
PII tt[N];

int main() {
    freopen("in.txt", "r", stdin);

    scanf("%d %d", &b, &d);
    scanf("%s %s", a, c);
    int an = strlen(a), cn = strlen(c);

    REP(i, cn) {
        int *k = &t[i];
        REP(j, an) if (a[j] == c[(i + *k) % cn]) ++(*k);
    }

    FLC(tt, -1);
    int s = 0;
    int bj = 0;

    REP(i, b) {
        s += t[s % cn];

        if (bj) continue;

        if (tt[s % cn].fi == -1) {
            tt[s % cn].fi = i;
            tt[s % cn].se = s;
        } else {
            int r = i - tt[s % cn].fi;
            s += (s - tt[s % cn].se) * ((b - i) / r);
            i += ((b - i) / r) * r;
            bj = 1;
        }
    }
    s /= cn * d;
    printf("%d\n", s);
    return 0;
}
