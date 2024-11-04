#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef long long ll;
typedef struct {
    ll X, Y;
} pll;
typedef struct {
    int X, Y;
} pii;
typedef struct {
    pll *data;
    int size;
} vpll;
typedef struct {
    int *data;
    int size;
} vi;

void init_vpll(vpll *v, int size) {
    v->data = (pll *)malloc(size * sizeof(pll));
    v->size = size;
}

void init_vi(vi *v, int size) {
    v->data = (int *)malloc(size * sizeof(int));
    v->size = size;
}

void free_vpll(vpll *v) {
    free(v->data);
}

void free_vi(vi *v) {
    free(v->data);
}

void take(int k, vpll *perm, vpll *points) {
    int n = points->size;
    for (int i = 0; i < n; ++i) {
        if (points->data[i].Y == k) {
            pll temp = points->data[i];
            points->data[i] = points->data[n - 1];
            points->data[n - 1] = temp;
            break;
        }
    }
    perm->data[perm->size++] = points->data[n - 1];
    points->size--;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);

    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    clock_t start_time = clock();
    fprintf(stderr, "%.3f\n", (double)clock() / CLOCKS_PER_SEC);

    int n;
    scanf("%d", &n);
    vpll p;
    init_vpll(&p, n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &p.data[i].X, &p.data[i].Y);
        p.data[i].Y = i;
    }
    char s[100000];
    scanf("%s", s);
    vpll perm;
    init_vpll(&perm, n);
    int first_idx = 0;
    for (int i = 0; i < n; ++i) {
        if (p.data[i].X < p.data[first_idx].X) {
            first_idx = i;
        }
    }
    take(first_idx, &perm, &p);
    for (int i = 0; i < n - 2; ++i) {
        pll q = perm.data[perm.size - 1];
        int best = 0;
        for (int j = 1; j < p.size; ++j) {
            if ((((p.data[best].X - q.X) * (p.data[j].Y - q.Y)) - ((p.data[best].Y - q.Y) * (p.data[j].X - q.X))) > 0) == (s[i] == 'R')) {
                best = j;
            }
        }
        take(p.data[best].Y, &perm, &p);
    }
    take(p.data[0].Y, &perm, &p);
    for (int i = 0; i < perm.size; ++i) {
        printf("%lld ", perm.data[i].Y + 1);
    }
    printf("\n");

    clock_t end_time = clock();
    fprintf(stderr, "Execution time: %ld ms\n", (end_time - start_time) * 1000 / CLOCKS_PER_SEC);

    free_vpll(&p);
    free_vpll(&perm);
    return 0;
}
