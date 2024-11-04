#include <stdio.h>
#include <stdlib.h>

#define maxn 500007

int t;
int n, k;
int a[maxn], ans, res = 0;

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i] = -a[i];
    }
    qsort(a, n, sizeof(int), cmpfunc);
    int j = -1;
    for (int i = 0; i < n; i++) {
        res -= a[i];
        if (res < 0) {
            j = i;
            break;
        }
        if (i != n - 1)
            ans += res;
    }
    if (j == -1) {
        printf("%d", ans);
        return 0;
    }
    int tmp[maxn];
    int tmp_size = 0;
    tmp[tmp_size++] = res;
    for (int i = j + 1; i < n; i++)
        tmp[tmp_size++] = -a[i];
    qsort(tmp, tmp_size, sizeof(int), cmpfunc);
    int w = 0;
    for (int i = 0; i < tmp_size; i++) {
        ans += (w / (k + 1)) * tmp[i];
        w++;
    }
    printf("%d", ans);
    return 0;
}
