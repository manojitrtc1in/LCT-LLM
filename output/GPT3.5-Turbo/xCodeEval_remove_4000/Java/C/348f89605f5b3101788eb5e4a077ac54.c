#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

void sort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void main() {
    int n, k, i;
    long a[MAX_SIZE];
    scanf("%d", &n);
    scanf("%d", &k);
    for (i = 0; i < n; i++) {
        scanf("%ld", &a[i]);
    }
    sort(a, n);
    for (i = 0; i < n / 2; i++) {
        long temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - i - 1] = temp;
    }
    long pq[MAX_SIZE];
    int pq_size = 0;
    while (k-- >= 0) {
        pq[pq_size++] = 0;
    }
    long gg = 0;
    for (i = 0; i < n; i++) {
        long cur = pq[--pq_size];
        gg += cur;
        cur += a[i];
        pq[pq_size++] = cur;
        sort(pq, pq_size);
    }
    printf("%ld\n", gg);
}
