#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 500007

int n, k, a[MAXN], ans, res = 0;

int cmp(const void *x, const void *y) {
    return (*(int *)x - *(int *)y);
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i] = -a[i];
    }
    
    qsort(a, n, sizeof(int), cmp);
    
    int j = -1;
    for (int i = 0; i < n; i++) {
        res -= a[i];
        if (res < 0) {
            j = i;
            break;
        }
        if (i != n - 1) ans += res;
    }
    
    if (j == -1) {
        printf("%d\n", ans);
        return 0;
    }
    
    int tmp[MAXN];
    int tmp_size = 0;
    tmp[tmp_size++] = res;
    
    for (int i = j + 1; i < n; i++) {
        tmp[tmp_size++] = -a[i];
    }
    
    qsort(tmp, tmp_size, sizeof(int), cmp);
    
    int w = 0;
    for (int i = 0; i < tmp_size; i++) {
        ans += (w / (k + 1)) * tmp[i];
        w++;
    }
    
    printf("%d\n", ans);
    return 0;
}
