#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int first;
    int second;
} pair;

typedef struct {
    long long bit[100007];
    const int n = 100007;
} B1T;

int n;
double x[100007], y[100007];
int w;
int cnt[100007];
double as[100007];
int cnta;
pair bs[100007];

void add(B1T *bit, int djg, int x) {
    while (djg <= bit->n) {
        bit->bit[djg] += x;
        djg += (djg & -djg);
    }
}

long long sum(B1T *bit, int djg) {
    long long id0 = 0;
    while (djg) {
        id0 += bit->bit[djg];
        djg -= (djg & -djg);
    }
    return id0;
}

int compare(const void *a, const void *b) {
    pair *pa = (pair *)a;
    pair *pb = (pair *)b;
    if (pa->first < pb->first) {
        return -1;
    } else if (pa->first > pb->first) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    scanf("%d%d", &n, &w);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        x[i] = 1.00 * a / (b + w);
        y[i] = 1.00 * a / (b - w);
        cnt[(int)(y[i])] += 1;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += cnt[(int)(y[i])] - 1;
    }
    ans /= 2;
    for (int i = 0; i < n; i++) {
        as[i] = x[i];
    }
    qsort(as, n, sizeof(double), compare);
    cnta = 1;
    for (int i = 1; i < n; i++) {
        if (as[i] != as[i - 1]) {
            as[cnta] = as[i];
            cnta += 1;
        }
    }
    for (int i = 0; i < n; i++) {
        bs[i].first = (int)(y[i]);
        bs[i].second = i;
    }
    qsort(bs, n, sizeof(pair), compare);
    int now = 0;
    B1T bit;
    for (int i = 0; i < n; i++) {
        while (bs[now].first < bs[i].first) {
            int id = 0;
            for (int j = 0; j < cnta; j++) {
                if (as[j] == x[bs[now].second]) {
                    id = j;
                    break;
                }
            }
            add(&bit, 100006 - id, 1);
            now++;
        }
        int id = 0;
        for (int j = 0; j < cnta; j++) {
            if (as[j] == x[bs[i].second]) {
                id = j;
                break;
            }
        }
        ans += sum(&bit, 100006 - id);
    }

    printf("%lld\n", ans);

    return 0;
}
