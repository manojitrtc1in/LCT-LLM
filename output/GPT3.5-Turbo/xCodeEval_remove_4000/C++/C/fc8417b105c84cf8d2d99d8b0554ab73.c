#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAXN 200099
#define INF INT_MAX
#define MAXP 10000

typedef long long ll;
typedef unsigned long long llu;
typedef struct {
    int first;
    int second;
} pii;

ll HASHprime = 1333331;

int main() {
    int ans = INF, n, k;
    int i, temp, cnt;
    int a[MAXN][MAXN];
    bool t[MAXN];
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; ++i) {
        scanf("%d", &temp);
        cnt = 0;
        while (temp) {
            a[temp][cnt++] = 1;
            t[temp] = true;
            temp /= 2;
        }
    }
    for (i = 0; i < MAXN; ++i) {
        if (t[i]) {
            if (cnt < k) {
                continue;
            }
            int j;
            int sum = 0;
            for (j = 0; j < cnt; ++j) {
                sum += a[i][j];
            }
            if (sum < ans) {
                ans = sum;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
