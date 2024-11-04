#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define nax 1000

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    pii first;
    int second;
} pair;

typedef struct {
    int v;
    char* d;
    int m;
} nep;

typedef struct {
    int* arr;
    int size;
} vpii;

typedef struct {
    int* arr;
    int size;
} deque;

typedef struct {
    int* arr;
    int size;
} set;

typedef struct {
    int* arr;
    int size;
} list;

typedef struct {
    int* arr;
    int size;
} vector;

typedef struct {
    int* arr;
    int size;
} bitset;

typedef struct {
    int* arr;
    int size;
} unordered_map;

int graf[nax][nax];
int siz[nax];
int dep[nax];
pair ans[nax];
deque ava;
int n;

void dfs1(int x, int y, int d) {
    siz[x] = 1;
    dep[x] = d;
    for (int v = 0; v < n; v++) {
        if (graf[x][v] && v != y) {
            dfs1(v, x, d + 1);
            siz[x] += siz[v];
        }
    }
}

void dfs2(int x, int y, int d) {
    int t = ava.arr[0];
    ava.arr++;
    ava.size--;
    if (t > d) {
        ans[x].first.first = x;
        ans[x].first.second = y;
        ans[x].second = t - d;
    }
    for (int v = 0; v < n; v++) {
        if (graf[x][v] && v != y) {
            dfs2(v, x, t);
        }
    }
}

void dfs3(int x, int y, int d) {
    set_insert(&seen, d);
    for (int i = 0; i < graf2[x].size; i++) {
        if (graf2[x].arr[i].first != y) {
            dfs3(graf2[x].arr[i].first, x, d + graf2[x].arr[i].second);
        }
    }
}

void test_ans() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < graf2[i].size; j++) {
            graf2[i].arr[j].first = 0;
            graf2[i].arr[j].second = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        dfs3(i);
    }
}

int main() {
    scanf("%d", &n);
    if (n == 1) {
        return 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        graf[a][b] = 1;
        graf[b][a] = 1;
    }
    dfs1(1, -1, 0);
    int M = n * 2 / 3;
    for (int i = 1; i <= n; i++) {
        vpii sizes;
        sizes.arr = malloc(sizeof(pii));
        sizes.size = 1;
        sizes.arr[0].first = 1;
        sizes.arr[0].second = i;
        int p = -1;
        for (int v = 0; v < n; v++) {
            if (graf[i][v] && dep[v] == dep[i] + 1) {
                sizes.size++;
                sizes.arr = realloc(sizes.arr, sizes.size * sizeof(pii));
                sizes.arr[sizes.size - 1].first = siz[v];
                sizes.arr[sizes.size - 1].second = v;
            } else if (graf[i][v]) {
                p = v;
            }
        }
        if (i != 1) {
            sizes.size++;
            sizes.arr = realloc(sizes.arr, sizes.size * sizeof(pii));
            sizes.arr[sizes.size - 1].first = n - siz[i];
            sizes.arr[sizes.size - 1].second = p;
        }
        bool good = true;
        for (int j = 0; j < sizes.size; j++) {
            if (sizes.arr[j].first > M) {
                good = false;
                break;
            }
        }
        if (good) {
            vpii v1, v2;
            v1.arr = malloc(sizeof(pii));
            v1.size = 0;
            v2.arr = malloc(sizeof(pii));
            v2.size = 0;
            for (int j = 0; j < sizes.size; j++) {
                if (v1.size + sizes.arr[j].first > M) {
                    v2.size++;
                    v2.arr = realloc(v2.arr, v2.size * sizeof(pii));
                    v2.arr[v2.size - 1].first = sizes.arr[j].first;
                    v2.arr[v2.size - 1].second = sizes.arr[j].second;
                } else {
                    v1.size++;
                    v1.arr = realloc(v1.arr, v1.size * sizeof(pii));
                    v1.arr[v1.size - 1].first = sizes.arr[j].first;
                    v1.arr[v1.size - 1].second = sizes.arr[j].second;
                }
            }
            int sum1 = 0, sum2 = 0;
            int whme = 0;
            for (int j = 0; j < v1.size; j++) {
                sum1 += v1.arr[j].first;
            }
            for (int j = 0; j < v2.size; j++) {
                sum2 += v2.arr[j].first;
            }
            if (i == 1) {
                whme = 1;
            } else {
                whme = 2;
            }
            if (whme == 2) {
                vpii temp = v1;
                v1 = v2;
                v2 = temp;
                int temp_sum = sum1;
                sum1 = sum2;
                sum2 = temp_sum;
            }
            for (int j = 1; j < sum1; j++) {
                ava.arr[j - 1] = j;
            }
            for (int j = 0; j < v1.size; j++) {
                if (v1.arr[j].second != i) {
                    dfs2(v1.arr[j].second, i, 0);
                }
            }
            for (int j = 0; j < sum2; j++) {
                ava.arr[j] = 1 + j * sum1;
            }
            for (int j = 0; j < v2.size; j++) {
                dfs2(v2.arr[j].second, i, 0);
            }
            for (int j = 0; j < ava.size; j++) {
                printf("%d %d %d\n", ans[j].first.first, ans[j].first.second, ans[j].second);
            }
            test_ans();
            return 0;
        }
    }
    return 0;
}
