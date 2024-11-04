#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long INT;
typedef struct {
    INT bit[100007];
} B1T;

B1T bit;

void add(B1T *b, int djg, int x) {
    while (djg <= 100006) {
        b->bit[djg] += x;
        djg += (djg & -djg);
    }
}

INT sum(B1T *b, int djg) {
    INT id0 = 0;
    while (djg) {
        id0 += b->bit[djg];
        djg -= (djg & -djg);
    }
    return id0;
}

int main() {
    int n, w;
    scanf("%d%d", &n, &w);
    
    double x[100007], y[100007];
    int cnt[100007] = {0};
    double as[100007];
    int cnta;
    struct {
        double first;
        int second;
    } bs[100007];

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        x[i] = 1.00 * a / (b + w);
        y[i] = 1.00 * a / (b - w);
        cnt[(int)(y[i] * 1000)]++; // Using a scaling factor for mapping
    }

    INT ans = 0;
    for (int i = 0; i < n; i++)
        ans += cnt[(int)(y[i] * 1000)] - 1;
    ans /= 2;

    for (int i = 0; i < n; i++)
        as[i] = x[i];
    
    qsort(as, n, sizeof(double), cmpfunc);
    cnta = unique(as, as + n) - as;

    for (int i = 0; i < n; i++)
        bs[i] = (struct {double first; int second;}){y[i], i};
    
    qsort(bs, n, sizeof(bs[0]), cmpfunc);

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

int cmpfunc(const void *a, const void *b) {
    return (*(double*)a - *(double*)b);
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
