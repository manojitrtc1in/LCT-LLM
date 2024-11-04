#include <stdio.h>
#include <string.h>

typedef long long ll;
typedef unsigned long long ull;
typedef struct {
    ll first;
    ll second;
} pll;
typedef struct {
    int first;
    int second;
} pii;
typedef struct {
    pii first;
    pii second;
} ppiipii;
typedef struct {
    int first;
    pii second;
} pipii;

#define maxn (int)(1.5 * 1e7)
#define inf (~0U >> 1)
#define ll_inf (ll)(1e18 + 420)
#define eps 1e-4
#define N (int)(1e6 + 7)
#define MAX (int)(2e5 + 9)
#define MOD (int)(1e9 + 7)
#define pi 3.14159265359

char a[128], c[128];
int b, d, t[128];

int main() {
    scanf("%d%d", &b, &d);
    scanf("%s%s", a, c);
    int s = 0, n = strlen(c);
    for (int i = 0; c[i]; ++i) {
        int k = t[i];
        for (int j = 0; a[j]; ++j) {
            if (a[j] == c[(i + k) % n]) {
                ++k;
            }
        }
        t[i] = k;
    }
    for (int i = 0; i < b; ++i) {
        s += t[s % n];
    }
    printf("%d\n", s / n / d);
    return 0;
}
