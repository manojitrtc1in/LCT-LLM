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

LL cnt;
LL A[1001];
int A_size = 0;

void dfs(int k, int n) {
    A[A_size++] = n;
    if (k == 9) return;
    else {
        dfs(k + 1, n * 10 + 4);
        dfs(k + 1, n * 10 + 7);
    }
}

LL I(LL l, LL r, LL l_, LL r_) {
    if (l < l_) l = l_;
    if (r > r_) r = r_;
    return (r - l + 1 > 0) ? (r - l + 1) : 0;
}

void sort_array() {
    for (int i = 0; i < A_size - 1; i++) {
        for (int j = 0; j < A_size - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                LL temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

void read(LL *x) {
    char c;
    for (c = getchar(); c < '0'; c = getchar());
    *x = c - '0';
    for (c = getchar(); c >= '0'; c = getchar()) *x = *x * 10 + c - '0';
}

void output(DB x) {
    printf("%.12lf\n", x);
}

int main() {
    LL pl, pr, vl, vr, k;
    dfs(0, 0);
    sort_array();
    A[A_size++] = INF;

    read(&pl);
    read(&pr);
    read(&vl);
    read(&vr);
    read(&k);

    for (int i = 0; i < A_size - k; i++) {
        LL l1 = A[i - 1] + 1, r1 = A[i], l2 = A[i + k - 1], r2 = A[i + k] - 1;
        LL d1 = I(l1, r1, pl, pr) * I(l2, r2, vl, vr);
        LL d2 = I(l1, r1, vl, vr) * I(l2, r2, pl, pr);
        cnt += d1 + d2;
        if (d2 && d2 && k == 1) --cnt;
    }

    output((DB)cnt / ((pr - pl + 1) * (vr - vl + 1)));
}
