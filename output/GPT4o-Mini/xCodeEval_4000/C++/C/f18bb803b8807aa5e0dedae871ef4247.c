#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LL long long
#define MAXN 100007

typedef struct {
    LL bit[MAXN];
    int n;
} B1T;

void add(B1T *bit, int djg, int x) {
    while (djg <= bit->n) {
        bit->bit[djg] += x;
        djg += (djg & -djg);
    }
}

LL sum(B1T *bit, int djg) {
    LL s0m = 0;
    while (djg) {
        s0m += bit->bit[djg];
        djg -= (djg & -djg);
    }
    return s0m;
}

int main() {
    int n, w;
    scanf("%d%d", &n, &w);
    
    double x[MAXN], y[MAXN];
    int cnt[MAXN] = {0};
    double as[MAXN];
    int cnta;
    struct {
        double first;
        int second;
    } bs[MAXN];

    B1T bit = { .n = MAXN };

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        x[i] = 1.00 * a / (b + w);
        y[i] = 1.00 * a / (b - w);
        cnt[(int)(y[i])]++; // Assuming y[i] can be cast to int safely
    }

    LL ans = 0;
    for (int i = 0; i < n; i++)
        ans += cnt[(int)(y[i])] - 1;
    ans /= 2;

    for (int i = 0; i < n; i++)
        as[i] = x[i];
    
    qsort(as, n, sizeof(double), (int (*)(const void *, const void *))compare_doubles);
    cnta = unique(as, as + n) - as;

    for (int i = 0; i < n; i++) {
        bs[i].first = y[i];
        bs[i].second = i;
    }
    
    qsort(bs, n, sizeof(bs[0]), compare_pairs);
    
    int now = 0;
    for (int i = 0; i < n; i++) {
        while (bs[now].first < bs[i].first) {
            int id = lower_bound(as, as + cnta, x[bs[now].second]) - as;
            add(&bit, 100006 - id, 1);
            now++;
        }
        int id = lower_bound(as, as + cnta, x[bs[i].second]) - as;
        ans += sum(&bit, 100006 - id);
    }

    printf("%lld\n", ans);
    return 0;
}

int compare_doubles(const double *a, const double *b) {
    return (*a > *b) - (*a < *b);
}

int compare_pairs(const void *a, const void *b) {
    double diff = ((struct { double first; int second; } *)a)->first - ((struct { double first; int second; } *)b)->first;
    return (diff > 0) - (diff < 0);
}

int unique(double *arr, double *end) {
    double *last = arr;
    for (double *current = arr + 1; current < end; current++) {
        if (*current != *last) {
            last++;
            *last = *current;
        }
    }
    return last - arr + 1;
}

int lower_bound(double *arr, double *end, double value) {
    double *low = arr, *high = end;
    while (low < high) {
        double *mid = low + (high - low) / 2;
        if (*mid < value) low = mid + 1;
        else high = mid;
    }
    return low - arr;
}
