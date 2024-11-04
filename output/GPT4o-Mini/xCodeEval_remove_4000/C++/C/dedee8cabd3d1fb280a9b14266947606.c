#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef long long LL;
typedef double DB;
typedef int UINT;

#define PB push_back
#define ALL(x) (x).begin(), (x).end()
#define INF 0x7fffffff
#define MOD 1000000007
#define REP_C(i, n) for(int i = 0; i < (n); ++i)
#define SZ(x) ((int)(x).size())

LL pl, pr, vl, vr, k;
LL cnt;
int A[1001], A_size = 0;

void dfs(int k, int n) {
    A[A_size++] = n;
    if (k == 9) return;
    else {
        dfs(k + 1, n * 10 + 4);
        dfs(k + 1, n * 10 + 7);
    }
}

LL I(int l, int r, int l_, int r_) {
    if (l < l_) l = l_;
    if (r > r_) r = r_;
    return (r - l + 1 > 0) ? (r - l + 1) : 0;
}

void sort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    dfs(0, 0);
    sort(A, A_size);
    A[A_size++] = INF;

    scanf("%lld %lld %lld %lld %lld", &pl, &pr, &vl, &vr, &k);

    for (int i = 0; i < SZ(A) - k; i++) {
        int l1 = A[i - 1] + 1, r1 = A[i], l2 = A[i + k - 1], r2 = A[i + k] - 1;
        LL d1 = I(l1, r1, pl, pr) * I(l2, r2, vl, vr);
        LL d2 = I(l1, r1, vl, vr) * I(l2, r2, pl, pr);
        cnt += d1 + d2;
        if (d2 && d2 && k == 1) --cnt;
    }

    printf("%.12lf\n", (DB)cnt / ((pr - pl + 1) * (vr - vl + 1)));
    return 0;
}
