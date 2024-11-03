#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000000

int pr[8] = {2, 3, 5, 7, 11, 13, 17, 19};
int num[100][2] = {
    {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 0}, {1, 1}, {1, 2}, {1, 3},
    {1, 4}, {1, 5}, {1, 6}, {1, 7}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5},
    {2, 6}, {2, 7}, {3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}, {3, 7},
    {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {5, 0}, {5, 1},
    {5, 2}, {5, 3}, {5, 4}, {5, 5}, {5, 6}, {5, 7}, {6, 0}, {6, 1}, {6, 2}, {6, 3},
    {6, 4}, {6, 5}, {6, 6}, {6, 7}, {7, 0}, {7, 2}, {7, 3}, {7, 4}, {7, 5}, {7, 6},
    {7, 7}, {7, 8}, {8, 1}, {8, 3}, {8, 4}, {8, 5}, {8, 6}, {8, 7}, {8, 8}, {8, 9},
    {9, 3}, {9, 5}, {9, 6}, {9, 7}, {9, 8}, {9, 9}, {9, 10}, {10, 7}, {10, 8}
};

typedef struct {
    int* arr;
    int size;
} Vector;

Vector L[300];
int ans[300][300];
int cnt = 0;
int mp[MAX + 1];

void init(int i, int x, int la, Vector* v) {
    L[cnt++] = *v;
    int sz = v->size;
    v->arr[sz] = 0;
    v->size++;
    for (int d = 1; d <= la && (x /= pr[i]); d++) {
        v->arr[sz]++;
        init(i + 1, x, d, v);
    }
    v->size--;
}

int get(int x) {
    Vector v;
    v.size = 0;
    v.arr = malloc(sizeof(int) * 10);
    while (x > 1) {
        int p = mp[x];
        int c = 0;
        while (x % p == 0) {
            x /= p;
            c++;
        }
        v.arr[v.size++] = -c;
    }
    for (int i = v.size; i--;) {
        v.arr[i] *= -1;
    }
    qsort(v.arr, v.size, sizeof(int), compare);
    int res = -1;
    for (int i = 0; i < cnt; i++) {
        bool match = true;
        for (int j = 0; j < v.size; j++) {
            if (L[i].arr[j] != v.arr[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            res = i;
            break;
        }
    }
    free(v.arr);
    return res;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    Vector v;
    v.size = 0;
    v.arr = malloc(sizeof(int) * 10);
    init(0, MAX, 1 << 30, &v);
    for (int i = 2; i <= MAX; i++) {
        if (!mp[i]) {
            for (int j = i; j <= MAX; j += i) {
                if (!mp[j]) {
                    mp[j] = i;
                }
            }
        }
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", ans[get(a)][get(b)]);
    }
    return 0;
}
