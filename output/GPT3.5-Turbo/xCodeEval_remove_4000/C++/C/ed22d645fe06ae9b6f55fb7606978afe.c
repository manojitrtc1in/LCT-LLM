#include <stdio.h>
#include <string.h>

#define N 109

char a[N], c[N];
int t[N];
int b, d;

int main() {
    scanf("%d %d", &b, &d);
    scanf("%s %s", a, c);
    int an = strlen(a), cn = strlen(c);

    for (int i = 0; i < cn; i++) {
        int k = 0;
        for (int j = 0; j < an; j++) {
            if (a[j] == c[(i + k) % cn]) {
                k++;
            }
        }
        t[i] = k;
    }

    int tt[N][2];
    memset(tt, -1, sizeof(tt));
    int s = 0;
    int bj = 0;

    for (int i = 0; i < b; i++) {
        s += t[s % cn];

        if (bj) {
            continue;
        }

        if (tt[s % cn][0] == -1) {
            tt[s % cn][0] = i;
            tt[s % cn][1] = s;
        } else {
            int r = i - tt[s % cn][0];
            s += (s - tt[s % cn][1]) * ((b - i) / r);
            i += ((b - i) / r) * r;
            bj = 1;
        }
    }

    s /= cn * d;
    printf("%d\n", s);

    return 0;
}
