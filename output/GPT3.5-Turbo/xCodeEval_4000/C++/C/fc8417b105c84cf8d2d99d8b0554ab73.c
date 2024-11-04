#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 200099
#define INF 0x3f3f3f3f
#define MAXP 10000

typedef long long ll;
typedef unsigned long long llu;
typedef struct {
    int first;
    int second;
} pii;

int main() {
    int ans = INF, n, k;
    int HASHprime = 1333331;
    int i, temp, cnt;
    int* a[MAXN];
    bool* t = (bool*)malloc(MAXN * sizeof(bool));
    for (i = 0; i < MAXN; ++i) {
        a[i] = (int*)malloc(MAXN * sizeof(int));
    }

    scanf("%d%d", &n, &k);
    for (i = 0; i < n; ++i) {
        scanf("%d", &temp);
        cnt = 0;
        while (temp) {
            a[temp][cnt++] = cnt;
            t[temp] = true;
            temp /= 2;
        }
    }

    for (i = 0; i < MAXN; ++i) {
        if (t[i]) {
            if (cnt < k) {
                continue;
            }
            qsort(a[i], cnt, sizeof(int), compare);
            int sum = 0;
            for (int j = 0; j < k; ++j) {
                sum += a[i][j];
            }
            ans = (ans < sum) ? ans : sum;
        }
    }

    printf("%d\n", ans);

    for (i = 0; i < MAXN; ++i) {
        free(a[i]);
    }
    free(t);

    return 0;
}
