#include <stdio.h>
#include <string.h>

#define N 109

char a[N], c[N];
int t[N], b, d;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

    scanf("%d %d", &b, &d);
    scanf("%s %s", a, c);
    int an = strlen(a), cn = strlen(c);

    for (int i = 0; i < cn; i++) {
        int *k = &t[i];
        for (int j = 0; j < an; j++) {
            if (a[j] == c[(i + *k) % cn]) {
                (*k)++;
            }
        }
    }

    int s = 0;
    for (int i = 0; i < b; i++) {
        s += t[s % cn];
    }
    s /= (cn * d);
    printf("%d\n", s);

    return 0;
}
