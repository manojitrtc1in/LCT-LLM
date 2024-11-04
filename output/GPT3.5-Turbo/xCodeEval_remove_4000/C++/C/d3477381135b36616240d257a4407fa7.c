#include <stdio.h>
#include <string.h>

#define N 109

char a[N], c[N];
int t[N];
int b, d;

int main() {
    scanf("%d%d%s%s", &b, &d, a, c);
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

    int s = 0;
    for (int i = 0; i < b; i++) {
        s += t[s % cn];
    }
    s /= cn * d;

    printf("%d\n", s);

    return 0;
}
