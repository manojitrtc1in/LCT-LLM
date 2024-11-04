#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define DWN(i, n, m) for (int i = (n); i >= (m); --i)
#define REP_C(i, n) for (int i = 0; i < (n); ++i)

const int N = 1000009;
int a[N], n, s[N], top;

int main() {
    freopen("in.txt", "r", stdin);

    scanf("%d", &n);
    REP_C(i, n) scanf("%d", &a[i]);
    a[scanf("%d", &n) - 1] *= -1;

    top = 0;
    DWN(i, n - 1, 0) {
        if (a[i] > 0) {
            if (top && s[top] == a[i]) --top;
            else s[++top] = a[i], a[i] = -a[i];
        } else {
            s[++top] = -a[i];
        }
    }

    if (top) puts("NO");
    else {
        puts("YES");
        REP(i, n) printf("%d ", a[i]);
    }
}
