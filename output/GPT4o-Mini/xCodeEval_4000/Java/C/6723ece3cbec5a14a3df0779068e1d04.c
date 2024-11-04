#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAXN 1000
#define MOD 1000000007

typedef struct {
    int *data;
    int size;
    int capacity;
} ArrayList;

ArrayList* createArrayList(int capacity) {
    ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
    list->data = (int *)malloc(capacity * sizeof(int));
    list->size = 0;
    list->capacity = capacity;
    return list;
}

void add(ArrayList *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = value;
}

int adj[MAXN][MAXN];
int dist[MAXN];
bool mulpath[MAXN];
int memo[MAXN][MAXN];
char c[MAXN];
int notmemo[MAXN][MAXN];
int k;

void bfs(int s, int n) {
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[s] = 0;
    int queue[MAXN], front = 0, back = 0;
    queue[back++] = s;

    while (front < back) {
        int u = queue[front++];
        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                if (dist[v] == INT_MAX) {
                    dist[v] = dist[u] + 1;
                    queue[back++] = v;
                } else if (dist[v] == dist[u] + 1) {
                    mulpath[v] = true;
                }
            }
        }
    }
}

int changes(int i, int j) {
    if (i >= j) return 0;
    if (notmemo[i][j] != -1) return notmemo[i][j];
    if (c[i] != c[j]) {
        notmemo[i][j] = 1 + changes(i + 1, j - 1);
    } else {
        notmemo[i][j] = changes(i + 1, j - 1);
    }
    return notmemo[i][j];
}

int dp(int i, int count) {
    if (count > k) return INT_MAX;
    if (i >= strlen(c)) return 0;
    if (memo[i][count] != -1) return memo[i][count];
    int ans = INT_MAX;
    for (int j = i; j < strlen(c); j++) {
        ans = fmin(ans, dp(j + 1, count + 1) + changes(i, j));
    }
    return memo[i][count] = ans;
}

void trace(int i, int count) {
    if (i >= strlen(c)) return;
    if (count > k) return;
    int ans = dp(i, count);
    for (int j = i; j < strlen(c); j++) {
        if (dp(j + 1, count + 1) + changes(i, j) == ans) {
            int end = j;
            for (int idx = i; idx <= j && end >= 0; idx++) {
                putchar(c[idx]);
                c[end--] = c[idx];
            }
            if (end < strlen(c) - 1) putchar('+');
            trace(j + 1, count + 1);
            return;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[v - 1][u - 1] = 1;
    }
    int k;
    scanf("%d", &k);
    int p[k];
    for (int i = 0; i < k; i++) {
        scanf("%d", &p[i]);
        p[i]--;
    }
    bfs(p[k - 1], n);
    int min = 0, max = 0;
    for (int i = 0; i < k - 1; i++) {
        if (dist[p[i + 1]] + 1 == dist[p[i]]) {
            if (mulpath[p[i]]) {
                max++;
            }
        } else {
            min++;
            max++;
        }
    }
    printf("%d %d\n", min, max);
    return 0;
}
