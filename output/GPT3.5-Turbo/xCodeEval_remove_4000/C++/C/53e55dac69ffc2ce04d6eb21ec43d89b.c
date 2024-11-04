#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 202020

typedef struct {
    int a;
    int b;
    int c;
} Triple;

typedef struct {
    int first;
    int second;
} Pair;

typedef struct {
    int a;
    int b;
    int c;
} Triple;

int n;
int ct;
int sz[MAX_SIZE];
int used[MAX_SIZE];
int g[MAX_SIZE][MAX_SIZE];
int c[MAX_SIZE];
int c_size;
Triple ans[MAX_SIZE];
int ans_size;

void go(int cur, int iter) {
    sz[cur] = 1;
    used[cur] = iter;
    int t = 0;
    for (int i = 0; i < n; i++) {
        int to = g[cur][i];
        if (used[to] != iter) {
            go(to, iter);
            sz[cur] += sz[to];
            if (sz[to] > t) {
                t = sz[to];
            }
        }
    }
    if (n - sz[cur] > t) {
        t = n - sz[cur];
    }
    if (t * 2 <= n) {
        ct = cur;
        c[c_size++] = cur;
    }
}

void dfs2(int cur, int p) {
    used[cur] = 1;
    for (int i = 0; i < n; i++) {
        int to = g[cur][i];
        if (!used[to] && to != p) {
            dfs2(to, cur);
        }
    }
}

void solve(int cur) {
    dfs2(cur, -1);
    int last = cur;
    for (int i = 0; i < c_size; i++) {
        int v = c[i];
        int par = used[v];
        if (par != cur) {
            ans[ans_size].a = ct;
            ans[ans_size].b = last;
            ans[ans_size].c = v;
            ans_size++;
            ans[ans_size].a = v;
            ans[ans_size].b = par;
            ans[ans_size].c = cur;
            ans_size++;
            last = v;
        }
    }
    if (last != cur) {
        ans[ans_size].a = ct;
        ans[ans_size].b = last;
        ans[ans_size].c = cur;
        ans_size++;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x][i] = y;
        g[y][i] = x;
    }
    go(1, 1);
    for (int i = 0; i < MAX_SIZE; i++) {
        used[i] = 0;
    }
    for (int i = 0; i < c_size; i++) {
        used[c[i]] = 1;
    }
    for (int i = 0; i < c_size; i++) {
        ct = c[i];
        for (int j = 0; j < n; j++) {
            int to = g[ct][j];
            if (!used[to]) {
                solve(to);
            }
        }
    }
    printf("%d\n", ans_size);
    for (int i = 0; i < ans_size; i++) {
        printf("%d %d %d\n", ans[i].a, ans[i].b, ans[i].c);
    }
    return 0;
}
