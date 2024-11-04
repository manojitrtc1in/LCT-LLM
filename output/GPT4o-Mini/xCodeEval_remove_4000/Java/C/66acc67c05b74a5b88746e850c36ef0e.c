#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MOD 1000000007
#define MAX 200000

typedef struct {
    int idx, val;
} Pair;

Pair createPair(int idx, int val) {
    Pair p;
    p.idx = idx;
    p.val = val;
    return p;
}

int comparePairs(const void *a, const void *b) {
    Pair *pairA = (Pair *)a;
    Pair *pairB = (Pair *)b;
    return pairB->val - pairA->val;
}

long gcd(long x, long y) {
    return (y == 0) ? x : gcd(y, x % y);
}

void dfs(int start, int root, bool visited[], int par[], LinkedList *adj[]) {
    visited[start] = true;
    par[start] = root;
    for (int i = 0; i < adj[start].size; i++) {
        int neighbor = adj[start].data[i];
        if (!visited[neighbor]) {
            dfs(neighbor, start, visited, par, adj);
        }
    }
}

void soln() {
    int a, b, x, y, z;
    scanf("%d %d %d %d %d", &a, &b, &x, &y, &z);
    long ans = 0;

    if ((long)a < 2 * (long)x) {
        ans += 2 * (long)x - a;
        a = 0;
    } else {
        a -= 2 * x;
    }

    if ((long)b < 3 * (long)z) {
        ans += 3 * (long)z - b;
        b = 0;
    } else {
        b -= 3 * z;
    }

    if (a < b) {
        y = (y - a > 0) ? y - a : 0;
        b -= a;
        a = 0;
    } else {
        y = (y - b > 0) ? y - b : 0;
        b = a - b;
        a = 0;
    }

    if (y > b) {
        ans += b + 2 * (y - b);
    } else {
        ans += y;
    }

    printf("%ld\n", ans);
}

int main() {
    soln();
    return 0;
}
