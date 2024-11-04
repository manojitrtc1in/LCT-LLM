#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 500007

long long a[MAXN], ans, res = 0;

int cmp(const void *x, const void *y) {
    return (*(long long *)x - *(long long *)y);
}

int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        a[i] = -a[i];
    }
    
    qsort(a, n, sizeof(long long), cmp);
    
    long long j = -1;
    for (long long i = 0; i < n; i++) {
        res -= a[i];
        if (res < 0) {
            j = i;
            break;
        }
        if (i != n - 1) ans += res;
    }
    
    if (j == -1) {
        printf("%lld\n", ans);
        return 0;
    }
    
    long long *tmp = (long long *)malloc((n - j) * sizeof(long long));
    long long tmp_size = 0;
    tmp[tmp_size++] = res;
    
    for (long long i = j + 1; i < n; ++i) {
        tmp[tmp_size++] = -a[i];
    }
    
    qsort(tmp, tmp_size, sizeof(long long), cmp);
    
    long long w = 0;
    for (long long i = 0; i < tmp_size; i++) {
        ans += (w / (k + 1)) * tmp[i];
        w++;
    }
    
    printf("%lld\n", ans);
    free(tmp);
    return 0;
}
