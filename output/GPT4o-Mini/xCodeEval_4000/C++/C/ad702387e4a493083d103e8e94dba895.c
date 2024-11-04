#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MAXN 305
#define MAXV 1000000007

int n, v, m;
int a[MAXN];
int b[MAXN];
int edges[MAXN][MAXN];
int c[MAXN];
bool visit[MAXN];
int cnt;
long long s[MAXN];
int res[MAXN][3]; // To store results
int dist[MAXN];

void dfs(int x) {
    visit[x] = true;
    c[x] = cnt;
    for (int u = 0; u < n; u++) {
        if (edges[x][u]) {
            if (visit[u]) continue;
            dfs(u);
        }
    }
}

void bfs(int src) {
    memset(visit, 0, sizeof(visit));
    visit[src] = true;
    dist[src] = 0;
    int queue[MAXN], front = 0, rear = 0;
    queue[rear++] = src;
    while (front < rear) {
        int x = queue[front++];
        for (int u = 0; u < n; u++) {
            if (edges[x][u]) {
                if (visit[u]) continue;
                dist[u] = dist[x] + 1;
                visit[u] = true;
                queue[rear++] = u;
            }
        }
    }
}

void liu(int x, int y, int flow) {
    assert(flow >= 0);
    a[x] -= flow;
    assert(a[x] >= 0);
    a[y] += flow;
    assert(a[y] <= v);
    res[cnt][0] = x;
    res[cnt][1] = y;
    res[cnt][2] = flow;
    cnt++;
}

void liu_recursive(int i, int flow, int *routes, int route_size) {
    if (i == route_size - 1) return;
    int nxt = routes[i + 1];
    int now = routes[i];
    if (a[nxt] + flow <= v) {
        liu(now, nxt, flow);
        liu_recursive(i + 1, flow, routes, route_size);
    } else {
        int original_a_now = a[now];
        int moved = v - a[nxt];
        liu(now, nxt, v - a[nxt]);
        liu_recursive(i + 1, flow, routes, route_size);
        liu(now, nxt, flow - moved);
        int new_a_now = a[now];
    }
}

void adjust(int x, int y) {
    assert(a[x] != b[x]);
    assert(a[y] != b[y]);

    if (a[x] < b[x]) {
        int temp = x;
        x = y;
        y = temp;
    }
    int flow = (a[x] - b[x] < a[y] - b[y]) ? (a[x] - b[x]) : (a[y] - b[y]);
    bfs(x);
    int routes[MAXN], route_size = 0;
    routes[route_size++] = y;
    while (y != x) {
        int step = dist[y];
        int nxt = -1;
        for (int ny = 0; ny < n; ny++) {
            if (edges[y][ny] && dist[ny] == step - 1) {
                nxt = ny;
                break;
            }
        }
        y = nxt;
        routes[route_size++] = y;
    }
    for (int i = 0; i < route_size / 2; i++) {
        int temp = routes[i];
        routes[i] = routes[route_size - 1 - i];
        routes[route_size - 1 - i] = temp;
    }
    int notEq = 0;
    for (int i = 0; i < route_size; i++) {
        if (a[routes[i]] != b[routes[i]]) notEq++;
    }
    liu_recursive(0, flow, routes, route_size);
    for (int i = 0; i < route_size; i++) {
        if (a[routes[i]] != b[routes[i]]) notEq--;
    }
    assert(notEq >= 1);
}

int main() {
    scanf("%d %d %d", &n, &v, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    memset(edges, 0, sizeof(edges));
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--;
        y--;
        edges[x][y] = 1;
        edges[y][x] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (visit[i]) continue;
        dfs(i);
        cnt++;
    }
    for (int i = 0; i < n; i++) {
        s[c[i]] += a[i];
        s[c[i]] -= b[i];
    }
    for (int i = 0; i < n; i++) {
        if (s[i]) {
            printf("NO\n");
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;
        for (int j = i + 1; j < n; j++) {
            if (c[i] != c[j]) continue;
            if (a[j] == b[j]) continue;
            if (a[i] < b[i] && a[j] < b[j]) continue;
            if (a[i] > b[i] && a[j] > b[j]) continue;

            adjust(i, j);
            break;
        }
        if (a[i] != b[i]) i--;
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%d %d %d\n", res[i][0] + 1, res[i][1] + 1, res[i][2]);
    }
    return 0;
}
