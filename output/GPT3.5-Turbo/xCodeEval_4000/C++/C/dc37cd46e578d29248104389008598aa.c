#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    int p, q;
} F;

int x[101010];
int a[101010];
int v[2][101010][2];
int f1[202020];

int cmp(const void *a, const void *b) {
    F *f1 = (F *)a;
    F *f2 = (F *)b;
    if (f1->p * 1LL * f2->q < f2->p * 1LL * f1->q) {
        return -1;
    } else if (f1->p * 1LL * f2->q > f2->p * 1LL * f1->q) {
        return 1;
    } else {
        return 0;
    }
}

int lower_bound(F *arr, int size, F target) {
    int left = 0;
    int right = size - 1;
    int result = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid].p >= target.p) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int upper_bound(F *arr, int size, F target) {
    int left = 0;
    int right = size - 1;
    int result = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid].p <= target.p) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

long long solve1(int v[101010][2], int size, int w) {
    F allF[2 * size + 1];
    int allFSize = 0;
    for (int i = 0; i < size; i++) {
        F from = {v[i][0], v[i][1] + w};
        F to = {v[i][0], v[i][1] - w};
        allF[allFSize++] = from;
        allF[allFSize++] = to;
    }
    qsort(allF, allFSize, sizeof(F), cmp);
    int uniqueSize = 1;
    for (int i = 1; i < allFSize; i++) {
        if (allF[i].p * 1LL * allF[uniqueSize - 1].q != allF[uniqueSize - 1].p * 1LL * allF[i].q) {
            allF[uniqueSize++] = allF[i];
        }
    }
    for (int i = 0; i < size; i++) {
        F from = {v[i][0], v[i][1] + w};
        F to = {v[i][0], v[i][1] - w};
        int fromIndex = lower_bound(allF, uniqueSize, from);
        int toIndex = lower_bound(allF, uniqueSize, to);
        v[i][0] = fromIndex;
        v[i][1] = toIndex;
    }
    qsort(v, size, sizeof(v[0]), cmp);
    long long res = 0;
    memset(f1, 0, sizeof(f1));
    for (int i = 0; i < size; i++) {
        res += i - f1[v[i][1] - 1];
        for (int j = v[i][1]; j <= 200020; j |= j + 1) {
            f1[j]++;
        }
    }
    return res;
}

int f[2][202020];

long long solve2(int v[2][101010][2], int size[2], int w) {
    F allF[2 * (size[0] + size[1]) + 1];
    int allFSize = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < size[i]; j++) {
            F from = {v[i][j][0], v[i][j][1] + w};
            F to = {v[i][j][0], v[i][j][1] - w};
            allF[allFSize++] = from;
            allF[allFSize++] = to;
        }
    }
    qsort(allF, allFSize, sizeof(F), cmp);
    int uniqueSize = 1;
    for (int i = 1; i < allFSize; i++) {
        if (allF[i].p * 1LL * allF[uniqueSize - 1].q != allF[uniqueSize - 1].p * 1LL * allF[i].q) {
            allF[uniqueSize++] = allF[i];
        }
    }
    long long res = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < size[i]; j++) {
            F from = {v[i][j][0], v[i][j][1] + w};
            F to = {v[i][j][0], v[i][j][1] - w};
            int fromIndex = lower_bound(allF, uniqueSize, from);
            int toIndex = lower_bound(allF, uniqueSize, to);
            v[i][j][0] = fromIndex;
            v[i][j][1] = toIndex;
            f[i][fromIndex]++;
        }
    }
    for (int i = 1; i <= uniqueSize; i++) {
        f[0][i] += f[0][i - 1];
        f[1][i] += f[1][i - 1];
    }
    for (int i = 0; i < size[0]; i++) {
        res += f[1][v[0][i][1]] - f[1][v[0][i][0] - 1];
    }
    for (int i = 0; i < size[1]; i++) {
        res += f[0][v[1][i][1]] - f[0][v[1][i][0]];
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    int w;
    scanf("%d", &w);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &a[i]);
        v[x[i] < 0][i][0] = abs(x[i]);
        v[x[i] < 0][i][1] = abs(a[i]);
    }
    long long ans = 0;
    ans += solve1(v[0], n, w);
    ans += solve1(v[1], n, w);
    ans += solve2(v, (int[]){n, n}, w);
    printf("%lld\n", ans);
    return 0;
}
