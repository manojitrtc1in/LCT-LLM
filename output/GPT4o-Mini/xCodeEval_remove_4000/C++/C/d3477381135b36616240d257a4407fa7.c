#include <stdio.h>
#include <string.h>

#define N 109
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define DO(n) for (int _ = 0; _ < (n); ++_)

char a[N], c[N];
int t[N];
int b, d;

int main() {
    freopen("in.txt", "r", stdin);

    scanf("%d %d", &b, &d);
    scanf("%s %s", a, c);
    int an = strlen(a), cn = strlen(c);

    REP(i, cn) {
        int *k = &t[i];
        REP(j, an) if (a[j] == c[(*k + i) % cn]) ++(*k);
    }

    int s = 0;
    DO(b) s += t[s % cn];
    s /= cn * d;
    printf("%d\n", s);

    return 0;
}
