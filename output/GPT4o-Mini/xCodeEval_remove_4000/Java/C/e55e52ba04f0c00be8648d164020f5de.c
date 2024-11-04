#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAXN 10000001

long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long lcm(long a, long b) {
    return (a * b) / gcd(a, b);
}

long power(long x, long n) {
    if (n == 0) return 1;
    if (n == 1) return x;

    long ans = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            ans *= x;
        }
        n /= 2;
        x = x * x;
    }
    return ans;
}

long modInverse(long a, long p) {
    return power(a, p - 2);
}

long modBinomial(long n, long k, long p) {
    long numerator = 1;
    for (int i = 0; i < k; i++) {
        numerator = (numerator * (n - i)) % p;
    }

    long denominator = 1;
    for (int i = 1; i <= k; i++) {
        denominator = (denominator * i) % p;
    }

    return (numerator * modInverse(denominator, p)) % p;
}

void countNoOfNodesInsubtree(int child, int par, int *dp, int **tree) {
    int count = 1;
    for (int i = 0; i < tree[child][0]; i++) {
        int x = tree[child][i + 1];
        if (x == par) continue;
        countNoOfNodesInsubtree(x, child, dp, tree);
        count += dp[x];
    }
    dp[child] = count;
}

void dfs(int sv, bool *vis, int **tree) {
    vis[sv] = true;
    for (int i = 0; i < tree[sv][0]; i++) {
        int x = tree[sv][i + 1];
        if (!vis[x]) {
            dfs(x, vis, tree);
        }
    }
}

void solve() {
    long n;
    scanf("%ld", &n);
    long x = n;
    long *list = (long *)malloc(sizeof(long) * 100);
    int listSize = 0;

    for (long i = 2; i * i <= n; i++) {
        if (x % i == 0) {
            while (x % i == 0) {
                list[listSize++] = i;
                x = x / i;
            }
        }
    }

    if (x > 1) list[listSize++] = x;

    if (n == 1) {
        printf("1\n0\n");
    } else if (listSize == 2) {
        printf("2\n");
    } else {
        printf("1\n");
        if (listSize == 1) {
            printf("0\n");
        } else {
            long ans = list[0] * list[1];
            printf("%ld\n", ans);
        }
    }

    free(list);
}

int main() {
    solve();
    return 0;
}
