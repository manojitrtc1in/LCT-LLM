#include <stdio.h>
#include <string.h>

#define Maxn 100005

int l[Maxn], r[Maxn];
int n, m;
int sum[Maxn];
int dp1[Maxn], dp2[Maxn];
int bit[Maxn];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void modify(int pos, int val) {
    while (pos < Maxn) {
        if (bit[pos] < val) {
            bit[pos] = val;
        }
        pos += pos & -pos;
    }
}

int query(int pos) {
    int ans = 0;
    while (pos) {
        if (ans < bit[pos]) {
            ans = bit[pos];
        }
        pos -= pos & -pos;
    }
    return ans;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &l[i], &r[i]);
        sum[l[i]]++;
        sum[r[i] + 1]--;
    }
    for (int i = 1; i <= m; i++) {
        sum[i] += sum[i - 1];
    }
    dp1[0] = 0;
    for (int i = 1; i <= m; i++) {
        dp1[i] = query(sum[i] + 1) + 1;
        modify(sum[i] + 1, dp1[i]);
    }
    memset(bit, 0, sizeof(bit));
    for (int i = m; i >= 1; i--) {
        dp2[i] = query(sum[i] + 1) + 1;
        modify(sum[i] + 1, dp2[i]);
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (ans < dp1[i] + dp2[i] - 1) {
            ans = dp1[i] + dp2[i] - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
