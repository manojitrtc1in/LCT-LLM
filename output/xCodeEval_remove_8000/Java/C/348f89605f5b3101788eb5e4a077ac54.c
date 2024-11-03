#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

void swap(long *a, long *b) {
    long temp = *a;
    *a = *b;
    *b = temp;
}

void sort(long a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

void main() {
    int n, k;
    scanf("%d %d", &n, &k);
    long *a = (long *)malloc(n * sizeof(long));
    for (int i = 0; i < n; i++) {
        scanf("%ld", &a[i]);
    }
    sort(a, n);
    for (int i = 0; i < n / 2; i++) {
        swap(&a[i], &a[n - i - 1]);
    }
    long *pq = (long *)malloc((k + 1) * sizeof(long));
    for (int i = 0; i <= k; i++) {
        pq[i] = 0;
    }
    long gg = 0;
    for (int i = 0; i < n; i++) {
        long cur = pq[0];
        gg += cur;
        cur += a[i];
        pq[0] = cur;
        for (int j = 0; j < k; j++) {
            if (pq[j] < pq[j + 1]) {
                swap(&pq[j], &pq[j + 1]);
            }
        }
    }
    printf("%ld\n", gg);
    free(a);
    free(pq);
}
