#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <queue>

#define MOD 1000000007
#define INF 1039074182
#define MAXN 305

typedef long long ll;
typedef struct {
    int first, second;
} pii;

int n, v, m;
int a[MAXN];
int b[MAXN];
int edges[MAXN][MAXN];
int c[MAXN];
int visit[MAXN];
int cnt;
ll s[MAXN];
pii res[MAXN * MAXN];
int dist[MAXN];

void dfs(int x) {
    visit[x] = 1;
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
    visit[src] = 1;
    dist[src] = 0;
    std::queue<int> que;
    que.push(src);
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        for (int u = 0; u < n; u++) {
            if (edges[x][u]) {
                if (visit[u]) continue;
                dist[u] = dist[x] + 1;
                visit[u] = 1;
                que.push(u);
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
    res[cnt++] = (pii){x, y};
}

void liu_recursive(int i, int flow, int *routes, int route_size) {
    if (i == route_size - 1) return;
    int nxt = routes[i + 1];
    int now = routes[i];
    if (a[nxt] + flow <= v) {
        liu(now, nxt, flow);
        liu_recursive(i + 1, flow, routes, route_size);
    } else {
        int moved = v - a[nxt];
        liu(now, nxt, moved);
        liu_recursive(i + 1, flow, routes, route_size);
        liu(now, nxt, flow - moved);
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
    int routes[MAXN];
    int route_size = 0;
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
    for (int i = route_size - 1; i >= 0; i--) {
        if (a[routes[i]] != b[routes[i]]) {
            liu_recursive(0, flow, routes, route_size);
            break;
        }
    }
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
        printf("%d %d %d\n", res[i].first + 1, res[i].second + 1, res[i].second);
    }
    return 0;
}
