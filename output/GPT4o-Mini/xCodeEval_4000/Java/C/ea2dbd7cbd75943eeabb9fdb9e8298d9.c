#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MOD 1000000007

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int *parent;
    int *rank;
    int *size;
    int n;
} DSU;

DSU* create_dsu(int n) {
    DSU *dsu = (DSU *)malloc(sizeof(DSU));
    dsu->parent = (int *)malloc(n * sizeof(int));
    dsu->rank = (int *)malloc(n * sizeof(int));
    dsu->size = (int *)malloc(n * sizeof(int));
    dsu->n = n;
    for (int i = 0; i < n; i++) {
        dsu->parent[i] = i;
        dsu->rank[i] = 0;
        dsu->size[i] = 1;
    }
    return dsu;
}

int find(DSU *dsu, int a) {
    if (dsu->parent[a] != a) {
        dsu->parent[a] = find(dsu, dsu->parent[a]);
    }
    return dsu->parent[a];
}

void merge(DSU *dsu, int a, int b) {
    a = find(dsu, a);
    b = find(dsu, b);
    if (a != b) {
        if (dsu->rank[a] < dsu->rank[b]) {
            dsu->parent[a] = b;
            dsu->size[b] += dsu->size[a];
        } else {
            dsu->parent[b] = a;
            dsu->size[a] += dsu->size[b];
            if (dsu->rank[a] == dsu->rank[b]) {
                dsu->rank[a]++;
            }
        }
    }
}

typedef struct {
    int *data;
    int size;
    int capacity;
} IntegerList;

IntegerList* create_integer_list(int capacity) {
    IntegerList *list = (IntegerList *)malloc(sizeof(IntegerList));
    list->data = (int *)malloc(capacity * sizeof(int));
    list->size = 0;
    list->capacity = capacity;
    return list;
}

void add(IntegerList *list, int value) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = value;
}

void clear(IntegerList *list) {
    list->size = 0;
}

int unique(IntegerList *list) {
    int newSize = 0;
    for (int i = 0; i < list->size; i++) {
        bool found = false;
        for (int j = 0; j < newSize; j++) {
            if (list->data[i] == list->data[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            list->data[newSize++] = list->data[i];
        }
    }
    list->size = newSize;
    return newSize;
}

int combination(int n, int k) {
    if (k > n) return 0;
    long long res = 1;
    for (int i = 0; i < k; i++) {
        res = (res * (n - i)) % MOD;
        res = (res * pow(i + 1, MOD - 2)) % MOD; // Fermat's little theorem for modular inverse
    }
    return (int)res;
}

void solve(int n, Point *pts) {
    DSU *dsu = create_dsu(n);
    IntegerList *xList = create_integer_list(n);
    IntegerList *yList = create_integer_list(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (pts[i].x == pts[j].x) {
                merge(dsu, i, j);
            }
            if (pts[i].y == pts[j].y) {
                merge(dsu, i, j);
            }
        }
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (find(dsu, i) != i) continue;

        clear(xList);
        clear(yList);
        for (int j = 0; j < n; j++) {
            if (find(dsu, j) == i) {
                add(xList, pts[j].x);
                add(yList, pts[j].y);
            }
        }
        unique(xList);
        unique(yList);

        int line = xList->size + yList->size;
        int num = dsu->size[i];
        int local = 0;
        for (int j = 0; j <= num; j++) {
            local = (local + combination(line, j)) % MOD;
        }
        ans = (ans * local) % MOD;
    }

    printf("%d\n", ans);
    free(dsu->parent);
    free(dsu->rank);
    free(dsu->size);
    free(dsu);
    free(xList->data);
    free(xList);
    free(yList->data);
    free(yList);
}

int main() {
    int n;
    scanf("%d", &n);
    Point *pts = (Point *)malloc(n * sizeof(Point));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pts[i].x, &pts[i].y);
    }
    solve(n, pts);
    free(pts);
    return 0;
}