#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

void freeVector(Vector *v) {
    free(v->data);
}

int main() {
    int ans = INF, n, k;
    bool t[MAXN] = {false};
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
            t[temp] = true;
            temp /= 2;
        }
    }
    
    for (int i = 0; i < MAXN; i++) {
        if (t[i]) {
            if (a[i].size < k) continue;

            // Sort the vector
            for (int j = 0; j < a[i].size - 1; j++) {
                for (int l = j + 1; l < a[i].size; l++) {
                    if (a[i].data[j] > a[i].data[l]) {
                        int temp = a[i].data[j];
                        a[i].data[j] = a[i].data[l];
                        a[i].data[l] = temp;
                    }
                }
            }

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
        freeVector(&a[i]);
    }

    return 0;
}
