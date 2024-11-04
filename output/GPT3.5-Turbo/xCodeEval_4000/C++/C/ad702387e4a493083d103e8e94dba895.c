#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 305

int n, v, m;
int a[MAX_N];
int b[MAX_N];
int edges[MAX_N][MAX_N];
int c[MAX_N];
int visit[MAX_N];
int cnt;
long long s[MAX_N];
int res[MAX_N][3];
int dist[MAX_N];

void dfs(int x) {
    visit[x] = 1;
    c[x] = cnt;
    for (int u = 0; u < n; u++) {
        if (edges[x][u] && !visit[u]) {
            dfs(u);
        }
    }
}

void bfs(int src) {
    memset(visit, 0, sizeof(visit));
    visit[src] = 1;
    dist[src] = 0;
    int queue[MAX_N];
    int front = 0, rear = 0;
    queue[rear++] = src;
    while (front < rear) {
        int x = queue[front++];
        for (int u = 0; u < n; u++) {
            if (edges[x][u] && !visit[u]) {
                dist[u] = dist[x] + 1;
                visit[u] = 1;
                queue[rear++] = u;
            }
        }
    }
}

void liu(int x, int y, int flow) {
    a[x] -= flow;
    a[y] += flow;
    res[cnt][0] = x + 1;
    res[cnt][1] = y + 1;
    res[cnt][2] = flow;
    cnt++;
}

void liu_helper(int i, int flow, int *routes) {
    if (i == routes[0]) {
        return;
    }
    int nxt = routes[i + 1];
    int now = routes[i];
    if (a[nxt] + flow <= v) {
        liu(now, nxt, flow);
        liu_helper(i + 1, flow, routes);
    } else {
        int original_a_now = a[now];
        int moved = v - a[nxt];
        liu(now, nxt, v - a[nxt]);
        liu_helper(i + 1, flow, routes);
        liu(now, nxt, flow - moved);
        int new_a_now = a[now];
    }
}

void adjust(int x, int y) {
    if (a[x] != b[x] && a[y] != b[y]) {
        if (a[x] < b[x]) {
            int temp = x;
            x = y;
            y = temp;
        }
        int flow = abs(a[x] - b[x]) < abs(a[y] - b[y]) ? abs(a[x] - b[x]) : abs(a[y] - b[y]);
        bfs(x);
        int routes[MAX_N];
        int route_len = 0;
        routes[route_len++] = y;
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
            routes[route_len++] = y;
        }
        liu_helper(0, flow, routes);
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
    memset(visit, 0, sizeof(visit));
    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            dfs(i);
            cnt++;
        }
    }
    memset(s, 0, sizeof(s));
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
    int prev;
    int cur;
    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            continue;
        }
        for (int j = i + 1; j < n; j++) {
            if (c[i] != c[j]) {
                continue;
            }
            if (a[j] == b[j]) {
                continue;
            }
            if ((a[i] < b[i] && a[j] < b[j]) || (a[i] > b[i] && a[j] > b[j])) {
                continue;
            }
            adjust(i, j);
            break;
        }
        if (a[i] != b[i]) {
            i--;
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
    }
    return 0;
}
