#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 200000

typedef struct Pair {
    int idx;
    int val;
} Pair;

void dfs(int start, int root, bool visited[], int par[], int adj[][MAX_SIZE], int size) {
    visited[start] = true;
    par[start] = root;
    for (int i = 0; i < size; i++) {
        if (!visited[i] && adj[start][i]) {
            dfs(i, start, visited, par, adj, size);
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
        a = a - 2 * x;
    }
    if ((long)b < 3 * (long)z) {
        ans += 3 * (long)z - b;
        b = 0;
    } else {
        b = b - 3 * z;
    }
    if (a < b) {
        y = y - a > 0 ? y - a : 0;
        b = b - a;
        a = 0;
    } else {
        y = y - b > 0 ? y - b : 0;
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
    int adj[MAX_SIZE][MAX_SIZE] = {0};
    int a, b, x, y, z;
    scanf("%d %d %d %d %d", &a, &b, &x, &y, &z);
    long ans = 0;
    if ((long)a < 2 * (long)x) {
        ans += 2 * (long)x - a;
        a = 0;
    } else {
        a = a - 2 * x;
    }
    if ((long)b < 3 * (long)z) {
        ans += 3 * (long)z - b;
        b = 0;
    } else {
        b = b - 3 * z;
    }
    if (a < b) {
        y = y - a > 0 ? y - a : 0;
        b = b - a;
        a = 0;
    } else {
        y = y - b > 0 ? y - b : 0;
        b = a - b;
        a = 0;
    }
    if (y > b) {
        ans += b + 2 * (y - b);
    } else {
        ans += y;
    }
    printf("%ld\n", ans);
    return 0;
}
