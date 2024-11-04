#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int pr[8] = {2, 3, 5, 7, 11, 13, 17, 19};
int num[100][2] = {{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{1,0},{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7},{2,0},{2,1},{2,2},{2,3},{2,4},{2,5},{2,6},{2,7},{3,0},{3,1},{3,2},{3,3},{3,4},{3,5},{3,6},{3,7},{4,0},{4,1},{4,2},{4,3},{4,4},{4,5},{4,6},{4,7},{5,0},{5,1},{5,2},{5,3},{5,4},{5,5},{5,6},{5,7},{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{6,6},{6,7},{7,0},{7,2},{7,3},{7,4},{7,5},{7,6},{7,7},{7,8},{8,1},{8,3},{8,4},{8,5},{8,6},{8,7},{8,8},{8,9},{9,3},{9,5},{9,6},{9,7},{9,8},{9,9},{9,10},{10,7}};

typedef struct {
    int* arr;
    int size;
} Vector;

Vector L[300];
int ans[300][300];
int cnt;

void init(int i, int x, int la, Vector* v) {
    L[cnt++] = *v;
    int sz = v->size;
    v->arr = realloc(v->arr, (sz + 1) * sizeof(int));
    v->arr[sz] = 0;
    v->size = sz + 1;
    for (int d = 1; d <= la && (x /= pr[i]); d++) {
        v->arr[sz]++;
        init(i + 1, x, d, v);
    }
    v->arr = realloc(v->arr, sz * sizeof(int));
    v->size = sz;
}

int mp[MAX + 1];

int get(int x) {
    Vector v;
    v.arr = NULL;
    v.size = 0;
    while (x > 1) {
        int p = mp[x], c = 0;
        while (x % p == 0) {
            x /= p;
            c++;
        }
        v.arr = realloc(v.arr, (v.size + 1) * sizeof(int));
        v.arr[v.size++] = -c;
    }
    for (int i = v.size; i--;) {
        v.arr[i] *= -1;
    }
    qsort(v.arr, v.size, sizeof(int), cmp);
    int res = -1;
    for (int i = 0; i < cnt; i++) {
        if (memcmp(v.arr, L[i].arr, v.size * sizeof(int)) == 0) {
            res = i;
            break;
        }
    }
    free(v.arr);
    return res;
}

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    Vector v;
    v.arr = NULL;
    v.size = 0;
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
    int i = 0, j = 1;
