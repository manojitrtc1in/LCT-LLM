#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

typedef struct {
    int a;
    int b;
} Pair;

int compare(const void* a, const void* b) {
    Pair* p1 = (Pair*)a;
    Pair* p2 = (Pair*)b;
    return p1->a - p2->a;
}

int check(int x, int n, int m, int* l, Pair* t) {
    int now = x;
    int c = 0;
    for (int i = 0; i < n; i++) {
        c += l[i];
    }
    int cur = 0;
    int last = 0;
    int* ld = (int*)calloc(n + 1, sizeof(int));
    for (int i = 0; i < m; i++) {
        if (t[i].a <= x) {
            ld[t[i].b] = i;
        }
    }
    for (int i = 0; i < m; i++) {
        if (ld[t[i].b] != i) {
            continue;
        }
        if (t[i].a > x) {
            break;
        }
        cur += t[i].a - last;
        int rt = cur < l[t[i].b - 1] ? cur : l[t[i].b - 1];
        cur -= rt;
        now -= rt;
        c -= rt;
        last = t[i].a;
    }
    free(ld);
    if (now >= 2 * c) {
        return 1;
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int* l = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    Pair* t = (Pair*)malloc(m * sizeof(Pair));
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &t[i].a, &t[i].b);
    }
    qsort(t, m, sizeof(Pair), compare);
    int st = 1;
    int end = 2 * n;
    int ans = end;
    while (st <= end) {
        int mid = (st + end) / 2;
        if (check(mid, n, m, l, t)) {
            ans = mid;
            end = mid - 1;
        }
        else {
            st = mid + 1;
        }
    }
    printf("%d\n", ans);
    free(l);
    free(t);
    return 0;
}
