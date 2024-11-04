#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 305
#define MAX_M 305

typedef long long ll;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    pii first;
    int second;
} triple;

int mod;

const int gmod=2;
const int inf=1039074182;
const double eps=1e-9;
const ll llinf=1LL*inf*inf;

void chmin(int *x, int b) {
    if (b < *x) {
        *x = b;
    }
}

void chmax(int *x, int b) {
    if (b > *x) {
        *x = b;
    }
}

void chadd(int *x, int b) {
    *x += b - mod;
    *x += (*x >> 31 & mod);
}

void chaddll(ll *x, ll b) {
    *x += b - mod;
    *x += (*x >> 31 & mod);
}

void chmul(int *x, int b) {
    *x = 1LL * (*x) * b % mod;
}

void chmod(int *x, int b) {
    *x %= b;
    *x += b;
    if (*x >= b) {
        *x -= b;
    }
}

int mabs(int x) {
    return (x < 0 ? -x : x);
}

int n, v, m;
int a[MAX_N];
int b[MAX_N];
int edges[MAX_N][MAX_N];
int c[MAX_N];
int visit[MAX_N];
int cnt;
ll s[MAX_N];
triple res[MAX_M];
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
    int front = 0;
    int rear = 0;
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
    res[cnt].first.first = x;
    res[cnt].first.second = y;
    res[cnt].second = flow;
    cnt++;
}

void liu2(int i, int flow, int *routes) {
    if (i == routes[0]) {
        return;
    }
    int nxt = routes[i + 1];
    int now = routes[i];
    if (a[nxt] + flow <= v) {
        liu(now, nxt, flow);
        liu2(i + 1, flow, routes);
    } else {
        int id2 = a[now];
        int moved = v - a[nxt];
        liu(now, nxt, v - a[nxt]);
        liu2(i + 1, flow, routes);
        liu(now, nxt, flow - moved);
        int id1 = a[now];
    }
}

void adjust(int x, int y) {
    if (a[x] != b[x] && a[y] != b[y]) {
        if (a[x] < b[x]) {
            int temp = x;
            x = y;
            y = temp;
        }
        int flow = (a[x] - b[x] < b[y] - a[y] ? a[x] - b[x] : b[y] - a[y]);
        bfs(x);
        int routes[MAX_N];
        int routeCnt = 0;
        routes[routeCnt++] = y;
        while (y != x) {
            int step = dist[y];
            int nxt = -1;
            for (int ny = 0; ny < n; ny++) {
                if (dist[ny] != step - 1) {
                    continue;
                }
                nxt = ny;
                break;
            }
            y = nxt;
            routes[routeCnt++] = y;
        }
        liu2(0, flow, routes);
    }
}

int main() {
    scanf("%d%d%d", &n, &v, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    memset(edges, 0, sizeof(edges));
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--;
        y--;
        edges[x][y] = 1;
        edges[y][x] = 1;
    }
    memset(visit, 0, sizeof(visit));
    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (visit[i]) {
            continue;
        }
        dfs(i);
        cnt++;
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
    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            for (int j = i + 1; j < n; j++) {
                if (c[i] == c[j] && a[j] != b[j] && ((a[i] < b[i] && a[j] < b[j]) || (a[i] > b[i] && a[j] > b[j]))) {
                    adjust(i, j);
                    break;
                }
            }
            if (a[i] != b[i]) {
                i--;
            }
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%d %d %d\n", res[i].first.first + 1, res[i].first.second + 1, res[i].second);
    }
    return 0;
}
