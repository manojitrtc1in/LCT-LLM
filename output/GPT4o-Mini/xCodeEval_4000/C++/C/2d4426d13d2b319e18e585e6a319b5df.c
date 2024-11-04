#include <stdio.h>
#include <string.h>
#include <math.h>

#define Mask(a) (1ll<<(a))
#define Maskx(a,x) ((a)<<(x))
#define Full(a) ((1ll<<(a))-1)
#define loop(i,n) for(int i=0;i<(n);i++)
#define pool(i,n) for(int i=(n)-1;i>=0;i--)
#define circ(i,a,b) for(int i=(a);i<=(b);i++)
#define SZ(a) ((int)((a).size()))

typedef long long ll;
typedef long double lf;

int n, m;
char s[55][25];
ll dy[Mask(20)+5];
lf dp[Mask(20)+5];

int main() {
    scanf("%d", &n);
    loop(i, n) {
        scanf("%s", s[i]);
    }
    m = strlen(s[0]);
    loop(i, n) {
        circ(j, i + 1, n - 1) {
            int num = 0;
            loop(k, m) {
                num |= Maskx(s[i][k] == s[j][k], k);
            }
            dy[num] |= Mask(i) | Mask(j);
        }
    }
    pool(i, Mask(m)) {
        for (int j = i; j & -j; j -= j & -j) {
            int lst = j & -j;
            dy[i ^ lst] |= dy[i];
        }
    }
    dp[0] = 1;
    lf ans = 0;
    loop(i, Mask(m)) {
        lf v = dp[i] / (m - __builtin_popcount(i));
        for (int j = Full(m) ^ i; j & -j; j -= j & -j) {
            dp[i | (j & -j)] += v;
        }
        ans += dp[i] * __builtin_popcountll(dy[i]);
    }
    printf("%.10Lf\n", ans / n);
    return 0;
}
