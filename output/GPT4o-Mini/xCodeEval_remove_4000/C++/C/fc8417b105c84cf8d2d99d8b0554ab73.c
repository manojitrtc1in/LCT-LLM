#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 200000
#define INF INT_MAX

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

void initVector(Vector *v) {
    v->size = 0;
    v->capacity = 10;
    v->data = (int *)malloc(v->capacity * sizeof(int));
}

void pushBack(Vector *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int ans = INF, n, k;
    int t[1000000] = {0}; // Assuming input values are less than 1,000,000
    Vector a[MAXN];

    for (int i = 0; i < MAXN; i++) {
        initVector(&a[i]);
    }

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        int temp, cnt = 0;
        scanf("%d", &temp);
        while (temp) {
            pushBack(&a[temp], cnt++);
            t[temp] = 1;
            temp /= 2;
        }
    }

    for (int i = 0; i < 1000000; i++) {
        if (t[i]) {
            if (a[i].size < k) continue;
            qsort(a[i].data, a[i].size, sizeof(int), compare);
            int sum = 0;
            for (int j = 0; j < k; j++) {
                sum += a[i].data[j];
            }
            if (sum < ans) {
                ans = sum;
            }
        }
    }

    printf("%d\n", ans);
    for (int i = 0; i < MAXN; i++) {
        free(a[i].data);
    }
}
